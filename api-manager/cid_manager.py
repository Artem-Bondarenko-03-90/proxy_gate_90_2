"""
CID Manager - Handles IEC 61850 CID file manipulation
"""
import os
import re
import shutil
from typing import List, Optional
from datetime import datetime


class CIDManager:
    def __init__(self, cid_file: str = "multi-ld-model.cid"):
        self.cid_file = cid_file
        self.backup_file = f"{cid_file}.backup"

    def backup(self) -> str:
        """Create backup of current CID file"""
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        backup_path = f"{self.cid_file}.{timestamp}"
        shutil.copy2(self.cid_file, backup_path)
        return backup_path

    def get_logical_devices(self) -> List[str]:
        """Get list of all logical devices from CID file"""
        with open(self.cid_file, 'r', encoding='utf-8') as f:
            content = f.read()

        # Find all LDevice instances
        pattern = r'<LDevice\s+inst="([^"]+)"'
        matches = re.findall(pattern, content)
        return matches

    def add_logical_device(self, ld_name: str, template_ld: str = "GenericIO") -> bool:
        """
        Add a new logical device by cloning a template.
        Creates a read-only GGIO with only MX and ST (measurements and status), no controls.
        Adds custom LNType to DataTypeTemplates for this purpose.

        Args:
            ld_name: Name for the new logical device
            template_ld: Name of the LD to use as template

        Returns:
            True if successful, False otherwise
        """
        # Check if LD already exists
        existing_lds = self.get_logical_devices()
        if ld_name in existing_lds:
            return False

        # Create backup
        self.backup()

        with open(self.cid_file, 'r', encoding='utf-8') as f:
            content = f.read()

        # Find the template LD section
        template_pattern = rf'(<LDevice\s+inst="{template_ld}"[\s\S]*?</LDevice>)'
        template_match = re.search(template_pattern, content)
        if not template_match:
            return False

        template_block = template_match.group(1)

        # Create new LD block
        new_ld_block = template_block.replace(f'inst="{template_ld}"', f'inst="{ld_name}"')
        new_ld_block = re.sub(rf'ldInst="{template_ld}"', f'ldInst="{ld_name}"', new_ld_block)
        new_ld_block = re.sub(
            rf'<Val>libiec61850 server example - LD[^<]*</Val>',
            f'<Val>libiec61850 server example - {ld_name}</Val>',
            new_ld_block
        )

        # Replace GGIO1 with custom read-only type
        new_ld_block = new_ld_block.replace('lnType="GGIO1"', 'lnType="GGIO1_RO"')

        # Find DataTypeTemplates section and add GGIO1_RO
        dtype_section = r'(<DataTypeTemplates>[\s\S]*?)</DataTypeTemplates>'
        dtype_match = re.search(dtype_section, content)

        if dtype_match:
            dtype_content = dtype_match.group(1)

            # Create GGIO1_RO (read-only) type - only AnIn and Ind, no SPC
            ggio_ro = '''
    <LNodeType id="GGIO1_RO" lnClass="GGIO">
      <DO name="Mod" type="INC_2_Mod" />
      <DO name="Beh" type="INS_1_Beh" />
      <DO name="Health" type="INS_1_Beh" />
      <DO name="NamPlt" type="LPL_2_NamPlt" />
      <DO name="AnIn1" type="MV_1_AnIn1" />
      <DO name="AnIn2" type="MV_1_AnIn1" />
      <DO name="AnIn3" type="MV_1_AnIn1" />
      <DO name="AnIn4" type="MV_1_AnIn1" />
      <DO name="Ind1" type="SPS_1_Proxy" />
      <DO name="Ind2" type="SPS_1_Proxy" />
      <DO name="Ind3" type="SPS_1_Proxy" />
      <DO name="Ind4" type="SPS_1_Proxy" />
    </LNodeType>
'''

            # Insert GGIO1_RO after GGIO1
            new_dtype_content = dtype_content + ggio_ro
            content = content.replace(dtype_content, new_dtype_content)

        # Remove control and configuration elements from new LD
        # Remove DOI with ctlModel
        new_ld_block = re.sub(
            r'\s*<DOI name="[^"]*">\s*<DAI name="ctlModel">[\s\S]*?</DAI>\s*</DOI>\s*',
            '\n',
            new_ld_block
        )

        # Remove ReportControl
        new_ld_block = re.sub(r'\s*<ReportControl[^>]*>[\s\S]*?</ReportControl>\s*', '\n', new_ld_block)

        # Remove LogControl
        new_ld_block = re.sub(r'\s*<LogControl[^>]*>[\s\S]*?</LogControl>\s*', '\n', new_ld_block)

        # Remove Log
        new_ld_block = re.sub(r'\s*<Log[^/]*/>\s*', '', new_ld_block)

        # Keep only Measurements DataSet (remove Events)
        new_ld_block = re.sub(
            r'\s*<DataSet name="(?!Measurements)[^"]*"[^>]*>[\s\S]*?</DataSet>\s*',
            '\n',
            new_ld_block
        )

        # Insert new LD
        insert_pattern = r'(</LDevice>)'
        last_ld_match = list(re.finditer(insert_pattern, content))[-1]

        if last_ld_match:
            insert_pos = last_ld_match.end()
            new_content = content[:insert_pos] + "\n        " + new_ld_block + content[insert_pos:]

            # Write back
            with open(self.cid_file, 'w', encoding='utf-8') as f:
                f.write(new_content)

            return True

        return False

    def remove_logical_device(self, ld_name: str) -> bool:
        """Remove a logical device from CID file"""
        if ld_name in ["GenericIO", "GenericIO2"]:
            # Protect original LDs
            return False

        self.backup()

        with open(self.cid_file, 'r', encoding='utf-8') as f:
            content = f.read()

        # Remove the LDevice block
        pattern = rf'\s*<LDevice\s+inst="{ld_name}"[\s\S]*?</LDevice>\s*'
        new_content = re.sub(pattern, '\n', content)

        with open(self.cid_file, 'w', encoding='utf-8') as f:
            f.write(new_content)

        return True

    def validate(self) -> bool:
        """Validate CID file structure"""
        try:
            with open(self.cid_file, 'r', encoding='utf-8') as f:
                content = f.read()

            # Basic validation
            required_elements = ['<SCL', '<IED', '<LDevice', '</SCL>']
            return all(elem in content for elem in required_elements)
        except Exception:
            return False


if __name__ == "__main__":
    # Test
    manager = CIDManager("../multi-ld-model.cid")
    print("Current LDs:", manager.get_logical_devices())
    print("Validation:", manager.validate())
