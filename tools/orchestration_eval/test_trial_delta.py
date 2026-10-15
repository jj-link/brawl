"""Real private Git and Windows-job regressions; no assignment/provider dispatch."""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import sqlite3
import subprocess
import threading
import time
import unittest
from unittest.mock import patch
import uuid
from types import SimpleNamespace

from . import trial_runtime
from .processes import ProcessManager
from .safety import BUILD, SafetyError, confined, isolated_environment, save_json
from .state import Ledger
from .policy import SlotPolicy
from .test_state import trial_manifest
from .test_runtime import held
from .trial import recover
from .trial_runtime import TrialRuntime


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned verification required")
class TrialDeltaTests(unittest.TestCase):
    def setUp(self):
        self.root = confined(BUILD / "delta" / uuid.uuid4().hex[:12])
        self.root.mkdir(parents=True)
        self.environment = isolated_environment(self.root)
        self.runtime = None

    def initialize(self, manifest=None):
        self.manifest = manifest or trial_manifest(self.root)
        self.ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
        self.trial = self.ledger.register_trial(manifest=self.manifest, event_id="manifest")
        self.revision = self.ledger.authorize("RUN", event_id="run", expected_revision=0,
                                             reason="Synthetic delta regression; no assignment dispatch")["revision"]
        self.runtime = TrialRuntime(self.root, self.ledger, Path("never-launch-native.exe"), {"runtime": {}})

    def tearDown(self):
        if self.runtime:
            self.runtime.manager.stop_all()

    def git(self, cwd, *arguments, allowed=(0,)):
        result = subprocess.run(["git", "-C", str(cwd), "-c", "user.name=Owned regression",
                                 "-c", "core.longpaths=true", "-c", "user.email=owned-regression@invalid", *arguments],
                                env=self.environment, capture_output=True, text=True, timeout=20)
        self.assertIn(result.returncode, allowed, result.stderr)
        return result.stdout.strip()

    def dispatch_case(self, mutation):
        main = self.root / "git-main"
        main.mkdir()
        self.git(main, "init")
        (main / "input.txt").write_text("first baseline\n")
        self.git(main, "add", "input.txt")
        self.git(main, "commit", "-m", "Owned fixture baseline")
        baseline = self.git(main, "rev-parse", "HEAD")
        (main / "input.txt").write_text("different baseline\n")
        self.git(main, "add", "input.txt")
        self.git(main, "commit", "-m", "Owned fixture alternative")
        alternative = self.git(main, "rev-parse", "HEAD")
        manifest = trial_manifest(self.root)
        reservation = manifest["reservations"][0]
        workspace = main / "build/isolated-workers" / f"QwenTrial{reservation['function']['start']:X}"
        workspace.parent.mkdir(parents=True)
        self.git(main, "clone", "--no-local", "--no-hardlinks", "--no-checkout", str(main), str(workspace))
        self.git(workspace, "checkout", "--detach", baseline)
        reservation.update(workspace=str(workspace), baseline_commit=baseline)
        self.initialize(manifest)
        gates = {"manifest_digest": self.trial["manifest_digest"], "confirmed_by": "coordinator",
                 "coordinator_ref": "synthetic", "execution_ref": "synthetic", "dashboard_ref": "synthetic",
                 "evidence_refs": ["synthetic"]}
        self.ledger.prepare_trial(gates=gates, event_id="prepare", authorization_revision=self.revision)
        self.ledger.claim_trial_initial(claims=[{"assignment_id": f"trial-{i}", "owner_id": f"owner-{i}",
            "root_session_id": f"root-{i}", "slot": i} for i in range(4)], event_id="claims",
            authorization_revision=self.revision)
        self.runtime.roots["trial-0"] = SimpleNamespace(directory=self.root / "native-contract-only")
        original_inode = workspace.stat().st_ino
        identity = {"directory_identity": original_inode}
        for label, arguments in (
            ("head", ["rev-parse", "HEAD"]),
            ("common", ["rev-parse", "--path-format=absolute", "--git-common-dir"]),
            ("index", ["rev-parse", "--path-format=absolute", "--git-path", "index"]),
            ("gitdir", ["rev-parse", "--absolute-git-dir"]),
            ("toplevel", ["rev-parse", "--show-toplevel"]),
        ):
            identity[label] = self.git(workspace, *arguments)
        identity["branch"] = self.git(workspace, "symbolic-ref", "--quiet", "HEAD", allowed=(1,))
        for label, file in (("config_sha256", workspace / ".git/config"),
                            ("index_sha256", Path(identity["index"]))):
            identity[label] = hashlib.sha256(file.read_bytes()).hexdigest()
        def created_then_changed(*_args):
            if mutation == "head":
                self.git(workspace, "checkout", "--detach", alternative)
            elif mutation == "pointer":
                (workspace / ".git/objects/info/alternates").write_text(
                    str(main / ".git/objects") + "\n", encoding="utf-8")
            else:
                index = Path(identity["index"])
                index.write_bytes(index.read_bytes() + b"changed-private-index")
            self.assertEqual(workspace.stat().st_ino, original_inode)
            save_json(self.root / "dispatch-mutation.json", {"mutation": mutation, "recorded_identity": identity,
                                                            "unchanged_directory_inode": original_inode})
            return identity
        # Substitute only approvals/setup of this private fixture. Native dispatch
        # is a tripwire, never a synthetic native process/session or echo host.
        with patch.object(trial_runtime, "ACTIVE", main), \
             patch.object(trial_runtime, "require_fresh_workspace", return_value=workspace), \
             patch.object(trial_runtime, "validate_approval"), \
             patch.object(trial_runtime, "validate_runtime_identity"), \
             patch.object(self.runtime, "create_workspace", side_effect=created_then_changed), \
             patch.object(self.runtime, "native_command", side_effect=AssertionError("Changed Git identity reached native dispatch")):
            if mutation == "unchanged":
                self.assertEqual(self.runtime.workspace_identity(reservation, self.revision), identity)
                return
            with self.assertRaises(SafetyError):
                self.runtime.start_assignment("trial-0")

    def test_dispatch_rejects_changed_head_in_same_directory(self):
        self.dispatch_case("head")

    def test_dispatch_rejects_foreign_object_store_in_same_directory(self):
        self.dispatch_case("pointer")

    def test_dispatch_rejects_changed_private_index_in_same_directory(self):
        self.dispatch_case("index")

    def test_workspace_identity_accepts_unchanged_real_private_git(self):
        self.dispatch_case("unchanged")

    def cancellation_case(self, boundary):
        self.initialize()
        processes = [held(self.runtime.manager, revision=self.revision) for _ in range(3)]
        for owned in processes:
            self.runtime.register_process(owned, self.revision)
        entered, release, finished = threading.Event(), threading.Event(), threading.Event()
        errors = []
        if boundary == "snapshot":
            original = self.runtime.snapshot
            def blocked(*args, **kwargs):
                entered.set()
                if not release.wait(15):
                    raise TimeoutError("Test did not release optional snapshot")
                return original(*args, **kwargs)
            replacement = patch.object(self.runtime, "snapshot", blocked)
        elif boundary == "setup":
            from . import runtime
            original = runtime.isolated_environment
            def blocked(*args, **kwargs):
                entered.set()
                if not release.wait(15):
                    raise TimeoutError("Test did not release optional recovery setup")
                return original(*args, **kwargs)
            replacement = patch.object(runtime, "isolated_environment", blocked)
        else:
            original = ProcessManager.receipt
            def blocked(manager, *args, **kwargs):
                entered.set()
                if not release.wait(15):
                    raise TimeoutError("Test did not release optional receipt persistence")
                return original(manager, *args, **kwargs)
            replacement = patch.object(ProcessManager, "receipt", blocked)
        def stop():
            try:
                if boundary == "snapshot":
                    self.runtime.stop(event_id="delta-stop", reason="Native cancellation before optional IO")
                else:
                    recover(self.root, "Recover native ownership without optional startup or receipt delays")
            except BaseException as exc:
                errors.append(repr(exc))
            finally:
                finished.set()
        worker = threading.Thread(target=stop, daemon=True)
        with replacement:
            began = time.monotonic()
            worker.start()
            try:
                if boundary != "setup":
                    self.assertTrue(entered.wait(5), "STOP never reached the selected optional IO boundary")
                deadline = began + 5
                for owned in processes:
                    try:
                        owned.process.wait(timeout=max(0, deadline - time.monotonic()))
                    except subprocess.TimeoutExpired:
                        pass
                exits = [owned.process.poll() is not None for owned in processes]
                save_json(self.root / (boundary + "-stop-observation.json"), {
                    "boundary": boundary, "native_exits_while_optional_io_blocked": exits,
                    "optional_io_entered": entered.is_set(), "elapsed_seconds": time.monotonic() - began,
                    "errors_before_release": list(errors)})
                self.assertTrue(all(exits), "Optional snapshot/setup/receipt IO delayed aggregate native cancellation")
                if boundary == "setup":
                    self.assertFalse(entered.is_set(), "Recovery initialized an unnecessary environment")
            finally:
                release.set()
                worker.join(timeout=20)
        self.assertFalse(worker.is_alive(), "Owned STOP thread survived test cleanup")
        self.assertEqual(errors, [])
        self.assertTrue(finished.is_set())
        self.assertEqual(self.ledger.authorization()["mode"], "STOPPED")

    def test_stop_signals_jobs_before_blocked_snapshot(self):
        self.cancellation_case("snapshot")

    def test_recovery_does_not_initialize_optional_environment(self):
        self.cancellation_case("setup")

    def test_recovery_signals_all_jobs_before_first_blocked_receipt(self):
        self.cancellation_case("receipt")

    def test_public_stop_cli_skips_optional_configuration(self):
        from . import trial
        run_id = "realtrial-delta-cli-" + uuid.uuid4().hex[:12]
        self.root = confined(BUILD / "runs" / run_id)
        self.initialize()
        owned = held(self.runtime.manager, revision=self.revision)
        self.runtime.register_process(owned, self.revision)
        with patch.object(trial, "configure", side_effect=AssertionError("STOP attempted optional launch configuration")):
            result = trial.main(["stop", "--run-id", run_id, "--authorize-exact-run-stop"])
        self.assertEqual(result, 0)
        self.assertIsNotNone(owned.process.poll())
        self.assertEqual(self.ledger.authorization()["mode"], "STOPPED")


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned verification required")
class ModelInspectionTests(unittest.TestCase):
    def setUp(self):
        self.root = confined(BUILD / "delta" / uuid.uuid4().hex[:12])
        self.root.mkdir(parents=True)
        self.model = {"id": "Qwen3.8-Flash-Next", "provider": "spark1",
                      "baseUrl": "http://100.86.3.45:8000/v1", "api": "openai-completions",
                      "reasoning": True, "contextWindow": 1048576,
                      "compat": {"supportsReasoningEffort": False, "thinkingFormat": "qwen"}}
        self.provider = {"baseUrl": self.model["baseUrl"], "api": self.model["api"], "auth": "none"}

    def inspect_catalog(self, generations, *, provider=None):
        from . import trial
        directory = self.root / uuid.uuid4().hex[:8]
        directory.mkdir()
        cache, config = directory / "models.db", directory / "models.yml"
        with sqlite3.connect(cache) as connection:
            connection.execute("CREATE TABLE model_cache (provider_id TEXT PRIMARY KEY, models TEXT)")
            connection.executemany("INSERT INTO model_cache VALUES (?, ?)",
                                   [(key, json.dumps(models)) for key, models in generations])
        # JSON is valid YAML; use real config parsing and real read-only SQLite.
        config.write_text(json.dumps({"providers": {"spark1": self.provider if provider is None else provider}}),
                          encoding="utf-8")
        before = {path: path.read_bytes() for path in (cache, config)}
        paths = {"C:/Users/josep/.omp/agent/models.db": cache,
                 "C:/Users/josep/.omp/agent/models.yml": config}
        try:
            # Redirect only the two fixed filesystem inputs, not SQL or parsing.
            with patch.object(trial, "Path", side_effect=paths.__getitem__):
                result = trial.inspect_model()
            self.assertEqual(result["cache_path"], str(cache))
            self.assertEqual(result["configuration_path"], str(config))
            self.assertEqual(result["configuration_sha256"], hashlib.sha256(before[config]).hexdigest())
            self.assertEqual(result["requests_sent"], 0)
            return result
        finally:
            for path, original in before.items():
                self.assertEqual(path.read_bytes(), original, "Inspection changed actual cache/config bytes")

    def test_identical_generations_return_complete_model_without_mutation(self):
        reordered = dict(reversed(list(self.model.items())))
        reordered["compat"] = dict(reversed(list(self.model["compat"].items())))
        result = self.inspect_catalog([
            ("spark1:retained-generation", [self.model, {"id": "OtherModel"}]),
            ("spark1:current-generation", [reordered]),
            ("spark1:future-generation", [self.model]),
            ("foreign:current-generation", [dict(self.model, provider="foreign")]),
        ])
        self.assertEqual(result["model_definition"], self.model)

    def test_complete_definition_disagreement_refuses_in_either_order(self):
        alternatives = [
            dict(self.model, contextWindow=32768),
            dict(self.model, reasoning=1),
            dict(self.model, compat=dict(self.model["compat"], thinkingFormat="openai")),
            dict(self.model, additionalCapability=True),
        ]
        for changed in alternatives:
            for models in ((self.model, changed), (changed, self.model)):
                with self.subTest(changed=changed, first=models[0]), self.assertRaises(SafetyError):
                    self.inspect_catalog([("spark1:retained", [models[0]]), ("spark1:current", [models[1]])])

    def test_missing_selected_model_refuses(self):
        for generations in ([], [("spark1:current", [])],
                            [("spark1:current", [{"id": "OtherModel"}])],
                            [("foreign:current", [self.model])]):
            with self.subTest(generations=generations), self.assertRaises(SafetyError):
                self.inspect_catalog(generations)

    def test_wrong_selected_provider_endpoint_or_api_refuses(self):
        for key, value in (("provider", "foreign"), ("baseUrl", "http://127.0.0.1:1/v1"),
                           ("api", "openai-responses")):
            changed = dict(self.model, **{key: value})
            with self.subTest(field=key), self.assertRaises(SafetyError):
                self.inspect_catalog([("spark1:retained", [changed]), ("spark1:current", [changed])])

    def test_missing_required_selected_identity_fields_refuses(self):
        for key in ("id", "provider", "baseUrl", "api"):
            changed = dict(self.model)
            del changed[key]
            with self.subTest(field=key), self.assertRaises(KeyError) as raised:
                self.inspect_catalog([("spark1:current", [changed])])
            self.assertEqual(raised.exception.args, (key,))

    def test_missing_or_wrong_config_provider_fields_refuses(self):
        for key, value in (("baseUrl", "http://127.0.0.1:1/v1"), ("api", "openai-responses"),
                           ("auth", "required")):
            wrong = dict(self.provider, **{key: value})
            missing = dict(self.provider)
            del missing[key]
            for provider in (wrong, missing):
                with self.subTest(field=key, provider=provider), self.assertRaises(SafetyError):
                    self.inspect_catalog([("spark1:retained", [self.model]),
                                          ("spark1:current", [self.model])], provider=provider)
