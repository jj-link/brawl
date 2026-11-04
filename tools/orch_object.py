"""Preserve original exception-table names without changing compiled code or table bytes.

This module is also installed in the target's tools directory and run after compilation.
Only registered units with exception bindings use the additional Ninja rule.
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
from pathlib import Path

_SYMBOL = re.compile(r"^([0-9a-fA-F]+) (.{7})\s+(\S+)\s+([0-9a-fA-F]+)\s+(?:\.hidden )?(\S+)\s*$", re.M)
_ORIGINAL = re.compile(r'^"?([^" =]+)"? = (extab|extabindex):0x([0-9A-Fa-f]+); // type:object size:0x([0-9A-Fa-f]+)', re.M)


def exception_bindings(cfg, unit) -> list[dict]:
    if unit.exceptions is None:
        return []
    ranges = dict(zip(("extab", "extabindex"), unit.exceptions))
    text = (cfg.module_config_dir(unit.fn.lib) / "symbols.txt").read_text(encoding="utf-8")
    result = []
    for name, section, address, size in _ORIGINAL.findall(text):
        address, size = int(address, 16), int(size, 16)
        first, last = ranges[section]
        if first <= address < last:
            if not size or address + size > last:
                raise ValueError(f"exception symbol {name} crosses the registered {section} range")
            result.append({"name": name, "section": section, "offset": address - first, "size": size})
    for section, (first, last) in ranges.items():
        covered = sorted((b["offset"], b["size"]) for b in result if b["section"] == section)
        end = 0
        for offset, size in covered:
            if offset != end:
                raise ValueError(f"exception symbol metadata does not cover {section} contiguously")
            end += size
        if end != last - first:
            raise ValueError(f"exception symbol metadata is incomplete for {section}")
    return result


def preserve_symbols(obj: Path, bindings: list[dict], objdump: Path, objcopy: Path) -> None:
    listing = subprocess.run([str(objdump), "-t", str(obj)], check=True, capture_output=True,
                             text=True, encoding="utf-8", errors="replace").stdout
    symbols = [(name, section, int(offset, 16), int(size, 16))
               for offset, flags, section, size, name in _SYMBOL.findall(listing)
               if flags[5] != "d"]
    args = []
    selected = set()
    for binding in bindings:
        name = binding["name"]
        location = (binding["section"], binding["offset"], binding["size"])
        named = [s for s in symbols if s[0] == name]
        if named and any(s[1:] != location for s in named):
            raise ValueError(f"{name} already exists at a different exception-table location")
        candidates = named or [s for s in symbols if s[1:] == location]
        if len(candidates) != 1 or candidates[0][0] in selected:
            raise ValueError(f"cannot uniquely bind {name} to {location} in {obj}")
        old = candidates[0][0]
        selected.add(old)
        if old != name:
            args.extend(["--redefine-sym", f"{old}={name}"])
        args.extend(["--globalize-symbol", name])
    if args:
        subprocess.run([str(objcopy), *args, str(obj)], check=True)


_RULES = '''    # decomp-orchestrator exception symbol contracts
    contract_script = config.tools_dir / "orch_object.py"
    contract_objdump = binutils / f"powerpc-eabi-objdump{EXE}"
    for rule, command in (("mwcc", mwcc_cmd), ("mwcc_sjis", mwcc_sjis_cmd),
                          ("mwcc_extab", mwcc_extab_cmd), ("mwcc_sjis_extab", mwcc_sjis_extab_cmd),
                          ("mwcc_align4", mwcc_align4_cmd), ("mwcc_sjis_align4", mwcc_sjis_align4_cmd)):
        command = command if command.startswith(CHAIN) else CHAIN + command
        n.rule(name=rule + "_contract",
               command=command + f' && $python "{contract_script}" "$out" "$orch_contract" '
                                 f'"{contract_objdump}" "{objcopy}"',
               description="MWCC $out", depfile="$basefile.d", deps="gcc")
    n.newline()
    # end decomp-orchestrator exception symbol contracts

'''
_SELECT = '''            # decomp-orchestrator exception object
            if obj.options.get("orch_contract"):
                from hashlib import sha256 as _orch_sha256
                from json import dumps as _orch_dumps
                contract = _orch_dumps(obj.options["orch_contract"], sort_keys=True).encode("utf-8")
                contract_file = build_path / "orch-contracts" / (_orch_sha256(contract).hexdigest() + ".json")
                if not contract_file.is_file():
                    contract_file.parent.mkdir(parents=True, exist_ok=True)
                    contract_file.write_bytes(contract)
                build_rule += "_contract"
                build_implcit = [*build_implcit, contract_script, contract_file,
                                  binutils_implicit or contract_objdump, binutils_implicit or objcopy]
                variables["orch_contract"] = contract_file
            # end decomp-orchestrator exception object
'''


def install_contract_support(cfg) -> list[str]:
    """Install the reproducible compiler hook; fail closed for an incompatible build generator."""
    project = cfg.repo / "tools" / "project.py"
    original = project.read_bytes().decode("utf-8")
    text = original.replace("\r\n", "\n")
    for anchor, addition in [('    n.comment("Assemble asm")', _RULES),
                             ('            n.comment(f"{obj.name}: {lib_name} (linked {obj.completed})")\n'
                              '            n.build(\n'
                              '                outputs=obj.src_obj_path,', _SELECT)]:
        begin, end = addition.splitlines()[0], addition.rstrip().splitlines()[-1]
        if begin in text:
            start = text.index(begin)
            if end not in text[start:]:
                raise ValueError("incomplete target exception-contract hook")
            stop = text.index(end, start) + len(end)
            text = text[:start] + addition.rstrip("\n") + text[stop:]
        else:
            if text.count(anchor) != 1:
                raise ValueError(f"unsupported target build generator: expected one {anchor.strip()}")
            text = text.replace(anchor, addition + anchor)
    if "\r\n" in original:
        text = text.replace("\n", "\r\n")
    script = cfg.repo / "tools" / "orch_object.py"
    contents = Path(__file__).read_bytes()
    changed = []
    if text != original:
        project.write_bytes(text.encode("utf-8"))
        changed.append("tools/project.py")
    if not script.is_file() or script.read_bytes() != contents:
        script.write_bytes(contents)
        changed.append("tools/orch_object.py")
    return changed


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("object", type=Path)
    parser.add_argument("contract", type=Path)
    parser.add_argument("objdump", type=Path)
    parser.add_argument("objcopy", type=Path)
    args = parser.parse_args()
    bindings = json.loads(args.contract.read_text(encoding="utf-8"))
    if not bindings:
        raise ValueError(f"empty exception symbol contract: {args.contract}")
    preserve_symbols(args.object, bindings, args.objdump, args.objcopy)


if __name__ == "__main__":
    main()
