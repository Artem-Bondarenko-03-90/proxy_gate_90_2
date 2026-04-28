"""
FastAPI REST API Manager for IEC 61850 Server
Manages logical devices dynamically using Docker CLI
"""
import os
import subprocess
import logging
import json
import shutil
from pathlib import Path
from typing import List, Dict, Any
from fastapi import FastAPI, HTTPException, BackgroundTasks, UploadFile, File, Form, Request
from starlette.datastructures import UploadFile as StarletteUploadFile
from pydantic import BaseModel
from typing import Optional
from cid_manager import CIDManager
from device_registry import get_registry, DeviceNotFound

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Paths (mounted from host)
HOST_WORK_DIR = "/work"
HOST_WORK_DIR_ABS = "/f/RTSoft/Code/proxy_gate_90_2"  # Absolute path for Docker binds
CID_FILE = os.path.join(HOST_WORK_DIR, "multi-ld-model.cid")
STATIC_MODEL_C = os.path.join(HOST_WORK_DIR, "static_model.c")
STATIC_MODEL_H = os.path.join(HOST_WORK_DIR, "static_model.h")
GENMODEL_JAR = os.path.join(HOST_WORK_DIR, "genmodel.jar")
DOCKERFILE = os.path.join(HOST_WORK_DIR, "Dockerfile")
DEVICE_REGISTRY = os.path.join(HOST_WORK_DIR, "device_registry.json")

# FastAPI app
app = FastAPI(
    title="IEC 61850 LD Manager API",
    description="""
## REST API for managing IEC 61850 Server Logical Devices

This API allows you to:
* **Add Logical Devices** - Add new LDs to the IEC 61850 server configuration
* **Deploy Changes** - Rebuild and restart the server with updated configuration
* **Upload Files** - Upload files to device-specific directories
* **Manage Devices** - Update device metadata and registry

### Workflow
1. Add one or more Logical Devices via `POST /api/ld`
2. Upload files via `POST /api/files` (files are routed to device directories)
3. Deploy changes via `POST /api/ld/deploy` (regenerates model and restarts server)

### Device Registry
Each device is mapped by `device_cim_id` to a storage directory. Files uploaded
via the API are automatically routed to the correct device directory.

### Authentication
Currently no authentication is required. Add authentication as needed for production.
    """,
    version="1.0.0",
    docs_url="/docs",
    redoc_url="/redoc",
    openapi_tags=[
        {
            "name": "devices",
            "description": "Logical device management operations"
        },
        {
            "name": "files",
            "description": "File upload and management operations"
        },
        {
            "name": "system",
            "description": "System status and health check operations"
        }
    ]
)

# Pydantic models
class LDCreateRequest(BaseModel):
    name: str
    device_cim_id: str
    friendly_name: str
    template: str = "GenericIO"

    model_config = {
        "json_schema_extra": {
            "examples": [
                {
                    "name": "DeviceMoscow001",
                    "device_cim_id": "aaaa09c7-1af1-4534-8e77-720476fb0552",
                    "friendly_name": "Device-Moscow-Office",
                    "template": "GenericIO"
                }
            ]
        }
    }

class LDUpdateRequest(BaseModel):
    device_cim_id: Optional[str] = None
    friendly_name: Optional[str] = None

    model_config = {
        "json_schema_extra": {
            "examples": [
                {
                    "friendly_name": "Device-Moscow-Central"
                }
            ]
        }
    }

class LDResponse(BaseModel):
    name: str
    status: str
    message: str

class DeployResponse(BaseModel):
    status: str
    message: str

class ServerStatusResponse(BaseModel):
    container_running: bool
    logical_devices: List[str]
    port: int


def run_command(cmd: List[str], cwd: str = None) -> tuple[bool, str]:
    """Run shell command and return success status and output"""
    try:
        logger.info(f"Running command: {' '.join(cmd)}")
        result = subprocess.run(
            cmd,
            cwd=cwd,
            capture_output=True,
            text=True,
            timeout=120  # 2 minutes timeout (much faster with builder image)
        )
        success = result.returncode == 0
        output = result.stdout + result.stderr
        logger.info(f"Command result: success={success}, output_len={len(output)}")
        return success, output
    except subprocess.TimeoutExpired:
        logger.error("Command timed out")
        return False, "Command timed out"
    except Exception as e:
        logger.error(f"Command error: {str(e)}")
        return False, str(e)


def regenerate_model() -> tuple[bool, str]:
    """Regenerate static_model.c/h from CID file"""
    logger.info("Regenerating model from CID file...")

    cmd = ["java", "-jar", GENMODEL_JAR, CID_FILE]
    success, output = run_command(cmd, cwd=HOST_WORK_DIR)

    if success:
        logger.info("Model regenerated successfully")
        return True, "Model regenerated successfully"
    else:
        logger.error(f"Model regeneration failed: {output}")
        return False, f"Model regeneration failed: {output}"


def rebuild_docker_image() -> tuple[bool, str]:
    """Rebuild server binary with new model using pre-built builder image"""
    logger.info("Rebuilding server binary...")

    try:
        # Use builder image with pre-compiled libiec61850
        # Mount host directory directly to access files
        cmd = [
            "docker", "run", "--rm",
            "-v", f"{HOST_WORK_DIR_ABS}:/work",
            "iec61850-builder:latest",
            "bash", "-c",
            """
            set -e
            echo "Copying new model files..."
            cp /work/static_model.* /build/libiec61850/examples/server_example_files/

            echo "Rebuilding server_example_files..."
            cd /build/libiec61850/build/examples/server_example_files
            rm -f CMakeFiles/server_example_files.dir/static_model.c.o
            make server_example_files

            echo "Copying binary to host..."
            cp server_example_files /work/

            echo "Done!"
            """
        ]

        success, output = run_command(cmd)

        if success:
            logger.info("Server binary rebuilt successfully")
            return True, "Server binary rebuilt successfully"
        else:
            logger.error(f"Binary rebuild failed: {output}")
            return False, f"Binary rebuild failed: {output}"

    except Exception as e:
        logger.error(f"Binary rebuild error: {str(e)}")
        return False, f"Binary rebuild error: {str(e)}"


def stop_container() -> tuple[bool, str]:
    """Stop the IEC 61850 server container"""
    logger.info("Stopping container...")

    try:
        cmd = ["docker", "stop", "iec61850-fileserver"]
        success, output = run_command(cmd)

        if success:
            logger.info("Container stopped successfully")
            return True, "Container stopped successfully"
        else:
            logger.warning(f"Stop warning: {output}")
            # Consider it success even if container was not running
            return True, "Container was not running"
    except Exception as e:
        logger.error(f"Container stop error: {str(e)}")
        return False, f"Container stop error: {str(e)}"


def start_container() -> tuple[bool, str]:
    """Start the IEC 61850 server container"""
    logger.info("Starting container...")

    try:
        cmd = ["docker", "start", "iec61850-fileserver"]
        success, output = run_command(cmd)

        if success:
            logger.info("Container started successfully")
            return True, "Container started successfully"
        else:
            logger.error(f"Container start failed: {output}")
            return False, f"Container start failed: {output}"
    except Exception as e:
        logger.error(f"Container start error: {str(e)}")
        return False, f"Container start error: {str(e)}"


def restart_container() -> tuple[bool, str]:
    """Restart the IEC 61850 server container (stop + start)"""
    stop_success, stop_msg = stop_container()
    if not stop_success:
        return False, stop_msg

    start_success, start_msg = start_container()
    if not start_success:
        return False, start_msg

    return True, "Container restarted successfully"


def get_container_status() -> tuple[bool, int]:
    """Get container status and port"""
    try:
        # Check if container is running
        cmd_ps = ["docker", "ps", "--filter", "name=iec61850-fileserver",
                   "--format", "{{.Status}}"]
        success, output = run_command(cmd_ps)

        is_running = "Up" in output if success else False

        # Get port mapping
        cmd_port = ["docker", "port", "iec61850-fileserver", "102"]
        success, output = run_command(cmd_port)

        port = 102
        if success and output:
            try:
                port_str = output.split("->")[1].split("/")[0].strip()
                port = int(port_str)
            except:
                pass

        return is_running, port

    except Exception as e:
        logger.error(f"Error getting container status: {str(e)}")
        return False, 102


async def add_ld_only_async(ld_name: str, device_cim_id: str,
                              friendly_name: str, template_ld: str = "GenericIO"):
    """
    Background task to add LD to CID file and registry (without rebuild/restart)

    This only:
    1. Modifies CID file
    2. Creates filestore directory with friendly name
    3. Adds entry to device registry

    Use /api/ld/deploy to rebuild and restart server when ready.
    """
    try:
        logger.info(f"Adding new LD: {ld_name} (device_cim_id: {device_cim_id}, "
                   f"friendly_name: {friendly_name}, template: {template_ld})")

        # 1. Modify CID file
        cid_manager = CIDManager(CID_FILE)
        if not cid_manager.add_logical_device(ld_name, template_ld):
            logger.error(f"Failed to add LD {ld_name} to CID file")
            return

        # 2. Create filestore directory with friendly name
        # Sanitize friendly_name for filesystem
        safe_friendly_name = friendly_name.replace(" ", "-").replace("/", "-").replace("\\", "-")
        ld_dir = os.path.join(HOST_WORK_DIR, "vmd-filestore", safe_friendly_name)
        os.makedirs(ld_dir, exist_ok=True)

        # Create initial files
        readme = os.path.join(ld_dir, "README.txt")
        config = os.path.join(ld_dir, "config.ini")

        with open(readme, 'w') as f:
            f.write(f"IEC 61850 Server - File Service\n")
            f.write(f"=" * 50 + "\n")
            f.write(f"Logical Device: {ld_name}\n")
            f.write(f"Friendly Name: {friendly_name}\n")
            f.write(f"Device CIM ID: {device_cim_id}\n")

        with open(config, 'w') as f:
            f.write(f"[Device]\n")
            f.write(f"Name=simpleIO\n")
            f.write(f"LogicalDevice={ld_name}\n")
            f.write(f"Description=IEC 61850 Server - {friendly_name}\n")
            f.write(f"DeviceCimId={device_cim_id}\n")
            f.write(f"Version=1.0.0\n")

        # 3. Add to device registry
        registry = get_registry(DEVICE_REGISTRY)
        registry.add_device(
            device_cim_id=device_cim_id,
            ld_name=ld_name,
            storage_path=ld_dir,
            friendly_name=friendly_name
        )

        logger.info(f"Successfully added LD {ld_name} (use /api/ld/deploy to rebuild)")

    except Exception as e:
        logger.error(f"Error in add_ld_only_async: {str(e)}")


async def deploy_lds_async():
    """
    Background task to rebuild and restart server with updated CID file

    This:
    1. Regenerates model from CID file
    2. Stops container
    3. Rebuilds binary
    4. Starts container
    """
    try:
        logger.info("Deploying: regenerating model and rebuilding server...")

        # 1. Regenerate model
        success, msg = regenerate_model()
        if not success:
            logger.error(f"Model regeneration failed: {msg}")
            return

        # 2. Stop container (MUST be done before rebuild to avoid "text file busy" error)
        success, msg = stop_container()
        if not success:
            logger.error(f"Container stop failed: {msg}")
            return

        # 3. Rebuild binary (can now copy since container is stopped)
        success, msg = rebuild_docker_image()
        if not success:
            logger.error(f"Binary rebuild failed: {msg}")
            # Try to start container even if rebuild failed
            start_container()
            return

        # 4. Start container with new binary
        success, msg = start_container()
        if not success:
            logger.error(f"Container start failed: {msg}")
            return

        logger.info("Successfully deployed server with updated LDs")

    except Exception as e:
        logger.error(f"Error in deploy_lds_async: {str(e)}")


async def delete_ld_async(ld_name: str):
    """
    Background task to delete a logical device completely

    This:
    1. Removes LD from CID file
    2. Removes from device registry
    3. Deletes filestore directory (by both ld_name and storage_path)
    """
    try:
        logger.info(f"Deleting LD: {ld_name}")

        # 1. Remove from CID file
        cid_manager = CIDManager(CID_FILE)
        if not cid_manager.remove_logical_device(ld_name):
            logger.error(f"Failed to remove LD {ld_name} from CID file")
            return

        logger.info(f"Removed {ld_name} from CID file")

        # 2. Remove from device registry (find by ld_name)
        registry = get_registry(DEVICE_REGISTRY)

        # Find device by ld_name and remove from registry
        storage_path = None
        for device_id, config in registry.list_devices().items():
            if config.ld_name == ld_name:
                storage_path = config.storage_path
                registry.remove_device(device_id)
                logger.info(f"Removed {ld_name} from registry (device_id: {device_id})")
                break

        # 3. Delete filestore directory (try both ld_name and storage_path)
        base_dir = os.path.join(HOST_WORK_DIR, "vmd-filestore")
        paths_to_delete = [os.path.join(base_dir, ld_name)]

        if storage_path:
            paths_to_delete.append(storage_path)

        for path in paths_to_delete:
            if os.path.exists(path):
                try:
                    shutil.rmtree(path)
                    logger.info(f"Deleted directory: {path}")
                except Exception as e:
                    logger.warning(f"Failed to delete directory {path}: {str(e)}")

        logger.info(f"Successfully deleted LD {ld_name}")

    except Exception as e:
        logger.error(f"Error in delete_ld_async: {str(e)}")


# API Endpoints

@app.get("/", tags=["system"], summary="API Root")
async def root():
    """
    Root endpoint - API information

    Returns basic API information and status.
    """
    return {
        "service": "IEC 61850 LD Manager API",
        "version": "1.0.0",
        "status": "running",
        "docs": "/docs",
        "redoc": "/redoc"
    }


@app.get("/api/status", response_model=ServerStatusResponse, tags=["system"], summary="Get Server Status")
async def get_status():
    """
    Get server status and list of logical devices

    Returns:
    - Container running status
    - List of all logical devices from CID file
    - Mapped port for IEC 61850 server
    """
    try:
        # Check container status
        container_running, port = get_container_status()

        # Get LD list
        cid_manager = CIDManager(CID_FILE)
        logical_devices = cid_manager.get_logical_devices()

        return ServerStatusResponse(
            container_running=container_running,
            logical_devices=logical_devices,
            port=port
        )

    except Exception as e:
        logger.error(f"Error getting status: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.get("/api/ld", tags=["devices"], summary="List All Logical Devices")
async def list_lds():
    """
    List all logical devices with registry information

    Returns a list of all logical devices with their:
    - ld_name: Logical device name (from CID file)
    - device_cim_id: Device CIM ID (from registry)
    - friendly_name: Human-readable name (from registry)
    - storage_path: File storage path (from registry)

    Use device_cim_id from this response for file upload operations.
    """
    try:
        # Get LDs from CID file
        cid_manager = CIDManager(CID_FILE)
        lds = cid_manager.get_logical_devices()

        # Get registry data
        registry = get_registry(DEVICE_REGISTRY)

        # Build detailed device list
        devices_info = []
        for ld_name in lds:
            # Find device in registry by ld_name
            device_cim_id = None
            friendly_name = None
            storage_path = None

            for dev_id, config in registry.mappings.items():
                if config.ld_name == ld_name:
                    device_cim_id = config.device_cim_id
                    friendly_name = config.friendly_name
                    storage_path = config.storage_path
                    break

            devices_info.append({
                "ld_name": ld_name,
                "device_cim_id": device_cim_id,
                "friendly_name": friendly_name,
                "storage_path": storage_path
            })

        return {
            "logical_devices": devices_info,
            "count": len(devices_info)
        }

    except Exception as e:
        logger.error(f"Error listing LDs: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/ld", response_model=LDResponse, tags=["devices"], summary="Add Logical Device")
async def add_ld(request: LDCreateRequest, background_tasks: BackgroundTasks):
    """
    Add a new logical device (without rebuilding server)

    This endpoint adds a new logical device to the system:
    1. Modifies CID file with new LD configuration
    2. Creates filestore directory with friendly name
    3. Adds entry to device registry (device_cim_id → storage_path)

    **Important:** The server is NOT rebuilt. Use `POST /api/ld/deploy` to apply changes.

    The process runs in background. Check `/api/status` for results.

    - **name**: Logical device name (1-64 characters)
    - **device_cim_id**: Unique device identifier (UUID)
    - **friendly_name**: Human-readable name for directory (1-255 characters)
    - **template**: Template LD to copy from (default: "GenericIO")

    Returns: Confirmation of LD addition with deployment instructions.
    """
    try:
        # Validate inputs
        if not request.name or len(request.name) > 64:
            raise HTTPException(
                status_code=400,
                detail="Invalid LD name (must be 1-64 characters)"
            )

        if not request.device_cim_id:
            raise HTTPException(
                status_code=400,
                detail="device_cim_id is required"
            )

        if not request.friendly_name or len(request.friendly_name) > 255:
            raise HTTPException(
                status_code=400,
                detail="friendly_name is required (max 255 characters)"
            )

        # Check if LD already exists
        cid_manager = CIDManager(CID_FILE)
        existing_lds = cid_manager.get_logical_devices()

        if request.name in existing_lds:
            raise HTTPException(
                status_code=409,
                detail=f"Logical device '{request.name}' already exists"
            )

        # Check if device_cim_id already registered
        registry = get_registry(DEVICE_REGISTRY)
        if request.device_cim_id in registry:
            existing_device = registry.get_device(request.device_cim_id)
            raise HTTPException(
                status_code=409,
                detail=f"device_cim_id '{request.device_cim_id}' already registered "
                       f"with LD '{existing_device.ld_name}'"
            )

        # Start background task
        background_tasks.add_task(
            add_ld_only_async,
            request.name,
            request.device_cim_id,
            request.friendly_name,
            request.template
        )

        return LDResponse(
            name=request.name,
            status="pending",
            message=f"Adding logical device '{request.name}' (use POST /api/ld/deploy to rebuild)"
        )

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error adding LD: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/ld/deploy", response_model=DeployResponse, tags=["devices"], summary="Deploy Server Changes")
async def deploy_lds(background_tasks: BackgroundTasks):
    """
    Rebuild and restart server with updated logical devices

    This endpoint deploys all pending changes:
    1. Regenerates C model from CID file (using genmodel.jar)
    2. Stops IEC 61850 server container
    3. Rebuilds server binary with new model (~2 minutes downtime)
    4. Starts server container

    **Call this after adding/updating LDs when ready to deploy.**

    The process runs in background. Server will be unavailable during rebuild.

    Typical downtime: ~2 minutes

    Returns: Confirmation that deployment has started.
    """
    try:
        # Start background task
        background_tasks.add_task(deploy_lds_async)

        return DeployResponse(
            status="pending",
            message="Deploying: regenerating model and rebuilding server in background"
        )

    except Exception as e:
        logger.error(f"Error deploying LDs: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/files", tags=["files"], summary="Upload Files to Device Directories")
async def upload_files(request: Request):
    """
    Upload files and save them to device-specific directories

    Files are automatically routed to device directories based on `device_cim_id` in metadata.

    ## Request Format (multipart/form-data)

    ### Field: `files_extra_data`
    JSON string with file metadata. Format:
    ```json
    {
      "file-uuid-1, null": {
        "ssnti_client_file_id": "file-uuid-1",
        "device_cim_id": "device-uuid-aaa"
      },
      "file-uuid-2, ftp123": {
        "ssnti_client_file_id": "file-uuid-2",
        "device_cim_id": "device-uuid-bbb"
      }
    }
    ```

    ### File Fields
    Field name = composite key (`"file_id, ftp_id"`)
    - Example: `file-uuid-1, null` = file content
    - Example: `file-uuid-2, ftp123` = file content

    ## Example using curl:
    ```bash
    curl -X POST http://localhost:8000/api/files \\
      -F "files_extra_data={\\"file1, null**: {\\"device_cim_id**: \\"dev-aaa**}}" \\
      -F "file1, null=@document.pdf"
    ```

    ## Example using Python:
    ```python
    metadata = {"file1, null": {"device_cim_id": "dev-aaa"}}
    files = [("file1, null", open("doc.pdf", "rb"))]
    requests.post(url, files=files, data={"files_extra_data": json.dumps(metadata)})
    ```

    ## Returns
    - `uploaded_count`: Number of successfully uploaded files
    - `error_count`: Number of failed uploads
    - `uploaded_files`: List of upload details
    - `errors`: List of error details

    ## Error Cases
    - `404`: device_cim_id not found in registry
    - `400`: Invalid files_extra_data JSON
    """
    try:
        # Parse multipart form data
        form = await request.form()

        # Extract files_extra_data
        files_extra_data_str = form.get("files_extra_data")
        if not files_extra_data_str:
            raise HTTPException(
                status_code=400,
                detail="Missing 'files_extra_data' field"
            )

        # Parse files_extra_data JSON
        try:
            files_metadata = json.loads(files_extra_data_str)
        except json.JSONDecodeError as e:
            raise HTTPException(
                status_code=400,
                detail=f"Invalid files_extra_data JSON: {str(e)}"
            )

        registry = get_registry(DEVICE_REGISTRY)
        uploaded_files = []
        errors = []

        # Process each form field (excluding files_extra_data)
        for field_name, field_value in form.items():
            # Skip the metadata field
            if field_name == "files_extra_data":
                continue

            # Check if this field is a file upload
            if not isinstance(field_value, StarletteUploadFile):
                # Skip non-file fields
                continue

            file = field_value
            composite_key = field_name  # "file_id, ftp_id"

            try:
                # Read file content
                file_content = await file.read()

                # Get metadata for this file using composite key
                file_metadata = files_metadata.get(composite_key)

                if not file_metadata:
                    errors.append({
                        "composite_key": composite_key,
                        "filename": file.filename,
                        "error": f"No metadata found for key '{composite_key}'"
                    })
                    continue

                # Extract device_cim_id from metadata
                device_cim_id = file_metadata.get("device_cim_id")
                if not device_cim_id:
                    errors.append({
                        "composite_key": composite_key,
                        "filename": file.filename,
                        "error": "device_cim_id not found in metadata"
                    })
                    continue

                # Get storage path from registry
                try:
                    storage_path = registry.get_storage_path(device_cim_id)
                except DeviceNotFound as e:
                    errors.append({
                        "composite_key": composite_key,
                        "filename": file.filename,
                        "device_cim_id": device_cim_id,
                        "error": str(e)
                    })
                    continue

                # Save file with original filename from client
                file_path = os.path.join(storage_path, file.filename)
                os.makedirs(storage_path, exist_ok=True)

                with open(file_path, 'wb') as f:
                    f.write(file_content)

                uploaded_files.append({
                    "composite_key": composite_key,
                    "filename": file.filename,
                    "device_cim_id": device_cim_id,
                    "storage_path": storage_path,
                    "size": len(file_content),
                    "status": "uploaded"
                })

                logger.info(f"Uploaded file '{file.filename}' (key: {composite_key}) "
                           f"to {storage_path}")

            except Exception as e:
                errors.append({
                    "composite_key": composite_key,
                    "filename": file.filename,
                    "error": str(e)
                })
                logger.error(f"Error uploading file '{file.filename}': {str(e)}")

        return {
            "uploaded_count": len(uploaded_files),
            "error_count": len(errors),
            "uploaded_files": uploaded_files,
            "errors": errors
        }

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error in upload_files: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/files/single", tags=["files"], summary="Upload Single File (Swagger UI Friendly)")
async def upload_single_file(
    file: UploadFile = File(..., description="File to upload"),
    device_cim_id: str = Form(..., description="Device CIM ID from registry")
):
    """
    Upload a single file to a device directory (simplified for Swagger UI)

    This endpoint is designed for easy manual file upload through Swagger UI.
    Simply select a file and provide the device_cim_id.

    ## Parameters

    - **file**: File to upload (use Swagger UI file picker)
    -device_cim_id**: Target device ID from registry

    ## How to use in Swagger UI:
    1. Click "Try it out"
    2. Select a file using the "Choose File" button
    3. Enter device_cim_id (e.g., from /api/registry response)
    4. Click "Execute"

    ## Available Device CIM IDs:
    Use GET /api/registry to see all available devices.

    ## Example device_cim_id values:
    - GenericIO: `34dd1ed1-163c-4233-bc5c-dbffd161ccd9`
    - GenericIO2: `f63ed770-6f1a-41dc-a81d-e51b29fed614`
    - DeviceTest001: `c402e4ec-d636-4661-9ece-305c59946fb9`
    - GenericIO21: `e7e19427-96ca-4315-9b82-11c666cb5f75`

    ## Returns
    - `filename`: Original filename
    - `device_cim_id`: Device ID
    - `storage_path`: Full path where file was saved
    - `size`: File size in bytes

    ## Error Cases
    - `404`: device_cim_id not found in registry
    """
    try:
        # Get registry
        registry = get_registry(DEVICE_REGISTRY)

        # Get storage path for device
        try:
            storage_path = registry.get_storage_path(device_cim_id)
        except DeviceNotFound as e:
            raise HTTPException(
                status_code=404,
                detail=str(e)
            )

        # Read file content
        file_content = await file.read()

        # Save with original filename
        file_path = os.path.join(storage_path, file.filename)
        os.makedirs(storage_path, exist_ok=True)

        with open(file_path, 'wb') as f:
            f.write(file_content)

        logger.info(f"Uploaded single file '{file.filename}' to {storage_path}")

        return {
            "filename": file.filename,
            "device_cim_id": device_cim_id,
            "storage_path": storage_path,
            "size": len(file_content),
            "status": "uploaded"
        }

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error in upload_single_file: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.delete("/api/ld/{ld_name}", tags=["devices"], summary="Delete Logical Device")
async def delete_ld(ld_name: str, background_tasks: BackgroundTasks = None):
    """
    Delete a logical device completely

    Deletes the logical device from:
    1. CID file configuration
    2. Device registry (if registered)
    3. Filestore directory (including all files)

    **Protected devices** (cannot be deleted):
    - GenericIO
    - GenericIO2

    **Warning:** This operation cannot be undone!

    Returns: Confirmation of deletion with details of what was removed.
    """
    try:
        # Protect original LDs
        if ld_name in ["GenericIO", "GenericIO2"]:
            raise HTTPException(
                status_code=403,
                detail=f"Cannot delete protected logical device '{ld_name}'"
            )

        # Check if LD exists in CID
        cid_manager = CIDManager(CID_FILE)
        lds = cid_manager.get_logical_devices()

        if ld_name not in lds:
            raise HTTPException(
                status_code=404,
                detail=f"Logical device '{ld_name}' not found"
            )

        # Start background deletion task
        if background_tasks:
            background_tasks.add_task(delete_ld_async, ld_name)
            return {
                "name": ld_name,
                "status": "pending",
                "message": f"Deleting logical device '{ld_name}' in background"
            }
        else:
            # Synchronous deletion (for testing)
            await delete_ld_async(ld_name)
            return {
                "name": ld_name,
                "status": "deleted",
                "message": f"Logical device '{ld_name}' has been deleted"
            }

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error deleting LD: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/ld/cleanup", tags=["devices"], summary="Remove Orphaned Logical Devices")
async def cleanup_lds(background_tasks: BackgroundTasks = None):
    """
    Remove all logical devices that are not in the device registry

    This endpoint finds and deletes LDs that exist in the CID file but are NOT
    registered in the device registry. This is useful for cleaning up stale devices.

    **Process:**
    1. Gets all LDs from CID file
    2. Gets all registered LDs from device registry
    3. Identifies orphaned LDs (in CID but not in registry)
    4. Deletes each orphaned LD:
       - From CID file
       - From filestore directory

    **Protected devices** are never deleted:
    - GenericIO
    - GenericIO2

    Returns: List of deleted LDs and any errors encountered.
    """
    try:
        # Get all LDs from CID
        cid_manager = CIDManager(CID_FILE)
        cid_lds = set(cid_manager.get_logical_devices())

        # Get all registered LDs from registry
        registry = get_registry(DEVICE_REGISTRY)
        registry_lds = {config.ld_name for config in registry.list_devices().values()}

        # Find orphaned LDs (in CID but not in registry, excluding protected)
        protected_lds = {"GenericIO", "GenericIO2"}
        orphaned_lds = [
            ld for ld in cid_lds
            if ld not in registry_lds and ld not in protected_lds
        ]

        if not orphaned_lds:
            return {
                "deleted_count": 0,
                "deleted_lds": [],
                "message": "No orphaned logical devices found"
            }

        # Start background cleanup task
        if background_tasks:
            background_tasks.add_task(cleanup_lds_async, orphaned_lds)
            return {
                "deleted_count": len(orphaned_lds),
                "deleted_lds": orphaned_lds,
                "status": "pending",
                "message": f"Cleaning up {len(orphaned_lds)} orphaned devices in background"
            }
        else:
            # Synchronous cleanup (for testing)
            result = await cleanup_lds_async(orphaned_lds)
            return {
                "deleted_count": len(result.get("deleted", [])),
                "deleted_lds": result.get("deleted", []),
                "errors": result.get("errors", []),
                "message": f"Cleaned up {len(result.get('deleted', []))} devices"
            }

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error cleaning up LDs: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


async def cleanup_lds_async(ld_names: List[str]):
    """
    Background task to cleanup multiple logical devices

    Args:
        ld_names: List of LD names to delete
    """
    deleted = []
    errors = []

    for ld_name in ld_names:
        try:
            await delete_ld_async(ld_name)
            deleted.append(ld_name)
            logger.info(f"Cleaned up orphaned LD: {ld_name}")
        except Exception as e:
            errors.append({
                "ld_name": ld_name,
                "error": str(e)
            })
            logger.error(f"Error cleaning up {ld_name}: {str(e)}")

    return {
        "deleted": deleted,
        "errors": errors
    }


@app.put("/api/ld/{ld_name}", tags=["devices"], summary="Update Logical Device Metadata")
async def update_ld(ld_name: str, request: LDUpdateRequest):
    """
    Update logical device metadata

    Updates device registry and can rename storage directory if `friendly_name` changes.

    **Supported updates:**
    - `device_cim_id`: Change device identifier
    - `friendly_name`: Change human-readable name (renames directory)

    **Behavior:**
    - Updates device registry entry
    - Renames storage directory if friendly_name changes
    - Moves all files to new directory
    - Does NOT modify CID file (LD name in CID cannot be changed)
    - Does NOT rebuild server

    Use `POST /api/ld/deploy` after updates if needed.

    ## Example Request:
    ```json
    {
      "friendly_name": "Device-Moscow-Central"
    }
    ```

    ## Returns
    - Updated device name
    - List of changes applied
    - Deployment instructions
    """
    try:
        # Validate LD exists
        cid_manager = CIDManager(CID_FILE)
        lds = cid_manager.get_logical_devices()

        if ld_name not in lds:
            raise HTTPException(
                status_code=404,
                detail=f"Logical device '{ld_name}' not found in CID file"
            )

        registry = get_registry(DEVICE_REGISTRY)

        # Find existing device config
        # We need to find by ld_name since device_cim_id might change
        existing_config = None
        for config in registry.list_devices().values():
            if config.ld_name == ld_name:
                existing_config = config
                break

        if not existing_config:
            raise HTTPException(
                status_code=404,
                detail=f"Logical device '{ld_name}' not found in registry"
            )

        # Track changes
        changes = []

        # Update device_cim_id if provided
        if request.device_cim_id is not None:
            if request.device_cim_id != existing_config.device_cim_id:
                # Check if new device_cim_id already registered
                if request.device_cim_id in registry:
                    other_config = registry.get_device(request.device_cim_id)
                    if other_config.ld_name != ld_name:
                        raise HTTPException(
                            status_code=409,
                            detail=f"device_cim_id '{request.device_cim_id}' already "
                                   f"registered with LD '{other_config.ld_name}'"
                        )

                # Remove old mapping and add new one
                old_device_cim_id = existing_config.device_cim_id
                registry.remove_device(old_device_cim_id)
                registry.add_device(
                    device_cim_id=request.device_cim_id,
                    ld_name=ld_name,
                    storage_path=existing_config.storage_path,
                    friendly_name=existing_config.friendly_name
                )
                changes.append(f"device_cim_id: {old_device_cim_id} -> {request.device_cim_id}")

        # Update friendly_name if provided
        if request.friendly_name is not None:
            if request.friendly_name != existing_config.friendly_name:
                old_friendly_name = existing_config.friendly_name
                old_storage_path = existing_config.storage_path

                # Create new directory name
                new_safe_name = request.friendly_name.replace(" ", "-").replace("/", "-").replace("\\", "-")
                new_storage_path = os.path.join(HOST_WORK_DIR, "vmd-filestore", new_safe_name)

                # Rename directory if path changed
                if old_storage_path != new_storage_path:
                    try:
                        # Create new directory
                        os.makedirs(new_storage_path, exist_ok=True)

                        # Move files from old to new directory
                        if os.path.exists(old_storage_path):
                            for item in os.listdir(old_storage_path):
                                old_item = os.path.join(old_storage_path, item)
                                new_item = os.path.join(new_storage_path, item)
                                if os.path.isfile(old_item):
                                    shutil.move(old_item, new_item)
                                elif os.path.isdir(old_item):
                                    shutil.move(old_item, new_item)

                            # Remove old directory if empty
                            try:
                                os.rmdir(old_storage_path)
                            except:
                                logger.warning(f"Could not remove old directory {old_storage_path}")

                    except Exception as e:
                        logger.error(f"Error renaming directory: {str(e)}")
                        raise HTTPException(
                            status_code=500,
                            detail=f"Failed to rename storage directory: {str(e)}"
                        )

                # Update registry
                device_cim_id_to_update = request.device_cim_id or existing_config.device_cim_id
                registry.update_device(
                    device_cim_id_to_update,
                    storage_path=new_storage_path,
                    friendly_name=request.friendly_name
                )
                changes.append(f"friendly_name: {old_friendly_name} -> {request.friendly_name}")
                changes.append(f"storage_path: {old_storage_path} -> {new_storage_path}")

        return {
            "name": ld_name,
            "status": "updated",
            "changes": changes,
            "message": f"Updated logical device '{ld_name}'. Use POST /api/ld/deploy to apply changes."
        }

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error updating LD: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


@app.get("/api/ld/{ld_name}", tags=["devices"], summary="Get Logical Device Details")
async def get_ld(ld_name: str):
    """
    Get details of a specific logical device

    Returns information about a logical device including:
    - LD name
    - Existence in CID file
    - Filestore directory existence

    Returns 404 if LD not found in CID file.
    """
    try:
        cid_manager = CIDManager(CID_FILE)
        lds = cid_manager.get_logical_devices()

        if ld_name not in lds:
            raise HTTPException(
                status_code=404,
                detail=f"Logical device '{ld_name}' not found"
            )

        return {
            "name": ld_name,
            "exists": True,
            "filestore_exists": os.path.exists(
                os.path.join(HOST_WORK_DIR, "vmd-filestore", ld_name)
            )
        }

    except HTTPException:
        raise
    except Exception as e:
        logger.error(f"Error getting LD: {str(e)}")
        raise HTTPException(status_code=500, detail=str(e))


if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
