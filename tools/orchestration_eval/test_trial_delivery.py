"""Concrete local file-boundary tests, not native/provider acceptance evidence."""
import copy
import hashlib
import json
import os
from pathlib import Path
import unittest
import uuid

from .evidence import capture_inputs, file_identity
from .safety import WORKTREE
from .trial_delivery import (DeliveryError, WorkerDelivery, observe_delivery,
                             validate_delivery_files, verify_binary_hashes)


@unittest.skipUnless(os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned behavioral verification required")
class WorkerDeliveryTests(unittest.TestCase):
    def setUp(self):
        self.root = WORKTREE / "build/orchestration-eval/tests/automatic-delivery" / uuid.uuid4().hex
        self.root.mkdir(parents=True)
        self.source = "src/worker.cpp"
        for name, text in ((self.source, "int value() { return 1; }\n"),
                           ("configure.py", "objects = ['worker.cpp']\n"),
                           ("config/splits.txt", "worker.cpp: .text start:0xE228 end:0xE230\n")):
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(text, encoding="utf-8", newline="\n")
        inputs = capture_inputs(self.root, {"source": [self.source], "config": ["configure.py", "config/splits.txt"],
                                           "header": [], "tool": []}, {"scope": "synthetic file-boundary fixture"})
        artifacts = {}
        for name in ("compile", "object_compare", "data_relocations", "source_link", "binary_hashes", "progress"):
            path = self.root / "evidence" / (name + ".json")
            path.parent.mkdir(exist_ok=True)
            path.write_text(json.dumps({"fixture": name}), encoding="utf-8")
            artifacts[name] = {"path": path.relative_to(self.root).as_posix(), "identity": file_identity(path)}
        changes = {}
        for name in inputs.paths:
            data = (self.root / name).read_bytes()
            blob = hashlib.sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()
            changes[name] = {"before": None, "after": {"mode": "100644", "blob": blob},
                             "raw": file_identity(self.root / name)}
        self.payload = {"schema": 1, "assignment_id": "fn_117_E228", "owner_id": "OwnerE228",
                        "session_id": "synthetic-session", "manifest_digest": "a" * 64,
                        "candidate_id": "measured-candidate", "inputs": inputs.to_dict(),
                        "changes": changes, "artifacts": artifacts,
                        "logical_units": [{"message": "Reconstruct reserved function", "paths": list(changes)}],
                        "cleanup": []}
        self.assignment = {"assignment_id": self.payload["assignment_id"], "owner_id": self.payload["owner_id"],
                           "session_id": self.payload["session_id"],
                           "identity": {"reservation": {"owned_paths": list(changes)}},
                           "stages": [{"candidates": {"measured-candidate": {"input_identity": inputs.identity}}}]}
        self.event = {"kind": "owner_turn_end", "will_continue": False,
                      "registry_id": self.payload["owner_id"], "session_id": self.payload["session_id"]}
        self.path = self.root / "evidence/delivery.json"
        self.path.write_text(json.dumps(self.payload), encoding="utf-8")

    def observe(self, **overrides):
        return observe_delivery(self.root, "evidence/delivery.json", assignment=self.assignment,
                                manifest_digest=self.payload["manifest_digest"],
                                native_event=self.event | overrides, archive_directory=self.root / "captured-raw")

    def test_actual_files_bind_delivery_and_reject_later_source_drift(self):
        delivery, captured = self.observe()
        self.assertEqual(captured["sha256"], file_identity(self.path)["sha256"])
        first = validate_delivery_files(self.root, delivery)
        self.assertEqual(first["input_identity"], self.payload["inputs"]["identity"])
        (self.root / self.source).write_text("int value() { return 2; }\n", encoding="utf-8")
        with self.assertRaises(DeliveryError):
            validate_delivery_files(self.root, delivery)

    def test_reconciliation_preserves_original_raw_delivery_not_mutable_inbox(self):
        first_raw = self.path.read_bytes()
        first, captured = self.observe()
        self.path.write_text(json.dumps(self.payload, indent=2) + "\n", encoding="utf-8")
        second, later = self.observe()
        self.assertEqual(first.delivery_id, second.delivery_id)
        self.assertNotEqual(captured["path"], later["path"])
        self.assertEqual(Path(captured["path"]).read_bytes(), first_raw)
        self.assertEqual(Path(later["path"]).read_bytes(), self.path.read_bytes())
        from .trial_cleanup import retained_files
        retained = retained_files(self.root, self.assignment, {
            "first": {"delivery": first.payload, "record": captured},
            "second": {"delivery": second.payload, "record": later}},
            {"workspace_inputs": []})
        self.assertTrue({captured["path"], later["path"], str(self.path)}.issubset(
            {row["path"] for row in retained}))

    def test_worker_file_does_not_replace_genuine_native_owner_boundary(self):
        for values in ({"registry_id": "other"}, {"session_id": "other"},
                       {"will_continue": True}, {"kind": "coordinator_approval"}):
            with self.subTest(values=values), self.assertRaises(DeliveryError):
                self.observe(**values)

    def test_extra_source_or_foreign_measured_inputs_cannot_enter_review(self):
        self.assignment["identity"]["reservation"]["owned_paths"].remove(self.source)
        with self.assertRaises(DeliveryError):
            self.observe()
        self.assignment["identity"]["reservation"]["owned_paths"].append(self.source)
        self.assignment["stages"][0]["candidates"]["measured-candidate"]["input_identity"] = "f" * 64
        with self.assertRaises(DeliveryError):
            self.observe()

    def test_logical_commits_cannot_duplicate_or_drop_a_delivered_path(self):
        for paths in ([self.source], list(self.payload["changes"]) + [self.source]):
            payload = copy.deepcopy(self.payload)
            payload["logical_units"][0]["paths"] = paths
            with self.subTest(paths=paths), self.assertRaises(DeliveryError):
                WorkerDelivery.from_dict(payload)

    def test_cleanup_cannot_include_verified_source_or_retained_artifact(self):
        for path in (self.source, self.payload["artifacts"]["compile"]["path"]):
            payload = copy.deepcopy(self.payload)
            payload["cleanup"] = [{"path": path, "identity": file_identity(self.root / path)}]
            with self.subTest(path=path), self.assertRaises(DeliveryError):
                WorkerDelivery.from_dict(payload)

    def test_evidence_byte_changes_invalidate_prepared_delivery(self):
        delivery, _ = self.observe()
        path = self.root / self.payload["artifacts"]["object_compare"]["path"]
        path.write_text("changed", encoding="utf-8")
        with self.assertRaises(DeliveryError):
            validate_delivery_files(self.root, delivery)

    def test_all_127_binary_contents_are_checked_not_a_claimed_count(self):
        expected = {}
        for index in range(127):
            path = self.root / "build" / (str(index) + ".bin")
            path.parent.mkdir(exist_ok=True)
            data = bytes([index])
            path.write_bytes(data)
            expected[path.relative_to(self.root).as_posix()] = hashlib.sha1(data).hexdigest()
        self.assertEqual(len(verify_binary_hashes(self.root, expected)), 127)
        (self.root / "build/126.bin").write_bytes(b"changed")
        with self.assertRaises(DeliveryError):
            verify_binary_hashes(self.root, expected)
        expected.pop("build/126.bin")
        with self.assertRaises(DeliveryError):
            verify_binary_hashes(self.root, expected)

    def test_cleanup_preflight_rejects_future_required_outputs_and_old_drafts(self):
        from .safety import SafetyError
        from .trial_cleanup import delivery_plan
        specification = {"workspace_inputs": [], "binary_hashes": {},
            "selection": {"source": self.source, "object": "build/candidate.o",
                          "link_output": "build/native.rel", "fallback_object": "build/original.o"}}
        for name in ("build/candidate.o", "drafts/preserved-best.cpp"):
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(b"required retained bytes")
            if name.startswith("drafts/"):
                self.assignment["stages"][0]["candidates"]["measured-candidate"]["source_ref"] = {
                    "path": str(path), "sha256": file_identity(path)["sha256"]}
            payload = copy.deepcopy(self.payload)
            payload["cleanup"] = [{"path": name, "identity": file_identity(path)}]
            delivery = WorkerDelivery.from_dict(payload)
            with self.subTest(name=name), self.assertRaises(SafetyError):
                delivery_plan(self.root, self.assignment, {}, specification, delivery, {})

    def test_invalid_delivery_preserves_exact_raw_bytes_before_parsing(self):
        raw = b'{"schema": 1, "unfinished":'
        self.path.write_bytes(raw)
        with self.assertRaises(ValueError):
            self.observe()
        archives = list((self.root / "captured-raw").glob("*.json"))
        self.assertEqual(len(archives), 1, "Malformed owner output was discarded instead of retained")
        self.assertEqual(archives[0].read_bytes(), raw)

    def test_binary_coverage_rejects_case_aliases_as_distinct_native_outputs(self):
        expected = {}
        for index in range(126):
            path = self.root / "build" / (str(index) + ".bin")
            path.parent.mkdir(exist_ok=True)
            path.write_bytes(bytes([index]))
            expected[path.relative_to(self.root).as_posix()] = hashlib.sha1(path.read_bytes()).hexdigest()
        expected["BUILD/0.BIN"] = expected["build/0.bin"]
        self.assertEqual(len(expected), 127)
        with self.assertRaises(DeliveryError):
            verify_binary_hashes(self.root, expected)
