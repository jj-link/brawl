"""Actual ELF/hash evidence consumers; fixtures are not reconstruction compile proof."""
import hashlib
import json
import os
from pathlib import Path
import unittest
import uuid

from .safety import BUILD, WORKTREE, RESERVED_WORKTREE, SafetyError, check_worktree, digest
from .test_state import WorkflowFixture
from .test_trial_objects import elf_bytes
from .trial_delivery import verify_binary_hashes
from .trial_objects import compare_objects
from .evidence import content_identity, file_identity
from .trial_verification import (VerificationRejected, fixed_native_equivalence,
                                 apply_judgment_requirements, reusable_evidence, verification_outputs)


@unittest.skipUnless(os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned behavioral verification required")
class CoverageEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.root = BUILD / "tests/criterion-coverage" / uuid.uuid4().hex
        self.root.mkdir(parents=True)
        self.expected = {}
        for index in range(127):
            name = f"binary-{index}.rel"
            raw = f"Owned hash-consumer fixture {index}".encode()
            (self.root / name).write_bytes(raw)
            self.expected[name] = hashlib.sha1(raw).hexdigest()
        self.hashes = verify_binary_hashes(self.root, self.expected)
        self.original = self.root / "original.o"
        self.candidate = self.root / "candidate.o"
        self.original.write_bytes(elf_bytes())
        self.candidate.write_bytes(elf_bytes(comment=b"candidate compiler metadata"))
        self.selection = {"selected": True, "fallback_selected": False}

    def covered(self, *, comparison=None, selection=None, hashes=None, symbol="function", exhausted=False):
        return fixed_native_equivalence(
            compare_objects(self.candidate, self.original) if comparison is None else comparison,
            self.selection if selection is None else selection, self.expected,
            self.hashes if hashes is None else hashes, symbol=symbol, exhausted=exhausted)

    def test_complete_native_image_chain_covers_fixed_abi_and_edges(self):
        self.assertTrue(self.covered())
        self.assertNotEqual(self.candidate.read_bytes(), self.original.read_bytes())

    def test_matching_label_cannot_hide_actual_relocation_change(self):
        self.candidate.write_bytes(elf_bytes(target="other_callee"))
        comparison = compare_objects(self.candidate, self.original)
        self.assertFalse(self.covered(comparison=comparison))
        comparison["matching"] = True
        with self.assertRaises(VerificationRejected) as failure:
            self.covered(comparison=comparison)
        self.assertEqual(failure.exception.findings[0]["criterion"], "object_compare")

    def test_count_alone_cannot_cover_missing_or_failed_native_hash(self):
        for rows in (self.hashes[:-1], [self.hashes[0]] * 127,
                     [dict(self.hashes[0], observed="0" * 40), *self.hashes[1:]]):
            with self.subTest(rows=len(rows)), self.assertRaises(VerificationRejected) as failure:
                self.covered(hashes=rows)
            self.assertEqual(failure.exception.findings[0]["criterion"], "binary_hashes")

    def test_missing_reserved_export_or_wrong_selection_stays_uncovered(self):
        self.assertFalse(self.covered(symbol="unproved_function"))
        self.assertFalse(self.covered(selection={"selected": True, "fallback_selected": True}))
        self.assertFalse(self.covered(selection={"selected": False, "fallback_selected": True}))

    def test_exhausted_nonmatching_requires_actual_original_fallback(self):
        self.candidate.write_bytes(elf_bytes(text=b"\x38\x60\x00\x02\x4e\x80\x00\x20"))
        fallback = {"selected": False, "fallback_selected": True}
        self.assertFalse(self.covered(selection=fallback))
        self.assertTrue(self.covered(selection=fallback, exhausted=True))
        self.assertFalse(self.covered(exhausted=True))

    @unittest.skipIf(WORKTREE == RESERVED_WORKTREE, "Applies only to the approved clean candidate assembly")
    def test_clean_candidate_cannot_activate_trial_or_import_unapproved_native_delta(self):
        with self.assertRaises(SafetyError):
            check_worktree(real_trial=True)
        assembly = json.loads((WORKTREE / "candidate-assembly.json").read_bytes())
        published = json.loads(Path(assembly["publication_receipt"]["path"]).read_bytes())
        self.assertEqual(assembly["implementation_baseline"], published["head"])
        for name in ("trial_native.mjs", "trial_native_probe.mjs", "test_trial_native_api.py", "__main__.py"):
            relative = "tools/orchestration_eval/" + name
            self.assertEqual(digest(WORKTREE / relative), assembly["source_files"][relative]["sha256"])

    def test_explicit_reason_and_automatic_context_reach_real_ledger_unchanged(self):
        requirements = {"abi": "Review the declared source ABI.", "ownership": "Review the source ownership boundary."}

        def configure(fixture):
            for specification in fixture.config["verification"].values():
                specification["judgment_requirements"] = requirements

        fixture = WorkflowFixture(mechanical=True, configure=configure)
        fixture.start()
        fixture.capture()
        action = fixture.admit()
        result = fixture.validation_result()
        coverage = result["coverage"]
        for criterion in requirements:
            coverage["unresolved"][criterion]["reason"] = "Automatic unresolved " + criterion
        apply_judgment_requirements(fixture.config["acceptance_policy"], requirements,
                                   coverage["covered"], coverage["unresolved"])
        for criterion, reason in requirements.items():
            self.assertEqual(coverage["unresolved"][criterion]["reason"], reason)
            self.assertEqual(coverage["unresolved"][criterion]["context"], "Automatic unresolved " + criterion)
        fixture.complete(action, result)
        ready = fixture.ledger.trial_readiness("trial-0")
        self.assertEqual(ready["kind"], "prepare_review")
        self.assertEqual(ready["binding"]["unresolved_criteria"], coverage["unresolved"])

    def test_reuse_rehashes_real_retained_receipts_outputs_and_verification_specification(self):
        specification = {"recipe": {"compiler": "fixture-fixed"}, "selection": {
            "object": "candidate.o", "fallback_object": "original.o", "link_output": "binary-0.rel"},
            "binary_hashes": self.expected}
        receipt = self.root / "native-check.json"
        raw = b'{"fixture":"retained-native-check","qualification":"not a real compile receipt"}'
        receipt.write_bytes(raw)
        previous = {"verification_spec_identity": content_identity(specification),
                    "check_identities": {str(receipt): file_identity(receipt)},
                    "output_identities": verification_outputs(self.root, specification)}
        witness = reusable_evidence(previous, self.root, specification, self.root)
        self.assertEqual(witness["identities"], previous["check_identities"])
        self.assertEqual(witness["output_identities"], previous["output_identities"])
        receipt.write_bytes(raw + b"\n")
        self.assertIsNone(reusable_evidence(previous, self.root, specification, self.root))
        receipt.write_bytes(raw)
        changed = dict(specification, recipe={"compiler": "changed"})
        self.assertIsNone(reusable_evidence(previous, self.root, changed, self.root))
        candidate_raw = self.candidate.read_bytes()
        self.candidate.write_bytes(candidate_raw + b"changed")
        self.assertIsNone(reusable_evidence(previous, self.root, specification, self.root))
        self.candidate.write_bytes(candidate_raw)
        (self.root / "binary-42.rel").write_bytes(b"changed native output")
        self.assertIsNone(reusable_evidence(previous, self.root, specification, self.root))
