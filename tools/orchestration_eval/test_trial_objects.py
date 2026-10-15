"""Actual ELF byte consumers; these fixtures are not native compile evidence."""
import os
from pathlib import Path
import struct
import unittest
import uuid

from .safety import BUILD, SafetyError
from .trial_objects import compare_objects, object_contents


def elf_bytes(*, text=b"\x38\x60\x00\x01\x4e\x80\x00\x20", export="function",
              target="callee", relocation=10, addend=0, address=0, comment=b"compiler one"):
    names = ["", ".text", ".shstrtab", ".strtab", ".symtab", ".rela.text", ".comment"]
    strings = b"\0" + export.encode() + b"\0" + target.encode() + b"\0"
    names_data = b"\0"
    offsets = [0]
    for name in names[1:]:
        offsets.append(len(names_data))
        names_data += name.encode() + b"\0"
    symbols = bytes(16) + struct.pack(">IIIBBH", 1, 0, len(text), 0x12, 0, 1)
    symbols += struct.pack(">IIIBBH", len(export) + 2, 0, 0, 0x10, 0, 0)
    payloads = [b"", text, names_data, strings, symbols,
                struct.pack(">IIi", address, (2 << 8) | relocation, addend), comment]
    types = [0, 1, 3, 3, 2, 4, 1]
    flags = [0, 6, 0, 0, 0, 0, 0]
    body, headers = bytearray(bytes(52)), []
    for index, payload in enumerate(payloads):
        headers.append((offsets[index], types[index], flags[index], 0, len(body), len(payload),
                        3 if index == 4 else 4 if index == 5 else 0,
                        1 if index in (4, 5) else 0, 4 if index in (1, 4, 5) else 1,
                        16 if index == 4 else 12 if index == 5 else 0))
        body.extend(payload)
    table = len(body)
    for header in headers:
        body.extend(struct.pack(">10I", *header))
    body[:16] = b"\x7fELF\x01\x02\x01" + bytes(9)
    body[16:52] = struct.pack(">HHIIIIIHHHHHH", 1, 20, 1, 0, 0, table, 0, 52, 0, 0, 40, len(names), 2)
    return bytes(body)


@unittest.skipUnless(os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned behavioral verification required")
class TrialObjectTests(unittest.TestCase):
    def setUp(self):
        self.root = BUILD / "tests/trial-objects" / uuid.uuid4().hex
        self.root.mkdir(parents=True)
        self.original = self.put("original.o", elf_bytes())

    def put(self, name, content):
        path = self.root / name
        path.write_bytes(content)
        return path

    def test_nonallocatable_compiler_metadata_is_not_code(self):
        candidate = self.put("candidate.o", elf_bytes(comment=b"different compiler comment"))
        result = compare_objects(candidate, self.original)
        self.assertTrue(result["matching"])
        self.assertNotEqual(result["candidate"], result["original"])

    def test_equal_text_does_not_hide_relocation_or_export_changes(self):
        for changes in ({"target": "other"}, {"relocation": 1}, {"addend": 4},
                        {"address": 4}, {"export": "wrong_function"}):
            with self.subTest(changes=changes):
                candidate = self.put("candidate.o", elf_bytes(**changes))
                result = compare_objects(candidate, self.original)
                self.assertFalse(result["matching"])
                self.assertEqual(result["candidate_contents"]["sections"],
                                 result["original_contents"]["sections"])

    def test_actual_instruction_change_is_nonmatching(self):
        candidate = self.put("candidate.o", elf_bytes(text=b"\x38\x60\x00\x02\x4e\x80\x00\x20"))
        self.assertFalse(compare_objects(candidate, self.original)["matching"])

    def test_truncation_architecture_and_outside_relocations_are_rejected(self):
        wrong_arch = bytearray(elf_bytes())
        wrong_arch[18:20] = struct.pack(">H", 3)
        for raw in (elf_bytes()[:51], elf_bytes()[:-1], bytes(wrong_arch), elf_bytes(address=8)):
            with self.subTest(size=len(raw)), self.assertRaises(SafetyError):
                object_contents(self.put("malformed.o", raw))
