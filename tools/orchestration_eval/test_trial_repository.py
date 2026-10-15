"""Actual owned Git/process effects; fixture review/compile admissions are explicitly synthetic."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import unittest
from unittest.mock import patch
import uuid

from . import trial_repository
from .evidence import capture_inputs, file_identity
from .safety import SafetyError, digest, isolated_environment, save_json
from .test_state import WorkflowFixture
from .trial_delivery import WorkerDelivery
from .trial_recovery import ReadOnlyGit, recover_action
from .trial_repository import IndependentRepository, ReconciliationRequired
from .trial_runtime import TrialRuntime


@unittest.skipUnless(os.name == "nt" and os.environ.get("OMP_EVAL_TEST_AUTHORIZATION") == "isolated-fixtures",
                     "Explicit owned Git/native process verification required")
class TrialRepositoryTests(unittest.TestCase):
    def git(self, cwd, *arguments, data=None):
        argv = ["git", "-C", str(cwd), "-c", "core.longpaths=true", "-c", "core.autocrlf=false",
                "-c", "user.name=Owned Git regression", "-c", "user.email=owned-git@invalid", *arguments]
        result = subprocess.run(argv, input=data, env=self.environment, capture_output=True, timeout=30)
        save_json(self.fixture_root / "setup-commands" / (uuid.uuid4().hex + ".json"),
                  {"argv": argv, "returncode": result.returncode, "stdout": result.stdout.decode(errors="replace"),
                   "stderr": result.stderr.decode(errors="replace"), "qualification": "Owned local Git fixture setup/query"})
        self.assertEqual(result.returncode, 0, result.stderr.decode(errors="replace"))
        return result.stdout.decode().strip()

    def prepare(self, fixture):
        self.fixture_root = fixture.root
        self.environment = isolated_environment(fixture.root / "git-setup-environment")
        self.environment.update(GIT_CONFIG_NOSYSTEM="1", GIT_CONFIG_GLOBAL=os.devnull, GIT_TERMINAL_PROMPT="0")
        self.source = fixture.root / "read-only-source"
        self.remote = fixture.root / "owned-remote.git"
        self.target = fixture.root / "independent-publication"
        self.source.mkdir()
        self.remote.mkdir()
        self.git(self.source, "init", "-b", "baseline")
        self.git(self.remote, "init", "--bare")
        self.git(self.remote, "config", "--local", "core.longpaths", "true")
        row = fixture.case.manifest["reservations"][0]
        for name in row["owned_paths"]:
            if name.endswith(".cpp"):
                continue
            path = self.source / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(b"baseline registration\n")
        (self.source / ".gitattributes").write_bytes(b"*.cpp text eol=lf\n*.py text eol=lf\n*.txt text eol=lf\n")
        self.git(self.source, "add", "--", ".")
        self.git(self.source, "commit", "-m", "Owned fixture baseline")
        self.baseline = self.git(self.source, "rev-parse", "HEAD")
        fixture.case.manifest["publication_target"] = {
            "repository": str(self.target), "remote": str(self.remote), "branch": "controller-trial"}
        for reservation in fixture.case.manifest["reservations"]:
            reservation["baseline_commit"] = self.baseline
        self.source_index = file_identity(self.source / ".git/index")
        self.source_head = (self.source / ".git/HEAD").read_bytes()

    def configure(self, fixture):
        target = fixture.config["publication_target"]
        target["baseline"] = self.baseline
        helper = Path("C:/Program Files/Git/mingw64/bin/git-credential-manager.exe")
        target["credential_helper"] = {"path": str(helper), "sha256": digest(helper)}
        authority = {key: target[key] for key in ("repository", "remote", "branch")}
        authority.update(engineering_baseline=self.baseline, parent_repository_read_only=str(self.source),
                         scope={"parent_index_refs_objects_writes": False, "force_push": False})
        authority["credential_helper"] = dict(target["credential_helper"],
            observation_source="Actual installed executable, not a credential request",
            allowed_use="Command-local noninteractive authentication for the exact owned target",
            credential_extraction_or_logging=False, global_configuration_changes=False,
            interactive_authentication=False)
        path = fixture.root / "actual-fixture-target.json"
        save_json(path, authority)
        target["ownership_evidence"] = {"path": str(path), "sha256": digest(path)}

    def setUp(self):
        self.f = WorkflowFixture(prepare=self.prepare, configure=self.configure)
        self.runtime = TrialRuntime(self.f.root, self.f.ledger, Path("never-a-native-model-host.exe"), {})
        self.source_override = patch.object(trial_repository, "ACTIVE", self.source)
        self.source_override.start()
        self.addCleanup(self.source_override.stop)
        self.repository = IndependentRepository(self.runtime)
        action = self.admit(None)
        result = self.repository.prepare_target(action)
        self.runtime.workflow.complete(action, result, refs=result["evidence_refs"])
        self.f.start(target=False)
        self.workspace = Path(self.f.case.manifest["reservations"][0]["workspace"])
        self.workspace.parent.mkdir(parents=True, exist_ok=True)
        self.git(self.source, "clone", "--no-local", "--no-hardlinks", str(self.source), str(self.workspace))
        self.packet = self.real_delivery()
        self.f.reviewed(packet=self.packet)
        self.delivery = WorkerDelivery.from_dict(self.packet)

    def tearDown(self):
        self.runtime.workflow.shutdown()
        self.runtime.refill_pool.shutdown(wait=True, cancel_futures=True)
        self.runtime.manager.stop_all()

    def admit(self, index=0):
        action = self.f.admit(index)
        self.assertTrue(action.pop("execute"))
        return action

    def real_delivery(self):
        packet = self.f.packet(two_units=True)
        paths = self.f.case.manifest["reservations"][0]["owned_paths"]
        source_name = next(name for name in paths if name.endswith(".cpp"))
        changes = {}
        for name in paths:
            path = self.workspace / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(b"int fixture_function() { return 1; }\r\n" if name == source_name
                             else b"baseline registration\r\nowned registration\r\n")
            before = self.git(self.source, "ls-tree", self.baseline, "--", name)
            entry = None if not before else {"mode": before.split()[0], "blob": before.split()[2]}
            changes[name] = {"before": entry, "after": {"mode": "100644", "blob": self.git(
                self.workspace, "hash-object", "--path=" + name, "--stdin", data=path.read_bytes())},
                "raw": file_identity(path)}
        inputs = capture_inputs(self.workspace, {"source": [source_name], "header": [], "tool": [],
            "config": [name for name in paths if name != source_name] + [".gitattributes"]},
            self.f.config["verification"]["trial-0"]["recipe"])
        packet.update(changes=changes, inputs=inputs.to_dict(), cleanup=[], logical_units=[
            {"message": "Owned source logical unit", "paths": [source_name]},
            {"message": "Owned registration logical unit", "paths": [name for name in paths if name != source_name]}])
        for name in packet["artifacts"]:
            path = self.workspace / "evidence" / (name + ".json")
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(json.dumps({"qualification": "synthetic compile/review fixture", "category": name}), encoding="utf-8")
            packet["artifacts"][name] = {"path": path.relative_to(self.workspace).as_posix(), "identity": file_identity(path)}
        return packet

    def materialize(self):
        action = self.admit()
        self.assertEqual(action["kind"], "materialize")
        result = self.runtime.workflow.dispatch(action)
        self.runtime.workflow.complete(action, result)
        return action, result

    def test_actual_raw_materialization_and_separate_commit_push_units(self):
        index_before = file_identity(self.target / ".git/index")
        self.materialize()
        commits, pushes = [], []
        while self.f.ledger.trial_readiness("trial-0")["kind"] in {"commit", "push"}:
            action = self.admit()
            result = self.runtime.workflow.dispatch(action)
            self.runtime.workflow.complete(action, result)
            (commits if action["kind"] == "commit" else pushes).append(result)
        self.assertEqual(len(commits), 2)
        self.assertEqual(len(pushes), 2)
        self.assertEqual(commits[1]["parent"], commits[0]["commit"])
        self.assertNotEqual(commits[0]["commit"], commits[1]["commit"])
        for index, commit in enumerate(commits):
            actual = self.git(self.target, "diff-tree", "--no-commit-id", "--name-only", "-r", commit["parent"], commit["commit"])
            self.assertEqual(set(actual.splitlines()), set(self.packet["logical_units"][index]["paths"]))
        action = self.admit()
        self.assertEqual(action["kind"], "acknowledge")
        self.runtime.workflow.complete(action, self.runtime.workflow.dispatch(action))
        for name, change in self.packet["changes"].items():
            self.assertEqual(file_identity(self.target / name), change["raw"])
        self.assertEqual(file_identity(self.target / ".git/index"), index_before)
        self.assertEqual(file_identity(self.source / ".git/index"), self.source_index)
        self.assertEqual((self.source / ".git/HEAD").read_bytes(), self.source_head)
        self.assertEqual(self.git(self.remote, "rev-parse", "refs/heads/controller-trial"), commits[-1]["commit"])
        self.assertTrue(all(row.get("exit_proof", {}).get("observed_exit") for row in self.runtime.manager.records()))

    def test_exit_zero_partial_apply_is_retained_not_accepted_or_replayed(self):
        action = self.admit()
        actual_git = self.repository.git
        def omit_registration(effect, arguments, **kwargs):
            if arguments[0] == "apply":
                arguments = [*arguments[:-1], "--exclude=configure.py", arguments[-1]]
            return actual_git(effect, arguments, **kwargs)
        with patch.object(self.repository, "git", side_effect=omit_registration):
            with self.assertRaises(SafetyError):
                self.repository.materialize(action, self.delivery, self.workspace)
        receipt = self.f.root / "workflow" / action["effect_id"] / "materialization.json"
        observed = json.loads(receipt.read_bytes())
        self.assertEqual(observed["apply_exit_code"], 0)
        self.assertTrue(any(row["matches"] for row in observed["postimages"]))
        self.assertFalse(all(row["matches"] for row in observed["postimages"]))
        before = {name: file_identity(self.target / name) for name in self.packet["changes"]}
        self.runtime.workflow.complete(action, {"error": "Observed actual partial apply", "receipt": str(receipt)}, outcome="uncertain")
        action = self.f.ledger.snapshot()["trial"]["workflow"]["actions"][action["effect_id"]]
        observer = ReadOnlyGit(self.runtime, self.repository)
        with self.assertRaises(SafetyError):
            recover_action(self.runtime, action, observer)
        self.assertEqual(before, {name: file_identity(self.target / name) for name in self.packet["changes"]})
        workflow = self.f.ledger.snapshot()["trial"]["workflow"]
        self.assertEqual(workflow["actions"][workflow["target_lease"]]["assignment_id"], "trial-0")

    def test_interrupted_commit_and_push_are_observed_from_actual_git_without_replay(self):
        self.materialize()
        commit_action = self.admit()
        actual = self.runtime.workflow.dispatch(commit_action)
        self.assertEqual(self.git(self.target, "rev-parse", "HEAD"), actual["commit"])
        observer = ReadOnlyGit(self.runtime, self.repository)
        recovered = recover_action(self.runtime, commit_action, observer)
        self.assertTrue(recovered["recovered_from_git"])
        self.runtime.workflow.complete(commit_action, recovered, refs=observer.references)
        push_action = self.admit()
        actual_push = self.runtime.workflow.dispatch(push_action)
        self.assertEqual(actual_push["push_exit_code"], 0)
        observer = ReadOnlyGit(self.runtime, self.repository)
        recovered_push = recover_action(self.runtime, push_action, observer)
        self.assertTrue(recovered_push["recovered_from_remote"])
        self.assertIsNone(recovered_push["push_exit_code"])
        self.runtime.workflow.complete(push_action, recovered_push, refs=observer.references)
        self.assertEqual(self.git(self.remote, "rev-parse", "refs/heads/controller-trial"), actual["commit"])
        self.assertEqual(self.f.ledger.trial_readiness("trial-0")["kind"], "commit")

    def test_current_preimage_drift_routes_same_owner_without_materialization(self):
        action = self.admit()
        registration = self.target / "configure.py"
        registration.write_bytes(b"unrelated current registration change\n")
        with self.assertRaises(ReconciliationRequired):
            self.repository.materialize(action, self.delivery, self.workspace)
        self.assertEqual(registration.read_bytes(), b"unrelated current registration change\n")
        source = next(name for name in self.packet["changes"] if name.endswith(".cpp"))
        self.assertFalse((self.target / source).exists())

    def test_superseded_actual_materialization_restores_then_recovers_without_replay(self):
        before = {name: None if change["before"] is None else (self.target / name).read_bytes()
                  for name, change in self.packet["changes"].items()}
        index = file_identity(self.target / ".git/index")
        action = self.admit()
        result = self.runtime.workflow.dispatch(action)
        self.f.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="explicit-fixture-changed-header", event_id="changed-during-real-materialization")
        observed = self.runtime.workflow.complete(action, result)
        self.assertTrue(observed["superseded"])
        restore = self.admit()
        self.assertEqual(restore["kind"], "restore_materialization")
        restored = self.runtime.workflow.dispatch(restore)
        for name, original in before.items():
            if original is None:
                self.assertFalse((self.target / name).exists())
            else:
                self.assertEqual((self.target / name).read_bytes(), original)
        self.assertEqual(file_identity(self.target / ".git/index"), index)
        self.assertEqual(self.git(self.target, "rev-parse", "HEAD"), self.baseline)
        self.assertEqual(restored["restored_action_id"], action["effect_id"])
        self.f.ledger.request_stop(event_id="stop-after-actual-restoration", reason="Observe, never replay, restoration")
        observer = ReadOnlyGit(self.runtime, self.repository)
        recovered = recover_action(self.runtime, restore, observer)
        self.assertTrue(recovered["recovered_restoration"])
        self.runtime.workflow.complete(restore, recovered, refs=observer.references)
        workflow = self.f.ledger.snapshot()["trial"]["workflow"]
        self.assertIsNone(workflow["target_lease"])
        self.assertEqual(workflow["actions"][action["effect_id"]]["restored_by"], restore["effect_id"])
        self.assertEqual(self.f.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        self.assertEqual(file_identity(self.source / ".git/index"), self.source_index)

    def test_pinned_helper_with_authority_metadata_prepares_actual_independent_target(self):
        self.repository.guard()
        self.assertEqual(self.git(self.target, "remote", "get-url", "origin"), str(self.remote))
        specifications = [json.loads(path.read_bytes())
                          for path in (self.f.root / "workflow").glob("*/commands/*/command.json")]
        authenticated = [item for item in specifications
                         if any(arg.startswith("credential.helper=!") for arg in item["argv"])]
        self.assertTrue(authenticated, "Actual admitted Git commands must carry the pinned helper")
        for item in authenticated:
            self.assertEqual(item["environment"]["GIT_TERMINAL_PROMPT"], "0")
            self.assertEqual(item["environment"]["GCM_INTERACTIVE"], "never")
            self.assertEqual(item["environment"]["GCM_GUI_PROMPT"], "false")
            self.assertEqual(item["environment"]["GCM_TRACE_SECRETS"], "0")
        self.assertEqual(file_identity(self.source / ".git/index"), self.source_index)

    def test_exact_engineering_publication_continues_without_reinitializing_target(self):
        path = self.target / "engineering-publication.txt"
        path.write_bytes(b"Owned actual Git continuation fixture\n")
        self.git(self.target, "add", "--", path.name)
        self.git(self.target, "commit", "-m", "Owned engineering publication fixture")
        head = self.git(self.target, "rev-parse", "HEAD")
        self.git(self.target, "push", "origin", "HEAD:refs/heads/controller-trial")
        index_before = file_identity(self.target / ".git/index")
        descriptor = {"schema": "brawl-owned-engineering-publication/v1",
            "engineering_baseline": self.baseline, "repository": str(self.target),
            "git_dir": str(self.target / ".git"), "remote": str(self.remote), "branch": "controller-trial",
            "head": head, "remote_head": head, "directory_identity": self.target.stat().st_ino,
            "config_sha256": digest(self.target / ".git/config"),
            "files": {path.name: {"mode": "100644", "blob": self.git(self.target, "rev-parse", "HEAD:" + path.name),
                                 "raw": file_identity(path)}},
            "evidence_refs": [str(self.fixture_root / "setup-commands")]}
        reviewed = self.fixture_root / "reviewed-engineering-source-identities.json"
        save_json(reviewed, {"sources": [{"path": path.name, **file_identity(path)}], "documentation": []})
        descriptor.update(source_manifest={"path": str(reviewed), "sha256": digest(reviewed)},
                          units=[{"commit": head, "parent": self.baseline, "paths": [path.name]}])
        def prepare(fixture):
            fixture.case.manifest["publication_target"] = dict(self.f.case.manifest["publication_target"])
        def configure(fixture):
            target = fixture.config["publication_target"]
            target.update(self.f.config["publication_target"], baseline=head)
            descriptor.update(next_run_id=fixture.root.name, controller_id=fixture.config["controller_id"])
            receipt = fixture.root / "actual-engineering-publication.json"
            save_json(receipt, descriptor)
            target["prepared_repository"] = {"path": str(receipt), "sha256": digest(receipt)}
        continuation = WorkflowFixture(prepare=prepare, configure=configure)
        runtime = TrialRuntime(continuation.root, continuation.ledger, Path("never-a-native-model-host.exe"), {})
        try:
            action = continuation.admit(None)
            action.pop("execute")
            repository = IndependentRepository(runtime)
            result = repository.prepare_target(action)
            self.assertEqual(result["head"], head)
            self.assertTrue(result["retained_engineering_publication"])
            self.assertEqual(file_identity(self.target / ".git/index"), index_before)
            changed_scope = dict(descriptor, units=[dict(descriptor["units"][0], paths=["configure.py"])])
            with self.assertRaises(SafetyError):
                repository.verify_prepared_target(action, changed_scope)
            changed_sequence = dict(descriptor, units=[])
            with self.assertRaises(SafetyError):
                repository.verify_prepared_target(action, changed_sequence)
            runtime.workflow.complete(action, result, refs=result["evidence_refs"])
            self.assertEqual(continuation.ledger.snapshot()["trial"]["workflow"]["target_head"], head)
            path.write_bytes(b"Foreign edit must never be overwritten\n")
            with self.assertRaises(SafetyError):
                repository.verify_prepared_target(action, descriptor)
            self.assertEqual(path.read_bytes(), b"Foreign edit must never be overwritten\n")
            self.assertEqual(file_identity(self.source / ".git/index"), self.source_index)
        finally:
            runtime.workflow.shutdown()
            runtime.refill_pool.shutdown(wait=True, cancel_futures=True)
            runtime.manager.stop_all()
