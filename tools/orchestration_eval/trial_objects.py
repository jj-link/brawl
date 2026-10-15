"""Compare actual PowerPC ELF32 allocatable bytes and normalized relocations."""
from __future__ import annotations

import json
from pathlib import Path
import struct

from .evidence import file_identity
from .safety import SafetyError


def object_contents(path):
    raw = Path(path).read_bytes()
    if len(raw) < 52 or raw[:7] != b"\x7fELF\x01\x02\x01":
        raise SafetyError("Comparison requires actual big-endian ELF32 objects")
    header = struct.unpack_from(">HHIIIIIHHHHHH", raw, 16)
    if header[0:3] != (1, 20, 1) or header[7] != 52:
        raise SafetyError("Comparison input is not a relocatable PowerPC object")
    offset, stride, count, names_index = header[5], header[10], header[11], header[12]
    if stride != 40 or not count or names_index >= count or offset + count * stride > len(raw):
        raise SafetyError("Invalid ELF section table")
    headers = [struct.unpack_from(">10I", raw, offset + index * stride) for index in range(count)]

    def data(section):
        if section[1] == 8:
            return b""
        start, size = section[4:6]
        if start + size > len(raw):
            raise SafetyError("ELF section exceeds actual file bytes")
        return raw[start:start + size]

    def string(table, start):
        if start >= len(table):
            raise SafetyError("Invalid ELF string offset")
        end = table.find(b"\0", start)
        if end < 0:
            raise SafetyError("Unterminated ELF string")
        return table[start:end].decode("utf-8", errors="strict")

    names = data(headers[names_index])
    section_names = [string(names, section[0]) for section in headers]
    contents, relocations, exports = {}, [], []
    for index, section in enumerate(headers):
        if section[2] & 2 and section[5]:
            name = section_names[index]
            if name in contents:
                raise SafetyError("Ambiguous repeated allocatable section")
            contents[name] = {"bytes": None if section[1] == 8 else data(section).hex(),
                              "size": section[5], "flags": section[2]}
        if section[1] == 2:
            if section[9] != 16 or section[5] % 16 or section[6] >= count:
                raise SafetyError("Invalid ELF symbol table")
            table, strings = data(section), data(headers[section[6]])
            for location in range(0, len(table), 16):
                name, value, size, info, other, defined = struct.unpack_from(">IIIBBH", table, location)
                if info >> 4 and 0 < defined < count and headers[defined][2] & 2:
                    exports.append([string(strings, name), info, other & 3, section_names[defined], value, size])
        if section[1] not in (4, 9):
            continue
        if section[7] >= count or section[6] >= count:
            raise SafetyError("Invalid ELF relocation section reference")
        if not headers[section[7]][2] & 2:
            continue
        symbols = headers[section[6]]
        if symbols[1] != 2 or symbols[9] != 16 or symbols[6] >= count:
            raise SafetyError("Invalid ELF relocation symbol table")
        table, strings = data(symbols), data(headers[symbols[6]])
        entries, width = data(section), 12 if section[1] == 4 else 8
        if section[9] != width or len(entries) % width:
            raise SafetyError("Invalid ELF relocation entries")
        for location in range(0, len(entries), width):
            address, information = struct.unpack_from(">II", entries, location)
            symbol_index, relocation_type = information >> 8, information & 255
            if address >= headers[section[7]][5]:
                raise SafetyError("ELF relocation lies outside its target section")
            if symbol_index * 16 + 16 > len(table):
                raise SafetyError("Invalid ELF relocation symbol index")
            name, value, size, info, other, defined = struct.unpack_from(">IIIBBH", table, symbol_index * 16)
            if info >> 4 or defined == 0:
                symbol = ["named", string(strings, name)]
            elif defined < count:
                symbol = ["section", section_names[defined], value]
            else:
                symbol = ["absolute", value, defined]
            addend = struct.unpack_from(">i", entries, location + 8)[0] if width == 12 else None
            relocations.append([section_names[section[7]], address, relocation_type, symbol, addend])
    return {"sections": contents, "exports": sorted(exports),
            "relocations": sorted(relocations, key=lambda value: json.dumps(value))}


def compare_objects(candidate, original):
    left, right = object_contents(candidate), object_contents(original)
    return {"matching": left == right, "candidate": file_identity(Path(candidate)),
            "original": file_identity(Path(original)), "candidate_contents": left, "original_contents": right}
