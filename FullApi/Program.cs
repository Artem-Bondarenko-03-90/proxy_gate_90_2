using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using System;
using System.IO;
using System.Diagnostics;
using System.Threading.Tasks;
using System.Collections.Generic;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddAntiforgery();

var app = builder.Build();
app.UseSwagger();
app.UseSwaggerUI();

const string LibiecPath = "/app/libiec61850_full";
const string ExamplesDir = LibiecPath + "/examples/server_example_files";
const string GenmodelJar = LibiecPath + "/tools/model_generator/genmodel.jar";
const string ServerDir = LibiecPath + "/build/examples/server_example_files";
const string ServerExe = ServerDir + "/server_example_files";
const string FileStoreDir = ServerDir + "/vmd-filestore";

Process? _serverProcess = null;

// GET /health
app.MapGet("/health", () => new
{
    status = "healthy",
    timestamp = DateTime.UtcNow,
    api = "IEC-61850 Server Manager",
    version = "2.0"
});

// GET /api/server/status
app.MapGet("/api/server/status", () =>
{
    bool running = _serverProcess != null && !_serverProcess.HasExited;
    return new
    {
        status = running ? "running" : "stopped",
        port = 8102,
        pid = _serverProcess?.Id,
        timestamp = DateTime.UtcNow
    };
});

// POST /api/server/rebuild
app.MapPost("/api/server/rebuild", async (IFormFile cidFile, string iedName, string accessPoint, int port) =>
{
    if (cidFile == null || cidFile.Length == 0)
        return Results.BadRequest(new { error = "CID file required" });

    var uploadId = Guid.NewGuid().ToString("N")[..8];
    var cidPath = $"/app/uploaded_{uploadId}.cid";
    var logs = new List<string>();

    try
    {
        // Save CID
        using (var stream = System.IO.File.Create(cidPath))
            await cidFile.CopyToAsync(stream);

        logs.Add($"[1/5] Uploading CID: {cidFile.FileName}");

        // Generate model
        logs.Add("[2/5] Generating static model...");
        using (var proc = new Process
        {
            StartInfo = new ProcessStartInfo
            {
                FileName = "java",
                Arguments = $"-jar {GenmodelJar} {cidPath} -ied {iedName} -ap {accessPoint} -out iedModel -modelprefix iedModel",
                WorkingDirectory = ExamplesDir,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false
            }
        })
        {
            proc.Start();
            proc.WaitForExit();

            if (proc.ExitCode != 0)
            {
                var error = proc.StandardError.ReadToEnd();
                logs.Add($"✗ Error: {error}");
                return Results.Problem("Model generation failed", null, 500);
            }
        }

        // Copy files
        System.IO.File.Copy($"{ExamplesDir}/iedModel.c", $"{ExamplesDir}/static_model.c", true);
        System.IO.File.Copy($"{ExamplesDir}/iedModel.h", $"{ExamplesDir}/static_model.h", true);
        logs.Add("  ✓ Model generated");

        // Compile
        logs.Add("[3/5] Compiling server...");
        using (var proc = new Process
        {
            StartInfo = new ProcessStartInfo
            {
                FileName = "/bin/sh",
                Arguments = "-c \"cd /app/libiec61850_full/build && make server_example_files -j\\$(nproc)\"",
                WorkingDirectory = $"{LibiecPath}/build",
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false
            }
        })
        {
            proc.Start();
            proc.WaitForExit();

            if (proc.ExitCode != 0)
            {
                var error = proc.StandardError.ReadToEnd();
                logs.Add($"✗ Compilation failed: {error}");
                return Results.Problem("Compilation failed", null, 500);
            }
        }
        logs.Add("  ✓ Compiled");

        // Restart server
        logs.Add("[4/5] Restarting server...");
        if (_serverProcess != null && !_serverProcess.HasExited)
        {
            _serverProcess.Kill();
            _serverProcess.WaitForExit(5000);
        }

        logs.Add("[5/5] Starting server...");
        _serverProcess = new Process
        {
            StartInfo = new ProcessStartInfo
            {
                FileName = ServerExe,
                Arguments = port.ToString(),
                WorkingDirectory = ServerDir,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false
            }
        };
        _serverProcess.Start();
        await Task.Delay(2000);
        logs.Add($"  ✓ Server started (PID: {_serverProcess.Id})");
    }
    finally
    {
        if (System.IO.File.Exists(cidPath))
            System.IO.File.Delete(cidPath);
    }

    return Results.Ok(new { message = "Server rebuilt", uploadId, iedName, accessPoint, port, pid = _serverProcess?.Id, logs });
})
.DisableAntiforgery();

// GET /api/files/{deviceName}
app.MapGet("/api/files/{deviceName}", (string deviceName) =>
{
    var filestoreDir = Path.Combine(FileStoreDir, deviceName);

    if (!Directory.Exists(filestoreDir))
    {
        Directory.CreateDirectory(filestoreDir);
    }

    var files = Directory.GetFiles(filestoreDir)
        .Select(f => new
        {
            name = Path.GetFileName(f),
            size = new FileInfo(f).Length,
            modified = System.IO.File.GetLastWriteTimeUtc(f)
        })
        .ToArray();

    return Results.Ok(new { deviceName, files });
});

// POST /api/files/{deviceName}
app.MapPost("/api/files/{deviceName}", async (string deviceName, IFormFile file) =>
{
    var result = await UploadFileAsync(deviceName, file);
    return Results.Ok(result);
})
.DisableAntiforgery();

async Task<object> UploadFileAsync(string deviceName, IFormFile file)
{
    if (file == null || file.Length == 0)
        return new { error = "File is required" };

    var filestoreDir = Path.Combine(FileStoreDir, deviceName);

    if (!Directory.Exists(filestoreDir))
    {
        Directory.CreateDirectory(filestoreDir);
    }

    var filePath = Path.Combine(filestoreDir, file.FileName);

    await using (var stream = System.IO.File.Create(filePath))
    {
        await file.CopyToAsync(stream);
    }

    return new
    {
        message = "File uploaded successfully",
        deviceName,
        fileName = file.FileName,
        size = file.Length,
        path = $"{deviceName}/{file.FileName}"
    };
}

// GET /api/files/{deviceName}/{fileName}
app.MapGet("/api/files/{deviceName}/{fileName}", (string deviceName, string fileName) =>
{
    var filePath = Path.Combine(FileStoreDir, deviceName, fileName);

    if (!System.IO.File.Exists(filePath))
    {
        return Results.NotFound(new { error = "File not found", path = $"{deviceName}/{fileName}" });
    }

    var fileBytes = System.IO.File.ReadAllBytes(filePath);
    return Results.File(fileBytes, "application/octet-stream", fileName);
});

// DELETE /api/files/{deviceName}/{fileName}
app.MapDelete("/api/files/{deviceName}/{fileName}", (string deviceName, string fileName) =>
{
    var filePath = Path.Combine(FileStoreDir, deviceName, fileName);

    if (!System.IO.File.Exists(filePath))
    {
        return Results.NotFound(new { error = "File not found" });
    }

    System.IO.File.Delete(filePath);

    return Results.Ok(new { message = "File deleted", fileName, deviceName });
});

// POST /api/server/stop
app.MapPost("/api/server/stop", () =>
{
    if (_serverProcess != null && !_serverProcess.HasExited)
    {
        _serverProcess.Kill();
        _serverProcess.WaitForExit(5000);
        _serverProcess = null;
    }
    return Results.Ok(new { message = "Server stopped" });
});

// POST /api/server/start
app.MapPost("/api/server/start", (int port = 8102) =>
{
    if (_serverProcess != null && !_serverProcess.HasExited)
        return Results.Ok(new { message = "Already running" });

    _serverProcess = new Process
    {
        StartInfo = new ProcessStartInfo
        {
            FileName = ServerExe,
            Arguments = port.ToString(),
            WorkingDirectory = ServerDir,
            RedirectStandardOutput = true,
            RedirectStandardError = true,
            UseShellExecute = false
        }
    };
    _serverProcess.Start();
    return Results.Ok(new { message = "Server started", port, pid = _serverProcess.Id });
});

// GET /api/devices
app.MapGet("/api/devices", () =>
{
    return Results.Ok(new[]
    {
        new { name = "Measurements", description = "Measurement data (LD1)" },
        new { name = "Protection", description = "Protection events (LD2)" },
        new { name = "Control", description = "Control status (LD3)" }
    });
});

// Redirect root
app.MapGet("/", () => Results.Redirect("/swagger"));

app.Run();
