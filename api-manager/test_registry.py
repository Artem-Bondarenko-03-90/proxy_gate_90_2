"""
Test script for DeviceRegistry
"""
import os
import json
from device_registry import DeviceRegistry, DeviceNotFound

def test_device_registry():
    print("=" * 60)
    print("Testing DeviceRegistry")
    print("=" * 60)

    # Use test registry file
    test_registry_path = "test_device_registry.json"

    # Clean up if exists
    if os.path.exists(test_registry_path):
        os.remove(test_registry_path)
        print("[OK] Removed old test registry")

    # Create new registry
    registry = DeviceRegistry(test_registry_path)
    print("[OK] Created new registry")

    # Test 1: Add device
    print("\n[Test 1] Adding device...")
    try:
        config = registry.add_device(
            device_cim_id="aaaa09c7-1af1-4534-8e77-720476fb0552",
            ld_name="DeviceMoscow001",
            storage_path="/work/vmd-filestore/Device-Moscow-Office",
            friendly_name="Device-Moscow-Office"
        )
        print(f"[OK] Added device: {config.device_cim_id}")
        print(f"  - LD Name: {config.ld_name}")
        print(f"  - Storage: {config.storage_path}")
        print(f"  - Friendly: {config.friendly_name}")
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Test 2: Get storage path
    print("\n[Test 2] Getting storage path...")
    try:
        path = registry.get_storage_path("aaaa09c7-1af1-4534-8e77-720476fb0552")
        print(f"[OK] Got path: {path}")
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Test 3: Get non-existent device (should fail)
    print("\n[Test 3] Getting non-existent device (should fail)...")
    try:
        path = registry.get_storage_path("non-existent-id")
        print(f"[FAIL] Should have raised DeviceNotFound!")
        return False
    except DeviceNotFound as e:
        print(f"[OK] Correctly raised error: {e}")

    # Test 4: Add second device
    print("\n[Test 4] Adding second device...")
    try:
        config = registry.add_device(
            device_cim_id="bbb909c7-1af1-4534-8e77-720476fb0552",
            ld_name="DeviceSPB001",
            storage_path="/work/vmd-filestore/Device-SPB-Office",
            friendly_name="Device-SPB-Office"
        )
        print(f"[OK] Added device: {config.device_cim_id}")
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Test 5: List all devices
    print("\n[Test 5] Listing all devices...")
    try:
        devices = registry.list_devices()
        print(f"[OK] Total devices: {len(devices)}")
        for device_id, config in devices.items():
            print(f"  - {device_id}: {config.friendly_name}")
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Test 6: Update device
    print("\n[Test 6] Updating device...")
    try:
        config = registry.update_device(
            "aaaa09c7-1af1-4534-8e77-720476fb0552",
            friendly_name="Device-Moscow-Central"
        )
        print(f"[OK] Updated device friendly name to: {config.friendly_name}")
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Test 7: Save and reload
    print("\n[Test 7] Testing persistence...")
    try:
        # Save
        registry.save()
        print(f"[OK] Saved registry to file")

        # Reload
        registry2 = DeviceRegistry(test_registry_path)
        devices = registry2.list_devices()
        print(f"[OK] Reloaded registry, {len(devices)} devices found")

        # Verify data
        config = registry2.get_device("aaaa09c7-1af1-4534-8e77-720476fb0552")
        if config.friendly_name == "Device-Moscow-Central":
            print(f"[OK] Data persisted correctly")
        else:
            print(f"[FAIL] Data mismatch!")
            return False
    except Exception as e:
        print(f"[FAIL] Error: {e}")
        return False

    # Test 8: Show registry file content
    print("\n[Test 8] Registry file content:")
    try:
        with open(test_registry_path, 'r') as f:
            data = json.load(f)
            print(json.dumps(data, indent=2))
    except Exception as e:
        print(f"[FAIL] Error: {e}")

    # Clean up
    print("\n[Test 9] Cleanup...")
    os.remove(test_registry_path)
    print(f"[OK] Removed test registry")

    print("\n" + "=" * 60)
    print("[OK] All tests passed!")
    print("=" * 60)
    return True

if __name__ == "__main__":
    success = test_device_registry()
    exit(0 if success else 1)
