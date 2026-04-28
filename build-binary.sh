#!/bin/bash
# Script to build IEC 61850 server binary with custom model

set -e

echo "Building IEC 61850 server binary..."

# Run builder container
docker run --rm \
    -v "$(pwd):/work" \
    -w /work \
    iec61850-builder:latest \
    bash -c "
        cp /work/static_model.* /build/libiec61850/examples/server_example_files/ && \
        cd /build/libiec61850/build/examples/server_example_files && \
        rm -f CMakeFiles/server_example_files.dir/static_model.c.o && \
        make server_example_files && \
        cp /build/libiec61850/build/examples/server_example_files/server_example_files /work/
    "

echo "Binary built successfully: ./server_example_files"
