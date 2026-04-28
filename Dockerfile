# IEC 61850 Server with File Services - Multi-stage build
FROM debian:bookworm-slim AS builder

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

# Copy custom model files before building
COPY static_model.* /build/libiec61850/examples/server_example_files/

# Build the library
WORKDIR /build/libiec61850
RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

# Build server_example_files with custom model
WORKDIR /build/libiec61850/build/examples/server_example_files
RUN rm -f CMakeFiles/server_example_files.dir/static_model.c.o && \
    make server_example_files


# Runtime stage
FROM debian:bookworm-slim

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

# Create runtime directory
WORKDIR /app

# Copy the built server binary from builder
COPY --from=builder /build/libiec61850/build/examples/server_example_files/server_example_files /app/

# Create filestore directory with both LD folders
RUN mkdir -p /app/vmd-filestore/GenericIO && \
    mkdir -p /app/vmd-filestore/GenericIO2 && \
    echo "IEC 61850 Server File Service - LD1" > /app/vmd-filestore/GenericIO/README.txt && \
    echo "Test configuration file" > /app/vmd-filestore/GenericIO/config.ini && \
    echo "IEC 61850 Server File Service - LD2" > /app/vmd-filestore/GenericIO2/README.txt && \
    echo "Test configuration file" > /app/vmd-filestore/GenericIO2/config.ini

# Expose IEC 61850 MMS port
EXPOSE 102/tcp

# Set the entrypoint
ENTRYPOINT ["/app/server_example_files"]

# Run on port 102 by default
CMD ["102"]
