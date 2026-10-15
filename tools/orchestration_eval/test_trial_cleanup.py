"""Owned Windows fixtures for the historical junction deletion failure boundary."""
import json
import os
from pathlib import Path
import subprocess
import unittest
import uuid

from unittest.mock import patch

from .evidence import InputError, file_identity
from .safety import BUILD, SafetyError, digest, save_json
from .trial_cleanup import delete_exact_file, execute_plan, validate_plan


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned Windows cleanup verification required")
class TrialCleanupTests(unittest.TestCase):
    def setUp(self):
        self.root = BUILD / "tests/trial-cleanup" / uuid.uuid4().hex
        self.workspace = self.root / "workspace"
        self.workspace.mkdir(parents=True)
        self.retained = self.root / "retained-original.bin"
        self.retained.write_bytes(b"owned original fixture, never shared originals")
        self.tracked = self.workspace / "source.cpp"
        self.tracked.write_bytes(b"int value() { return 1; }\n")
        self.disposable = self.workspace / "scratch/disposable.bin"
        self.disposable.parent.mkdir()
        self.disposable.write_bytes(b"temporary owned output")
        self.plan = {"workspace": str(self.workspace),
            "retained": [{"path": str(self.retained), "resolved_path": str(self.retained.resolve()),
                          "identity": file_identity(self.retained)}],
            "tracked": {"source.cpp": file_identity(self.tracked)},
            "files": [{"path": "scratch/disposable.bin", "identity": file_identity(self.disposable)}]}

    def junction(self, path, target):
        result = subprocess.run(["cmd.exe", "/d", "/c", "mklink", "/J", str(path), str(target)],
                                capture_output=True, timeout=15)
        (self.root / (path.name + "-junction.stdout")).write_bytes(result.stdout)
        (self.root / (path.name + "-junction.stderr")).write_bytes(result.stderr)
        self.assertEqual(result.returncode, 0, result.stderr.decode(errors="replace"))

    def test_actual_handle_deletes_only_exact_disposable_and_never_prunes(self):
        protected = validate_plan(self.plan)
        parent_identity = self.disposable.parent.stat().st_ino
        delete_exact_file(self.disposable, self.plan["files"][0]["identity"], protected)
        self.assertFalse(self.disposable.exists())
        self.assertTrue(self.disposable.parent.is_dir())
        self.assertEqual(self.disposable.parent.stat().st_ino, parent_identity)
        self.assertEqual(file_identity(self.retained), self.plan["retained"][0]["identity"])
        self.assertEqual(file_identity(self.tracked), self.plan["tracked"]["source.cpp"])

    def test_changed_bytes_after_validation_are_not_deleted(self):
        protected = validate_plan(self.plan)
        self.disposable.write_bytes(b"new bytes after approval")
        with self.assertRaises(SafetyError):
            delete_exact_file(self.disposable, self.plan["files"][0]["identity"], protected)
        self.assertEqual(self.disposable.read_bytes(), b"new bytes after approval")

    def test_hardlink_added_after_validation_is_rejected(self):
        protected = validate_plan(self.plan)
        alias = self.root / "retained-new-alias.bin"
        os.link(self.disposable, alias)
        with self.assertRaises(InputError):
            delete_exact_file(self.disposable, self.plan["files"][0]["identity"], protected)
        self.assertEqual(file_identity(alias), self.plan["files"][0]["identity"])
        self.assertTrue(self.disposable.exists())

    def test_junction_swap_after_validation_does_not_follow_original(self):
        protected = validate_plan(self.plan)
        original = self.root / "owned-originals"
        original.mkdir()
        original_file = original / "disposable.bin"
        original_file.write_bytes(self.disposable.read_bytes())
        original_identity = file_identity(original_file)
        self.disposable.parent.rename(self.workspace / "preserved-scratch")
        self.junction(self.workspace / "scratch", original)
        with self.assertRaises(InputError):
            delete_exact_file(self.disposable, self.plan["files"][0]["identity"], protected)
        with self.assertRaises(InputError):
            validate_plan(self.plan)
        self.assertEqual(file_identity(original_file), original_identity)
        self.assertTrue((self.workspace / "preserved-scratch/disposable.bin").exists())
        self.assertTrue(original.is_dir())

    def test_retained_inode_alias_is_rejected_before_deletion(self):
        alias = self.workspace / "scratch/alias.bin"
        os.link(self.retained, alias)
        self.plan["files"] = [{"path": "scratch/alias.bin", "identity": file_identity(alias)}]
        with self.assertRaises(InputError):
            validate_plan(self.plan)
        self.assertTrue(alias.exists())
        self.assertEqual(file_identity(self.retained), self.plan["retained"][0]["identity"])

    def test_native_handle_rejects_junction_changed_after_lexical_check(self):
        from . import trial_cleanup
        protected = validate_plan(self.plan)
        original = self.root / "owned-originals"
        original.mkdir()
        original_file = original / "disposable.bin"
        original_file.write_bytes(self.disposable.read_bytes())
        before = file_identity(original_file)
        checked = trial_cleanup.reject_links
        def replace_after_check(path):
            checked(path)
            self.disposable.parent.rename(self.workspace / "preserved-scratch")
            self.junction(self.workspace / "scratch", original)
        with patch.object(trial_cleanup, "reject_links", side_effect=replace_after_check):
            with self.assertRaises(SafetyError):
                delete_exact_file(self.disposable, self.plan["files"][0]["identity"], protected)
        self.assertEqual(file_identity(original_file), before)
        self.assertTrue((self.workspace / "preserved-scratch/disposable.bin").exists())

    def test_stop_between_plan_creation_and_execution_preserves_all_files(self):
        from .test_state import WorkflowFixture
        fixture = WorkflowFixture()
        fixture.start()
        packet = fixture.packet()
        packet["cleanup"] = self.plan["files"]
        fixture.reviewed(packet=packet)
        fixture.materialize()
        fixture.publish()
        action = fixture.admit()
        self.assertEqual(action["kind"], "cleanup")
        self.plan.update(ledger_path=str(fixture.ledger.path), effect_id=action["effect_id"],
                         authorization_revision=action["authorization_revision"], binding=action["binding"])
        path = self.root / "cleanup-plan.json"
        save_json(path, self.plan)
        fixture.ledger.request_stop(event_id="stop-before-cleanup", reason="Owned STOP boundary regression")
        with self.assertRaises((SafetyError, RuntimeError, ValueError)):
            execute_plan(str(path), digest(path))
        self.assertEqual(file_identity(self.disposable), self.plan["files"][0]["identity"])
        self.assertFalse((self.root / "cleanup-effects.jsonl").exists())
