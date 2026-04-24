#!/bin/bash

# ============================================
# Deploy script for local server
# ============================================

# Configuration
SERVER_HOST="${SERVER_HOST:-192.168.1.10}"
SERVER_USER="${SERVER_USER:-root}"
SERVER_PORT="${SERVER_PORT:-22}"
DOCKER_IMAGE="iec61850-server"

echo "=== Deploying to $SERVER_USER@$SERVER_HOST:$SERVER_PORT ==="

# Build and publish
echo "📦 Building application..."
dotnet publish FullApi/FullApi.csproj -c Release -o publish-full

# Build Docker image
echo "🐳 Building Docker image..."
docker build --no-cache -f Dockerfile.final -t $DOCKER_IMAGE:latest .

# Save Docker image
echo "💾 Saving Docker image..."
docker save $DOCKER_IMAGE:latest | gzip > iec61850-server.tar.gz

# Copy to server
echo "📤 Copying to server..."
scp -P $SERVER_PORT iec61850-server.tar.gz $SERVER_USER@$SERVER_HOST:/tmp/

# Deploy on server
echo "🚀 Deploying on server..."
ssh -p $SERVER_PORT $SERVER_USER@$SERVER_HOST << 'ENDSSH'
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
ENDSSH

# Cleanup local file
rm iec61850-server.tar.gz

# Health check
echo "⏳ Waiting for service to start..."
sleep 10

echo "🔍 Checking service health..."
curl -f http://$SERVER_HOST:8080/health && echo "✅ Service is healthy!" || echo "❌ Health check failed"

echo ""
echo "=== Deployment complete! ==="
echo "Web API: http://$SERVER_HOST:8080"
echo "Swagger: http://$SERVER_HOST:8080/swagger"
echo "IEC-61850: $SERVER_HOST:8102"
