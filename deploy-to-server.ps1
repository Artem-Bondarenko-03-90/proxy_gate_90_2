# ============================================
# Deploy script for local server (PowerShell)
# ============================================

# Configuration
$SERVER_HOST = if ($env:SERVER_HOST) { $env:SERVER_HOST } else { "192.168.1.10" }
$SERVER_USER = if ($env:SERVER_USER) { $env:SERVER_USER } else { "root" }
$SERVER_PORT = if ($env:SERVER_PORT) { $env:SERVER_PORT } else { "22" }
$DOCKER_IMAGE = "iec61850-server"

Write-Host "=== Deploying to $SERVER_USER@$SERVER_HOST`:$SERVER_PORT ===" -ForegroundColor Green

# Build and publish
Write-Host "📦 Building application..." -ForegroundColor Cyan
dotnet publish FullApi/FullApi.csproj -c Release -o publish-full

# Build Docker image
Write-Host "🐳 Building Docker image..." -ForegroundColor Cyan
docker build --no-cache -f Dockerfile.final -t ${DOCKER_IMAGE}:latest .

# Save Docker image
Write-Host "💾 Saving Docker image..." -ForegroundColor Cyan
docker save ${DOCKER_IMAGE}:latest | gzip > iec61850-server.tar.gz

# Copy to server
Write-Host "📤 Copying to server..." -ForegroundColor Cyan
scp -P $SERVER_PORT iec61850-server.tar.gz ${SERVER_USER}@${SERVER_HOST}:/tmp/

# Deploy on server
Write-Host "🚀 Deploying on server..." -ForegroundColor Cyan
$deployScript = @'
set -e

# Create directory if not exists
sudo mkdir -p /opt/iec61850-server
cd /opt/iec61850-server

# Load Docker image
echo "Loading Docker image..."
docker load < /tmp/iec61850-server.tar.gz

# Stop old container
echo "Stopping old container..."
docker stop iec61850-server 2>/dev/null || true
docker rm iec61850-server 2>/dev/null || true

# Run new container
echo "Starting new container..."
docker run -d \
  --name iec61850-server \
  --restart unless-stopped \
  -p 8080:80 \
  -p 8102:8102 \
  -v iec61850-filestore:/app/libiec61850_full/build/examples/server_example_files/vmd-filestore \
  iec61850-server:latest

# Cleanup
echo "Cleaning up..."
docker image prune -af --filter "until=24h"
rm /tmp/iec61850-server.tar.gz

echo "✅ Deployment successful!"
'@

ssh -p $SERVER_PORT ${SERVER_USER}@${SERVER_HOST} $deployScript

# Cleanup local file
Remove-Item iec61850-server.tar.gz

# Health check
Write-Host "⏳ Waiting for service to start..." -ForegroundColor Yellow
Start-Sleep -Seconds 10

Write-Host "🔍 Checking service health..." -ForegroundColor Cyan
try {
    $response = Invoke-WebRequest -Uri "http://${SERVER_HOST}:8080/health" -UseBasicParsing
    if ($response.StatusCode -eq 200) {
        Write-Host "✅ Service is healthy!" -ForegroundColor Green
    }
} catch {
    Write-Host "❌ Health check failed: $($_.Exception.Message)" -ForegroundColor Red
}

Write-Host ""
Write-Host "=== Deployment complete! ===" -ForegroundColor Green
Write-Host "Web API: http://${SERVER_HOST}:8080"
Write-Host "Swagger: http://${SERVER_HOST}:8080/swagger"
Write-Host "IEC-61850: ${SERVER_HOST}:8102"
