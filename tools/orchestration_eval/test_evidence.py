"""Relevant-input regressions retaining independent Git fixtures and observations."""
from __future__ import annotations

import json
import unittest
import uuid

from .evidence import InputError, InputManifest, capture_inputs, validate_inputs
from .publication import EVALUATION_DATA, FixtureScope, _git, _text, initialize_fixture


INPUTS = {"source": ["source.cpp"], "header": ["shared.h"],
          "config": ["config.json"], "tool": ["tool.txt"]}
RECIPE = {"scope": "evaluation_fixture", "operation": "compare declared raw-byte identities",
          "semantic_correctness": "not established"}


class EvidenceTests(unittest.TestCase):
    def setUp(self):
        self.root = EVALUATION_DATA / "evidence-tests" / uuid.uuid4().hex[:16]
        self.scope = FixtureScope(self.root, authorized=True)
        self.fixture = initialize_fixture(self.scope, "case")
        self.manifest = capture_inputs(self.fixture.repository, INPUTS, RECIPE)
        (self.fixture.evidence_dir / "input-manifest.json").write_text(
            json.dumps(self.manifest.to_dict(), indent=2), encoding="utf-8")

    def test_unrelated_real_commit_does_not_invalidate_inputs(self):
        before = _text(self.fixture.repository, ["rev-parse", "HEAD"], self.fixture.evidence_dir)
        (self.fixture.repository / "unrelated.txt").write_bytes(b"a genuinely unrelated committed change\n")
        _git(self.fixture.repository, ["add", "--", "unrelated.txt"], self.fixture.evidence_dir)
        _git(self.fixture.repository, ["commit", "-m", "Unrelated input-identity exercise"], self.fixture.evidence_dir)
        after = _text(self.fixture.repository, ["rev-parse", "HEAD"], self.fixture.evidence_dir)
        self.assertNotEqual(before, after)
        actual = capture_inputs(self.fixture.repository, INPUTS, RECIPE)
        self.assertEqual(self.manifest.identity, actual.identity)
        self.assertTrue(validate_inputs(self.fixture.repository, self.manifest).valid)

    def test_shared_header_change_invalidates_every_affected_manifest(self):
        (self.fixture.repository / "second.cpp").write_bytes(b"int second() { return FIXTURE_VALUE; }\n")
        second = capture_inputs(self.fixture.repository, INPUTS | {"source": ["second.cpp"]}, RECIPE)
        (self.fixture.repository / "shared.h").write_bytes(b"#define FIXTURE_VALUE 2\n")
        for manifest in (self.manifest, second):
            with self.subTest(identity=manifest.identity):
                result = validate_inputs(self.fixture.repository, manifest)
                self.assertFalse(result.valid)
                self.assertEqual(("shared.h",), result.changed)
                self.assertNotEqual(manifest.identity, result.current_identity)

    def test_configuration_tool_and_recipe_participate_in_identity(self):
        for category, path in (("configuration", "config.json"), ("tool", "tool.txt")):
            with self.subTest(category=category):
                original = (self.fixture.repository / path).read_bytes()
                (self.fixture.repository / path).write_bytes(original + b"changed\n")
                result = validate_inputs(self.fixture.repository, self.manifest)
                self.assertFalse(result.valid)
                self.assertEqual((path,), result.changed)
                (self.fixture.repository / path).write_bytes(original)
        revised = capture_inputs(self.fixture.repository, INPUTS, RECIPE | {"operation": "different recipe"})
        self.assertNotEqual(self.manifest.identity, revised.identity)

    def test_missing_input_is_invalid_without_discarding_original(self):
        original = self.fixture.repository / "shared.h"
        original.rename(self.fixture.repository / "shared.h.retained")
        result = validate_inputs(self.fixture.repository, self.manifest)
        self.assertFalse(result.valid)
        self.assertEqual(("shared.h",), result.changed)
        self.assertIsNone(result.current_identity)

    def test_manifest_roundtrip_is_immutable_and_tampering_is_refused(self):
        serialized = self.manifest.to_dict()
        restored = InputManifest.from_dict(serialized)
        self.assertEqual(self.manifest, restored)
        serialized["recipe"]["operation"] = "changed after review"
        with self.assertRaises(InputError):
            InputManifest.from_dict(serialized)
        self.assertEqual(RECIPE, self.manifest.to_dict()["recipe"])

    def test_outside_and_git_metadata_inputs_are_refused(self):
        for name in ("../outside", ".git/config", "C:/outside", "/outside", "..\\outside"):
            with self.subTest(path=name), self.assertRaises(InputError):
                capture_inputs(self.fixture.repository, INPUTS | {"header": [name]}, RECIPE)


if __name__ == "__main__":
    unittest.main()
