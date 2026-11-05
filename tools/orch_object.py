"""Preserve original exception names and reuse verified original numeric constant storage.

This module is also installed in the target's tools directory and run after compilation.
Only registered units with explicit symbol bindings use the additional Ninja rule.
"""
from __future__ import annotations

import argparse
import json
import re
import struct
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
    if not bindings:
        return
    listing = subprocess.run([str(objdump), "-t", str(obj)], check=True, capture_output=True,
                             text=True, encoding="utf-8", errors="replace").stdout
    symbols = [(name, section, int(offset, 16), int(size, 16))
               for offset, flags, section, size, name in _SYMBOL.findall(listing)
               if flags[5] != "d"]
    args = []
    selected = set()
    renames = {}
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
        renames[old] = name
        if old != name:
            args.extend(["--redefine-sym", f"{old}={name}"])
        args.extend(["--globalize-symbol", name])
    if args:
        metadata = _comment_snapshot(obj.read_bytes(), renames=renames)
        subprocess.run([str(objcopy), *args, str(obj)], check=True)
        _restore_comment(obj, metadata)


def _elf_tables(data):
    """Read the target's ELF32 big-endian relocatable object; reject other formats."""
    if len(data) < 52 or data[:7] != b"\x7fELF\x01\x02\x01" or struct.unpack_from(">HH", data, 16) != (1, 20):
        raise ValueError("constant contracts require an ELF32 big-endian PowerPC relocatable object")
    start = struct.unpack_from(">I", data, 32)[0]
    width, count, names = struct.unpack_from(">HHH", data, 46)
    if width != 40 or not count or names >= count or start + count * width > len(data):
        raise ValueError("invalid ELF section table")
    sections = [struct.unpack_from(">10I", data, start + i * width) for i in range(count)]
    if any(s[1] != 8 and s[4] + s[5] > len(data) for s in sections):
        raise ValueError("ELF section exceeds object bounds")
    strings = data[sections[names][4]:sections[names][4] + sections[names][5]]
    def name(table, offset):
        end = table.find(b"\0", offset)
        if offset < 0 or end < offset:
            raise ValueError("invalid ELF string offset")
        return bytes(table[offset:end]).decode("ascii")
    section_names = [name(strings, s[0]) for s in sections]
    tables = [s for s in sections if s[1] == 2]
    if len(tables) != 1 or tables[0][9] != 16 or tables[0][5] % 16 or tables[0][6] >= count:
        raise ValueError("invalid ELF symbol table")
    table = tables[0]
    string_section = sections[table[6]]
    strings = data[string_section[4]:string_section[4] + string_section[5]]
    symbols = []
    for offset in range(table[4], table[4] + table[5], 16):
        fields = struct.unpack_from(">IIIBBH", data, offset)
        symbols.append((offset, name(strings, fields[0]), fields))
    return sections, section_names, symbols


def _metadata_key(name, fields, sections):
    section = sections[fields[5]] if 0 < fields[5] < len(sections) else fields[5]
    return (section if fields[3] & 15 == 3 else name, section, fields[1], fields[2], fields[3] & 15)


def _comment_snapshot(data, *, renames=None, external=None):
    """CodeWarrior stores an alignment/visibility/activation record for every ELF symbol, in symbol-table order."""
    sections, names, symbols = _elf_tables(data)
    if ".comment" not in names:
        return None
    section = sections[names.index(".comment")]
    comment = data[section[4]:section[4] + section[5]]
    if not comment.startswith(b"CodeWarrior"):
        return None
    if len(comment) != 0x2c + 8 * len(symbols) or comment[0x14] != 0x2c:
        raise ValueError("unsupported CodeWarrior symbol metadata")
    records = {}
    for i, (_, name, fields) in enumerate(symbols):
        if external and name in external:
            continue
        key = _metadata_key((renames or {}).get(name, name), fields, names)
        entry = comment[0x2c + 8 * i:0x34 + 8 * i]
        if key in records and records[key] != entry:
            raise ValueError(f"ambiguous CodeWarrior metadata for {name}")
        records[key] = entry
    for original in (external or {}).values():
        records.setdefault((original, 0, 0, 0, 0), bytes(8))  # an extern has no owned alignment or activation
    return comment[:0x2c], records


def _restore_comment(obj, snapshot):
    """Keep all surviving symbols' compiler attributes after objcopy reorders or removes symbols."""
    if snapshot is None:
        return
    data = bytearray(obj.read_bytes())
    sections, names, symbols = _elf_tables(data)
    if ".comment" not in names:
        raise ValueError("objcopy removed CodeWarrior metadata")
    header, records = snapshot
    entries = []
    for _, name, fields in symbols:
        key = _metadata_key(name, fields, names)
        if key not in records:
            raise ValueError(f"objcopy introduced unaccounted symbol metadata: {name}")
        entries.append(records[key])
    comment = header + b"".join(entries)
    table = struct.unpack_from(">I", data, 32)[0]
    position = table + 40 * names.index(".comment")
    struct.pack_into(">II", data, position + 16, len(data), len(comment))
    data.extend(comment)
    obj.write_bytes(data)


def _constant_pool_plan(data, bindings, *, function=None):
    """Validate complete immutable pools and every incoming reference before removing any bytes."""
    sections, names, symbols = _elf_tables(data)
    by_name = {b["name"]: b for b in bindings}
    if len(by_name) != len(bindings) or len({b["original"] for b in bindings}) != len(bindings):
        raise ValueError("ambiguous constant contract")
    originals = {b["original"] for b in bindings}
    if any(name in originals and fields[5] for _, name, fields in symbols):
        raise ValueError("original storage symbol is already defined in this object")
    discard = {i for i, name in enumerate(names) if name in {b["section"] for b in bindings}}
    # CodeWarrior marks ABI read-only .sdata2 literals SHF_WRITE; .rodata must not be writable.
    if (not discard or {names[i] for i in discard} != {b["section"] for b in bindings}
            or any(names[i] not in {".rodata", ".sdata2"} for i in discard)
            or any(sections[i][1] != 1 or (names[i] == ".rodata" and sections[i][2] & 1)
                   for i in discard)
            or any(s[5] and name in {".rodata", ".sdata2"} and i not in discard
                   for i, (name, s) in enumerate(zip(names, sections)))):
        raise ValueError("incomplete constant pool sections")
    functions = [(name, fields) for _, name, fields in symbols
                 if fields[3] == 0x12 and fields[5] < len(names) and names[fields[5]] == ".text" and fields[2]]
    if len(functions) != 1 or (function is not None and functions[0][0] != function):
        raise ValueError("constant pool requires one owning function")
    _, owner = functions[0]
    seen, selected = set(), set()
    for index, (_, name, fields) in enumerate(symbols):
        _, value, size, info, _, section = fields
        if section not in discard or info & 15 == 3:  # section symbols are checked at every relocation below
            continue
        anchor = (info == 0 and not size and not value
                  and re.fullmatch(r"\.\.\.(?:rodata|sdata2)\.\d+", name))
        numeric = info == 1 and size > 0 and re.fullmatch(r"@\d+", name)
        if not (anchor or numeric) or value + size > sections[section][5]:
            raise ValueError(f"unexpected definition in constant pool: {name}")
        binding = by_name.get(name)
        if binding is None:
            continue  # unused compiler labels disappear with the section; references are checked below
        extent = sections[section][5] if not size and name.startswith("...") and not value else size
        if (name in seen or (names[section], value, extent)
                != (binding["section"], binding["offset"], binding["size"])):
            raise ValueError(f"changed constant extent: {name}")
        payload = bytes.fromhex(binding["bytes"])
        start = sections[section][4] + value
        if not extent or len(payload) != extent or data[start:start + extent] != payload:
            raise ValueError(f"changed constant bytes: {name}")
        seen.add(name)
        selected.add(index)
    if seen != by_name.keys():
        raise ValueError("missing constant")
    for section in discard:
        cursor = 0
        for binding in sorted((b for b in bindings if b["section"] == names[section]), key=lambda b: b["offset"]):
            if binding["offset"] != cursor:
                raise ValueError("unowned bytes in constant pool")
            cursor += binding["size"]
        if cursor != sections[section][5]:
            raise ValueError("unowned trailing bytes in constant pool")
    for section in sections:
        if section[1] not in {4, 9}:
            continue
        width = 12 if section[1] == 4 else 8
        if section[9] != width or section[5] % width or section[7] >= len(names):
            raise ValueError("invalid ELF relocation section")
        if section[7] in discard and section[5]:
            raise ValueError("relocated data is not a numeric constant pool")
        for at in range(section[4], section[4] + section[5], width):
            site, info = struct.unpack_from(">II", data, at)
            index, kind = info >> 8, info & 255
            if index >= len(symbols):
                raise ValueError("invalid ELF relocation symbol")
            if symbols[index][2][5] in discard:
                addend = struct.unpack_from(">i", data, at + 8)[0] if width == 12 else None
                if (index not in selected or section[7] != owner[5] or kind not in {4, 6, 109} or addend != 0
                        or site % 4 != (0 if kind == 109 else 2)
                        or not owner[1] <= site <= owner[1] + owner[2] - (4 if kind == 109 else 2)):
                    raise ValueError("unproven reference into constant pool")
    return {b["name"]: symbols[index][2][2] for b in bindings for index in selected
            if symbols[index][1] == b["name"]}


def externalize_constants(obj: Path, bindings: list[dict], objcopy: Path) -> None:
    """Reuse verified original storage; retain instructions, relocations and compiler attributes."""
    if not bindings:
        return
    data = obj.read_bytes()
    symbol_sizes = _constant_pool_plan(data, bindings)
    metadata = _comment_snapshot(data, external={b["name"]: b["original"] for b in bindings})
    args = [arg for b in bindings for arg in ("--redefine-sym", f'{b["name"]}={b["original"]}',
                                            "--globalize-symbol", b["original"])]
    subprocess.run([str(objcopy), *args, str(obj)], check=True)
    data = bytearray(obj.read_bytes())
    _, names, symbols = _elf_tables(data)
    originals = {b["original"]: b for b in bindings}
    changed = set()
    for at, name, fields in symbols:
        if name not in originals or not fields[5]:
            continue
        binding = originals[name]
        if fields[5] >= len(names) or (names[fields[5]], fields[1], fields[2]) != (
                binding["section"], binding["offset"], symbol_sizes[binding["name"]]):
            raise ValueError(f"constant symbol collides with another definition: {name}")
        struct.pack_into(">IIIBBH", data, at, fields[0], 0, 0, 0x10, 0, 0)
        changed.add(name)
    if changed != originals.keys():
        raise ValueError("objcopy lost constant symbols")
    obj.write_bytes(data)
    subprocess.run([str(objcopy), *[f"--remove-section={s}" for s in sorted({b["section"] for b in bindings})],
                    str(obj)], check=True)
    _restore_comment(obj, metadata)


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
        raise ValueError(f"empty object symbol contract: {args.contract}")
    preserve_symbols(args.object, [b for b in bindings if "original" not in b], args.objdump, args.objcopy)
    externalize_constants(args.object, [b for b in bindings if "original" in b], args.objcopy)


if __name__ == "__main__":
    main()
