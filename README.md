# IEC 61850 Server - Docker Implementation

IEC 61850 server with MMS file services running in Docker container, based on libiec61850 v1.6 server_example_files.

## Features

- IEC 61850 MMS server with file transfer capabilities
- Persistent file storage via volume mount
- Default MMS port: 102/TCP
- Based on libiec61850 v1.6 (stable release)

## Quick Start

### Option 1: Using Docker Compose (Recommended)

```bash
# Build and start the server
docker-compose up -d

# View logs
docker-compose logs -f

# Stop the server
docker-compose down
```

### Option 2: Using Docker CLI

```bash
# Build the image
docker build -t iec61850-server .

# Run the container
docker run -d -p 102:102/tcp --name iec61850-fileserver iec61850-server

# View logs
docker logs -f iec61850-fileserver

# Stop the container
docker stop iec61850-fileserver
docker rm iec61850-fileserver
```

## File Storage

Files are stored in the `vmd-filestore` directory with the following structure:

```
vmd-filestore/
├── LD1/
│   ├── Control/        # Control files
│   ├── Measurements/   # Measurement data
│   ├── Protection/     # Protection event files
│   ├── Settings/       # Configuration files
│   └── README.txt      # Example file
```

The `vmd-filestore` directory is mounted as a volume, so files persist across container restarts.

## Testing the Server

### Using telnet (basic connectivity test)

```bash
telnet localhost 102
```

### Using IEC 61850 Client

You can use any IEC 61850 compliant client to connect to the server:

- **OpenSCD** (open-source)
- **IEC 61850 Substation Tester**
- **libiec61850 client examples**

### Connection Parameters

- **Host:** localhost (or container IP)
- **Port:** 102
- **Protocol:** MMS over TCP

## Custom Port

To run on a different port:

```bash
docker run -d -p 8102:102/tcp --name iec61850-custom iec61850-server 8102
```

Or modify `docker-compose.yml`:

```yaml
services:
  iec61850-server:
    # ... other settings ...
    command: ["8102"]
    ports:
      - "8102:102/tcp"
```

## Troubleshooting

### Port 102 already in use

Port 102 is a privileged port and may require admin rights or may be in use by another application.

**Solution:** Use a non-privileged port (e.g., 8102):

```bash
docker-compose down
# Edit docker-compose.yml to change port mapping
docker-compose up -d
```

### Build fails

**Solution:** Ensure Docker Desktop is running and you have sufficient disk space (~2GB for build).

### Cannot connect to server

**Solution:** Check if the container is running:

```bash
docker ps
docker logs iec61850-fileserver
```

## Architecture

The container runs the `server_example_files` from libiec61850 with:

- **IEC Name:** simpleIO
- **Logical Device:** GenericIO
- **Logical Nodes:**
  - LLN0 (Logical Node Zero)
  - LPHD1 (Physical Device Health)
  - GGIO1 (Generic I/O with 4 inputs and 4 outputs)

## Resources

- [libiec61850 GitHub](https://github.com/mz-automation/libiec61850)
- [IEC 61850 Standard](https://webstore.iec.ch/publication/6038)
- [libiec61850 Documentation](https://libiec61850.com/libiec61850/)

## License

This container uses libiec61850 which is released under the MPL 2.0 license.
