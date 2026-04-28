# IEC 61850 Server - Builder for compiling binary
FROM debian:bookworm-slim

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    default-jre-headless \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /build

# Download and build libiec61850 v1.6
RUN git clone --depth 1 --branch v1.6 https://github.com/mz-automation/libiec61850.git

# Build the library
WORKDIR /build/libiec61850
RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

# Keep build artifacts for reuse
VOLUME ["/build/libiec61850/build"]

# Default command - build server with mounted model
CMD ["bash", "-c", "cd /build/libiec61850/build/examples/server_example_files && rm -f CMakeFiles/server_example_files.dir/static_model.c.o && make server_example_files"]
