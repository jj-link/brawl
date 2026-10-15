"""Explicitly authorized native infrastructure probe, never a function/child trial."""
from __future__ import annotations

import json
import os
from pathlib import Path
import re
import time
import unittest

from .runtime import EvaluationRuntime
from .safety import WORKTREE, SafetyError, confined, digest, save_json
from .state import Ledger
from .trial_rpc import NATIVE_OMP, NATIVE_OMP_VERSION, TrialRpc, validate_runtime_identity
from .trial_identity import journal_header, native_process_identity


@unittest.skipUnless(os.environ.get("OMP_EVAL_NATIVE_API_PROBE") == "infrastructure-only",
                     "Separate native API infrastructure authorization required")
class NativeApiTests(unittest.TestCase):
    def test_actual_native_hook_semantics_without_provider_or_child_dispatch(self):
        if os.environ.get("OMP_EVAL_NATIVE_API_PROBE_MODE", "original") != "original":
            self.skipTest("Original native API scenarios are outside this changed-boundary authorization")
        self.run_probe("original")

    def test_native_title_prefix_and_late_payload_abort(self):
        if os.environ.get("OMP_EVAL_NATIVE_API_PROBE_MODE") != "late-boundaries":
            self.skipTest("Late-boundary native scenarios require their exact authorized selector")
        self.run_probe("late-boundaries")

    def test_production_workflow_adapter_startup_without_dispatch(self):
        if os.environ.get("OMP_EVAL_NATIVE_API_PROBE_MODE") != "workflow-startup":
            self.skipTest("Production workflow startup requires its exact infrastructure selector")
        self.run_probe("workflow-startup")

    def run_probe(self, mode):
        run = confined(Path(os.environ["OMP_EVAL_NATIVE_API_PROBE_ROOT"]))
        root = confined(run / "native-api-infrastructure")
        root.mkdir()
        expected_path = confined(Path(os.environ["OMP_EVAL_NATIVE_API_PROBE_IDENTITY"]), run)
        approved = json.loads(expected_path.read_text(encoding="utf-8"))
        validate_runtime_identity(NATIVE_OMP, approved, require_version_receipt=False)
        ledger = Ledger(root / "ledger.sqlite3")
        revision = ledger.authorize("RUN", event_id="native-api-only", expected_revision=0,
                                   reason="Approved isolated native API infrastructure; no assignment/provider")['revision']
        runtime = EvaluationRuntime(root, ledger)
        rpc = None
        try:
            version = runtime.manager.launch([str(NATIVE_OMP), "--version"], kind="native-version-metadata",
                                             cwd=root, authorization_revision=revision)
            runtime.register_process(version, revision)
            self.assertEqual(version.process.wait(timeout=15), 0)
            version.stop(grace=0)
            version_logs = Path(version.record["record_path"]).parent
            version_text = (version_logs / "stdout.log").read_text(encoding="utf-8")
            save_json(root / "native-version.json", {"expected": approved["omp"], "stdout": version_text,
                "stderr": (version_logs / "stderr.log").read_text(encoding="utf-8"), "process": version.record})
            self.assertRegex(version_text, r"\b" + re.escape(NATIVE_OMP_VERSION) + r"\b")
            approved["omp"]["version_receipt"] = {"path": str(root / "native-version.json"),
                                                   "sha256": digest(root / "native-version.json")}
            # Hashes and the actual version are checked before the RPC process.
            validate_runtime_identity(NATIVE_OMP, approved)
            sessions = root / "sessions"
            sessions.mkdir()
            config = root / "config.yml"
            save_json(config, {
                "autoResume": False, "autoTitle": False, "enabledProviders": [],
                "disabledProviders": ["native", "claude", "codex", "gemini", "github", "opencode", "cursor", "agents-md"],
                "providers": {"cacheWarming": "off"}, "telemetry": {"otlpExportEnabled": False},
                "advisor": {"enabled": False}, "memory": {"enabled": False, "backend": "off"},
                "compaction": {"enabled": False}, "completion": {"enabled": False},
                "plan": {"defaultOnStartup": False}, "retry": {"enabled": False, "maxRetries": 0, "modelFallback": False},
                "modelRoles": {name: "native-api-disabled/no-model" for name in ("tiny", "commit", "smol")},
            })
            adapter = WORKTREE / "tools/orchestration_eval/trial_native.mjs"
            probe = WORKTREE / "tools/orchestration_eval/trial_native_probe.mjs"
            gate = WORKTREE / "tools/orchestration_eval/trial_gate.mjs"
            spec_path = root / "api-probe-spec.json"
            save_json(spec_path, {"root": str(root), "adapter": str(adapter), "adapter_sha256": digest(adapter),
                                  "probe_sha256": digest(probe), "expected_runtime": approved,
                                  "gate": str(gate), "gate_sha256": digest(gate), "mode": mode})
            runtime.environment.update(OMP_NATIVE_API_PROBE_SPEC=str(spec_path),
                                       OMP_NATIVE_API_PROBE_SHA256=digest(spec_path))
            argv = [str(NATIVE_OMP), "--mode", "rpc", "--no-ui",
                    *([] if mode == "workflow-startup" else ["--no-tools"]), "--no-extensions", "--no-title",
                    "--no-skills", "--no-rules", "--no-lsp", "--no-pty", "--config", str(config),
                    "--cwd", str(root), "--session-dir", str(sessions), "--extension", str(probe),
                    "--model", "openai/gpt-4o-mini"]
            owned = runtime.manager.launch(argv, kind="native-api-control-only", cwd=root, pipe=True,
                                           authorization_revision=revision)
            runtime.register_process(owned, revision)
            rpc = TrialRpc(owned, root)
            rpc.wait_ready(timeout=45)
            complete = root / "native-api-result.complete"
            deadline = time.monotonic() + 30
            while not complete.exists():
                if rpc.failure:
                    raise rpc.failure
                self.assertIsNone(owned.process.poll(), "Native probe exited without a complete result")
                self.assertLess(time.monotonic(), deadline, "Native API probe did not complete")
                time.sleep(0.02)
            result = json.loads((root / "native-api-result.json").read_text(encoding="utf-8"))
            self.assertTrue(result["success"], result)
            state = rpc.request("get_state")
            save_json(root / "native-api-root-state.json", state)
            child = json.loads((Path(owned.record["record_path"]).parent / "child.json").read_text(encoding="utf-8"))
            self.assertEqual(result["root"]["pid"], child["pid"])
            self.assertEqual(state["sessionId"], result["root"]["uuid"])
            self.assertEqual(state.get("messageCount", 0), 0)
            self.assertEqual(result["external_requests_forwarded"], 0)
            if mode == "original":
                self.assertEqual(result["denied_fetch_entries"], 0)
            self.assertEqual(result["children_dispatched"], 0)
            self.assertEqual(result["observer_imports"], 0)
            cases = result["cases"]
            if mode == "workflow-startup":
                startup = cases["production_workflow_startup"]
                self.assertEqual(startup["root_credential_checkpoints"], 0)
                self.assertEqual(result["denied_fetch_entries"], 0)
                self.assertEqual(startup["ready"]["root_session_id"], result["root"]["uuid"])
                self.assertEqual(startup["ready"]["pid"], child["pid"])
                self.assertEqual({row["name"] for row in startup["ready"]["tools"] if row["available"]}, {"task", "write"})
                self.assertTrue(startup["ready"]["enforceable_guard"])
                header = journal_header(confined(Path(startup["ready"]["root_journal"]), sessions))
                self.assertEqual(header["id"], result["root"]["uuid"])
                self.assertEqual(Path(header["cwd"]), root)
                identity = native_process_identity(owned, child["pid"], NATIVE_OMP)
                self.assertEqual(identity["pid"], child["pid"])
                self.assertTrue(identity["creation_time"].isdigit())
                self.assertNotEqual(identity["pid"], owned.record["pid"])
                with self.assertRaises(SafetyError):
                    native_process_identity(owned, child["pid"], NATIVE_OMP, expected_creation="0")
                with self.assertRaises(SafetyError):
                    native_process_identity(owned, child["pid"], Path("not-the-native-executable.exe"))
                save_json(root / "actual-native-process-identity.json", {
                    "identity": identity, "wrapper": owned.record, "wrong_creation_refused": True,
                    "wrong_executable_refused": True, "registry_or_observer_writes": 0})
                return
            if mode == "late-boundaries":
                journal = confined(Path(result["root"]["journal"]), sessions)
                with journal.open("rb") as stream:
                    prefix = stream.readline(65537) + stream.readline(65537)
                save_json(root / "actual-native-journal-prefix.json",
                          {"journal": str(journal), "prefix_utf8": prefix.decode("utf-8"),
                           "root_uuid": result["root"]["uuid"], "source": result["journal_source"]})
                with self.subTest(boundary="actual-native-title-prefix"):
                    header = journal_header(journal)
                    self.assertEqual(header["id"], result["root"]["uuid"])
                    self.assertEqual(Path(header["cwd"]), root)
                for name in ("late_stop", "late_revision", "diagnostic_failure"):
                    with self.subTest(boundary=name):
                        case = cases[name]
                        self.assertFalse(case["timed_out"], case)
                        self.assertEqual(case["credentials"], 1, case)
                        self.assertEqual(case["payloads"], 1, case)
                        self.assertGreaterEqual(case["aborts"], 1, case)
                        self.assertEqual(case["denied_fetches"], [], case)
                        self.assertLess(case["order"].index("credential-resolved"),
                                        case["order"].index("native-onPayload"))
                        self.assertLess(case["order"].index("late-boundary-changed"),
                                        case["order"].index("native-agent-abort"))
                        self.assertEqual(case["api"], "openai-completions")
                return
            self.assertTrue(cases["production_before_provider_root_refusal"]["returned_unchanged_payload"])
            self.assertEqual(len(cases["production_before_provider_root_refusal"]["errors"]), 1)
            self.assertTrue(cases["session_start_failure"]["returned_normally"])
            self.assertEqual(len(cases["session_start_failure"]["errors"]), 1)
            for name in ("premodel_stop", "premodel_throw", "held_abort"):
                self.assertEqual(cases[name]["credential_checkpoints"], 0, cases[name])
            self.assertEqual(cases["wait_without_revalidation"]["credential_checkpoints"], 1)
            self.assertTrue(cases["production_root_auth_denial"]["rejected"])
            for name in ("production_root_auth_denial", "production_guard_unready",
                         "production_guard_foreign_model", "production_guard_revoked_after_wait",
                         "production_guard_auth_recheck"):
                self.assertEqual(cases[name]["credential_checkpoints"], 0, cases[name])
            self.assertEqual(cases["production_guard_admitted_checkpoint"]["credential_checkpoints"], 1)
        finally:
            if rpc is not None:
                rpc.closing = True
            final = runtime.stop(event_id="native-api-stop", reason="End isolated API probe; prove owned native exit")
            save_json(root / "native-api-final.json", {"authorization": final, "processes": runtime.manager.records()})
            self.assertEqual(final["mode"], "STOPPED")
            self.assertTrue(all(row.get("exit_proof", {}).get("observed_exit") for row in runtime.manager.records()))
