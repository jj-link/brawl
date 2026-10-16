"""Byte/AST insertion consumers; real Git publication is exercised separately."""
import os
import unittest

from .trial_ownership import prove_registration_insertions


@unittest.skipUnless(os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned behavioral verification required")
class RegistrationOwnershipTests(unittest.TestCase):
    def setUp(self):
        self.source = "src/mo_fighter/sample/function_abcd.cpp"
        self.relative = self.source.removeprefix("src/")
        self.split = "config/version/rels/sample/splits.txt"
        self.reservation = {"function": {"module": 7, "symbol": "function", "start": 0xABCD, "end": 0xABD9},
                            "owned_paths": [self.source, "configure.py", self.split]}
        self.specification = {"selection": {"source": self.source}, "recipe": {"registration": {
            "schema": 1, "module": 7, "library": "sample", "configure_path": "configure.py",
            "splits_path": self.split, "cflags": "cflags_fighter", "extra_cflags": ["-RTTI off"]}}}
        self.before = {"configure.py": b'libraries = [\n    {"lib": "sample", "objects": [\n'
                       b'        Object(Matching, "unrelated.cpp", cflags=cflags_other),\n    ]},\n]\n',
                       self.split: b'Sections:\n\t.text type:code align:4\n\nunrelated.cpp:\n\t.text start:0x0 end:0x10\n'}
        entry = (f'        Object(Matching, "{self.relative}",\n'
                 '               cflags=cflags_fighter, extra_cflags=["-RTTI off"]),\n').encode()
        self.after = {"configure.py": self.before["configure.py"].replace(b'        Object', entry + b'        Object', 1),
                      self.split: self.before[self.split] + f'\n{self.relative}:\n\t.text start:0xABCD end:0xABD9\n'.encode()}

    def proof(self, after=None, *, matching=True):
        return prove_registration_insertions(self.before, self.after if after is None else after,
                                             self.reservation, self.specification, matching)

    def test_exact_dynamic_module_source_and_non_eight_byte_range_are_proved(self):
        proof, reason = self.proof()
        self.assertIsNone(reason)
        self.assertEqual(proof, {"configure.py": "configure-obj-insertion-v1",
                                 self.split: "splits-section-insertion-v1"})

    def test_unrelated_semantic_or_whitespace_changes_are_not_path_based_approval(self):
        for replacement in (b'Object(NonMatching, "unrelated.cpp"', b'Object(Matching,  "unrelated.cpp"'):
            after = dict(self.after, **{"configure.py": self.after["configure.py"].replace(
                b'Object(Matching, "unrelated.cpp"', replacement)})
            proof, reason = self.proof(after)
            self.assertIsNone(proof)
            self.assertTrue(reason)

    def test_recipe_side_effect_expression_and_wrong_library_remain_judgments(self):
        for after in ({**self.after, "configure.py": self.after["configure.py"].replace(
                b"cflags=cflags_fighter", b"cflags=unexpected_call()")},
                {**self.after, "configure.py": self.after["configure.py"].replace(b'"lib": "sample"', b'"lib": "foreign"')}):
            self.assertIsNone(self.proof(after)[0])

    def test_split_range_overlap_or_stolen_existing_section_cannot_pass(self):
        wrong = {**self.after, self.split: self.after[self.split].replace(b"end:0xABD9", b"end:0xABDA")}
        self.assertIsNone(self.proof(wrong)[0])
        self.before[self.split] = self.before[self.split].replace(b"end:0x10", b"end:0xFFFF")
        overlapping = {**self.after, self.split: self.after[self.split].replace(b"end:0x10", b"end:0xFFFF")}
        self.assertIsNone(self.proof(overlapping)[0])
        self.before[self.split] = b'Sections:\n\t.text type:code align:4\n\nunrelated.cpp:\n\t.text start:0x0 end:0x10\n\t.data start:0x0 end:0x4\n'
        stolen = {**self.after, self.split: self.before[self.split].replace(
            b"\t.data", f'{self.relative}:\n\t.text start:0xABCD end:0xABD9\n\t.data'.encode())}
        self.assertIsNone(self.proof(stolen)[0])

    def test_matching_mode_and_recipe_are_explicit_not_inferred_from_path(self):
        nonmatching = {**self.after, "configure.py": self.after["configure.py"].replace(
            f'Object(Matching, "{self.relative}"'.encode(), f'Object(NonMatching, "{self.relative}"'.encode())}
        self.assertIsNone(self.proof(nonmatching)[0])
        self.assertIsNotNone(self.proof(nonmatching, matching=False)[0])
        self.specification["recipe"].pop("registration")
        self.assertIsNone(self.proof()[0])
