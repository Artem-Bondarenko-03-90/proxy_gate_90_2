#!/bin/bash
# Test script for adding LD via API

echo "=================================================="
echo "Testing POST /api/ld - Add Logical Device"
echo "=================================================="

API_URL="http://localhost:8000/api/ld"

echo ""
echo "[Test 1] Add new device (DeviceMoscow001)"
echo "--------------------------------------------------"

curl -X POST "$API_URL" \
  -H "Content-Type: application/json" \
  -d '{
    "name": "DeviceMoscow001",
    "device_cim_id": "aaaa09c7-1af1-4534-8e77-720476fb0552",
    "friendly_name": "Device-Moscow-Office",
    "template": "GenericIO"
  }' \
  | python -m json.tool

echo ""
echo ""
echo "[Test 2] Add second device (DeviceSPB001)"
echo "--------------------------------------------------"

curl -X POST "$API_URL" \
  -H "Content-Type: application/json" \
  -d '{
    "name": "DeviceSPB001",
    "device_cim_id": "bbb909c7-1af1-4534-8e77-720476fb0552",
    "friendly_name": "Device-SPB-Office",
    "template": "GenericIO"
  }' \
  | python -m json.tool

echo ""
echo ""
echo "[Test 3] List all devices"
echo "--------------------------------------------------"

curl -X GET "http://localhost:8000/api/ld" | python -m json.tool

echo ""
echo ""
echo "[Test 4] Get device registry"
echo "--------------------------------------------------"

if [ -f "device_registry.json" ]; then
    cat device_registry.json | python -m json.tool
else
    echo "Registry file not found (will be created after first API call)"
fi

echo ""
echo ""
echo "=================================================="
echo "Tests completed!"
echo "=================================================="
