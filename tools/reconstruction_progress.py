#!/usr/bin/env python3
"""Count accepted C/C++ code separately from assembly and partial matches."""

import argparse
import json
import re
from pathlib import Path


SOURCE_SUFFIXES = {".c", ".cc", ".cpp", ".cxx"}
NON_CODE = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', re.DOTALL)
ASSEMBLY = re.compile(r"\b(?:asm|__asm|__asm__)\b")


def calculate(report, root):
    total = int(report["measures"]["total_code"])
    accepted = 0
    units = 0
    assembly = 0
    inline_assembly = 0
    for unit in report["units"]:
        metadata = unit.get("metadata", {})
        size = int(unit["measures"].get("total_code", 0))
        if not size or not metadata.get("complete", False):
            continue
        source = Path(metadata.get("source_path", ""))
        if source.suffix.lower() not in SOURCE_SUFFIXES:
            assembly += size
            continue
        # The resolved source_path honors configure.py's assembly overrides.
        # Conservatively exclude an entire mixed C/inline-assembly unit.
        text = (root / source).read_text(encoding="utf-8")
        if ASSEMBLY.search(NON_CODE.sub(" ", text)):
            inline_assembly += size
            continue
        accepted += size
        units += 1
    if not 0 <= accepted <= total or total == 0:
        raise ValueError("Invalid code-byte totals in progress report")
    return {
        "total_code_bytes": total,
        "accepted_source_code_bytes": accepted,
        "remaining_code_bytes": total - accepted,
        "percent_complete": 100 * accepted / total,
        "accepted_source_units": units,
        "excluded_assembly_code_bytes": assembly,
        "excluded_inline_assembly_unit_code_bytes": inline_assembly,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("report", type=Path, help="Fresh objdiff report.json")
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    report = json.loads(args.report.read_text(encoding="utf-8"))
    print(json.dumps(calculate(report, root), indent=2))


if __name__ == "__main__":
    main()
