"""Reviewed pure file/ledger boundaries; no native agent or provider execution."""
from __future__ import annotations

import hashlib
import importlib.metadata
import json
import os
from pathlib import Path
import sys
from types import SimpleNamespace
import unittest
from unittest.mock import patch
import uuid

from . import trial_rpc
from .policy import SlotPolicy
from .safety import BUILD, SafetyError, confined, now
from .state import Ledger, StateError
from .trial import recover, submit
from .trial_authority import validate_approval
from .trial_runtime import TrialRuntime
from .test_state import trial_manifest


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned verification required")
class TrialReviewTests(unittest.TestCase):
    def setUp(self):
        self.root = confined(BUILD / "tests/trial-review" / uuid.uuid4().hex)
        self.manifest = trial_manifest(self.root)
        self.recovered = self.manifest["reservations"][4]["history"]
        self.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending"]}
        self.ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
        self.trial = self.ledger.register_trial(manifest=self.manifest, event_id="manifest")
        self.revision = self.ledger.authorize("RUN", event_id="run", expected_revision=0,
                                             reason="Pure synthetic review boundary")['revision']
        self.runtime = TrialRuntime(self.root, self.ledger, Path("unused-native.exe"), {})

    def envelope(self):
        return {"event_id": "history-delivery", "operation": "history", "assignment_id": "trial-4",
                "manifest_digest": self.trial["manifest_digest"], "payload": {"history": self.recovered,
                    "record": {"assignment_id": "trial-4", "manifest_digest": self.trial["manifest_digest"],
                               "observed_by": "coordinator", "observed_at": now(),
                               "timestamp_provenance": {"source": "synthetic-review-test", "clock_id": "host-utc"},
                               "evidence_refs": ["synthetic-complete-history"]}}}

    def test_direct_inbox_content_has_no_coordinator_authority(self):
        envelope = self.envelope()
        inbox = self.root / "inbox"
        inbox.mkdir()
        path = inbox / "history-delivery.json"
        path.write_text(json.dumps(envelope, sort_keys=True) + "\n", encoding="utf-8")
        with self.assertRaises((SafetyError, StateError)):
            self.runtime.handle(json.loads(path.read_text(encoding="utf-8")))
        self.assertEqual(self.ledger.trial_history("trial-4")["status"], "unknown")
        self.assertEqual(self.ledger.snapshot()["trial"]["effects"], {})

    def test_in_place_rewrite_cannot_reuse_coordinator_delivery_admission(self):
        envelope = self.envelope()
        admitted = submit(self.root, envelope)
        envelope["payload"]["record"]["evidence_refs"] = ["not-the-admitted-content"]
        path = Path(admitted["path"])
        path.write_text(json.dumps(envelope, sort_keys=True) + "\n", encoding="utf-8")
        with self.assertRaises((SafetyError, StateError)):
            self.runtime.handle(json.loads(path.read_text(encoding="utf-8")))
        self.assertEqual(self.ledger.trial_history("trial-4")["status"], "unknown")

    def test_recovery_stop_does_not_depend_on_advisory_marker_enumeration(self):
        original = Path.glob
        def broken_marker_glob(path, pattern, *args, **kwargs):
            if path == self.root / "native":
                raise OSError("Injected unavailable advisory marker filesystem")
            return original(path, pattern, *args, **kwargs)
        with patch.object(Path, "glob", broken_marker_glob):
            try:
                recover(self.root, "Exact-run STOP with inaccessible marker directory")
            except OSError:
                pass
        self.assertEqual(self.ledger.authorization()["mode"], "STOPPED")

    def test_inprocess_stop_does_not_depend_on_advisory_marker_write(self):
        directory = self.root / "native/marker-only-fixture"
        directory.mkdir(parents=True)
        # File-fault fixture only: no native session or process is invented.
        self.runtime.roots["marker-only-fixture"] = SimpleNamespace(directory=directory, closing=False)
        original = Path.write_text
        def broken_marker_write(path, *args, **kwargs):
            if path == directory / "STOP":
                raise OSError("Injected unavailable advisory marker write")
            return original(path, *args, **kwargs)
        with patch.object(Path, "write_text", broken_marker_write):
            try:
                self.runtime.stop(event_id="review-stop", reason="Bounded native cancellation precedes advisory IO")
            except OSError:
                pass
        self.assertEqual(self.ledger.authorization()["mode"], "STOPPED")

    def test_occupied_workspace_is_rejected_before_assignment_launch_effect(self):
        gates = {"manifest_digest": self.trial["manifest_digest"], "confirmed_by": "coordinator",
                 "coordinator_ref": "synthetic", "execution_ref": "synthetic", "dashboard_ref": "synthetic",
                 "evidence_refs": ["synthetic"]}
        self.ledger.prepare_trial(gates=gates, event_id="prepare", authorization_revision=self.revision)
        self.ledger.claim_trial_initial(claims=[{"assignment_id": f"trial-{i}", "owner_id": f"owner-{i}",
            "root_session_id": f"root-{i}", "slot": i} for i in range(4)], event_id="claims",
            authorization_revision=self.revision)
        occupied = Path(self.manifest["reservations"][0]["workspace"])
        occupied.mkdir(parents=True)
        sentinel = occupied / "foreign-owner.txt"
        sentinel.write_text("must remain untouched", encoding="utf-8")
        try:
            self.runtime.start_assignment("trial-0")
        except Exception:
            pass
        self.assertEqual(self.ledger.snapshot()["trial"]["effects"], {},
                         "Occupied worktree must be refused before native-child launch admission")
        self.assertEqual(sentinel.read_text(encoding="utf-8"), "must remain untouched")

    def test_runtime_identity_validation_is_fail_closed_on_wrong_executable(self):
        impostor = self.root / "omp.exe"
        impostor.write_bytes(b"not an authorized native executable")
        with self.assertRaises(SafetyError):
            trial_rpc.validate_runtime_identity(impostor, {"omp": {"path": str(impostor), "sha256": "0" * 64,
                                                                  "version": "18.10.1"}})

    def test_runtime_identity_validation_is_fail_closed_on_wrong_python(self):
        with self.assertRaises(SafetyError):
            trial_rpc.validate_runtime_identity(Path("C:/Users/josep/AppData/Local/omp/omp.exe"),
                {"python": {"path": str(self.root / "foreign-python.exe"), "sha256": "0" * 64,
                            "version": sys.version.split()[0]},
                 "prefect": {"version": importlib.metadata.version("prefect")}})

    def approval_fixture(self):
        contract = {key: {"synthetic_identity": key} for key in
                    ("runtime", "observer", "agent_definition", "session_directory", "session_store_grant_ref",
                     "preparation_grant_ref", "configuration_sha256", "model_definition",
                     "workflow_config", "review_model_definition", "registration")}
        fields = ("assignment_id", "workspace", "baseline_commit", "instruction_revision", "input_identity",
                  "recipe_ref", "owned_paths", "function")
        packet = dict(contract, schema="brawl-qwen-trial-approval/v2",
                      coordinator_id=self.manifest["coordinator_id"], execution=self.manifest["execution"],
                      manifest_digest=self.trial["manifest_digest"],
                      reservations=[{key: row[key] for key in fields} for row in self.manifest["reservations"]])
        path = self.root / "approval.json"
        raw = json.dumps(packet, sort_keys=True).encode()
        path.write_bytes(raw)
        contract["approval_packet"] = {"path": str(path), "sha256": hashlib.sha256(raw).hexdigest()}
        return contract, path

    def test_approval_binds_actual_packet_not_hardcoded_engineering_revision(self):
        contract, path = self.approval_fixture()
        observed = validate_approval(self.manifest, contract)
        self.assertEqual(observed["raw_utf8"], path.read_text())
        changed = json.loads(json.dumps(self.manifest))
        changed["reservations"][0]["instruction_revision"] = "c" * 40
        with self.assertRaises(SafetyError):
            validate_approval(changed, contract)
        contract["observer"] = {"synthetic_identity": "different-published-source"}
        with self.assertRaises(SafetyError):
            validate_approval(self.manifest, contract)

    def test_approval_binds_controller_registration_scope(self):
        contract, _ = self.approval_fixture()
        contract["registration"] = {"mode": "unbound-writer"}
        with self.assertRaises(SafetyError):
            validate_approval(self.manifest, contract)

    def test_approval_packet_cannot_be_rewritten_after_its_identity_is_pinned(self):
        contract, path = self.approval_fixture()
        path.write_bytes(path.read_bytes() + b"\n")
        with self.assertRaises(SafetyError):
            validate_approval(self.manifest, contract)

    def test_v1_approval_cannot_bypass_workflow_and_review_binding(self):
        contract, path = self.approval_fixture()
        packet = json.loads(path.read_bytes())
        packet["schema"] = "brawl-qwen-trial-approval/v1"
        raw = json.dumps(packet, sort_keys=True).encode()
        path.write_bytes(raw)
        contract["approval_packet"]["sha256"] = hashlib.sha256(raw).hexdigest()
        with self.assertRaises(SafetyError):
            validate_approval(self.manifest, contract)

    def test_review_profile_and_workflow_are_immutable_approval_inputs(self):
        for field in ("workflow_config", "review_model_definition"):
            contract, path = self.approval_fixture()
            contract[field] = {"synthetic_identity": "unapproved-change"}
            with self.subTest(field=field), self.assertRaises(SafetyError):
                validate_approval(self.manifest, contract)
