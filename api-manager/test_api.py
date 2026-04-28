"""
Test script for API endpoints
"""
import requests
import json
import time
import sys

API_BASE = "http://localhost:8000"

def print_section(title):
    print("\n" + "=" * 60)
    print(title)
    print("=" * 60)

def print_response(response):
    print(f"Status: {response.status_code}")
    try:
        print(f"Response:\n{json.dumps(response.json(), indent=2)}")
    except:
        print(f"Response: {response.text}")

def test_api():
    print_section("Testing API - Add Logical Devices")

    # Test 1: Check if API is running
    print("\n[Test 0] Check API status...")
    try:
        response = requests.get(f"{API_BASE}/")
        if response.status_code == 200:
            print("[OK] API is running")
        else:
            print("[FAIL] API returned error")
            return False
    except requests.exceptions.ConnectionError:
        print("[FAIL] Cannot connect to API. Is it running?")
        print("Start with: cd api-manager && python app.py")
        return False

    # Test 2: Add first device
    print_section("[Test 1] Add DeviceMoscow001")
    try:
        response = requests.post(
            f"{API_BASE}/api/ld",
            json={
                "name": "DeviceMoscow001",
                "device_cim_id": "aaaa09c7-1af1-4534-8e77-720476fb0552",
                "friendly_name": "Device-Moscow-Office",
                "template": "GenericIO"
            }
        )
        print_response(response)
        if response.status_code not in [200, 202]:
            print("[WARNING] Unexpected status code")
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Wait a bit for background task
    time.sleep(1)

    # Test 3: Add second device
    print_section("[Test 2] Add DeviceSPB001")
    try:
        response = requests.post(
            f"{API_BASE}/api/ld",
            json={
                "name": "DeviceSPB001",
                "device_cim_id": "bbb909c7-1af1-4534-8e77-720476fb0552",
                "friendly_name": "Device-SPB-Office",
                "template": "GenericIO"
            }
        )
        print_response(response)
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Wait for background tasks
    time.sleep(2)

    # Test 4: List all LDs
    print_section("[Test 3] List all logical devices")
    try:
        response = requests.get(f"{API_BASE}/api/ld")
        print_response(response)
    except Exception as e:
        print(f"[FAIL] Error: {e}")

    # Test 5: Check device registry
    print_section("[Test 4] Check device registry file")
    try:
        import os
        if os.path.exists("device_registry.json"):
            with open("device_registry.json", "r") as f:
                data = json.load(f)
                print(json.dumps(data, indent=2))
                print(f"\n[OK] Total devices in registry: {len(data['mappings'])}")
        else:
            print("[WARNING] device_registry.json not found")
    except Exception as e:
        print(f"[FAIL] Error: {e}")

    # Test 6: Check server status
    print_section("[Test 5] Check server status")
    try:
        response = requests.get(f"{API_BASE}/api/status")
        print_response(response)
    except Exception as e:
        print(f"[FAIL] Error: {e}")

    print_section("Tests completed!")
    print("\nNOTE: Devices were added but NOT deployed.")
    print("Use POST /api/ld/deploy to rebuild and restart server.")

    return True

if __name__ == "__main__":
    try:
        success = test_api()
        sys.exit(0 if success else 1)
    except KeyboardInterrupt:
        print("\n\nInterrupted")
        sys.exit(1)
