"""
Device Registry - Manages device_cim_id to storage_path mappings
"""
import os
import json
import logging
from typing import Optional, Dict
from datetime import datetime
from pathlib import Path

logger = logging.getLogger(__name__)


class DeviceNotFound(Exception):
    """Raised when device_cim_id is not found in registry"""
    pass


class DeviceConfig:
    """Device configuration in registry"""
    def __init__(self, device_cim_id: str, ld_name: str, storage_path: str,
                 friendly_name: str, created_at: str = None):
        self.device_cim_id = device_cim_id
        self.ld_name = ld_name
        self.storage_path = storage_path
        self.friendly_name = friendly_name
        self.created_at = created_at or datetime.now().isoformat()

    def to_dict(self) -> dict:
        """Convert to dictionary"""
        return {
            "device_cim_id": self.device_cim_id,
            "ld_name": self.ld_name,
            "storage_path": self.storage_path,
            "friendly_name": self.friendly_name,
            "created_at": self.created_at
        }

    @classmethod
    def from_dict(cls, data: dict) -> 'DeviceConfig':
        """Create from dictionary"""
        return cls(
            device_cim_id=data["device_cim_id"],
            ld_name=data["ld_name"],
            storage_path=data["storage_path"],
            friendly_name=data["friendly_name"],
            created_at=data.get("created_at")
        )


class DeviceRegistry:
    """
    Registry for device_cim_id -> storage_path mappings

    Storage format (device_registry.json):
    {
      "mappings": {
        "device-uuid-1": {
          "device_cim_id": "device-uuid-1",
          "ld_name": "DeviceMoscow001",
          "storage_path": "/work/vmd-filestore/Device-Moscow-Office",
          "friendly_name": "Device-Moscow-Office",
          "created_at": "2025-01-15T10:30:00Z"
        }
      },
      "version": 1
    }
    """

    def __init__(self, registry_path: str = "device_registry.json"):
        self.registry_path = registry_path
        self.mappings: Dict[str, DeviceConfig] = {}
        self._version = 1
        self.load()

    def load(self):
        """Load registry from file"""
        try:
            if not os.path.exists(self.registry_path):
                logger.info(f"Registry file {self.registry_path} not found, creating new one")
                self.save()
                return

            with open(self.registry_path, 'r', encoding='utf-8') as f:
                data = json.load(f)

            self._version = data.get("version", 1)
            mappings_data = data.get("mappings", {})

            self.mappings = {
                device_cim_id: DeviceConfig.from_dict(config)
                for device_cim_id, config in mappings_data.items()
            }

            logger.info(f"Loaded {len(self.mappings)} device mappings from registry")

        except Exception as e:
            logger.error(f"Error loading registry: {str(e)}")
            self.mappings = {}

    def save(self):
        """Save registry to file"""
        try:
            data = {
                "mappings": {
                    device_cim_id: config.to_dict()
                    for device_cim_id, config in self.mappings.items()
                },
                "version": self._version
            }

            with open(self.registry_path, 'w', encoding='utf-8') as f:
                json.dump(data, f, indent=2, ensure_ascii=False)

            logger.info(f"Saved {len(self.mappings)} device mappings to registry")

        except Exception as e:
            logger.error(f"Error saving registry: {str(e)}")
            raise

    def add_device(self, device_cim_id: str, ld_name: str,
                   storage_path: str, friendly_name: str) -> DeviceConfig:
        """
        Add or update device in registry

        Args:
            device_cim_id: Device UUID
            ld_name: Logical device name
            storage_path: Absolute path to storage directory
            friendly_name: Human-readable name

        Returns:
            DeviceConfig instance
        """
        config = DeviceConfig(
            device_cim_id=device_cim_id,
            ld_name=ld_name,
            storage_path=storage_path,
            friendly_name=friendly_name
        )

        self.mappings[device_cim_id] = config
        self.save()

        logger.info(f"Added device {device_cim_id} -> {storage_path}")
        return config

    def get_storage_path(self, device_cim_id: str) -> str:
        """
        Get storage path for device

        Args:
            device_cim_id: Device UUID

        Returns:
            Storage path string

        Raises:
            DeviceNotFound: If device_cim_id not in registry
        """
        if device_cim_id not in self.mappings:
            raise DeviceNotFound(
                f"Device '{device_cim_id}' not found in registry. "
                f"Available devices: {list(self.mappings.keys())}"
            )

        return self.mappings[device_cim_id].storage_path

    def get_device(self, device_cim_id: str) -> Optional[DeviceConfig]:
        """
        Get device config by device_cim_id

        Args:
            device_cim_id: Device UUID

        Returns:
            DeviceConfig or None if not found
        """
        return self.mappings.get(device_cim_id)

    def get_by_ld_name(self, ld_name: str) -> Optional[DeviceConfig]:
        """
        Find device config by LD name

        Args:
            ld_name: Logical device name

        Returns:
            DeviceConfig or None if not found
        """
        for config in self.mappings.values():
            if config.ld_name == ld_name:
                return config
        return None

    def update_device(self, device_cim_id: str, **kwargs) -> Optional[DeviceConfig]:
        """
        Update device configuration

        Args:
            device_cim_id: Device UUID
            **kwargs: Fields to update (storage_path, friendly_name, etc.)

        Returns:
            Updated DeviceConfig or None if not found

        Raises:
            DeviceNotFound: If device_cim_id not in registry
        """
        if device_cim_id not in self.mappings:
            raise DeviceNotFound(f"Device '{device_cim_id}' not found in registry")

        config = self.mappings[device_cim_id]

        if "storage_path" in kwargs:
            config.storage_path = kwargs["storage_path"]
        if "friendly_name" in kwargs:
            config.friendly_name = kwargs["friendly_name"]
        if "ld_name" in kwargs:
            config.ld_name = kwargs["ld_name"]

        self.save()
        logger.info(f"Updated device {device_cim_id}")
        return config

    def remove_device(self, device_cim_id: str) -> bool:
        """
        Remove device from registry

        Args:
            device_cim_id: Device UUID

        Returns:
            True if removed, False if not found
        """
        if device_cim_id in self.mappings:
            del self.mappings[device_cim_id]
            self.save()
            logger.info(f"Removed device {device_cim_id}")
            return True
        return False

    def list_devices(self) -> Dict[str, DeviceConfig]:
        """Get all devices"""
        return self.mappings.copy()

    def __contains__(self, device_cim_id: str) -> bool:
        """Check if device exists in registry"""
        return device_cim_id in self.mappings

    def __len__(self) -> int:
        """Get count of devices"""
        return len(self.mappings)


# Global registry instance
_registry_instance: Optional[DeviceRegistry] = None


def get_registry(registry_path: str = "device_registry.json") -> DeviceRegistry:
    """
    Get or create global DeviceRegistry instance

    Args:
        registry_path: Path to registry file

    Returns:
        DeviceRegistry instance
    """
    global _registry_instance

    if _registry_instance is None:
        _registry_instance = DeviceRegistry(registry_path)

    return _registry_instance
