"""Behavioral ledger tests; all fixtures and observations are retained in build.

Run from the evaluation worktree with:
    python -m unittest tools.orchestration_eval.test_state -v

These tests exercise SQLite, real Python compilation/execution, owned child exits,
and local Git commit/push observations. They do not claim C++ semantic correctness.
"""

from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import sqlite3
import subprocess
import sys
from threading import Barrier
import unittest
import uuid

from .evidence import content_identity
from .policy import Mode, PolicyError, SlotPolicy, workflow_acceptance_policy
from .state import Ledger, StateError, read_snapshot


ROOT = Path(__file__).resolve().parents[2]
CHILD_CREATION_FLAGS = subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0


class LedgerTests(unittest.TestCase):
    def setUp(self):
        self.root = ROOT / "build" / "orchestration-eval" / "tests" / "state" / uuid.uuid4().hex
        self.root.mkdir(parents=True)
        self.db = self.root / "ledger.sqlite3"
        self.ledger = Ledger(self.db)
        self.serial = 0
        self.header = self.root / "shared-input.json"
        self.header.write_text('{"constant": 7}\n', encoding="utf-8")
        self.recipe = self.root / "recipe.json"
        self.recipe.write_text(json.dumps({"engine": sys.executable, "version": sys.version,
                                           "recipe": "compile(source, path, exec); result()"}), encoding="utf-8")
        self.authorize()

    def event(self, label="event"):
        self.serial += 1
        return f"{label}-{self.serial}"

    def artifact(self, label, value):
        path = self.root / f"{self.event(label)}.json"
        path.write_text(json.dumps(value, sort_keys=True, indent=2), encoding="utf-8")
        return str(path)

    def authorize(self, mode="RUN"):
        self.auth = self.ledger.authorize(mode, event_id=self.event("authorization"),
                                          reason="Explicit retained evaluation fixture",
                                          expected_revision=self.ledger.authorization()["revision"])
        return self.auth

    def create(self, assignment_id="a", stage="sol", **overrides):
        args = dict(assignment_id=assignment_id,
                    function={"module": "evaluation_fixture", "symbol": assignment_id, "size": 8},
                    stage=stage, provider="evaluation-fixture", model=f"fixture-{stage}",
                    owner_id=f"owner-{assignment_id}", session_id=f"session-{assignment_id}",
                    event_id=self.event("create"), authorization_revision=self.auth["revision"])
        args.update(overrides)
        return self.ledger.create_assignment(**args)

    def input_identity(self, source):
        files = [source, self.header, self.recipe, Path(sys.executable)]
        return hashlib.sha256(json.dumps({str(p): hashlib.sha256(p.read_bytes()).hexdigest()
                                          for p in files}, sort_keys=True).encode()).hexdigest()

    def measure(self, assignment_id="a", candidate_id="initial", value=7, target=7, syntax_error=False,
                source=None, event_id=None):
        if source is None:
            source = self.root / f"{assignment_id}-{candidate_id}.py"
            text = "def result(:\n" if syntax_error else f"# preserved {candidate_id}\ndef result():\n    return {value}\n"
            source.write_text(text, encoding="utf-8")
        raw = source.read_bytes()
        try:
            namespace = {"HEADER_CONSTANT": json.loads(self.header.read_text(encoding="utf-8"))["constant"],
                         "RECIPE_OFFSET": json.loads(self.recipe.read_text(encoding="utf-8")).get("offset", 0)}
            code = compile(raw, str(source), "exec")
            exec(code, namespace)
            actual = namespace["result"]()
            outcome = "matching" if actual == target else "nonmatching"
            observation = {"scope": "evaluation_fixture", "result": actual, "target": target,
                           "outcome": outcome, "source_sha256": hashlib.sha256(raw).hexdigest()}
            quality = -abs(target - actual)
        except SyntaxError as error:
            outcome, quality = "compile_failed", None
            observation = {"scope": "evaluation_fixture", "outcome": outcome, "diagnostic": str(error)}
        observation["preserved_inputs"] = {
            str(path): {"sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
                        "content": path.read_text(encoding="utf-8")}
            for path in (source, self.header, self.recipe)}
        observation["tool_sha256"] = hashlib.sha256(Path(sys.executable).read_bytes()).hexdigest()
        ref = self.artifact("measurement", observation)
        args = dict(event_id=event_id or self.event("attempt"), candidate_id=candidate_id,
                    source_ref={"path": str(source), "sha256": hashlib.sha256(raw).hexdigest()},
                    input_identity=self.input_identity(source), recipe_ref=str(self.recipe),
                    outcome=outcome, evidence_refs=[ref], quality=quality,
                    authorization_revision=self.auth["revision"])
        result = self.ledger.record_attempt(assignment_id, **args)
        return result, args

    def verify(self, assignment_id, attempt):
        evidence = {"scope": "evaluation_fixture", "checks": {"python_compile_and_measure": attempt["evidence_refs"][0]},
                    "runtime_status": "exercised", "runtime_ref": attempt["evidence_refs"][0]}
        return self.ledger.record_verification(assignment_id, event_id=self.event("verification"),
                                               candidate_id=attempt["candidate_id"], input_identity=attempt["input_identity"],
                                               evidence=evidence, authorization_revision=self.auth["revision"])

    def transition(self, status, details=None, assignment_id="a"):
        return self.ledger.transition(assignment_id, status, event_id=self.event(status),
                                      details=details or {}, authorization_revision=self.auth["revision"])

    def ready(self, assignment_id="a"):
        self.create(assignment_id)
        _, attempt = self.measure(assignment_id)
        self.verify(assignment_id, attempt)
        binding = self.publication_binding(assignment_id)
        self.transition("review_wait", assignment_id=assignment_id)
        self.transition("reconciling", {"review": {
            "approved_by": "fixture-parent", "input_identity": attempt["input_identity"],
            **binding,
            "evidence_refs": [self.artifact("review", {"scope": "evaluation_fixture", "source_ref": attempt["source_ref"]})]
        }}, assignment_id)
        patch_identity = hashlib.sha256(Path(attempt["source_ref"]["path"]).read_bytes()).hexdigest()
        self.transition("publication_wait", {"materialization": {
            "owner_id": f"owner-{assignment_id}", "input_identity": attempt["input_identity"],
            **binding,
            "patch_identity": patch_identity, "evidence_refs": [attempt["evidence_refs"][0]]
        }}, assignment_id)
        return attempt, patch_identity

    def git(self, repo, *args):
        env = os.environ.copy()
        env.update(GIT_CONFIG_NOSYSTEM="1", GIT_CONFIG_GLOBAL=os.devnull,
                   GIT_TERMINAL_PROMPT="0", GIT_AUTHOR_NAME="Evaluation Fixture",
                   GIT_AUTHOR_EMAIL="fixture@invalid", GIT_COMMITTER_NAME="Evaluation Fixture",
                   GIT_COMMITTER_EMAIL="fixture@invalid", GIT_AUTHOR_DATE="2026-01-01T00:00:00Z",
                   GIT_COMMITTER_DATE="2026-01-01T00:00:00Z")
        completed = subprocess.run(["git", "-C", str(repo), *args], check=True, capture_output=True,
                                   text=True, env=env, cwd=repo, stdin=subprocess.DEVNULL,
                                   creationflags=CHILD_CREATION_FLAGS)
        ref = self.artifact("git-observation", {"argv": ["git", "-C", str(repo), *args],
                                               "returncode": completed.returncode,
                                               "stdout": completed.stdout, "stderr": completed.stderr})
        return completed.stdout.strip(), ref

    def publication_binding(self, assignment_id="a"):
        repo = self.root / f"repo-{assignment_id}"
        remote = self.root / f"remote-{assignment_id}.git"
        if not repo.exists():
            repo.mkdir()
            remote.mkdir()
            self.git(repo, "init", "-b", "main")
            self.git(remote, "init", "--bare")
            # Receive-pack does not inherit sender command-scoped configuration.
            self.git(remote, "config", "--local", "core.longpaths", "true")
            self.git(repo, "config", "--local", "core.longpaths", "true")
            (repo / "baseline.txt").write_text("Independent ledger fixture\n", encoding="utf-8")
            self.git(repo, "add", "--", "baseline.txt")
            self.git(repo, "commit", "-m", "Initialize independent fixture")
            self.git(repo, "remote", "add", "origin", str(remote))
            self.git(repo, "push", "origin", "HEAD:refs/heads/main")
        a = self.ledger.assignment(assignment_id)
        target = {"repository": str(repo), "remote": str(remote), "branch": "main"}
        packet = {"assignment_id": assignment_id, "target": target,
                  "input_identity": a["verification"]["input_identity"],
                  "source_ref": a["best_candidate"]["source_ref"]}
        return {"publication_target": target, "request_digest": hashlib.sha256(
            json.dumps(packet, sort_keys=True, separators=(",", ":")).encode()).hexdigest()}

    def prepare_publication(self, assignment_id="a"):
        a = self.ledger.assignment(assignment_id)
        target = a["materialization"]["publication_target"]
        repo = Path(target["repository"])
        source = Path(a["best_candidate"]["source_ref"]["path"])
        (repo / "fixture.py").write_bytes(source.read_bytes())
        base, _ = self.git(repo, "rev-parse", "HEAD")
        self.git(repo, "add", "--", "fixture.py")
        tree, _ = self.git(repo, "write-tree")
        planned, observation_ref = self.git(repo, "commit-tree", tree, "-p", base, "-m",
                                             f"Evaluation assignment {assignment_id}")
        intent = dict(request_digest=a["materialization"]["request_digest"],
                      publication_target=target, planned_commit=planned, base_head=base, tree=tree,
                      branch=target["branch"], remote=target["remote"], observation_ref=observation_ref,
                      patch_identity=a["materialization"]["patch_identity"],
                      input_identity=a["materialization"]["input_identity"],
                      request={"assignment_id": assignment_id, "target": target,
                               "input_identity": a["materialization"]["input_identity"],
                               "source_ref": a["best_candidate"]["source_ref"]})
        self.ledger.record_publication(assignment_id, event_id=self.event("intent"), record=intent)
        return intent

    def admit(self, intent, kind, assignment_id="a", *, effect_id=None, event_id=None):
        return self.ledger.admit_publication_effect(
            assignment_id, effect_id=effect_id or self.event(kind), kind=kind,
            request_digest=intent["request_digest"], target=intent["publication_target"],
            planned_commit=intent["planned_commit"], authorization_revision=self.auth["revision"],
            event_id=event_id or self.event("admission"))

    def commit_effect(self, intent, effect, assignment_id="a", *, observe=True):
        self.assertTrue(effect["execute"])
        repo = Path(intent["publication_target"]["repository"])
        self.git(repo, "update-ref", "refs/heads/main", intent["planned_commit"], intent["base_head"])
        actual, ref = self.git(repo, "rev-parse", "refs/heads/main")
        self.assertEqual(actual, intent["planned_commit"])
        record = {"commit": actual, "local_head": actual, "effect_observed": True, "observation_ref": ref}
        if observe:
            self.ledger.observe_publication_effect(assignment_id, effect_id=effect["effect_id"],
                                                   event_id=self.event("commit-observation"), record=record)
        return record

    def push_effect(self, intent, effect, assignment_id="a", *, observe=True):
        self.assertTrue(effect["execute"])
        repo = Path(intent["publication_target"]["repository"])
        self.git(repo, "push", str(intent["remote"]), f"{intent['planned_commit']}:refs/heads/main")
        actual, ref = self.git(repo, "ls-remote", str(intent["remote"]), "refs/heads/main")
        head = actual.split()[0]
        self.assertEqual(head, intent["planned_commit"])
        record = {"commit": intent["planned_commit"], "pushed": True, "remote_head": head,
                  "remote_contains_commit": True, "effect_observed": True, "push_error": None,
                  "observation_ref": ref}
        if observe:
            self.ledger.observe_publication_effect(assignment_id, effect_id=effect["effect_id"],
                                                   event_id=self.event("push-observation"), record=record)
        return record

    def publish_observation(self, assignment_id="a"):
        intent = self.prepare_publication(assignment_id)
        commit = self.admit(intent, "commit", assignment_id)
        self.commit_effect(intent, commit, assignment_id)
        push = self.admit(intent, "push", assignment_id)
        self.push_effect(intent, push, assignment_id)
        return self.ledger.publication(assignment_id)

    def test_default_status_is_nonexecuting_and_read_only(self):
        untouched = self.root / "never-created" / "ledger.sqlite3"
        with self.assertRaises(sqlite3.OperationalError):
            read_snapshot(untouched)
        self.assertFalse(untouched.parent.exists())
        other = Ledger(self.root / "unapproved.sqlite3")
        self.assertEqual(other.authorization()["mode"], "STOPPED")
        with self.assertRaises(PolicyError):
            other.require_operation("launch", 0)
        before = self.db.read_bytes()
        self.assertEqual(read_snapshot(self.db)["authorization"], self.auth)
        self.assertEqual(before, self.db.read_bytes())
        with self.assertRaises(PolicyError):
            Ledger(ROOT / "protected-parent-state.sqlite3")
        self.assertFalse((ROOT / "protected-parent-state.sqlite3").exists())

    def test_duplicate_events_and_assignment_identity_are_atomic(self):
        args = dict(assignment_id="a", function={"module": "fixture", "symbol": "a"},
                    stage="sol", provider="fixture-provider", model="exact-fixture-model",
                    owner_id="owner-a", session_id="session-a", event_id="same-create",
                    authorization_revision=self.auth["revision"])
        with ThreadPoolExecutor(max_workers=4) as executor:
            receipts = list(executor.map(lambda _: self.ledger.create_assignment(**args), range(4)))
        self.assertTrue(all(r == receipts[0] for r in receipts))
        self.assertEqual(len(self.ledger.assignments()), 1)
        self.assertEqual(self.ledger.assignment("a")["stages"][0]["model"], "exact-fixture-model")
        with self.assertRaises(StateError):
            self.ledger.create_assignment(**(args | {"model": "another-model"}))
        with self.assertRaises(StateError):
            self.ledger.create_assignment(**(args | {"assignment_id": "duplicate-function", "event_id": "new-event"}))
        _, attempt = self.measure(event_id="same-completion")
        once = self.ledger.snapshot()["event_count"]
        self.ledger.record_attempt("a", **attempt)
        self.assertEqual(self.ledger.snapshot()["event_count"], once)
        self.assertEqual(len(self.ledger.assignment("a")["stages"][0]["attempts"]), 1)

    def test_nominal_slots_and_separate_retained_publisher(self):
        for stage, count in (("sol", 8), ("glm", 2), ("qwen", 3)):
            for number in range(count):
                self.create(f"{stage}-{number}", stage)
            with self.assertRaises(PolicyError):
                self.create(f"{stage}-overflow", stage)
        self.ledger.register_publisher(owner_id="publisher-owner", session_id="publisher-session",
                                       provider="fixture", model="fixture-sol", event_id=self.event(),
                                       authorization_revision=self.auth["revision"])
        with self.assertRaises(StateError):
            self.ledger.register_publisher(owner_id="replacement", session_id="replacement-session",
                                           provider="fixture", model="fixture-sol", event_id=self.event(),
                                           authorization_revision=self.auth["revision"])
        with self.assertRaises(PolicyError):
            self.create("astra-without-capacity", "astra")
        with self.assertRaises(StateError):
            self.create("reuse-agent", owner_id="owner-sol-0")
        with self.assertRaises(StateError):
            self.create("reuse-session", session_id="session-sol-0")

    def test_explicit_count_and_paused_overrides_survive_restart(self):
        path = self.root / "overridden.sqlite3"
        self.ledger = Ledger(path, policy=SlotPolicy(overrides={"glm": 3}, paused=("qwen",)))
        self.authorize()
        for number in range(3):
            self.create(f"glm-{number}", "glm")
        with self.assertRaises(PolicyError):
            self.create("glm-recovery-overflow", "glm")
        with self.assertRaises(PolicyError):
            self.create("paused-qwen", "qwen")
        restored = Ledger(path)
        self.assertEqual(restored.policy.capacity("glm"), 3)
        self.assertEqual(restored.policy.capacity("qwen"), 0)
        with self.assertRaises(PolicyError):
            Ledger(path, policy=SlotPolicy())

    def test_distinct_authorization_modes_and_stale_queue_rejection(self):
        revision = self.auth["revision"]
        self.create()
        for mode in ("PUBLISH_EXISTING", "RESEARCH"):
            self.authorize(mode)
            for operation in ("launch", "resume", "reconstruct", "verify"):
                with self.assertRaises(PolicyError):
                    self.ledger.require_operation(operation, self.auth["revision"])
            self.ledger.require_operation("publish" if mode == "PUBLISH_EXISTING" else "research")
            with self.assertRaises(PolicyError):
                self.ledger.require_operation("research" if mode == "PUBLISH_EXISTING" else "publish")
        self.authorize("RUN")
        with self.assertRaises(PolicyError):
            self.ledger.require_operation("resume", revision)
        with self.assertRaises(PolicyError):
            self.ledger.require_operation("provider_request", self.auth["revision"])
        self.assertEqual(self.ledger.assignment("a")["stages"][0]["initial_count"], 0)

    def test_stop_survives_restart_and_requires_real_exit_receipt(self):
        self.create()
        started = datetime.now(timezone.utc).isoformat()
        process = subprocess.Popen([sys.executable, "-I", "-c", "raise SystemExit(7)"], cwd=self.root,
                                   stdin=subprocess.DEVNULL, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                   creationflags=CHILD_CREATION_FLAGS)
        identity = {"pid": process.pid, "creation_time": started, "token": uuid.uuid4().hex,
                    "job_name": "ledger-test-owned-child"}
        self.ledger.register_process(process_id="owned", session_id="session-a", identity=identity,
                                     event_id=self.event(), authorization_revision=self.auth["revision"])
        self.ledger.request_stop(event_id="stop", reason="Explicit evaluation stop")
        self.ledger = Ledger(self.db)
        self.assertEqual(self.ledger.authorization()["mode"], "STOPPING")
        with self.assertRaises(PolicyError):
            self.create("queued")
        with self.assertRaises(PolicyError):
            self.authorize("RUN")
        with self.assertRaises(StateError):
            self.ledger.finish_stop(event_id="insufficient-engine-state", exit_proofs=[])
        stdout, stderr = process.communicate(timeout=30)
        ref = self.artifact("native-exit", {"pid": process.pid, "wait_returncode": process.returncode,
                                            "stdout": stdout.decode(), "stderr": stderr.decode()})
        proof = identity | {"process_id": "owned", "observed_exit": True, "exit_code": process.returncode,
                            "verified_at": datetime.now(timezone.utc).isoformat(), "evidence_ref": ref}
        with self.assertRaises(StateError):
            self.ledger.record_process_exit("owned", event_id="wrong-token", proof=proof | {"token": "not-owned"})
        self.ledger.finish_stop(event_id="finished", exit_proofs=[proof])
        self.ledger.request_stop(event_id="stop", reason="Explicit evaluation stop")
        restored = Ledger(self.db)
        self.assertEqual(restored.authorization()["mode"], "STOPPED")
        self.assertFalse(restored.process("owned")["active"])
        self.assertTrue(restored.session("session-a")["active"])
        with self.assertRaises(PolicyError):
            restored.require_operation("resume", self.auth["revision"])

    def test_compile_failure_correction_reconnection_and_best_survive_restart(self):
        self.create()
        self.measure(candidate_id="initial", syntax_error=True)
        _, second = self.measure(candidate_id="correction-1", value=6)
        self.measure(candidate_id="correction-2", value=1)
        self.ledger = Ledger(self.db)
        a = self.ledger.assignment("a")
        self.assertEqual((a["stages"][0]["initial_count"], a["stages"][0]["corrections"]), (1, 2))
        self.assertEqual(a["best_candidate"]["candidate_id"], "correction-1")
        second["event_id"] = self.event("remeasurement")
        self.ledger.record_attempt("a", **second)
        self.assertEqual(self.ledger.assignment("a")["stages"][0]["corrections"], 2)
        self.assertEqual(len(self.ledger.assignment("a")["stages"][0]["attempts"]), 4)
        self.assertTrue(Path(a["stages"][0]["attempts"][0]["source_ref"]["path"]).exists())

    def test_infrastructure_failure_is_blocked_not_exhausted(self):
        self.create()
        source = self.root / "candidate.py"
        source.write_text("def result(): return 7\n", encoding="utf-8")
        try:
            subprocess.run([str(self.root / "missing-compiler.exe")], check=True, capture_output=True,
                           stdin=subprocess.DEVNULL, cwd=self.root, creationflags=CHILD_CREATION_FLAGS)
        except OSError as error:
            ref = self.artifact("tool-failure", {"exception": type(error).__name__, "message": str(error)})
        else:
            self.fail("Owned deliberately absent compiler unexpectedly exists")
        self.ledger.record_attempt("a", event_id=self.event(), candidate_id="initial",
                                   source_ref={"path": str(source), "sha256": hashlib.sha256(source.read_bytes()).hexdigest()},
                                   input_identity=self.input_identity(source), recipe_ref=str(self.recipe),
                                   outcome="tool_failed", evidence_refs=[ref], authorization_revision=self.auth["revision"])
        a = self.ledger.assignment("a")
        self.assertEqual(a["status"], "blocked")
        self.assertEqual((a["stages"][0]["initial_count"], a["stages"][0]["corrections"]), (0, 0))
        with self.assertRaises(StateError):
            self.ledger.exhaust_stage("a", event_id=self.event(), evidence_refs=[ref], authorization_revision=self.auth["revision"])
        self.measure(candidate_id="initial", source=source)
        self.assertEqual(self.ledger.assignment("a")["stages"][0]["initial_count"], 1)

    def test_stage_handoffs_preserve_counts_best_and_exhausted_fallback(self):
        self.db = self.root / "stages.sqlite3"
        self.ledger = Ledger(self.db, policy=SlotPolicy(astra_capacity=1))
        self.authorize()
        self.create(stage="glm")
        owners = []
        for stage in ("glm", "sol", "astra"):
            for number in range(11):
                self.measure(candidate_id=f"{stage}-{number}", value=number, target=-1)
            a = self.ledger.assignment("a")
            owners.append(a["owner_id"])
            ref = self.artifact("exhausted-stage", {"stage": stage, "attempts": a["stages"][-1]["attempts"]})
            self.ledger.exhaust_stage("a", event_id=self.event(), evidence_refs=[ref], authorization_revision=self.auth["revision"])
            if stage != "astra":
                following = "sol" if stage == "glm" else "astra"
                self.ledger.escalate("a", event_id=self.event(), stage=following, provider="fixture-provider",
                                     model=f"fixture-{following}", owner_id=f"fresh-owner-{following}",
                                     session_id=f"fresh-session-{following}", authorization_revision=self.auth["revision"])
        a = Ledger(self.db).assignment("a")
        self.assertEqual(len(set(owners)), 3)
        self.assertEqual([s["corrections"] for s in a["stages"]], [10, 10, 10])
        self.assertEqual(a["best_candidate"]["candidate_id"], "glm-0")
        fallback_source = self.root / "original-fallback.py"
        fallback_source.write_text("def result(): return -1\n", encoding="utf-8")
        fallback_namespace = {}
        exec(compile(fallback_source.read_bytes(), str(fallback_source), "exec"), fallback_namespace)
        fallback_result = fallback_namespace["result"]()
        self.assertEqual(fallback_result, -1)
        fallback = self.artifact("original-fallback", {
            "scope": "evaluation_fixture", "path": str(fallback_source), "result": fallback_result,
            "sha256": hashlib.sha256(fallback_source.read_bytes()).hexdigest()})
        selection = {"candidate_id": a["best_candidate"]["candidate_id"], "accepted_credit": 0,
                     "input_identity": a["best_candidate"]["input_identity"], "fallback_ref": fallback,
                     "label": "nonmatching—attempts exhausted", "evidence_refs": [ref]}
        a = self.transition("review_wait", {"selection": selection})
        self.assertEqual(a["accepted_credit"], 0)
        self.assertTrue(a["selection"]["valid"])
        changed = self.ledger.check_input_identity("a", event_id=self.event(), input_identity="changed-relevant-inputs", evidence_ref=ref)
        self.assertFalse(changed["selection"]["valid"])
        self.assertEqual(changed["status"], "verifying")

    def test_relevant_input_invalidation_and_remeasurement_do_not_reset_counts(self):
        attempt, _ = self.ready()
        original = self.ledger.assignment("a")
        unchanged = self.ledger.check_input_identity("a", event_id=self.event(), input_identity=attempt["input_identity"],
                                                     evidence_ref=attempt["evidence_refs"][0])
        self.assertEqual(unchanged["status"], "publication_wait")
        self.assertEqual(unchanged["verification"], original["verification"])
        self.header.write_text('{"constant": 8}\n', encoding="utf-8")
        current = self.input_identity(Path(attempt["source_ref"]["path"]))
        changed = self.ledger.check_input_identity("a", event_id=self.event(), input_identity=current,
                                                   evidence_ref=self.artifact("changed-input", {"input_identity": current}))
        self.assertFalse(changed["verification"]["valid"])
        self.assertIsNone(changed["review"])
        self.assertIsNone(changed["materialization"])
        with self.assertRaises(StateError):
            self.transition("review_wait")
        _, revised = self.measure(source=Path(attempt["source_ref"]["path"]))
        self.verify("a", revised)
        self.transition("review_wait")
        self.assertEqual(self.ledger.assignment("a")["stages"][0]["corrections"], 0)

    def test_header_and_recipe_only_revisions_count_as_immutable_candidates(self):
        self.create()
        source = self.root / "header-sensitive.py"
        source.write_text("def result(): return HEADER_CONSTANT + RECIPE_OFFSET\n", encoding="utf-8")
        _, initial = self.measure(source=source, target=9)
        self.header.write_text('{"constant": 8}\n', encoding="utf-8")
        _, header_revision = self.measure(candidate_id="header-only", source=source, target=9)
        recipe = json.loads(self.recipe.read_text(encoding="utf-8"))
        recipe["offset"] = 1
        self.recipe.write_text(json.dumps(recipe), encoding="utf-8")
        _, recipe_revision = self.measure(candidate_id="recipe-only", source=source, target=9)
        a = Ledger(self.db).assignment("a")
        self.assertEqual(a["stages"][0]["corrections"], 2)
        self.assertEqual({attempt["source_ref"]["sha256"] for attempt in (initial, header_revision, recipe_revision)},
                         {initial["source_ref"]["sha256"]})
        self.assertEqual(len({attempt["input_identity"] for attempt in (initial, header_revision, recipe_revision)}), 3)
        self.assertEqual(a["stages"][0]["candidate_inputs"]["initial"]["input_identity"], initial["input_identity"])
        self.assertEqual(a["stages"][0]["candidate_inputs"]["header-only"]["input_identity"], header_revision["input_identity"])
        for attempt in (initial, header_revision, recipe_revision):
            preserved = json.loads(Path(attempt["evidence_refs"][0]).read_text(encoding="utf-8"))
            self.assertIn(str(self.header), preserved["preserved_inputs"])
            self.assertIn(str(self.recipe), preserved["preserved_inputs"])
        with self.assertRaises(StateError):
            self.measure(candidate_id="not-a-revision", source=source, target=9)
        self.assertEqual(self.ledger.assignment("a")["stages"][0]["corrections"], 2)

    def test_obsolete_match_cannot_block_current_context_exhaustion(self):
        self.create()
        source = self.root / "context-sensitive.py"
        source.write_text("def result(): return HEADER_CONSTANT\n", encoding="utf-8")
        _, initial = self.measure(source=source)
        self.verify("a", initial)
        self.header.write_text('{"constant": 8}\n', encoding="utf-8")
        changed_identity = self.input_identity(source)
        change_ref = self.artifact("shared-input-change", {
            "input_identity": changed_identity, "header": self.header.read_text(encoding="utf-8")})
        invalidated = self.ledger.check_input_identity("a", event_id=self.event(),
                                                       input_identity=changed_identity, evidence_ref=change_ref)
        self.assertIsNone(invalidated["best_candidate"])
        self.assertEqual(invalidated["historical_best_candidate"]["outcome"], "matching")
        self.assertEqual(invalidated["input_epoch"], 1)
        repeated = self.ledger.check_input_identity("a", event_id=self.event(),
                                                    input_identity=changed_identity, evidence_ref=change_ref)
        self.assertEqual(repeated["input_epoch"], 1)
        with self.assertRaises(StateError):
            self.verify("a", initial)
        self.measure(source=source)
        for number in range(1, 11):
            revised_source = self.root / f"context-correction-{number}.py"
            revised_source.write_text(f"def result(): return HEADER_CONSTANT + {number}\n", encoding="utf-8")
            self.measure(candidate_id=f"correction-{number}", source=revised_source)
        self.ledger = Ledger(self.db)
        a = self.ledger.exhaust_stage("a", event_id=self.event(), evidence_refs=[change_ref],
                                     authorization_revision=self.auth["revision"])
        self.assertEqual(a["status"], "exhausted")
        self.assertEqual(a["stages"][0]["corrections"], 10)
        self.assertEqual(a["best_candidate"]["outcome"], "nonmatching")
        self.assertEqual(a["best_candidate"]["input_epoch"], 1)
        self.assertEqual(a["historical_best_candidate"]["outcome"], "matching")
        self.assertEqual(a["historical_best_candidate"]["input_epoch"], 0)
        self.assertEqual(a["stages"][0]["candidate_inputs"]["initial"]["input_identity"], initial["input_identity"])
        self.assertEqual(len(a["stages"][0]["attempts"]), 12)

    def test_publication_only_reviews_existing_materialization_without_owner_execution(self):
        self.create()
        _, attempt = self.measure()
        self.verify("a", attempt)
        binding = self.publication_binding()
        materialized = self.root / "owner-materialized.py"
        materialized.write_bytes(Path(attempt["source_ref"]["path"]).read_bytes())
        receipt = {
            **binding,
            "owner_id": "owner-a", "input_identity": attempt["input_identity"],
            "patch_identity": hashlib.sha256(materialized.read_bytes()).hexdigest(),
            "evidence_refs": [self.artifact("existing-materialization", {
                "path": str(materialized), "sha256": hashlib.sha256(materialized.read_bytes()).hexdigest()})],
            "authorization_revision": self.auth["revision"],
            "observed_at": datetime.now(timezone.utc).isoformat()}
        self.authorize("PUBLISH_EXISTING")
        before = materialized.read_bytes()
        self.ledger.require_operation("review")
        self.ledger.require_operation("record_receipt")
        for operation in ("launch", "resume", "reconstruct", "verify", "materialize", "cleanup"):
            with self.assertRaises(PolicyError):
                self.ledger.require_operation(operation, self.auth["revision"])
        self.transition("review_wait")
        self.transition("reconciling", {"review": {
            **binding,
            "approved_by": "fixture-parent", "input_identity": attempt["input_identity"],
            "evidence_refs": attempt["evidence_refs"]}})
        with self.assertRaises(PolicyError):
            self.transition("publication_wait", {"materialization": receipt | {
                "observed_at": datetime.now(timezone.utc).isoformat()}})
        a = self.transition("publication_wait", {"materialization": receipt})
        self.assertEqual(a["status"], "publication_wait")
        self.assertEqual(materialized.read_bytes(), before)
        self.assertEqual(a["owner_id"], "owner-a")
        self.assertTrue(self.ledger.session("session-a")["active"])
        record = self.publish_observation()
        self.assertEqual(self.ledger.assignment("a")["status"], "pushed")
        self.assertTrue(self.ledger.session("session-a")["active"])

    def test_worker_success_without_measured_acceptance_is_rejected(self):
        self.create()
        _, attempt = self.measure()
        with self.assertRaises(StateError):
            self.transition("review_wait")
        with self.assertRaises(StateError):
            self.ledger.record_verification("a", event_id=self.event(), candidate_id="initial",
                                            input_identity=attempt["input_identity"],
                                            evidence={"scope": "reconstruction", "checks": {"worker_success": "true"},
                                                      "runtime_status": "unavailable"},
                                            authorization_revision=self.auth["revision"])
        self.verify("a", attempt)
        a = self.transition("review_wait")
        self.assertEqual(a["accepted_credit"], 0)
        self.assertTrue(self.ledger.session("session-a")["active"])
        with self.assertRaises(StateError):
            self.transition("closed")

    def test_publication_restart_duplicate_commit_and_owner_cleanup_lifecycle(self):
        self.ready()
        intent = self.prepare_publication()
        self.ledger = Ledger(self.db)
        self.assertEqual(self.ledger.publication("a")["planned_commit"], intent["planned_commit"])
        commit = self.admit(intent, "commit", effect_id="commit-effect", event_id="commit-admission")
        self.commit_effect(intent, commit)
        duplicate = self.admit(intent, "commit", effect_id="commit-effect", event_id="commit-admission")
        self.assertFalse(duplicate["execute"])
        self.assertEqual(self.ledger.assignment("a")["status"], "committed")
        self.ledger = Ledger(self.db)
        self.assertFalse(self.ledger.publication("a")["pushed"])
        push = self.admit(intent, "push")
        observation = self.push_effect(intent, push, observe=False)
        record = self.ledger.observe_publication_effect("a", effect_id=push["effect_id"],
                                                        event_id="push-observed", record=observation)
        self.ledger.observe_publication_effect("a", effect_id=push["effect_id"],
                                               event_id="push-observed", record=observation)
        self.assertEqual(self.ledger.assignment("a")["status"], "pushed")
        count, _ = self.git(self.root / "repo-a", "rev-list", "--count", "HEAD")
        self.assertEqual(count, "2")  # One fixture baseline and one assignment commit.
        self.assertEqual(Ledger(self.db).publication("a")["commit"], record["commit"])
        self.assertTrue(Ledger(self.db).publication("a")["pushed"])
        self.assertTrue(self.ledger.session("session-a")["active"])
        self.transition("publication_acknowledged", {"acknowledgment": {
            key: record[key] for key in ("commit", "branch", "patch_identity", "input_identity")
        } | {"acknowledged_by": "fixture-parent"}})
        self.transition("cleanup")
        preserved = Path(self.ledger.assignment("a")["best_candidate"]["source_ref"]["path"])
        retained = self.artifact("cleanup-observation", {
            "removed_paths": [], "removed_bytes": 0, "retained_path": str(preserved),
            "retained_sha256": hashlib.sha256(preserved.read_bytes()).hexdigest(),
            "is_symlink": preserved.is_symlink(), "scope": "evaluation_fixture",
            "original_input_ref": str(self.header),
            "original_input_sha256": hashlib.sha256(self.header.read_bytes()).hexdigest()})
        self.transition("closed", {"cleanup": {"retained_evidence_refs": [retained], "removed_paths": [],
                                               "removed_bytes": 0, "shared_link_checks_ref": retained,
                                               "original_input_checks_ref": retained}})
        self.assertFalse(self.ledger.session("session-a")["active"])
        self.create("next-function")
        with self.assertRaises(StateError):
            self.create("reuse-after-close", owner_id="owner-a")
        with self.assertRaises(StateError):
            self.ledger.record_publication("a", event_id=self.event(), record=record | {"commit": "0" * 40})

    def test_publication_target_and_request_cannot_be_substituted(self):
        self.ready()
        self.ready("other")
        intent = self.prepare_publication()
        other = self.ledger.assignment("other")["materialization"]
        target = other["publication_target"]
        original_head, _ = self.git(Path(target["repository"]), "rev-parse", "HEAD")
        original_remote, _ = self.git(Path(target["repository"]), "ls-remote", target["remote"], "refs/heads/main")
        with self.assertRaises(StateError):
            self.ledger.record_publication("a", event_id=self.event(), record=intent | {
                "publication_target": target, "remote": target["remote"], "branch": target["branch"]})
        with self.assertRaises(StateError):
            self.admit(intent | {"publication_target": target}, "commit")
        with self.assertRaises(StateError):
            self.admit(intent | {"request_digest": other["request_digest"]}, "commit")
        self.assertEqual(self.ledger.publication_effects("a"), [])
        self.assertEqual(self.git(Path(target["repository"]), "rev-parse", "HEAD")[0], original_head)
        self.assertEqual(self.git(Path(target["repository"]), "ls-remote", target["remote"], "refs/heads/main")[0],
                         original_remote)
        self.create("approval-mismatch")
        _, attempt = self.measure("approval-mismatch")
        self.verify("approval-mismatch", attempt)
        self.transition("review_wait", assignment_id="approval-mismatch")
        binding = self.publication_binding("approval-mismatch")
        self.transition("reconciling", {"review": binding | {
            "approved_by": "fixture-parent", "input_identity": attempt["input_identity"],
            "evidence_refs": attempt["evidence_refs"]}}, "approval-mismatch")
        materialization = binding | {
            "owner_id": "owner-approval-mismatch", "input_identity": attempt["input_identity"],
            "patch_identity": attempt["source_ref"]["sha256"], "evidence_refs": attempt["evidence_refs"]}
        for changed in ({"publication_target": target}, {"request_digest": other["request_digest"]}):
            with self.assertRaises(StateError):
                self.transition("publication_wait", {"materialization": materialization | changed}, "approval-mismatch")

    def test_stop_before_admission_blocks_effect_and_unadmitted_observation(self):
        self.ready()
        intent = self.prepare_publication()
        repo = Path(intent["publication_target"]["repository"])
        before_local, _ = self.git(repo, "rev-parse", "HEAD")
        before_remote, _ = self.git(repo, "ls-remote", intent["remote"], "refs/heads/main")
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Stop precedes publication admission")
        self.ledger = Ledger(self.db)
        with self.assertRaises(PolicyError):
            self.admit(intent, "commit")
        with self.assertRaises(PolicyError):
            self.ledger.record_publication("a", event_id=self.event(), record=intent)
        with self.assertRaises(StateError):
            self.ledger.observe_publication_effect("a", effect_id="never-admitted", event_id=self.event(), record={
                "local_head": before_local, "effect_observed": False, "observation_ref": intent["observation_ref"]})
        self.assertEqual(self.ledger.publication_effects("a"), [])
        self.assertEqual(self.ledger.authorization(), stopped)
        self.assertEqual(self.git(repo, "rev-parse", "HEAD")[0], before_local)
        self.assertEqual(self.git(repo, "ls-remote", intent["remote"], "refs/heads/main")[0], before_remote)

    def test_unexecuted_admission_is_observable_but_not_replayed_after_stop(self):
        self.ready()
        intent = self.prepare_publication()
        effect = self.admit(intent, "commit", effect_id="never-executed", event_id="admitted-before-crash")
        self.assertTrue(effect["execute"])
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Caller exited before admitted mutation")
        self.ledger = Ledger(self.db)
        repo = Path(intent["publication_target"]["repository"])
        head, ref = self.git(repo, "rev-parse", "HEAD")
        self.assertEqual(head, intent["base_head"])
        result = self.ledger.observe_publication_effect("a", effect_id=effect["effect_id"], event_id=self.event(),
            record={"local_head": head, "effect_observed": False, "observation_ref": ref})
        self.assertIsNone(result["commit"])
        self.assertFalse(result["pushed"])
        duplicate = self.admit(intent, "commit", effect_id="never-executed", event_id="admitted-before-crash")
        self.assertFalse(duplicate["execute"])
        with self.assertRaises(PolicyError):
            self.admit(intent, "commit")
        self.assertEqual(self.git(repo, "rev-parse", "HEAD")[0], intent["base_head"])
        remote, _ = self.git(repo, "ls-remote", intent["remote"], "refs/heads/main")
        self.assertEqual(remote.split()[0], intent["base_head"])
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_admitted_commit_after_stop_recovers_without_admitting_push(self):
        self.ready()
        intent = self.prepare_publication()
        effect = self.admit(intent, "commit", effect_id="ordered-commit", event_id="ordered-admission")
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Stop after commit admission")
        observation = self.commit_effect(intent, effect, observe=False)
        self.assertIsNone(self.ledger.publication("a")["commit"])
        self.ledger = Ledger(self.db)
        recovered = self.ledger.observe_publication_effect("a", effect_id=effect["effect_id"],
                                                           event_id=self.event(), record=observation)
        self.assertEqual(recovered["commit"], intent["planned_commit"])
        self.assertFalse(recovered["pushed"])
        self.assertEqual(self.ledger.authorization(), stopped)
        self.assertFalse(self.admit(intent, "commit", effect_id="ordered-commit",
                                    event_id="ordered-admission")["execute"])
        self.assertFalse(self.admit(intent, "commit", effect_id="ordered-commit")["execute"])
        with self.assertRaises(StateError):
            self.admit(intent, "push", effect_id="ordered-commit")
        with self.assertRaises(PolicyError):
            self.admit(intent, "push")
        with self.assertRaises(StateError):
            self.ledger.observe_publication_effect("a", effect_id=effect["effect_id"],
                                                   event_id=self.event(), record=observation | {"mode": "RUN"})
        remote, _ = self.git(Path(intent["publication_target"]["repository"]), "ls-remote",
                             intent["remote"], "refs/heads/main")
        self.assertEqual(remote.split()[0], intent["base_head"])
        self.assertEqual(len(self.ledger.publication_effects("a")), 1)
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_admitted_push_after_stop_preserves_actual_and_historical_outcomes(self):
        self.ready()
        intent = self.prepare_publication()
        self.commit_effect(intent, self.admit(intent, "commit"))
        effect = self.admit(intent, "push")
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Stop after push admission")
        observation = self.push_effect(intent, effect, observe=False)
        self.assertFalse(self.ledger.publication("a")["pushed"])
        self.ledger = Ledger(self.db)
        recovered = self.ledger.observe_publication_effect("a", effect_id=effect["effect_id"],
                                                           event_id="actual-push", record=observation)
        self.assertTrue(recovered["pushed"])
        self.assertTrue(recovered["remote_contains_commit"])
        self.assertEqual(self.ledger.authorization(), stopped)
        self.ledger.observe_publication_effect("a", effect_id=effect["effect_id"],
                                               event_id="actual-push", record=observation)
        saved_effect = next(item for item in self.ledger.publication_effects("a") if item["effect_id"] == effect["effect_id"])
        self.assertEqual(len(saved_effect["observations"]), 1)
        # An independent fixture-admin action models later loss of the remote ref.
        # It is not a publisher action and does not grant a replay of the old admission.
        self.git(Path(intent["remote"]), "update-ref", "-d", "refs/heads/main")
        current, ref = self.git(Path(intent["publication_target"]["repository"]), "ls-remote",
                                intent["remote"], "refs/heads/main")
        self.assertEqual(current, "")
        current_observation = dict(observation, pushed=False, remote_contains_commit=False,
                                   remote_head=None, effect_observed=False, observation_ref=ref)
        latest = self.ledger.observe_publication_effect("a", effect_id=effect["effect_id"],
                                                        event_id=self.event(), record=current_observation)
        self.assertTrue(latest["pushed"])
        self.assertFalse(latest["remote_contains_commit"])
        self.assertEqual(self.ledger.authorization(), stopped)
        with self.assertRaises(PolicyError):
            self.admit(intent, "push")

    def test_concurrent_stop_and_admission_have_one_durable_order(self):
        self.ready()
        intent = self.prepare_publication()
        barrier = Barrier(2)
        revision = self.auth["revision"]
        def admit():
            ledger = Ledger(self.db)
            barrier.wait(timeout=30)
            try:
                return ledger.admit_publication_effect("a", effect_id="racing-effect", kind="commit",
                    request_digest=intent["request_digest"], target=intent["publication_target"],
                    planned_commit=intent["planned_commit"], authorization_revision=revision, event_id="racing-admission")
            except PolicyError:
                return None
        def stop():
            ledger = Ledger(self.db)
            barrier.wait(timeout=30)
            return ledger.request_stop(event_id="racing-stop", reason="Concurrent explicit stop")
        with ThreadPoolExecutor(max_workers=2) as executor:
            admitted = executor.submit(admit)
            stopped = executor.submit(stop)
            effect, stop_receipt = admitted.result(timeout=30), stopped.result(timeout=30)
        self.ledger = Ledger(self.db)
        self.assertEqual(self.ledger.authorization(), stop_receipt)
        self.assertEqual(stop_receipt["revision"], revision + 1)
        if effect is not None:
            self.assertTrue(effect["execute"])
            self.commit_effect(intent, effect)
            self.assertEqual(self.ledger.publication("a")["commit"], intent["planned_commit"])
        else:
            self.assertEqual(self.ledger.publication_effects("a"), [])
            self.assertEqual(self.git(Path(intent["publication_target"]["repository"]), "rev-parse", "HEAD")[0],
                             intent["base_head"])
        self.assertEqual(self.ledger.authorization(), stop_receipt)

    def test_checkpoint_keeps_publisher_and_publication_only_does_not_wake_owner(self):
        self.ready()
        publication = self.publish_observation()
        publisher = self.ledger.register_publisher(owner_id="publisher", session_id="publisher-session",
                                                   provider="fixture", model="fixture-sol", event_id=self.event(),
                                                   authorization_revision=self.auth["revision"])
        self.authorize("PUBLISH_EXISTING")
        for number in range(2):
            record = {"source_commit": publication["commit"], "report_ref": publication["observation_ref"],
                      "observation_ref": publication["observation_ref"], "checkpoint_number": number}
            result = self.ledger.publisher_checkpoint(event_id=self.event(), checkpoint_id=f"checkpoint-{number}", record=record)
        self.assertEqual(result["session_id"], publisher["session_id"])
        self.assertEqual(result["status"], "awaiting-parent")
        self.assertEqual(len(result["checkpoints"]), 2)
        self.assertTrue(self.ledger.session("publisher-session")["active"])
        self.assertTrue(self.ledger.session("session-a")["active"])
        with self.assertRaises(PolicyError):
            self.ledger.require_operation("resume", self.auth["revision"])


def trial_manifest(root):
    """Synthetic deterministic boundary records, never real trial evidence."""
    starts = (0xE228, 0xE230, 0xE238, 0xE240, 0xE248, 0xE250, 0xE258, 0xE260)
    reservations = []
    for index, start in enumerate(starts):
        reservations.append({
            "assignment_id": f"trial-{index}",
            "function": dict(module=117, symbol=f"fn_117_{start:X}", start=start, end=start + 8, size=8),
            "workspace": str(root / f"owner-{index}"),
            "owned_paths": [f"src/mo_fighter/ft_dedede/ft_dedede_function_{start:x}.cpp",
                            "configure.py", "config/RSBE01_02/rels/ft_dedede/splits.txt"],
            "baseline_commit": "a" * 40, "instruction_revision": "b" * 40,
            "recipe_ref": "synthetic-recipe", "input_identity": "c" * 64,
            "history": {"status": "known", "evidence_refs": ["synthetic-history"],
                        "stages": {name: {"initial_count": 0, "corrections": 0,
                                          "best_candidate": None, "evidence_refs": ["synthetic-none"]}
                                   for name in ("glm", "qwen", "sol", "astra")}}})
    return {"trial_id": "deterministic-boundary-test", "coordinator_id": "coordinator",
            "confirmed_by": "coordinator", "confirmation_refs": ["synthetic-reservation"],
            "slots": 4, "execution": {"provider": "synthetic-provider", "model": "synthetic-qwen",
                                      "endpoint": "synthetic-no-network", "configuration_ref": "synthetic-config"},
            "publication_target": {"repository": str(root / "external"), "remote": "https://example.invalid/no-effects",
                                   "branch": "main"}, "reservations": reservations}


def recorded_trial_history(root):
    """Synthetic bounded inventories; these are not recovered lifetime totals."""
    history = trial_manifest(root)["reservations"][0]["history"]
    history.update(status="recorded", count_scope="attributable_recorded_within_inventory",
                   lifetime_totals="unknown",
                   inventories={name: {"path": str(root / f"synthetic-{name}-inventory.json"),
                                       "sha256": ("a" if name == "journal" else "b") * 64,
                                       "coverage": f"Synthetic completed bounded {name} inventory; outside scope unknown",
                                       "complete": True}
                                for name in ("journal", "workspace")})
    return history


class TrialLedgerTests(unittest.TestCase):
    """No native/provider/Git effects: exercise the durable consumer boundaries."""

    def setUp(self, *, root=None):
        self.root = (Path(root) if root is not None else
                     ROOT / "build" / "orchestration-eval" / "tests" / "trial-state" / uuid.uuid4().hex)
        self.ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
        self.manifest = trial_manifest(self.root)
        self.serial = 0
        self.binding = None
        self.auth = self.ledger.authorize("RUN", event_id=self.event(), reason="Synthetic deterministic test",
                                          expected_revision=0)

    def event(self):
        self.serial += 1
        return f"trial-test-{self.serial}"

    def observation(self, **extra):
        return {"observed_at": datetime.now(timezone.utc).isoformat(),
                "timestamp_provenance": {"source": "deterministic unit test", "clock_id": "ledger_utc"},
                "evidence_refs": ["synthetic-boundary-evidence"], **extra}

    def prepare(self):
        trial = self.ledger.register_trial(manifest=self.manifest, event_id=self.event())
        self.digest = trial["manifest_digest"]
        self.gates = dict(manifest_digest=self.digest, confirmed_by="coordinator",
                          coordinator_ref="synthetic-coordinator", execution_ref="synthetic-execution",
                          dashboard_ref="synthetic-dashboard", evidence_refs=["synthetic-gates"])
        self.ledger.prepare_trial(gates=self.gates, event_id=self.event(), authorization_revision=self.auth["revision"])

    def claim(self, index, slot=None):
        return dict(assignment_id=f"trial-{index}", owner_id=f"owner-{index}",
                    root_session_id=f"root-{index}", slot=index if slot is None else slot)

    def initial(self, *, activate=True, prompts=True):
        self.prepare()
        result = self.ledger.claim_trial_initial(claims=[self.claim(i) for i in range(4)],
                                                 event_id=self.event(), authorization_revision=self.auth["revision"])
        if activate:
            for index in range(4):
                self.attach(index)
            self.ledger.activate_trial(gates=self.gates, event_id=self.event(), authorization_revision=self.auth["revision"])
            if prompts:
                self.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
                                                event_id=self.event(), authorization_revision=self.auth["revision"])
        return result

    def attach(self, index=0):
        key = f"trial-{index}"
        if self.ledger.assignment(key)["session_id"] is not None:
            return
        self.ledger.admit_trial_effect(key, effect_id=f"launch-{index}", kind="launch",
                                       event_id=self.event(), authorization_revision=self.auth["revision"])
        identity = dict(pid=10000 + index, creation_time=f"synthetic-{index}", token=f"token-{index}", job_name=f"job-{index}")
        self.ledger.register_process(process_id=f"process-{index}", session_id=None, identity=identity,
                                     event_id=self.event(), authorization_revision=self.auth["revision"])
        self.ledger.attach_trial_session(key, session_id=f"child-{index}", root_session_id=f"root-{index}",
                                         process_id=f"process-{index}", journal_ref="synthetic-journal",
                                         registry_ref="synthetic-native-registry", event_id=self.event())

    def measure(self, candidate="candidate", outcome="matching"):
        return self.ledger.record_attempt("trial-0", candidate_id=candidate,
                                         source_ref={"path": str(self.root / f"{candidate}.cpp"),
                                                     "sha256": hashlib.sha256(candidate.encode()).hexdigest()},
                                         input_identity="c" * 64, recipe_ref="synthetic-recipe",
                                         outcome=outcome, evidence_refs=["synthetic-measurement"], quality=1,
                                         event_id=self.event(), authorization_revision=self.auth["revision"])

    def verify(self, candidate="candidate", **overrides):
        evidence = dict(scope="reconstruction", checks={name: "synthetic-check" for name in (
            "compile", "object_compare", "data_relocations", "source_link", "binary_hashes")},
                        binary_hash_count=127, runtime_status="unavailable", runtime_reason="Synthetic ledger unit test")
        evidence.update(overrides)
        return self.ledger.record_verification("trial-0", candidate_id=candidate, input_identity="c" * 64,
                                              evidence=evidence, event_id=self.event(),
                                              authorization_revision=self.auth["revision"])

    def receipt(self, kind, **extra):
        if self.binding is None:
            request = dict(assignment_id="trial-0", owner_id="owner-0", session_id="child-0",
                           manifest_digest=self.digest, patch_identity="d" * 64, input_identity="c" * 64,
                           publication_target=self.manifest["publication_target"])
            self.binding = dict(request, request_digest=hashlib.sha256(
                json.dumps(request, sort_keys=True, separators=(",", ":")).encode()).hexdigest())
            self.request = request
        observed = self.observation()
        receipt = dict(self.binding, **observed, started_at=observed["observed_at"],
                       authorization_revision=self.auth["revision"],
                       observed_by="owner-0" if kind in {"materialization", "cleanup"} else "coordinator")
        defaults = {
            "review": {"request": self.request},
            "materialization": {"grant_ref": "synthetic-grant", "preservation_ref": "synthetic-preservation",
                                "private_index_ref": "synthetic-private-index"},
            "commit": {"commit": "e" * 40, "local_head": "e" * 40},
            "push": {"commit": "e" * 40, "push_exit_code": 0, "pushed": True,
                     "remote_contains_commit": True, "remote_head": "e" * 40},
            "ack": {"commit": "e" * 40, "accepted_matching": True},
            "cleanup": {"commit": "e" * 40, "retained_evidence_refs": ["synthetic-retained"],
                        "deletion_manifest_ref": "synthetic-empty-deletion-manifest",
                        "shared_link_checks_ref": "synthetic-links", "original_input_checks_ref": "synthetic-originals",
                        "retained_evidence_checks_ref": "synthetic-retained-hashes",
                        "tracked_files_preserved": True, "removed_paths": [], "removed_bytes": 0},
            "closed": {"commit": "e" * 40, "process_id": "process-0", "exit_evidence_ref": "synthetic-exit"}}
        return dict(receipt, **(defaults[kind] | extra))

    def observe(self, kind, receipt=None):
        return self.ledger.observe_trial_receipt("trial-0", kind=kind, receipt=receipt or self.receipt(kind),
                                                 event_id=self.event())

    def ready(self):
        self.initial()
        self.attach()
        self.measure()
        self.verify()
        self.ledger.transition("trial-0", "review_wait", details={}, event_id=self.event(),
                               authorization_revision=self.auth["revision"])
        self.observe("review")
        self.observe("materialization")

    def pushed(self):
        self.ready()
        self.observe("commit")
        self.observe("push")

    def exit(self):
        process = self.ledger.process("process-0")
        self.ledger.record_process_exit("process-0", event_id=self.event(), proof={
            **process["identity"], "observed_exit": True, "exit_code": 0,
            "verified_at": datetime.now(timezone.utc).isoformat(), "evidence_ref": "synthetic-exit"})

    def test_default_policy_is_unchanged_and_real_trial_is_explicit(self):
        self.assertEqual(SlotPolicy().capacity("qwen"), 3)
        self.assertEqual(SlotPolicy.real_trial().capacity("qwen"), 4)
        default = Ledger(self.root / "default.sqlite3")
        with self.assertRaises(PolicyError):
            default.register_trial(manifest=self.manifest, event_id="not-opted-in")
        self.assertNotIn("trial", default.snapshot())

    def test_unknown_history_is_not_zero_and_manifest_cannot_mutate(self):
        self.manifest["reservations"][0]["history"] = {"status": "unknown", "evidence_refs": ["pending-scout"]}
        self.prepare()
        with self.assertRaises(StateError):
            self.ledger.activate_trial(gates=self.gates, event_id=self.event(),
                                        authorization_revision=self.auth["revision"])
        self.manifest["reservations"][0]["history"] = trial_manifest(self.root)["reservations"][0]["history"]
        with self.assertRaises(StateError):
            self.ledger.register_trial(manifest=self.manifest, event_id=self.event())
        self.assertEqual(self.ledger.assignments(), [])

    def test_fixed_queue_and_all_four_initial_claims_are_atomic(self):
        self.prepare()
        claims = [self.claim(i) for i in range(4)]
        claims[3]["owner_id"] = claims[0]["owner_id"]
        with self.assertRaises(StateError):
            self.ledger.claim_trial_initial(claims=claims, event_id=self.event(),
                                            authorization_revision=self.auth["revision"])
        self.assertEqual(self.ledger.assignments(), [])
        with self.assertRaises(StateError):
            self.ledger.claim_trial_initial(claims=[self.claim(0)], event_id=self.event(),
                                            authorization_revision=self.auth["revision"])
        self.manifest["reservations"][7]["function"]["size"] = 16
        with self.assertRaises(StateError):
            self.ledger.register_trial(manifest=self.manifest, event_id=self.event())

    def test_initial_claim_concurrency_has_one_winner(self):
        self.prepare()
        barrier = Barrier(2)
        def claim(index):
            barrier.wait()
            try:
                return self.ledger.claim_trial_initial(claims=[self.claim(i) for i in range(4)],
                                                       event_id=f"concurrent-{index}", authorization_revision=self.auth["revision"])
            except StateError:
                return None
        with ThreadPoolExecutor(max_workers=2) as pool:
            results = list(pool.map(claim, (0, 1)))
        self.assertEqual(sum(result is not None for result in results), 1)
        self.assertEqual(len(Ledger(self.ledger.path).assignments()), 4)

    def test_effect_stop_race_and_duplicate_never_replays(self):
        self.initial(activate=False)
        barrier = Barrier(2)
        args = dict(effect_id="provider-boundary", kind="launch", event_id="admit-provider",
                    authorization_revision=self.auth["revision"])
        def admit():
            barrier.wait()
            try:
                return self.ledger.admit_trial_effect("trial-0", **args)
            except PolicyError:
                return None
        def stop():
            barrier.wait()
            return self.ledger.request_stop(event_id="stop-race", reason="Synthetic STOP race")
        with ThreadPoolExecutor(max_workers=2) as pool:
            admission, stopped = pool.submit(admit), pool.submit(stop)
            result, stop_receipt = admission.result(), stopped.result()
        if result:
            self.assertFalse(self.ledger.admit_trial_effect("trial-0", **args)["execute"])
            self.ledger.observe_trial_effect(effect_id="provider-boundary",
                                              record=self.observation(effect_observed=True), event_id=self.event())
        self.assertEqual(self.ledger.authorization(), stop_receipt)
        with self.assertRaises(PolicyError):
            self.ledger.admit_trial_effect("trial-1", effect_id="new-after-stop", kind="launch",
                                           event_id=self.event(), authorization_revision=self.auth["revision"])

    def test_native_attachment_and_same_owner_are_required(self):
        self.initial(activate=False)
        with self.assertRaises(StateError):
            self.measure()
        self.attach()
        self.assertEqual(self.ledger.session("child-0")["owner_id"], "owner-0")
        with self.assertRaises(PolicyError):
            self.ledger.escalate("trial-0", stage="sol", provider="other", model="other",
                                 owner_id="replacement", session_id="replacement", event_id=self.event(),
                                 authorization_revision=self.auth["revision"])

    def test_preserved_qwen_counts_do_not_reset_on_fresh_owner(self):
        stage = self.manifest["reservations"][0]["history"]["stages"]["qwen"]
        stage.update(initial_count=1, corrections=9, best_candidate={
            "candidate_id": "inherited", "source_ref": {"path": "preserved-best.cpp", "sha256": "f" * 64},
            "input_identity": "c" * 64, "recipe_ref": "preserved-recipe", "outcome": "nonmatching",
            "evidence_refs": ["preserved-comparison"], "quality": 0})
        self.initial()
        self.attach()
        measured = self.measure("last-correction", outcome="nonmatching")
        self.assertEqual(measured["stages"][-1]["corrections"], 10)
        with self.assertRaises(StateError):
            self.measure("eleventh-correction", outcome="nonmatching")
        self.assertEqual(len(self.ledger.assignment("trial-0")["stages"][-1]["attempts"]), 2)

    def test_tool_failures_do_not_consume_or_exhaust(self):
        self.initial()
        self.attach()
        result = self.measure("tool-failure", outcome="tool_failed")
        self.assertEqual(result["stages"][-1]["initial_count"], 0)
        self.assertEqual(result["status"], "blocked")
        with self.assertRaises(StateError):
            self.ledger.exhaust_stage("trial-0", event_id=self.event(), evidence_refs=["synthetic"],
                                      authorization_revision=self.auth["revision"])

    def test_fixture_verification_and_model_success_never_accept(self):
        self.initial()
        self.attach()
        self.measure()
        with self.assertRaises(StateError):
            self.verify(scope="evaluation_fixture")
        with self.assertRaises(StateError):
            self.verify(binary_hash_count=126)
        with self.assertRaises(StateError):
            self.ledger.transition("trial-0", "review_wait", details={"success": True}, event_id=self.event(),
                                   authorization_revision=self.auth["revision"])
        self.assertEqual(self.ledger.assignment("trial-0")["accepted_credit"], 0)

    def test_external_receipts_bind_exact_identity_and_never_grant_git(self):
        self.ready()
        for changed in ({"owner_id": "other"}, {"patch_identity": "f" * 64}, {"input_identity": "f" * 64},
                        {"publication_target": dict(self.manifest["publication_target"], branch="other")}):
            with self.assertRaises(StateError):
                self.observe("commit", self.receipt("commit", **changed))
        with self.assertRaises(PolicyError):
            self.ledger.admit_publication_effect("trial-0", effect_id="forged-evaluator-admission", kind="commit",
                                                 request_digest=self.binding["request_digest"],
                                                 target={"repository": str(self.root), "remote": str(self.root / "local"), "branch": "main"},
                                                 planned_commit="e" * 40, event_id=self.event(),
                                                 authorization_revision=self.auth["revision"])
        self.assertEqual(self.ledger.publication_effects("trial-0"), [])

    def test_inflight_push_after_stop_is_observation_not_new_authority(self):
        self.ready()
        self.observe("commit")
        receipt = self.receipt("push")
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Synthetic in-flight push")
        receipt["observed_at"] = datetime.now(timezone.utc).isoformat()
        self.observe("push", receipt)
        self.observe("push", receipt)
        assignment = self.ledger.assignment("trial-0")
        self.assertTrue(assignment["publication"]["pushed"])
        self.assertEqual(len(assignment["external_receipts"]["push"]), 1)
        self.assertEqual(self.ledger.authorization(), stopped)
        self.observe("ack")
        self.assertEqual(self.ledger.authorization(), stopped)
        with self.assertRaises(PolicyError):
            self.observe("push")

    def test_failed_push_and_stale_verification_cannot_be_accepted(self):
        self.ready()
        self.observe("commit")
        self.observe("push", self.receipt("push", push_exit_code=1, pushed=False, remote_contains_commit=False))
        with self.assertRaises(StateError):
            self.observe("ack")
        self.observe("push")
        self.ledger.check_input_identity("trial-0", input_identity="f" * 64, evidence_ref="synthetic-changed",
                                         event_id=self.event())
        with self.assertRaises(StateError):
            self.observe("ack")

    def test_actual_exit_cleanup_ack_release_one_slot_independently(self):
        self.pushed()
        self.observe("ack")
        with self.assertRaises(StateError):
            self.observe("closed")
        self.observe("cleanup")
        with self.assertRaises(StateError):
            self.observe("closed")
        with self.assertRaises(StateError):
            self.ledger.claim_trial_refill(claim=self.claim(4, 0), event_id=self.event(),
                                           authorization_revision=self.auth["revision"])
        self.exit()
        self.observe("closed")
        self.ledger.claim_trial_refill(claim=self.claim(4, 0), event_id=self.event(),
                                       authorization_revision=self.auth["revision"])
        snapshot = self.ledger.snapshot()
        self.assertEqual(snapshot["assignments"]["trial-0"]["status"], "closed")
        self.assertEqual(snapshot["assignments"]["trial-1"]["status"], "assigned")
        self.assertEqual(snapshot["trial"]["claims"]["trial-4"]["slot"], 0)
        self.assertEqual(snapshot["assignments"]["trial-0"]["accepted_credit"], 0)

    def test_retained_owner_messages_are_exact_once_and_stop_ordered(self):
        self.pushed()
        self.observe("ack")
        request = dict(message="Perform canonical cleanup", owner_id="owner-0", session_id="child-0",
                       manifest_digest=self.digest, coordinator_id="coordinator", purpose="cleanup", receipt_ref="synthetic-ACK")
        args = dict(message_id="cleanup-message", request=request, event_id=self.event(),
                    authorization_revision=self.auth["revision"])
        self.assertTrue(self.ledger.admit_trial_message("trial-0", **args)["execute"])
        self.ledger.request_stop(event_id=self.event(), reason="Synthetic message STOP")
        self.assertFalse(self.ledger.admit_trial_message("trial-0", **args)["execute"])
        with self.assertRaises(PolicyError):
            self.ledger.admit_trial_message("trial-0", **(args | {"message_id": "new-id", "event_id": self.event()}))


    def test_provider_forwarding_requires_four_actual_children_and_atomic_admission(self):
        self.initial(activate=False)
        self.attach(0)
        with self.assertRaises(StateError):
            self.ledger.activate_trial(gates=self.gates, event_id=self.event(), authorization_revision=self.auth["revision"])
        for index in range(1, 4):
            self.attach(index)
        with self.assertRaises(PolicyError):
            self.ledger.admit_trial_effect("trial-0", effect_id="single-prompt", kind="prompt",
                                           event_id=self.event(), authorization_revision=self.auth["revision"])
        self.ledger.activate_trial(gates=self.gates, event_id=self.event(), authorization_revision=self.auth["revision"])
        args = dict(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
                    event_id=self.event(), authorization_revision=self.auth["revision"])
        first = self.ledger.admit_trial_prompts(**args)
        self.assertTrue(first["execute"])
        self.assertEqual(len(first["effects"]), 4)
        self.ledger.request_stop(event_id=self.event(), reason="Synthetic batch STOP")
        duplicate = self.ledger.admit_trial_prompts(**args)
        self.assertFalse(duplicate["execute"])
        self.assertTrue(all(not effect["execute"] for effect in duplicate["effects"]))

    def test_exhausted_qwen_keeps_fallback_and_never_receives_matching_credit(self):
        self.initial()
        for index in range(11):
            self.measure(f"candidate-{index}", outcome="nonmatching")
        self.ledger.exhaust_stage("trial-0", event_id=self.event(), evidence_refs=["synthetic-exhaustion"],
                                  authorization_revision=self.auth["revision"])
        selection = {"candidate_id": "candidate-0", "accepted_credit": 0, "fallback_ref": "synthetic-original",
                     "input_identity": "c" * 64, "evidence_refs": ["synthetic-best"],
                     "label": "nonmatching—attempts exhausted"}
        self.ledger.transition("trial-0", "review_wait", details={"selection": selection}, event_id=self.event(),
                               authorization_revision=self.auth["revision"])
        self.observe("review")
        self.verify(candidate="candidate-0")
        self.observe("materialization")
        self.observe("commit")
        self.observe("push")
        with self.assertRaises(StateError):
            self.observe("ack")
        self.observe("ack", self.receipt("ack", accepted_matching=False))
        self.assertEqual(self.ledger.assignment("trial-0")["accepted_credit"], 0)

    def test_inflight_measurement_receipt_survives_stop_without_resetting_counts(self):
        self.initial()
        observation = self.observation(assignment_id="trial-0", owner_id="owner-0", session_id="child-0",
                                       manifest_digest=self.digest, authorization_revision=self.auth["revision"])
        observation["started_at"] = observation["observed_at"]
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Synthetic measured work in flight")
        observation["observed_at"] = datetime.now(timezone.utc).isoformat()
        args = dict(candidate_id="inflight", source_ref={"path": "synthetic.cpp", "sha256": "f" * 64},
                    input_identity="c" * 64, recipe_ref="synthetic-recipe", outcome="matching",
                    evidence_refs=["synthetic-comparison"], authorization_revision=self.auth["revision"],
                    observation=observation, event_id=self.event())
        self.ledger.record_attempt("trial-0", **args)
        self.ledger.record_attempt("trial-0", **args)
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 1)
        self.assertEqual(self.ledger.authorization(), stopped)
        observation["started_at"] = datetime.now(timezone.utc).isoformat()
        observation["observed_at"] = observation["started_at"]
        with self.assertRaises(PolicyError):
            self.ledger.record_attempt("trial-0", **(args | {"event_id": self.event(), "candidate_id": "after-stop"}))


    def test_exhaustion_observation_after_stop_keeps_counts_and_authorization(self):
        self.initial()
        for index in range(11):
            self.measure(f"nonmatching-{index}", outcome="nonmatching")
        observation = self.observation(assignment_id="trial-0", owner_id="owner-0", session_id="child-0",
                                       manifest_digest=self.digest, authorization_revision=self.auth["revision"])
        observation["started_at"] = observation["observed_at"]
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Synthetic exhaustion observation")
        observation["observed_at"] = datetime.now(timezone.utc).isoformat()
        self.ledger.exhaust_stage("trial-0", event_id=self.event(), evidence_refs=["synthetic-ten-corrections"],
                                  authorization_revision=self.auth["revision"], observation=observation)
        assignment = self.ledger.assignment("trial-0")
        self.assertEqual(assignment["status"], "exhausted")
        self.assertEqual(assignment["stages"][-1]["corrections"], 10)
        self.assertEqual(assignment["accepted_credit"], 0)
        self.assertEqual(self.ledger.authorization(), stopped)


    def test_known_initial_four_do_not_wait_for_unknown_queued_history(self):
        for reservation in self.manifest["reservations"][4:]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.initial()
        snapshot = self.ledger.snapshot()
        self.assertIsNotNone(snapshot["trial"]["activation"])
        self.assertEqual(len(snapshot["assignments"]), 4)
        self.assertEqual(snapshot["trial"]["manifest"], self.manifest)
        self.assertEqual(snapshot["trial"]["manifest"]["reservations"][4]["history"]["status"], "unknown")

    def test_history_resolution_is_append_only_bound_and_never_resets_known_counts(self):
        known = self.manifest["reservations"][4]["history"]
        known["stages"]["qwen"].update(
            initial_count=1, corrections=3,
            best_candidate={"candidate_id": "preserved-best", "source_ref": {"path": "preserved.cpp", "sha256": "f" * 64},
                            "input_identity": "c" * 64, "recipe_ref": "preserved-recipe", "outcome": "nonmatching",
                            "evidence_refs": ["preserved-attempt-ledger"], "quality": 1})
        self.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        trial = self.ledger.register_trial(manifest=self.manifest, event_id=self.event())
        record = self.observation(assignment_id="trial-4", manifest_digest=trial["manifest_digest"], observed_by="coordinator")
        args = dict(history=known, record=record, event_id=self.event())
        self.ledger.resolve_trial_history("trial-4", **args)
        self.ledger.resolve_trial_history("trial-4", **args)
        self.assertEqual(self.ledger.trial_history("trial-4"), known)
        self.assertEqual(self.ledger.snapshot()["trial"]["manifest"], self.manifest)
        replacement = json.loads(json.dumps(known))
        replacement["stages"]["qwen"].update(initial_count=0, corrections=0, best_candidate=None)
        with self.assertRaises(StateError):
            self.ledger.resolve_trial_history("trial-4", history=replacement, record=record, event_id=self.event())
        self.assertEqual(self.ledger.trial_history("trial-4")["stages"]["qwen"]["corrections"], 3)

    def test_history_resolution_rejects_owner_assertion_and_wrong_manifest(self):
        known = self.manifest["reservations"][4]["history"]
        self.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        trial = self.ledger.register_trial(manifest=self.manifest, event_id=self.event())
        record = self.observation(assignment_id="trial-4", manifest_digest=trial["manifest_digest"], observed_by="owner-4")
        with self.assertRaises(StateError):
            self.ledger.resolve_trial_history("trial-4", history=known, record=record, event_id=self.event())
        record.update(observed_by="coordinator", manifest_digest="f" * 64)
        with self.assertRaises(StateError):
            self.ledger.resolve_trial_history("trial-4", history=known, record=record, event_id=self.event())
        self.assertEqual(self.ledger.trial_history("trial-4")["status"], "unknown")


    def test_resolved_refill_preserves_counts_and_bypasses_unknown_queued_predecessor(self):
        known = self.manifest["reservations"][5]["history"]
        known["stages"]["qwen"].update(
            initial_count=1, corrections=3,
            best_candidate={"candidate_id": "prior-best", "source_ref": {"path": "prior.cpp", "sha256": "f" * 64},
                            "input_identity": "c" * 64, "recipe_ref": "prior-recipe", "outcome": "nonmatching",
                            "evidence_refs": ["prior-attempt-ledger"], "quality": 1})
        for reservation in self.manifest["reservations"][4:]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["pending-history"]}
        self.pushed()
        self.observe("ack")
        self.observe("cleanup")
        self.exit()
        self.observe("closed")
        self.assertEqual(self.ledger.snapshot()["trial"]["capacity_history"][-1]["queued_reasons"]["trial-4"], "input_wait")
        record = self.observation(assignment_id="trial-5", manifest_digest=self.digest, observed_by="coordinator")
        self.ledger.resolve_trial_history("trial-5", history=known, record=record, event_id=self.event())
        assignment = self.ledger.claim_trial_refill(claim=self.claim(5, 0), event_id=self.event(),
                                                     authorization_revision=self.auth["revision"])
        self.assertEqual(assignment["stages"][-1]["corrections"], 3)
        self.assertEqual(assignment["identity"]["history"], known)
        self.assertEqual(assignment["identity"]["reservation"]["history"]["status"], "unknown")
        self.assertEqual(self.ledger.snapshot()["trial"]["manifest"], self.manifest)
        self.assertEqual(self.ledger.snapshot()["trial"]["capacity_history"][-1]["queued_reasons"]["trial-4"], "input_wait")
        self.assertEqual(self.ledger.assignment("trial-1")["status"], "assigned")

    def test_concurrent_history_resolution_retains_one_immutable_recovery(self):
        known = self.manifest["reservations"][4]["history"]
        self.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["pending-history"]}
        trial = self.ledger.register_trial(manifest=self.manifest, event_id=self.event())
        record = self.observation(assignment_id="trial-4", manifest_digest=trial["manifest_digest"], observed_by="coordinator")
        barrier = Barrier(2)
        def resolve(index):
            history = json.loads(json.dumps(known))
            history["evidence_refs"] = [f"independent-recovery-{index}"]
            barrier.wait()
            try:
                return self.ledger.resolve_trial_history("trial-4", history=history, record=record,
                                                         event_id=f"concurrent-history-{index}")
            except StateError:
                return None
        with ThreadPoolExecutor(max_workers=2) as pool:
            results = list(pool.map(resolve, (0, 1)))
        winners = [result for result in results if result is not None]
        self.assertEqual(len(winners), 1)
        self.assertEqual(self.ledger.trial_history("trial-4"), winners[0]["history"])
        self.assertEqual(self.ledger.snapshot()["trial"]["manifest"], self.manifest)


    def history_resolution_record(self, index):
        return self.observation(assignment_id=f"trial-{index}", manifest_digest=self.digest,
                                observed_by="coordinator", interpretation_ack_ref="TrialAdmissionExistingPlan4b9")

    def held_unknown_refill(self):
        for reservation in self.manifest["reservations"][4:]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.pushed()
        self.observe("ack")
        self.observe("cleanup")
        self.exit()
        self.observe("closed")
        self.ledger.claim_trial_refill(claim=self.claim(5, 0), event_id=self.event(),
                                       authorization_revision=self.auth["revision"])
        self.attach(5)

    def test_history_admission_unknown_initials_prepare_only_held_children(self):
        for reservation in self.manifest["reservations"]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.initial(activate=False)
        for index in range(4):
            self.attach(index)
            assignment = self.ledger.assignment(f"trial-{index}")
            self.assertEqual(assignment["session_id"], f"child-{index}")
            for stage in assignment["stages"]:
                self.assertIsNone(stage["initial_count"])
                self.assertIsNone(stage["corrections"])
                self.assertIsNone(stage["inherited_initial_count"])
                self.assertIsNone(stage["inherited_corrections"])
        with self.assertRaises(StateError):
            self.ledger.activate_trial(gates=self.gates, event_id=self.event(),
                                        authorization_revision=self.auth["revision"])
        with self.assertRaises(StateError):
            self.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
                                            event_id=self.event(), authorization_revision=self.auth["revision"])
        self.assertEqual({e["kind"] for e in self.ledger.snapshot()["trial"]["effects"].values()}, {"launch"})
        self.assertEqual(self.ledger.snapshot()["trial"]["manifest"], self.manifest)

    def test_history_admission_recorded_scope_is_append_only_not_lifetime_zero(self):
        self.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.prepare()
        history = recorded_trial_history(self.root)
        args = dict(history=history, record=self.history_resolution_record(4), event_id=self.event())
        first = self.ledger.resolve_trial_history("trial-4", **args)
        self.assertEqual(self.ledger.resolve_trial_history("trial-4", **args), first)
        self.assertEqual(self.ledger.trial_history("trial-4"), history)
        self.assertEqual(first["history"]["lifetime_totals"], "unknown")
        self.assertEqual(self.ledger.snapshot()["trial"]["manifest"], self.manifest)
        replacement = dict(history, evidence_refs=["different-inventory"])
        with self.assertRaises(StateError):
            self.ledger.resolve_trial_history("trial-4", history=replacement,
                                               record=args["record"], event_id=self.event())

    def test_history_admission_requires_both_complete_bound_inventories_and_ack(self):
        self.manifest["reservations"][4]["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.prepare()
        valid = recorded_trial_history(self.root)
        invalid = [dict(valid, lifetime_totals=0), dict(valid, count_scope="lifetime"),
                   dict(valid, status="known"),
                   dict(valid, inventories={"journal": valid["inventories"]["journal"]})]
        for field, value in (("complete", False), ("sha256", "unknown"), ("coverage", ""), ("path", "relative.json")):
            changed = json.loads(json.dumps(valid))
            changed["inventories"]["workspace"][field] = value
            invalid.append(changed)
        for history in invalid:
            with self.subTest(history=history), self.assertRaises(StateError):
                self.ledger.resolve_trial_history("trial-4", history=history,
                                                   record=self.history_resolution_record(4), event_id=self.event())
        for changed in ({"observed_by": "owner-4"}, {"manifest_digest": "f" * 64},
                        {"assignment_id": "trial-5"}, {"interpretation_ack_ref": ""}):
            with self.subTest(changed=changed), self.assertRaises(StateError):
                self.ledger.resolve_trial_history("trial-4", history=valid,
                    record=self.history_resolution_record(4) | changed, event_id=self.event())
        self.assertEqual(self.ledger.trial_history("trial-4")["status"], "unknown")
        self.ledger.resolve_trial_history("trial-4", history=valid,
                                           record=self.history_resolution_record(4), event_id=self.event())

    def test_history_admission_rejects_aliased_inventory_identities(self):
        for reservation in self.manifest["reservations"][4:]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.prepare()
        for index, case in enumerate(("same-artifact", "same-path", "normalized-path", "copied-content"), start=4):
            history = recorded_trial_history(self.root)
            journal, workspace = history["inventories"]["journal"], history["inventories"]["workspace"]
            if case == "same-artifact":
                history["inventories"]["workspace"] = dict(journal)
            elif case == "same-path":
                workspace["path"] = journal["path"]
            elif case == "normalized-path":
                path = Path(journal["path"])
                workspace["path"] = str(path.parent / "synthetic-child" / ".." / path.name).swapcase()
            else:
                workspace["sha256"] = journal["sha256"]
            with self.subTest(case=case):
                with self.assertRaises(StateError):
                    self.ledger.resolve_trial_history(f"trial-{index}", history=history,
                        record=self.history_resolution_record(index), event_id=self.event())
                self.assertEqual(self.ledger.trial_history(f"trial-{index}")["status"], "unknown")

    def test_history_admission_held_owner_preserves_recovered_counts_and_limit(self):
        for reservation in self.manifest["reservations"]:
            reservation["history"] = {"status": "unknown", "evidence_refs": ["synthetic-pending-history"]}
        self.initial(activate=False)
        for index in range(4):
            self.attach(index)
        identity = self.ledger.assignment("trial-0")["identity"]
        for index in range(4):
            history = recorded_trial_history(self.root)
            if index == 0:
                history["stages"]["qwen"].update(initial_count=1, corrections=9, best_candidate={
                    "candidate_id": "recovered-best", "source_ref": {"path": "recovered.cpp", "sha256": "f" * 64},
                    "input_identity": "c" * 64, "recipe_ref": "recovered-recipe", "outcome": "nonmatching",
                    "evidence_refs": ["synthetic-recovered-attempt-ledger"], "quality": 0.9})
            self.ledger.resolve_trial_history(f"trial-{index}", history=history,
                                               record=self.history_resolution_record(index), event_id=self.event())
        assignment = self.ledger.assignment("trial-0")
        self.assertEqual(assignment["identity"], identity)
        self.assertEqual(assignment["session_id"], "child-0")
        self.assertEqual(assignment["admitted_history"]["lifetime_totals"], "unknown")
        self.assertEqual(assignment["stages"][-1]["corrections"], 9)
        self.assertEqual(assignment["best_candidate"]["candidate_id"], "recovered-best")
        self.ledger.activate_trial(gates=self.gates, event_id=self.event(), authorization_revision=self.auth["revision"])
        self.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
                                        event_id=self.event(), authorization_revision=self.auth["revision"])
        self.measure("last-allowed", "nonmatching")
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["corrections"], 10)
        with self.assertRaises(StateError):
            self.measure("eleventh-correction", "nonmatching")
        with self.assertRaises(StateError):
            self.ledger.resolve_trial_history("trial-0", history=recorded_trial_history(self.root),
                                               record=self.history_resolution_record(0), event_id=self.event())
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["corrections"], 10)
        self.assertEqual(self.ledger.snapshot()["trial"]["manifest"], self.manifest)

    def test_history_admission_unknown_refill_is_held_until_own_resolution(self):
        self.held_unknown_refill()
        args = dict(effect_id="prompt-5", kind="prompt", authorization_revision=self.auth["revision"])
        with self.assertRaises(StateError):
            self.ledger.admit_trial_effect("trial-5", event_id=self.event(), **args)
        history = recorded_trial_history(self.root)
        self.ledger.resolve_trial_history("trial-5", history=history,
                                           record=self.history_resolution_record(5), event_id=self.event())
        result = self.ledger.admit_trial_effect("trial-5", event_id=self.event(), **args)
        self.assertTrue(result["execute"])
        self.assertEqual(result["history_digest"], hashlib.sha256(
            json.dumps(history, sort_keys=True, separators=(",", ":")).encode()).hexdigest())
        self.assertEqual(self.ledger.trial_history("trial-4")["status"], "unknown")
        self.assertEqual(self.ledger.assignment("trial-5")["session_id"], "child-5")
        self.assertEqual(self.ledger.snapshot()["trial"]["capacity_history"][-1]["queued_reasons"]["trial-4"], "input_wait")

    def test_history_admission_race_orders_resolution_before_any_refill_prompt(self):
        self.held_unknown_refill()
        history, record = recorded_trial_history(self.root), self.history_resolution_record(5)
        barrier = Barrier(2)
        def resolve():
            ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
            barrier.wait(timeout=30)
            return ledger.resolve_trial_history("trial-5", history=history, record=record, event_id="racing-history")
        def prompt():
            ledger = Ledger(self.root / "ledger.sqlite3", policy=SlotPolicy.real_trial())
            barrier.wait(timeout=30)
            try:
                return ledger.admit_trial_effect("trial-5", effect_id="racing-prompt", kind="prompt",
                    event_id="racing-prompt-admission", authorization_revision=self.auth["revision"])
            except StateError:
                return None
        with ThreadPoolExecutor(max_workers=2) as pool:
            resolved, admitted = pool.submit(resolve), pool.submit(prompt)
            resolution, effect = resolved.result(timeout=30), admitted.result(timeout=30)
        self.assertEqual(self.ledger.trial_history("trial-5"), history)
        if effect is not None:
            self.assertTrue(effect["execute"])
            self.assertEqual(effect["history_resolution_event_id"], resolution["event_id"])
        else:
            self.assertNotIn("racing-prompt", self.ledger.snapshot()["trial"]["effects"])
        self.assertEqual(self.ledger.assignment("trial-5")["stages"][-1]["initial_count"], 0)

    def test_assignment_ids_are_portable_single_components_before_registration(self):
        unsafe = ("../other", "x/../../../victim/status", "x\\..\\victim", "C:other",
                  "bad name", "bad.", "CON", "nul", "a" * 101, "\u00e9")
        for index, identifier in enumerate(unsafe):
            with self.subTest(identifier=identifier):
                ledger = Ledger(self.root / f"unsafe-id-{index}.sqlite3", policy=SlotPolicy.real_trial())
                manifest = trial_manifest(self.root)
                manifest["reservations"][4]["assignment_id"] = identifier
                with self.assertRaises(StateError):
                    ledger.register_trial(manifest=manifest, event_id="unsafe-reservation")
                self.assertNotIn("trial", ledger.snapshot())

    def test_materialization_cannot_start_before_coordinator_review(self):
        self.initial()
        self.measure()
        self.verify()
        self.ledger.transition("trial-0", "review_wait", details={}, event_id=self.event(),
                               authorization_revision=self.auth["revision"])
        self.observe("review")
        with self.assertRaises(StateError):
            self.observe("materialization", self.receipt("materialization", started_at=self.auth["updated_at"]))
        self.assertEqual(self.ledger.assignment("trial-0")["status"], "reconciling")

    def test_commit_cannot_predate_reviewed_materialization(self):
        self.ready()
        with self.assertRaises(StateError):
            self.observe("commit", self.receipt("commit", started_at=self.auth["updated_at"]))
        self.assertIsNone(self.ledger.assignment("trial-0")["publication"])

    def test_push_cannot_predate_its_actual_commit(self):
        self.ready()
        self.observe("commit")
        with self.assertRaises(StateError):
            self.observe("push", self.receipt("push", started_at=self.auth["updated_at"]))
        self.assertFalse(self.ledger.assignment("trial-0")["publication"]["pushed"])

    def test_ack_cannot_predate_successful_push(self):
        self.pushed()
        with self.assertRaises(StateError):
            self.observe("ack", self.receipt("ack", started_at=self.auth["updated_at"]))
        self.assertIsNone(self.ledger.assignment("trial-0")["publication_acknowledgment"])

    def test_cleanup_cannot_predate_canonical_ack(self):
        self.pushed()
        self.observe("ack")
        with self.assertRaises(StateError):
            self.observe("cleanup", self.receipt("cleanup", started_at=self.auth["updated_at"]))
        self.assertIsNone(self.ledger.assignment("trial-0")["cleanup"])

    def test_causal_receipts_require_comparable_timestamp_provenance(self):
        self.ready()
        receipt = self.receipt("commit")
        receipt["timestamp_provenance"]["clock_id"] = "uncorrelated-other-host"
        with self.assertRaises(StateError):
            self.observe("commit", receipt)

    def delivery(self, *, operation="event", role="owner"):
        identifier = self.event()
        payload = {"kind": "phase", "record": self.observation(owner_id="owner-0", phase="verification")} if operation == "event" else {}
        envelope = dict(event_id=identifier, manifest_digest=self.digest, assignment_id="trial-0",
                        owner_id="owner-0", session_id="child-0", operation=operation, payload=payload)
        raw = (json.dumps(envelope, sort_keys=True) + "\n").encode("utf-8")
        return dict(event_id=identifier, role=role, envelope=envelope,
                    content_sha256=hashlib.sha256(raw).hexdigest())

    def test_unadmitted_delivery_cannot_be_consumed(self):
        self.initial()
        with self.assertRaises(StateError):
            self.ledger.consume_trial_delivery(**self.delivery(operation="activate", role="coordinator"))

    def test_delivery_role_content_and_exact_raw_bytes_are_immutable(self):
        self.initial()
        delivery = self.delivery()
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        with self.assertRaises(StateError):
            self.ledger.consume_trial_delivery(**(delivery | {"role": "coordinator"}))
        altered = json.loads(json.dumps(delivery["envelope"]))
        altered.update(operation="activate", payload={})
        altered_digest = hashlib.sha256((json.dumps(altered, sort_keys=True) + "\n").encode()).hexdigest()
        with self.assertRaises(StateError):
            self.ledger.consume_trial_delivery(**(delivery | {"envelope": altered, "content_sha256": altered_digest}))
        same_json_different_bytes = hashlib.sha256(json.dumps(delivery["envelope"], sort_keys=True, indent=2).encode()).hexdigest()
        with self.assertRaises(StateError):
            self.ledger.consume_trial_delivery(**(delivery | {"content_sha256": same_json_different_bytes}))
        self.assertTrue(self.ledger.consume_trial_delivery(**delivery)["execute"])
        self.assertFalse(self.ledger.consume_trial_delivery(**delivery)["execute"])
        self.assertEqual(self.ledger.trial_delivery(delivery["event_id"])["role"], "owner")

    def test_owner_delivery_cannot_admit_coordinator_operations(self):
        self.initial()
        for operation in ("activate", "prepare-refill", "message", "close", "history", "eligibility"):
            with self.subTest(operation=operation), self.assertRaises(StateError):
                self.ledger.admit_trial_delivery(**self.delivery(operation=operation),
                                                  authorization_revision=self.auth["revision"])

    def test_delivery_stop_blocks_effects_but_not_bound_observations(self):
        self.initial()
        delivery = self.delivery(operation="activate", role="coordinator")
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Synthetic queued delivery STOP")
        with self.assertRaises(PolicyError):
            self.ledger.consume_trial_delivery(**delivery)
        observation = self.delivery()
        self.ledger.admit_trial_delivery(**observation)
        self.assertTrue(self.ledger.consume_trial_delivery(**observation)["execute"])
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_concurrent_delivery_consumption_has_one_durable_winner(self):
        self.initial()
        delivery = self.delivery()
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        barrier = Barrier(2)
        def consume(_):
            barrier.wait()
            return self.ledger.consume_trial_delivery(**delivery)
        with ThreadPoolExecutor(max_workers=2) as pool:
            results = list(pool.map(consume, (0, 1)))
        self.assertEqual(sum(result["execute"] for result in results), 1)


    def test_assignment_ids_cannot_alias_case_insensitive_snapshot_paths(self):
        self.manifest["reservations"][4]["assignment_id"] = self.manifest["reservations"][0]["assignment_id"].upper()
        with self.assertRaises(StateError):
            self.ledger.register_trial(manifest=self.manifest, event_id=self.event())
        self.assertNotIn("trial", self.ledger.snapshot())

    def test_delivery_consumption_does_not_collide_with_handler_event_or_replay_after_stop(self):
        self.initial()
        delivery = self.delivery()
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        self.assertTrue(self.ledger.consume_trial_delivery(**delivery)["execute"])
        envelope = delivery["envelope"]
        self.ledger.trial_event(envelope["assignment_id"], event_id=envelope["event_id"], **envelope["payload"])
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Synthetic consumed-delivery STOP")
        self.assertFalse(self.ledger.admit_trial_delivery(**delivery)["execute"])
        self.assertFalse(self.ledger.consume_trial_delivery(**delivery)["execute"])
        self.assertEqual(len(self.ledger.snapshot()["trial"]["events"]), 1)
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_delivery_ids_cannot_alias_case_insensitive_inbox_paths(self):
        self.initial()
        delivery = self.delivery()
        self.ledger.admit_trial_delivery(**delivery)
        alias = json.loads(json.dumps(delivery))
        alias["event_id"] = alias["event_id"].upper()
        alias["envelope"]["event_id"] = alias["event_id"]
        alias["content_sha256"] = hashlib.sha256((json.dumps(alias["envelope"], sort_keys=True) + "\n").encode()).hexdigest()
        with self.assertRaises(StateError):
            self.ledger.admit_trial_delivery(**alias)

    def test_consumed_observation_then_coordinator_rebind_is_rejected(self):
        self.initial()
        delivery = self.delivery()
        self.ledger.admit_trial_delivery(**delivery)
        self.ledger.consume_trial_delivery(**delivery)
        with self.assertRaises(StateError):
            self.ledger.admit_trial_delivery(**(delivery | {"role": "coordinator"}),
                                              authorization_revision=self.auth["revision"])


    def consumed_observation_gap(self, operation, payload, *, role="owner", assignment_id="trial-0"):
        """Persist the pre-handler crash boundary; no native process is launched."""
        delivery = self.delivery(operation=operation, role=role)
        delivery["envelope"]["payload"] = payload
        delivery["envelope"]["assignment_id"] = assignment_id
        if assignment_id != "trial-0" and role == "coordinator":
            delivery["envelope"].pop("owner_id")
            delivery["envelope"].pop("session_id")
        raw = (json.dumps(delivery["envelope"], sort_keys=True) + "\n").encode()
        delivery["content_sha256"] = hashlib.sha256(raw).hexdigest()
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        self.assertTrue(self.ledger.consume_trial_delivery(**delivery)["execute"])
        # Deliberately omit the operation-specific mutation, then reopen the
        # durable ledger via the actual record_after_stop consumer below.
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Synthetic crash after durable consume")
        return delivery["envelope"], stopped

    def recovery_execution_observation(self):
        observation = self.observation(assignment_id="trial-0", owner_id="owner-0", session_id="child-0",
                                       manifest_digest=self.digest, authorization_revision=self.auth["revision"])
        observation["started_at"] = observation["observed_at"]
        return observation

    def test_crashed_attempt_delivery_recovers_after_stop_without_losing_measurement(self):
        from .trial import record_after_stop
        self.initial()
        payload = dict(candidate_id="preserved-inbox-candidate",
                       source_ref={"path": "preserved-inbox.cpp", "sha256": "f" * 64},
                       input_identity="c" * 64, recipe_ref="preserved-inbox-recipe",
                       outcome="nonmatching", evidence_refs=["preserved-comparison"],
                       observation=self.recovery_execution_observation())
        envelope, stopped = self.consumed_observation_gap("attempt", payload)
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["attempts"], [])
        record_after_stop(self.root, envelope, role="owner")
        record_after_stop(self.root, envelope, role="owner")
        stage = self.ledger.assignment("trial-0")["stages"][-1]
        self.assertEqual(stage["initial_count"], 1)
        self.assertEqual(stage["corrections"], 0)
        self.assertEqual(len(stage["attempts"]), 1)
        self.assertEqual(stage["attempts"][0]["candidate_id"], payload["candidate_id"])
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_legacy_verification_delivery_is_refused_after_stop_without_losing_history(self):
        from .trial import record_after_stop
        from .safety import SafetyError
        self.initial()
        self.measure()
        evidence = dict(scope="reconstruction", checks={name: "preserved-check" for name in (
            "compile", "object_compare", "data_relocations", "source_link", "binary_hashes")},
                        binary_hash_count=127, runtime_status="unavailable", runtime_reason="Synthetic ledger fixture")
        envelope, stopped = self.consumed_observation_gap("verification", {
            "candidate_id": "candidate", "input_identity": "c" * 64, "evidence": evidence,
            "observation": self.recovery_execution_observation()})
        self.assertIsNone(self.ledger.assignment("trial-0")["verification"])
        before = self.ledger.snapshot()
        for _ in range(2):
            with self.assertRaises(SafetyError):
                record_after_stop(self.root, envelope, role="owner")
            self.assertEqual(self.ledger.snapshot(), before)
        self.assertIsNone(self.ledger.assignment("trial-0")["verification"])
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_legacy_push_delivery_cannot_create_a_push_observation_after_stop(self):
        from .trial import record_after_stop
        from .safety import SafetyError
        self.ready()
        self.observe("commit")
        envelope, stopped = self.consumed_observation_gap(
            "receipt", {"kind": "push", "receipt": self.receipt("push")}, role="coordinator")
        self.assertFalse(self.ledger.assignment("trial-0")["publication"]["pushed"])
        before = self.ledger.snapshot()
        for _ in range(2):
            with self.assertRaises(SafetyError):
                record_after_stop(self.root, envelope)
            self.assertEqual(self.ledger.snapshot(), before)
        assignment = self.ledger.assignment("trial-0")
        self.assertFalse(assignment["publication"]["pushed"])
        self.assertEqual(assignment["external_receipts"].get("push", []), [])
        self.assertEqual(assignment["external_receipts"]["commit"], before["assignments"]["trial-0"]["external_receipts"]["commit"])
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_legacy_ack_delivery_cannot_create_acceptance_after_stop(self):
        from .trial import record_after_stop
        from .safety import SafetyError
        self.pushed()
        envelope, stopped = self.consumed_observation_gap(
            "receipt", {"kind": "ack", "receipt": self.receipt("ack")}, role="coordinator")
        self.assertIsNone(self.ledger.assignment("trial-0")["publication_acknowledgment"])
        before = self.ledger.snapshot()
        for _ in range(2):
            with self.assertRaises(SafetyError):
                record_after_stop(self.root, envelope)
            self.assertEqual(self.ledger.snapshot(), before)
        assignment = self.ledger.assignment("trial-0")
        self.assertIsNone(assignment["publication_acknowledgment"])
        self.assertEqual(assignment["external_receipts"].get("ack", []), [])
        self.assertEqual(assignment["external_receipts"]["push"], before["assignments"]["trial-0"]["external_receipts"]["push"])
        self.assertEqual(assignment["accepted_credit"], 0)
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_concurrent_crash_gap_recovery_applies_observation_once(self):
        from .trial import record_after_stop
        self.initial()
        envelope, stopped = self.consumed_observation_gap(
            "event", {"kind": "phase", "record": self.observation(owner_id="owner-0", phase="verification")})
        barrier = Barrier(2)
        def recover(_):
            barrier.wait()
            return record_after_stop(self.root, envelope, role="owner")
        with ThreadPoolExecutor(max_workers=2) as pool:
            results = list(pool.map(recover, (0, 1)))
        self.assertEqual(len(self.ledger.snapshot()["trial"]["events"]), 1)
        self.assertEqual(results[0], results[1])
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_consumed_native_effect_delivery_never_becomes_observation_replay(self):
        self.initial()
        delivery = self.delivery(operation="message", role="coordinator")
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        self.assertTrue(self.ledger.consume_trial_delivery(**delivery)["execute"])
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Uncertain native effect is not replayable")
        result = self.ledger.consume_trial_delivery(**delivery)
        self.assertFalse(result["execute"])
        self.assertFalse(result.get("replay_observation", False))
        self.assertEqual(self.ledger.authorization(), stopped)


    def test_crashed_eligibility_observation_recovers_without_resuming_work(self):
        from .trial import record_after_stop
        self.initial()
        record = self.observation(observed_by="coordinator", assignment_id="trial-4", manifest_digest=self.digest)
        envelope, stopped = self.consumed_observation_gap(
            "eligibility", {"reason": "input_wait", "record": record}, role="coordinator", assignment_id="trial-4")
        record_after_stop(self.root, envelope)
        snapshot = self.ledger.snapshot()
        record_after_stop(self.root, envelope)
        self.assertEqual(self.ledger.snapshot(), snapshot)
        self.assertEqual(snapshot["trial"]["eligibility"]["trial-4"]["reason"], "input_wait")
        self.assertEqual(snapshot["trial"]["capacity_history"][-1]["eligible_work"], 0)
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_legacy_transition_delivery_is_refused_without_erasing_committed_history(self):
        from .trial import record_after_stop
        from .safety import SafetyError
        self.initial()
        delivery = self.delivery(operation="transition")
        delivery["envelope"]["payload"] = {"status": "verifying", "details": {}}
        delivery["content_sha256"] = hashlib.sha256((json.dumps(delivery["envelope"], sort_keys=True) + "\n").encode()).hexdigest()
        self.ledger.admit_trial_delivery(**delivery, authorization_revision=self.auth["revision"])
        self.ledger.consume_trial_delivery(**delivery)
        expected = self.ledger.transition("trial-0", "verifying", details={}, event_id=delivery["event_id"],
                                           authorization_revision=self.auth["revision"])
        stopped = self.ledger.request_stop(event_id=self.event(), reason="Committed transition recovery")
        before = self.ledger.snapshot()
        for _ in range(2):
            with self.assertRaises(SafetyError):
                record_after_stop(self.root, delivery["envelope"], role="owner")
            self.assertEqual(self.ledger.snapshot(), before)
        self.assertEqual(self.ledger.assignment("trial-0"), expected)
        self.assertEqual(self.ledger.authorization(), stopped)

    def test_legacy_uncommitted_transition_delivery_remains_nonexecuting_after_stop(self):
        from .trial import record_after_stop
        from .safety import SafetyError
        self.initial()
        envelope, stopped = self.consumed_observation_gap("transition", {"status": "verifying", "details": {}})
        before = self.ledger.snapshot()
        for _ in range(2):
            with self.assertRaises(SafetyError):
                record_after_stop(self.root, envelope, role="owner")
            self.assertEqual(self.ledger.snapshot(), before)
        self.assertEqual(self.ledger.assignment("trial-0")["status"], "assigned")
        self.assertEqual(self.ledger.authorization(), stopped)


class WorkflowFixture:
    """Synthetic native/Git observations for the controller's SQLite boundary."""

    def __init__(self, *, inherited_corrections=0, prepare=None, configure=None, mechanical=False, root=None):
        self.case = TrialLedgerTests("test_default_policy_is_unchanged_and_real_trial_is_explicit")
        self.case.setUp(root=root)
        self.ledger, self.root = self.case.ledger, self.case.root
        self.mechanical = mechanical
        if prepare is not None:
            prepare(self)
        if inherited_corrections:
            self.case.manifest["reservations"][0]["history"]["stages"]["qwen"].update(
                initial_count=1, corrections=inherited_corrections,
                best_candidate=dict(candidate_id="preserved-best",
                    source_ref={"path": "drafts/preserved.cpp", "sha256": "f" * 64},
                    input_identity="c" * 64, recipe_ref="preserved-recipe", outcome="nonmatching",
                    evidence_refs=["synthetic-inherited-comparison"], quality=0.5))
        trial = self.ledger.register_trial(manifest=self.case.manifest, event_id=self.case.event())
        self.case.digest = trial["manifest_digest"]
        execution = self.case.manifest["execution"]
        role = {key: execution[key] for key in ("provider", "model", "endpoint")}
        target = dict(self.case.manifest["publication_target"], baseline="a" * 40,
                      git_dir=str(Path(self.case.manifest["publication_target"]["repository"]) / ".git"),
                      author={"name": "Synthetic test", "email": "synthetic@example.invalid"},
                      ownership_evidence={"path": str(self.root / "target-grant.json"), "sha256": "a" * 64})
        self.config = dict(schema=1, run_id=self.root.name, controller_id="coordinator",
            profile=dict(reconstruction=dict(role, stage="qwen", capacity=4),
                         review=dict(role, stage="qwen", capacity=4),
                         total_model_capacities=[dict(provider=role["provider"], model=role["model"], capacity=4)]),
            publication_target=target, verification={}, acceptance_policy=workflow_acceptance_policy())
        for row in self.case.manifest["reservations"]:
            self.config["verification"][row["assignment_id"]] = dict(
                recipe={"compiler": "synthetic-fixed-recipe", "native_compile_command": "synthetic-compiler candidate.cpp"},
                commands=[dict(name=name, argv=[sys.executable, "-c", "pass"],
                               accepted_exit_codes=[0], timeout_seconds=10)
                          for name in ("compile", "object_compare", "data_relocations", "source_link", "progress")],
                binary_hashes={f"originals/{index}.bin": "a" * 40 for index in range(127)},
                workspace_inputs=[],
                selection=dict(source=next(path for path in row["owned_paths"] if path.endswith(".cpp")),
                               object="build/candidate.o", link_output="build/native.rel",
                               ninja=str(self.root / "synthetic-ninja.exe"), fallback_object="build/original.o"))
            if not mechanical:
                self.config["verification"][row["assignment_id"]]["judgment_requirements"] = {
                    "abi": "Synthetic source-level ABI judgment explicitly required by this fixture"}
        if configure is not None:
            configure(self)
        self.ledger.configure_trial_workflow(config=self.config, event_id=self.case.event(), authorization_revision=1)

    def start(self, *, target=True, prompts=True):
        self.case.initial(prompts=False)
        if target:
            action = self.admit(None)
            configured = self.config["publication_target"]
            self.complete(action, {key: configured[key] for key in ("repository", "git_dir", "remote", "branch")} | {
                "common_git_dir": configured["git_dir"], "head": configured["baseline"],
                "independent": True, "alternates": []})
        if prompts:
            return self.ledger.admit_trial_prompts(
                effect_ids={f"trial-{index}": f"prompt-{index}" for index in range(4)},
                event_id=self.case.event(), authorization_revision=1)

    def admit(self, index=0, *, effect_id=None):
        key = f"trial-{index}" if index is not None else None
        ready = self.ledger.trial_readiness(key) if key is not None else self.ledger.trial_readiness()["target"]
        effect_id = effect_id or "action-" + self.case.event()
        return self.ledger.admit_trial_action(key, kind=ready["kind"], effect_id=effect_id,
            binding=ready["binding"], authorization_revision=self.ledger.authorization()["revision"],
            event_id=self.case.event())

    def record(self, action, result, *, outcome="succeeded", **extra):
        return self.case.observation(binding=action["binding"], started_at=action["admitted_at"],
            authorization_revision=action["authorization_revision"], outcome=outcome, result=result, **extra)

    def complete(self, action, result, *, outcome="succeeded"):
        return self.ledger.observe_trial_action(effect_id=action["effect_id"],
            record=self.record(action, result, outcome=outcome), event_id=self.case.event())

    def owner_record(self, index=0, dispatch=None):
        dispatch = dispatch or f"prompt-{index}"
        doc = self.ledger.snapshot()
        effect = doc["trial"]["effects"].get(dispatch) or doc["trial"]["workflow"]["actions"][dispatch]
        return self.case.observation(dispatch_effect_id=dispatch, started_at=effect["admitted_at"],
            authorization_revision=effect["authorization_revision"],
            assignment_id=f"trial-{index}", owner_id=f"owner-{index}", session_id=f"child-{index}",
            manifest_digest=self.case.digest, native_event=dict(kind="owner_turn_end",
                registry_id=f"owner-{index}", session_id=f"child-{index}", root_session_id=f"root-{index}",
                request_id=dispatch, will_continue=False))

    def packet(self, index=0, candidate="candidate", *, two_units=False, source_only=None):
        row = self.case.manifest["reservations"][index]
        source_only = self.mechanical if source_only is None else source_only
        if source_only and two_units:
            raise ValueError("A source-only fixture has one logical publication unit")
        changes = {}
        for path in row["owned_paths"]:
            if source_only and not path.endswith(".cpp"):
                continue
            content = f"synthetic-{index}-{candidate}-{path}".encode()
            changes[path] = dict(before=None if path.endswith(".cpp") else {"mode": "100644", "blob": "a" * 40},
                                 after={"mode": "100644", "blob": hashlib.sha1(content).hexdigest()},
                                 raw={"sha256": hashlib.sha256(content).hexdigest(), "size": len(content)})
        source = next(path for path in changes if path.endswith(".cpp"))
        inputs = dict(schema=1, inputs=dict(source={source: changes[source]["raw"]}, header={},
            config={path: change["raw"] for path, change in changes.items() if path != source}, tool={}),
            recipe=self.config["verification"][row["assignment_id"]]["recipe"])
        inputs["identity"] = content_identity(inputs)
        paths = list(changes)
        units = [paths[:1], paths[1:]] if two_units else [paths]
        return dict(schema=1, assignment_id=row["assignment_id"], owner_id=f"owner-{index}",
            session_id=f"child-{index}", manifest_digest=self.case.digest, candidate_id=candidate,
            inputs=inputs, changes=changes,
            artifacts={name: {"path": f"evidence/{candidate}-{name}.json",
                              "identity": {"sha256": "b" * 64, "size": 8}}
                       for name in ("compile", "object_compare", "data_relocations", "source_link", "binary_hashes", "progress")},
            logical_units=[{"message": f"Synthetic logical unit {number}", "paths": paths}
                           for number, paths in enumerate(units)],
            cleanup=[{"path": "scratch/disposable.bin", "identity": {"sha256": "c" * 64, "size": 3}}])

    def measure(self, packet, *, index=0, dispatch=None):
        source = next(path for path in packet["changes"] if path.endswith(".cpp"))
        return self.ledger.record_attempt(f"trial-{index}", candidate_id=packet["candidate_id"],
            source_ref={"path": str(Path(self.case.manifest["reservations"][index]["workspace"]) /
                                    "drafts" / (packet["candidate_id"] + ".cpp")),
                        "sha256": packet["changes"][source]["raw"]["sha256"]},
            input_identity=packet["inputs"]["identity"], recipe_ref="synthetic-fixed-recipe",
            outcome="matching", evidence_refs=["synthetic-measured-comparison"], quality=1,
            observation=self.owner_record(index, dispatch), authorization_revision=1, event_id=self.case.event())

    def capture(self, index=0, *, packet=None, dispatch=None, measure=True):
        packet = packet or self.packet(index)
        if measure:
            self.measure(packet, index=index, dispatch=dispatch)
        record = self.owner_record(index, dispatch)
        raw_hash = content_identity(packet)
        record.update(path=str(self.root / "deliveries" / "raw" / (raw_hash + ".json")),
                      original_path=str(Path(self.case.manifest["reservations"][index]["workspace"]) /
                                        "evidence/controller-delivery.json"),
                      sha256=raw_hash, size=len(json.dumps(packet).encode()))
        entry = self.ledger.record_trial_delivery(f"trial-{index}", delivery=packet, record=record,
                                                 event_id=self.case.event())
        return packet, entry, record

    def validation_result(self, index=0):
        selection = self.config["verification"][f"trial-{index}"]["selection"]
        result = dict(valid=True, matching=True,
            checks={name: "synthetic-independent-" + name for name in (
                "compile", "object_compare", "data_relocations", "source_link", "binary_hashes", "progress")},
            binary_hash_count=127, runtime_status="unavailable", runtime_reason="Synthetic boundary test",
            source_selection={key: selection[key] for key in ("source", "object", "link_output")} |
                dict(selected=True, fallback_selected=False, evidence_ref="synthetic-actual-source-selection"))
        snapshot = self.ledger.snapshot()
        key = f"trial-{index}"
        state = snapshot["trial"]["workflow"]["assignments"][key]
        delivery = state["deliveries"][state["current_delivery_id"]]["delivery"]
        validations = [action for action in snapshot["trial"]["workflow"]["actions"].values()
                       if action["assignment_id"] == key and action["kind"] == "validate_delivery"
                       and action["binding"]["delivery_id"] == state["current_delivery_id"]]
        binding = validations[-1]["binding"] if validations else self.ledger.trial_readiness(key)["binding"]
        policy = self.config["acceptance_policy"]
        reasons = dict(self.config["verification"][key].get("judgment_requirements", {}))
        if set(delivery["changes"]) != {selection["source"]}:
            reasons.setdefault("ownership", "Synthetic shared registration insertion needs scoped source judgment")
        covered = {}
        for criterion, method in policy["criteria"].items():
            if criterion in reasons:
                continue
            references = [result["checks"].get(criterion, "synthetic-controller-" + criterion)]
            if criterion in {"abi", "edge_semantics"}:
                references = [result["checks"][name] for name in (
                    "object_compare", "data_relocations", "source_link", "binary_hashes")]
            covered[criterion] = dict(method=method, evidence_refs=references)
        result["coverage"] = dict(policy_identity=content_identity(policy), producer="coordinator", binding=binding,
            covered=covered, unresolved={criterion: dict(reason=reason, evidence_refs=["synthetic-source-context"])
                                        for criterion, reason in reasons.items()})
        references = set(result["checks"].values()) | {result["source_selection"]["evidence_ref"]}
        for evidence in (*covered.values(), *result["coverage"]["unresolved"].values()):
            references.update(evidence["evidence_refs"])
        result["check_identities"] = {
            reference: {"sha256": hashlib.sha256(reference.encode()).hexdigest(), "size": len(reference)}
            for reference in references}
        result["verification_spec_identity"] = content_identity(self.config["verification"][key])
        result["output_identities"] = {
            path: {"sha256": hashlib.sha256(("synthetic-output:" + path).encode()).hexdigest(), "size": 8}
            for path in (selection["object"], selection["fallback_object"], selection["link_output"],
                         *self.config["verification"][key]["binary_hashes"])}
        return result

    def validate(self, index=0):
        action = self.admit(index)
        return self.complete(action, self.validation_result(index))

    def prepare_review(self, index=0):
        action = self.admit(index)
        reviewer = dict(action["reviewer"], session_id=f"review-child-{index}",
                        journal_ref="synthetic-genuine-review-journal", registry_ref="synthetic-genuine-review-registry")
        return self.complete(action, dict(reviewer=reviewer, native_event=dict(
            kind="review_gate_wait", registry_id=reviewer["owner_id"], session_id=reviewer["session_id"],
            root_session_id=reviewer["root_session_id"])))

    def review_result(self, action, *, decision="approve"):
        reviewer = action["reviewer"]
        source = self.config["verification"][action["assignment_id"]]["selection"]["source"]
        scope = action["binding"]["unresolved_criteria"]
        criterion = "abi" if "abi" in scope else next(iter(scope))
        return dict(decision=decision, reviewed_criteria=sorted(scope), findings=[] if decision == "approve" else [
            dict(criterion=criterion, path=source, reason="Synthetic scoped source judgment rejection")],
            decision_file={"path": str(self.root / (action["effect_id"] + ".json")), "sha256": "d" * 64},
            native_event=dict(kind="reviewer_turn_end", registry_id=reviewer["owner_id"],
                session_id=reviewer["session_id"], root_session_id=reviewer["root_session_id"],
                request_id=action["effect_id"], will_continue=False))

    def reviewed(self, index=0, *, decision="approve", packet=None):
        self.capture(index, packet=packet)
        self.validate(index)
        self.prepare_review(index)
        action = self.admit(index)
        return self.complete(action, self.review_result(action, decision=decision))

    def materialize_result(self, index=0):
        state = self.ledger.snapshot()["trial"]["workflow"]["assignments"][f"trial-{index}"]
        packet = state["deliveries"][state["current_delivery_id"]]["delivery"]
        images = {path: dict(change["after"], raw=change["raw"]) for path, change in packet["changes"].items()}
        return dict(expected_postimages=images, actual_postimages=dict(images),
            scope_verified=True, source_binding_verified=True,
            base_head=self.ledger.snapshot()["trial"]["workflow"]["target_head"],
            grant_ref="synthetic-grant", preservation_ref="synthetic-preservation", private_index_ref="synthetic-private-index")

    def materialize(self, index=0):
        return self.complete(self.admit(index), self.materialize_result(index))

    def commit_result(self, action):
        state = self.ledger.snapshot()["trial"]["workflow"]["assignments"][action["assignment_id"]]
        packet = state["deliveries"][state["current_delivery_id"]]["delivery"]
        unit_id = action["binding"]["logical_unit_id"]
        index = int(unit_id.removeprefix("unit-"))
        commit = hashlib.sha1(action["effect_id"].encode()).hexdigest()
        paths = packet["logical_units"][index]["paths"]
        return dict(logical_unit_id=unit_id, commit=commit, local_head=commit, tree="e" * 40,
            parent=state["units"][f"unit-{index - 1}"]["commit"] if index else state["materialization"]["base_head"],
            postimages={path: state["materialization"]["postimages"][path] for path in paths},
            changed_paths=paths, command_refs=["synthetic-owned-commit-command"])

    def push_result(self, action):
        return dict(logical_unit_id=action["binding"]["logical_unit_id"], commit=action["binding"]["commit"],
            push_exit_code=0, pushed=True, remote_contains_commit=True, remote_head=action["binding"]["commit"],
            command_refs=["synthetic-owned-push-and-remote-query"])

    def publish(self, index=0):
        while self.ledger.trial_readiness(f"trial-{index}")["kind"] in {"commit", "push"}:
            action = self.admit(index)
            self.complete(action, self.commit_result(action) if action["kind"] == "commit" else self.push_result(action))
        return self.complete(self.admit(index), {})

    def cleanup(self, index=0):
        action = self.admit(index)
        native = self.owner_record(index, action["effect_id"])["native_event"]
        workspace = Path(self.case.manifest["reservations"][index]["workspace"])
        return self.complete(action, dict(native_event=native,
            retained_evidence_refs=["synthetic-all-drafts-and-comparisons"], deletion_manifest_ref="synthetic-deletion-manifest",
            shared_link_checks_ref="synthetic-shared-link-checks", original_input_checks_ref="synthetic-original-checks",
            retained_evidence_checks_ref="synthetic-retained-checks", tracked_files_preserved=True,
            ancestor_links_checked=True, directory_pruning_checked=True,
            removed_paths=[{"path": str(workspace / "scratch/disposable.bin"), "bytes": 3, "sha256": "c" * 64}],
            removed_bytes=3))

    def close(self, index=0):
        action = self.admit(index)
        process = self.ledger.process(f"process-{index}")
        self.ledger.record_process_exit(f"process-{index}", event_id=self.case.event(), proof={
            **process["identity"], "observed_exit": True, "exit_code": 0,
            "verified_at": datetime.now(timezone.utc).isoformat(), "evidence_ref": f"synthetic-exit-{index}"})
        return self.complete(action, dict(process_id=f"process-{index}", exit_evidence_ref=f"synthetic-exit-{index}"))


class WorkflowLedgerTests(unittest.TestCase):
    def setUp(self):
        self.f = WorkflowFixture()
        self.ledger = self.f.ledger

    def test_target_setup_and_aggregate_native_request_capacity_are_durable(self):
        self.f.start(target=False, prompts=False)
        self.assertEqual(self.ledger.trial_prompt_readiness("trial-0")["reason"], "target_setup")
        with self.assertRaises(PolicyError):
            self.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
                event_id="before-target", authorization_revision=1)
        self.assertFalse(any(effect["kind"] == "prompt" for effect in self.ledger.snapshot()["trial"]["effects"].values()))
        target = self.f.admit(None)
        configured = self.f.config["publication_target"]
        self.f.complete(target, {key: configured[key] for key in ("repository", "git_dir", "remote", "branch")} |
                        dict(common_git_dir=configured["git_dir"], head=configured["baseline"], independent=True, alternates=[]))
        self.ledger.admit_trial_prompts(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
            event_id="four-prompts", authorization_revision=1)
        reopened = Ledger(self.ledger.path)
        self.assertEqual(reopened.trial_prompt_readiness()["reason"], "model_capacity")
        self.assertEqual(reopened.trial_prompt_readiness("trial-0")["reason"], "already_admitted")
        self.assertFalse(reopened.admit_trial_prompts(effect_ids={f"trial-{i}": f"prompt-{i}" for i in range(4)},
            event_id="four-prompts", authorization_revision=1)["execute"])

    def test_invalid_review_output_releases_only_the_observed_inference_lease(self):
        self.f.start()
        self.f.capture()
        self.f.validate()
        prepared = self.f.prepare_review()
        reviewer = prepared["reviewer"]
        self.assertNotEqual(reviewer["session_id"], "child-0")
        action = self.f.admit()
        self.assertEqual(self.ledger.trial_prompt_readiness()["reason"], "model_capacity")
        result = self.f.review_result(action)
        result.pop("decision")
        result["error"] = "Synthetic missing native decision"
        self.f.complete(action, result, outcome="failed")
        self.assertTrue(self.ledger.trial_prompt_readiness()["ready"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "tool_wait")
        self.assertTrue(self.ledger.session("child-0")["active"])
        self.assertTrue(self.ledger.session(reviewer["session_id"])["active"])
        self.assertIsNone(self.ledger.assignment("trial-0")["publication_acknowledgment"])

    def test_rejection_returns_to_same_owner_without_reset_or_reviewer_replacement(self):
        self.f.start()
        self.f.reviewed(decision="reject")
        original = self.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]["reviewer"]
        correction = self.f.admit()
        self.assertEqual(correction["kind"], "reconcile")
        self.assertEqual(correction["binding"]["session_id"], "child-0")
        self.ledger.observe_trial_owner("trial-0", record=self.f.owner_record(), event_id="late-old-completion")
        self.assertTrue(self.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]["owner_activity"]["busy"])
        packet = self.f.packet(candidate="corrected")
        self.f.capture(packet=packet, dispatch=correction["effect_id"])
        self.f.complete(correction, {"native_event": self.f.owner_record(dispatch=correction["effect_id"])["native_event"]})
        self.f.validate()
        review = self.f.admit()
        self.assertEqual(review["kind"], "review")
        self.assertEqual(review["reviewer"], original)
        self.f.complete(review, self.f.review_result(review))
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "materialize")
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["corrections"], 1)

    def test_model_matching_assertion_and_skipped_postimages_never_accept(self):
        self.f.start()
        self.f.capture()
        action = self.f.admit()
        result = self.f.validation_result()
        result["matching"] = False
        with self.assertRaises(StateError):
            self.f.complete(action, result)
        self.assertIsNone(self.ledger.assignment("trial-0")["verification"])
        self.f.complete(action, self.f.validation_result())
        self.f.prepare_review()
        review = self.f.admit()
        self.f.complete(review, self.f.review_result(review))
        materialize = self.f.admit()
        skipped = self.f.materialize_result()
        skipped["actual_postimages"].pop("configure.py")
        with self.assertRaises(StateError):
            self.f.complete(materialize, skipped)
        self.assertIsNone(self.ledger.assignment("trial-0")["materialization"])
        self.f.complete(materialize, dict(error="Observed partial materialization", actual_postimages=skipped["actual_postimages"]),
                        outcome="uncertain")
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "uncertain_effect")
        self.assertEqual(self.ledger.snapshot()["trial"]["workflow"]["target_lease"], materialize["effect_id"])

    def test_concurrent_target_admission_serializes_only_publication_generations(self):
        self.f.start()
        self.f.reviewed(0)
        self.f.reviewed(1)
        requests = [self.ledger.trial_readiness(f"trial-{i}") for i in range(2)]
        barrier = Barrier(2)
        def admit(index):
            barrier.wait()
            try:
                return Ledger(self.ledger.path).admit_trial_action(
                    f"trial-{index}", kind="materialize", effect_id=f"concurrent-{index}",
                    binding=requests[index]["binding"], event_id=f"concurrent-admit-{index}", authorization_revision=1)
            except StateError as exc:
                return str(exc)
        with ThreadPoolExecutor(max_workers=2) as pool:
            results = list(pool.map(admit, range(2)))
        self.assertEqual(sum(isinstance(result, dict) and result["execute"] for result in results), 1)
        self.assertTrue(any(isinstance(result, str) and "publication_wait" in result for result in results))
        self.f.capture(2)
        self.assertTrue(self.ledger.trial_readiness("trial-2")["ready"])
        self.assertEqual(self.ledger.trial_readiness("trial-2")["kind"], "validate_delivery")

    def test_each_logical_unit_push_precedes_ack_cleanup_exit_and_independent_refill(self):
        self.f.start()
        self.f.reviewed(packet=self.f.packet(two_units=True))
        self.f.materialize()
        first = self.f.admit()
        self.assertEqual(first["binding"]["logical_unit_id"], "unit-0")
        self.f.complete(first, self.f.commit_result(first))
        push = self.f.admit()
        self.f.complete(push, self.f.push_result(push))
        self.assertIsNone(self.ledger.assignment("trial-0")["publication_acknowledgment"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["binding"]["logical_unit_id"], "unit-1")
        self.assertIsNotNone(self.ledger.snapshot()["trial"]["workflow"]["target_lease"])
        self.f.publish()
        self.assertIsNone(self.ledger.snapshot()["trial"]["workflow"]["target_lease"])
        self.assertFalse(self.ledger.assignment("trial-0")["publication"]["external_coordinator"])
        with self.assertRaises(StateError):
            self.ledger.claim_trial_refill(claim=self.f.case.claim(4, slot=0),
                                           event_id="early-refill", authorization_revision=1)
        self.f.cleanup()
        close = self.f.admit()
        with self.assertRaises(StateError):
            self.f.complete(close, dict(process_id="process-0", exit_evidence_ref="synthetic-exit-0"))
        self.f.case.exit()
        self.f.complete(close, dict(process_id="process-0", exit_evidence_ref="synthetic-exit"))
        self.ledger.claim_trial_refill(claim=self.f.case.claim(4, slot=0), event_id="independent-refill", authorization_revision=1)
        self.assertEqual(self.ledger.assignment("trial-4")["status"], "assigned")
        self.assertNotEqual(self.ledger.assignment("trial-4")["owner_id"], "owner-0")
        self.assertEqual(self.ledger.assignment("trial-0")["accepted_credit"], 0)

    def test_definitive_commit_failure_keeps_uncommitted_bundle_lease(self):
        self.f.start()
        self.f.reviewed()
        self.f.materialize()
        action = self.f.admit()
        self.f.complete(action, dict(error="Synthetic native commit failure", effect_absent=True), outcome="failed")
        self.assertEqual(self.ledger.snapshot()["trial"]["workflow"]["target_lease"], action["effect_id"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "tool_wait")

    def test_readonly_push_recovery_after_stop_neither_replays_nor_invents_exit(self):
        self.f.start()
        self.f.reviewed()
        self.f.materialize()
        commit = self.f.admit()
        self.f.complete(commit, self.f.commit_result(commit))
        push = self.f.admit()
        self.f.complete(push, {"error": "Synthetic transport loss"}, outcome="uncertain")
        stopped = self.ledger.request_stop(event_id="recovery-stop", reason="Synthetic recovery boundary")
        result = self.f.push_result(push) | dict(push_exit_code=None, recovered_from_remote=True)
        record = self.f.record(push, result)
        record["started_at"] = datetime.now(timezone.utc).isoformat()
        record["observed_at"] = datetime.now(timezone.utc).isoformat()
        recovered = self.ledger.observe_trial_action(effect_id=push["effect_id"], record=record, event_id="recovered-remote")
        self.assertFalse(recovered["execute"])
        self.assertIsNone(self.ledger.assignment("trial-0")["publication"]["push_receipt"]["push_exit_code"])
        self.assertFalse(self.ledger.observe_trial_action(effect_id=push["effect_id"], record=record,
                                                          event_id="duplicate-recovered-remote")["execute"])
        ack = self.f.admit()
        self.assertEqual(ack["kind"], "acknowledge")
        self.f.complete(ack, {})
        self.assertEqual(self.ledger.authorization(), stopped)
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "explicit_pause")
        self.assertTrue(self.ledger.session("child-0")["active"])

    def test_manual_lifecycle_bypass_and_foreign_review_actor_are_rejected(self):
        self.f.start()
        self.f.capture()
        self.f.validate()
        with self.assertRaises(PolicyError):
            self.ledger.transition("trial-0", "review_wait", details={}, event_id="manual-review", authorization_revision=1)
        action = self.f.admit()
        reviewer = dict(action["reviewer"], session_id="child-0", owner_id="owner-0",
                        journal_ref="synthetic-journal", registry_ref="synthetic-registry")
        with self.assertRaises(StateError):
            self.f.complete(action, dict(reviewer=reviewer, native_event=dict(kind="review_gate_wait",
                registry_id="owner-0", session_id="child-0", root_session_id="root-0")))
        self.assertEqual(self.ledger.assignment("trial-0")["status"], "review_wait")

    def test_delivery_cannot_authorize_deleting_a_preserved_candidate(self):
        self.f.start()
        packet = self.f.packet()
        packet["cleanup"] = [{"path": "drafts/candidate.cpp", "identity": {"sha256": "c" * 64, "size": 3}}]
        self.f.capture(packet=packet)
        validation = self.f.admit()
        with self.assertRaises(StateError):
            self.f.complete(validation, self.f.validation_result())
        self.assertIsNone(self.ledger.assignment("trial-0")["verification"])
        self.f.complete(validation, {"findings": [
            {"criterion": "ownership", "path": "", "reason": "Disposable aliases a preserved draft"}],
            "effect_absent": True}, outcome="rejected")
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 1)

    def test_nonzero_inherited_counts_survive_controller_delivery_and_approval(self):
        fixture = WorkflowFixture(inherited_corrections=3)
        fixture.start()
        fixture.reviewed()
        assignment = fixture.ledger.assignment("trial-0")
        self.assertEqual(assignment["stages"][-1]["initial_count"], 1)
        self.assertEqual(assignment["stages"][-1]["corrections"], 4)
        self.assertEqual(assignment["stages"][-1]["inherited_corrections"], 3)
        self.assertIn("preserved-best", assignment["stages"][-1]["candidates"])
        self.assertEqual(assignment["stage"], "qwen")

    def test_external_receipts_cannot_claim_controller_remote_recovery(self):
        old = TrialLedgerTests("test_default_policy_is_unchanged_and_real_trial_is_explicit")
        old.setUp()
        old.ready()
        old.observe("commit", old.receipt("commit", commit="e" * 40, local_head="e" * 40))
        receipt = old.receipt("push", commit="e" * 40, push_exit_code=None, pushed=True,
                              remote_contains_commit=True, remote_head="e" * 40, recovered_from_remote=True,
                              command_refs=["synthetic-unadmitted-query"])
        with self.assertRaises(StateError):
            old.ledger.observe_trial_receipt("trial-0", kind="push", receipt=receipt, event_id=old.event())


    def test_old_completion_cannot_bless_new_bytes_during_a_later_owner_turn(self):
        self.f.start()
        packet, _, original_record = self.f.capture()
        self.f.validate()
        self.f.prepare_review()
        review = self.f.admit()
        self.f.complete(review, self.f.review_result(review, decision="reject"))
        correction = self.f.admit()
        changed = json.loads(json.dumps(packet))
        changed["logical_units"][0]["message"] = "Different pending publication intent"
        record = dict(original_record, sha256=content_identity(changed), size=len(json.dumps(changed).encode()))
        record["path"] = str(self.f.root / "deliveries" / "raw" / (record["sha256"] + ".json"))
        with self.assertRaises(StateError):
            self.ledger.record_trial_delivery("trial-0", delivery=changed, record=record, event_id="stale-native-completion")
        activity = self.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]["owner_activity"]
        self.assertEqual(activity["effect_id"], correction["effect_id"])
        self.assertTrue(activity["busy"])


    def test_missing_fixed_native_command_is_rejected_before_provider_work(self):
        attempted = []
        def omit_command(fixture):
            attempted.append(fixture)
            fixture.config["verification"]["trial-0"]["recipe"].pop("native_compile_command")
        with self.assertRaises(StateError):
            WorkflowFixture(configure=omit_command)
        trial = attempted[0].ledger.snapshot()["trial"]
        self.assertNotIn("workflow", trial)
        self.assertEqual(trial["effects"], {})

    def test_changed_relevant_inputs_supersede_inflight_verification_without_credit(self):
        self.f.start()
        self.f.capture()
        action = self.f.admit()
        self.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="synthetic-changed-header", event_id="header-changed")
        observed = self.f.complete(action, self.f.validation_result())
        self.assertTrue(observed["superseded"])
        self.assertIsNone(self.ledger.assignment("trial-0")["verification"])
        ready = self.ledger.trial_readiness("trial-0")
        self.assertEqual(ready["kind"], "reconcile")
        self.assertEqual(ready["binding"]["changed_input_identity"], "f" * 64)
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 1)

    def test_unrelated_target_head_does_not_invalidate_immutable_verification(self):
        self.f.start()
        self.f.capture(0)
        self.f.validate(0)
        verification = self.ledger.assignment("trial-0")["verification"]
        self.f.reviewed(1)
        self.f.materialize(1)
        self.f.publish(1)
        self.assertEqual(self.ledger.assignment("trial-0")["verification"], verification)
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "prepare_review")


    def test_workflow_process_only_commands_keep_their_real_operation(self):
        for index, operation in enumerate(("verify", "materialize", "cleanup", "status")):
            identity = dict(pid=90000 + index, creation_time=f"synthetic-{index}",
                            token=f"command-{index}", job_name=f"job-{index}")
            registered = self.ledger.register_process(process_id=f"command-{index}", session_id=None,
                identity=identity, operation=operation, authorization_revision=1, event_id=self.f.case.event())
            self.assertEqual(registered["operation"], operation)
            with self.assertRaises(PolicyError):
                self.ledger.register_process(process_id=f"session-command-{index}", session_id="child-0",
                    identity=identity, operation=operation, authorization_revision=1, event_id=self.f.case.event())
        revision = self.ledger.request_stop(event_id=self.f.case.event(), reason="Synthetic STOP")["revision"]
        self.ledger.register_process(process_id="readonly-after-stop", session_id=None,
            identity=dict(pid=91000, creation_time="synthetic-stop", token="readonly-stop", job_name="readonly-stop"),
            operation="status", authorization_revision=revision, event_id=self.f.case.event())
        with self.assertRaises(PolicyError):
            self.ledger.register_process(process_id="verify-after-stop", session_id=None,
                identity=dict(pid=91001, creation_time="synthetic-stop", token="verify-stop", job_name="verify-stop"),
                operation="verify", authorization_revision=revision, event_id=self.f.case.event())
        control = Ledger(self.f.root / "control-only.sqlite3")
        control.authorize("RUN", event_id="control-run", expected_revision=0, reason="Synthetic control")
        for operation in ("verify", "materialize", "cleanup", "status"):
            with self.assertRaises(PolicyError):
                control.register_process(process_id="not-a-workflow", session_id=None,
                    identity=dict(pid=92000, creation_time="synthetic", token="control", job_name="control"),
                    operation=operation, authorization_revision=1, event_id=self.f.case.event())

    def test_missing_delivery_reconciles_same_owner_and_identical_failure_does_not_loop(self):
        self.f.start()
        error = dict(reason="No delivery file", original_path=str(
            Path(self.f.case.manifest["reservations"][0]["workspace"]) / "evidence/controller-delivery.json"),
            archive=None)
        record = self.f.owner_record()
        self.ledger.record_trial_delivery_error("trial-0", error=error, record=record, event_id="missing-delivery")
        first = self.ledger.trial_readiness("trial-0")
        self.assertTrue(first["ready"])
        self.assertEqual(first["kind"], "reconcile")
        self.assertIsNone(first["binding"]["delivery_id"])
        self.ledger.record_trial_delivery_error("trial-0", error=error, record=record, event_id="duplicate-missing")
        correction = self.f.admit()
        self.assertTrue(correction["binding"]["repair_only"])
        with self.assertRaises(StateError):
            self.f.measure(self.f.packet(), dispatch=correction["effect_id"])
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 0)
        self.assertIsNone(self.ledger.assignment("trial-0")["best_candidate"])
        completed = self.f.owner_record(dispatch=correction["effect_id"])
        self.f.complete(correction, {"native_event": completed["native_event"]})
        self.ledger.record_trial_delivery_error("trial-0", error=error, record=completed, event_id="still-missing")
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "unchanged_invalid_delivery")
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 0)

    def test_superseded_reviewer_is_registered_without_approving_stale_inputs(self):
        self.f.start()
        self.f.capture()
        self.f.validate()
        action = self.f.admit()
        reviewer = dict(action["reviewer"], session_id="observed-reviewer",
                        journal_ref="native-journal", registry_ref="native-registry")
        self.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="changed-header", event_id="change-during-review-preparation")
        observed = self.f.complete(action, dict(reviewer=reviewer, native_event=dict(
            kind="review_gate_wait", registry_id=reviewer["owner_id"], session_id=reviewer["session_id"],
            root_session_id=reviewer["root_session_id"])))
        self.assertTrue(observed["superseded"])
        snapshot = self.ledger.snapshot()
        self.assertEqual(snapshot["trial"]["workflow"]["assignments"]["trial-0"]["reviewer"], reviewer)
        self.assertTrue(snapshot["sessions"][reviewer["session_id"]]["active"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        self.assertIsNone(self.ledger.assignment("trial-0")["review"])

    def test_superseded_materialization_requires_observed_restoration_before_reconciliation(self):
        self.f.start()
        self.f.reviewed()
        action = self.f.admit()
        materialized = self.f.materialize_result()
        self.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="changed-header", event_id="change-during-materialization")
        observed = self.f.complete(action, materialized)
        self.assertTrue(observed["superseded"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "restore_materialization")
        self.assertIsNone(self.ledger.assignment("trial-0")["materialization"])
        restore = self.f.admit()
        self.assertEqual(self.ledger.snapshot()["trial"]["workflow"]["target_lease"], restore["effect_id"])
        state = self.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]
        delivery = state["deliveries"][action["binding"]["delivery_id"]]["delivery"]
        self.f.complete(restore, {"error": "Interrupted restoration"}, outcome="uncertain")
        self.assertEqual(self.ledger.snapshot()["trial"]["workflow"]["target_lease"], restore["effect_id"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "uncertain_effect")
        self.ledger.request_stop(event_id=self.f.case.event(), reason="Observe restoration without replay")
        result = dict(restored_action_id=action["effect_id"], base_head=action["binding"]["target_head"],
                      restored_preimages={path: change["before"] for path, change in delivery["changes"].items()},
                      scope_verified=True, preservation_ref="retained-materialized-bytes",
                      command_refs=["synthetic-restoration-proof"], recovered_restoration=True)
        query = self.f.record(restore, result)
        query["started_at"] = datetime.now(timezone.utc).isoformat()
        query["observed_at"] = datetime.now(timezone.utc).isoformat()
        self.ledger.observe_trial_action(effect_id=restore["effect_id"], record=query, event_id="restoration-observed")
        self.ledger.observe_trial_action(effect_id=restore["effect_id"], record=query, event_id="restoration-duplicate")
        self.assertIsNone(self.ledger.snapshot()["trial"]["workflow"]["target_lease"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        self.assertEqual(self.ledger.trial_readiness("trial-0")["reason"], "explicit_pause")

    def test_case_variant_binary_expectations_cannot_satisfy_127_distinct_paths(self):
        attempted = []
        def alias_binary(fixture):
            attempted.append(fixture)
            binaries = fixture.config["verification"]["trial-0"]["binary_hashes"]
            digest = binaries.pop("originals/126.bin")
            binaries["ORIGINALS/0.BIN"] = digest
        with self.assertRaises(StateError):
            WorkflowFixture(configure=alias_binary)
        self.assertNotIn("workflow", attempted[0].ledger.snapshot()["trial"])

    def test_owner_interval_cannot_impersonate_native_timing_even_with_expected_ids(self):
        self.f.start()
        record = self.f.case.observation(owner_id="owner-0", native_actor_id="owner-0",
            native_session_id="child-0", phase="model_execution", started_at="2025-01-01T00:00:00+00:00",
            observed_at="2025-01-01T00:00:01+00:00")
        with self.assertRaises(StateError):
            self.ledger.trial_event("trial-0", kind="interval", record=record, event_id="owner-forged-interval")


    def test_completed_materialization_is_restored_before_changed_input_reconciliation(self):
        self.f.start()
        self.f.reviewed()
        materialized = self.f.materialize()
        self.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="changed-after-materialization", event_id="late-header-change")
        ready = self.ledger.trial_readiness("trial-0")
        self.assertTrue(ready["ready"])
        self.assertEqual(ready["kind"], "restore_materialization")
        self.assertEqual(ready["binding"]["recovery_action_id"], materialized["effect_id"])
        snapshot = self.ledger.snapshot()["trial"]["workflow"]
        self.assertEqual(snapshot["target_lease"], materialized["effect_id"])
        self.assertTrue(snapshot["actions"][materialized["effect_id"]]["superseded"])
        state = snapshot["assignments"]["trial-0"]
        self.assertIsNone(state["materialization"])
        delivery = state["deliveries"][state["current_delivery_id"]]["delivery"]
        restoration = self.f.admit()
        self.f.complete(restoration, dict(restored_action_id=materialized["effect_id"],
            base_head=materialized["binding"]["target_head"],
            restored_preimages={path: change["before"] for path, change in delivery["changes"].items()},
            scope_verified=True, preservation_ref="synthetic-preserved-materialization",
            command_refs=["synthetic-restoration-command"]))
        self.assertIsNone(self.ledger.snapshot()["trial"]["workflow"]["target_lease"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        self.assertTrue(self.ledger.trial_readiness("trial-0")["ready"])

    def test_failed_dispatch_cannot_capture_later_valid_bytes_during_stop_recovery(self):
        self.f.start()
        packet = self.f.packet()
        self.f.measure(packet)
        completion = self.f.owner_record()
        original = str(Path(self.f.case.manifest["reservations"][0]["workspace"]) /
                       "evidence/controller-delivery.json")
        self.ledger.record_trial_delivery_error("trial-0",
            error=dict(reason="Missing at actual owner completion", original_path=original, archive=None),
            record=completion, event_id="original-failure")
        self.ledger.request_stop(event_id="stop-before-reread", reason="Observe only; no owner repair")
        raw_hash = content_identity(packet)
        capture = dict(completion, original_path=original, sha256=raw_hash,
            size=len(json.dumps(packet).encode()), path=str(self.f.root / "deliveries/raw" / (raw_hash + ".json")))
        with self.assertRaises(StateError):
            self.ledger.record_trial_delivery("trial-0", delivery=packet, record=capture,
                                             event_id="late-recovered-bytes")
        state = self.ledger.snapshot()["trial"]["workflow"]["assignments"]["trial-0"]
        self.assertIsNone(state["current_delivery_id"])
        self.assertEqual(state["correction"]["action_id"], "original-failure")
        self.assertEqual(self.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 1)


    def test_reporting_repair_captures_preserved_candidate_without_a_new_attempt(self):
        self.f.start()
        packet = self.f.packet()
        self.f.measure(packet)
        before = self.ledger.assignment("trial-0")
        original = str(Path(self.f.case.manifest["reservations"][0]["workspace"]) /
                       "evidence/controller-delivery.json")
        self.ledger.record_trial_delivery_error("trial-0",
            error=dict(reason="Missing delivery metadata", original_path=original, archive=None),
            record=self.f.owner_record(), event_id="metadata-missing")
        repair = self.f.admit()
        with self.assertRaises(StateError):
            self.f.measure(self.f.packet(candidate="unrequested-new-candidate"), dispatch=repair["effect_id"])
        completion = self.f.owner_record(dispatch=repair["effect_id"])
        self.f.complete(repair, {"native_event": completion["native_event"]})
        raw_hash = content_identity(packet)
        capture = dict(completion, original_path=original, sha256=raw_hash,
            size=len(json.dumps(packet).encode()), path=str(self.f.root / "deliveries/raw" / (raw_hash + ".json")))
        self.ledger.record_trial_delivery("trial-0", delivery=packet, record=capture, event_id="metadata-repaired")
        after = self.ledger.assignment("trial-0")
        self.assertEqual(after["stages"][-1]["initial_count"], before["stages"][-1]["initial_count"])
        self.assertEqual(after["stages"][-1]["corrections"], before["stages"][-1]["corrections"])
        self.assertEqual(after["best_candidate"], before["best_candidate"])
        self.assertEqual(self.ledger.trial_readiness("trial-0")["kind"], "validate_delivery")


class DeterministicAcceptanceTests(unittest.TestCase):
    """Controller evidence boundaries; no native compiler/provider proof is simulated as real work."""

    def started(self, **kwargs):
        fixture = WorkflowFixture(mechanical=True, **kwargs)
        fixture.start()
        return fixture

    def test_complete_coverage_publishes_and_closes_without_a_model_review(self):
        f = self.started()
        f.capture()
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "validate_delivery")
        action = f.admit()
        record = f.record(action, f.validation_result())
        f.ledger.observe_trial_action(effect_id=action["effect_id"], record=record, event_id="mechanical-result")
        f.ledger.observe_trial_action(effect_id=action["effect_id"], record=record, event_id="mechanical-duplicate")
        assignment = f.ledger.assignment("trial-0")
        self.assertEqual(assignment["status"], "verified")
        self.assertEqual(assignment["acceptance"]["mode"], "mechanical")
        self.assertIsNone(assignment["review"])
        self.assertEqual(assignment["verification"]["evidence"]["runtime_status"], "unavailable")
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "materialize")
        f.materialize()
        f.publish()
        f.cleanup()
        f.close()
        snapshot = f.ledger.snapshot()
        self.assertFalse(any(action["kind"] in {"prepare_review", "review"}
                             for action in snapshot["trial"]["workflow"]["actions"].values()))
        self.assertFalse(any(session["role"] == "review" for session in snapshot["sessions"].values()))
        assignment = f.ledger.assignment("trial-0")
        self.assertEqual(assignment["status"], "closed")
        self.assertEqual(assignment["external_receipts"].get("review", []), [])
        self.assertTrue(assignment["publication_acknowledgment"]["accepted_matching"])
        self.assertEqual(assignment["accepted_credit"], 0)
        self.assertFalse(f.ledger.session("child-0")["active"])

    def test_partial_unbound_or_worker_asserted_coverage_cannot_skip_judgment(self):
        f = self.started()
        f.capture()
        action = f.admit()
        result = f.validation_result()
        mutations = [
            lambda value: value.pop("coverage"),
            lambda value: value.update(reused_from="old-delivery-verification"),
            lambda value: value.update(coverage={"matching": True, "bytes": 8}),
            lambda value: value["coverage"].update(producer="owner-0"),
            lambda value: value["coverage"].update(policy_identity="f" * 64),
            lambda value: value["coverage"]["binding"].update(input_identity="f" * 64),
            lambda value: value["coverage"]["covered"].pop("attempt_rules"),
            lambda value: value["coverage"]["covered"].update(unrelated={"method": "owned-native-command", "evidence_refs": ["x"]}),
            lambda value: value["coverage"]["covered"]["abi"].update(method="matching-label"),
            lambda value: value["coverage"]["covered"]["abi"].update(evidence_refs=["object-only"]),
            lambda value: value["coverage"]["covered"]["relevant_inputs"].update(evidence_refs=[]),
            lambda value: value["coverage"]["unresolved"].update(compile={"reason": "Let reviewer waive compilation", "evidence_refs": ["x"]}),
        ]
        for number, mutate in enumerate(mutations):
            with self.subTest(boundary=number):
                changed = json.loads(json.dumps(result))
                mutate(changed)
                with self.assertRaises(StateError):
                    f.complete(action, changed)
                self.assertIsNone(f.ledger.assignment("trial-0")["verification"])
                self.assertIsNone(f.ledger.assignment("trial-0").get("acceptance"))
        f.complete(action, result)
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "materialize")

    def test_mechanical_rejection_returns_same_owner_and_cannot_be_waived(self):
        f = self.started()
        f.capture()
        action = f.admit()
        source = f.config["verification"]["trial-0"]["selection"]["source"]
        f.complete(action, {"findings": [{"criterion": "compile", "path": source,
                                         "reason": "Synthetic actual compiler rejection"}]}, outcome="rejected")
        ready = f.ledger.trial_readiness("trial-0")
        self.assertEqual(ready["kind"], "reconcile")
        self.assertEqual(ready["binding"]["owner_id"], "owner-0")
        with self.assertRaises(StateError):
            f.ledger.admit_trial_action("trial-0", kind="review", effect_id="waive-compiler",
                binding=ready["binding"], authorization_revision=1, event_id="invalid-waiver")
        self.assertIsNone(f.ledger.assignment("trial-0").get("acceptance"))
        self.assertEqual(f.ledger.assignment("trial-0")["stages"][-1]["initial_count"], 1)

    def test_shared_registration_needs_exact_ownership_judgment_not_just_path_coverage(self):
        f = self.started()
        f.capture(packet=f.packet(source_only=False))
        action = f.admit()
        result = f.validation_result()
        self.assertEqual(set(result["coverage"]["unresolved"]), {"ownership"})
        falsely_covered = json.loads(json.dumps(result))
        falsely_covered["coverage"]["unresolved"].pop("ownership")
        falsely_covered["coverage"]["covered"]["ownership"] = {
            "method": "controller-owned-delivery", "evidence_refs": ["allowed-paths-only"]}
        with self.assertRaises(StateError):
            f.complete(action, falsely_covered)
        f.complete(action, result)
        prepared = f.prepare_review()
        self.assertEqual(set(prepared["binding"]["unresolved_criteria"]), {"ownership"})
        review = f.admit()
        wrong_scope = f.review_result(review)
        wrong_scope["reviewed_criteria"] = ["abi"]
        with self.assertRaises(StateError):
            f.complete(review, wrong_scope)
        f.complete(review, f.review_result(review))
        assignment = f.ledger.assignment("trial-0")
        self.assertEqual(assignment["acceptance"]["mode"], "model_judgment")
        self.assertIsNotNone(assignment["review"])
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "materialize")

    def test_authorized_registration_proof_covers_only_exact_bound_insertions(self):
        def registration(fixture):
            fixture.config["verification"]["trial-0"]["recipe"]["registration"] = dict(
                schema=1, module=117, library="ft_dedede", configure_path="configure.py",
                splits_path="config/RSBE01_02/rels/ft_dedede/splits.txt",
                cflags="cflags_fighter", extra_cflags=["-RTTI off"])
        f = self.started(configure=registration)
        packet, _, _ = f.capture(packet=f.packet(source_only=False))
        action = f.admit()
        result = f.validation_result()
        source = f.config["verification"]["trial-0"]["selection"]["source"]
        shared = sorted(set(packet["changes"]) - {source})
        proof_ref = "synthetic-host-exact-insertion-proof"
        result["ownership_proof"] = dict(schema=1, binding=dict(action["binding"]), source=source,
            recipe_identity=content_identity(packet["inputs"]["recipe"]),
            paths={path: dict(json.loads(json.dumps(packet["changes"][path])),
                             transformation="configure-obj-insertion-v1" if path == "configure.py"
                             else "splits-section-insertion-v1") for path in shared},
            evidence={"path": proof_ref, "sha256": "e" * 64, "size": 8})
        result["check_identities"][proof_ref] = {"sha256": "e" * 64, "size": 8}
        result["coverage"]["unresolved"].pop("ownership")
        result["coverage"]["covered"]["ownership"] = {
            "method": "controller-owned-delivery", "evidence_refs": [proof_ref]}
        mutations = [
            lambda value: value.pop("ownership_proof"),
            lambda value: value["ownership_proof"]["binding"].update(delivery_id="f" * 64),
            lambda value: value["ownership_proof"].update(recipe_identity="f" * 64),
            lambda value: value["ownership_proof"].update(source="src/foreign.cpp"),
            lambda value: value["ownership_proof"]["paths"].pop(shared[0]),
            lambda value: value["ownership_proof"]["paths"].update({"foreign.txt": {}}),
            lambda value: value["ownership_proof"]["paths"]["configure.py"].update(
                transformation="splits-section-insertion-v1"),
            lambda value: value["ownership_proof"]["paths"][shared[0]]["before"].update(blob="f" * 40),
            lambda value: value["ownership_proof"]["paths"][shared[0]]["raw"].update(size=0),
            lambda value: value["ownership_proof"]["paths"][shared[0]].pop("raw"),
            lambda value: value["ownership_proof"]["evidence"].update(sha256="not-a-hash"),
            lambda value: value["ownership_proof"]["evidence"].update(size=False),
            lambda value: value["check_identities"][proof_ref].update(sha256="f" * 64),
            lambda value: value.update(check_identities=None),
            lambda value: value["coverage"]["covered"]["ownership"].update(evidence_refs=["allowed-paths-only"]),
        ]
        for number, mutate in enumerate(mutations):
            with self.subTest(boundary=number):
                changed = json.loads(json.dumps(result))
                mutate(changed)
                with self.assertRaises(StateError):
                    f.complete(action, changed)
                self.assertIsNone(f.ledger.assignment("trial-0").get("acceptance"))
        f.complete(action, result)
        self.assertEqual(f.ledger.assignment("trial-0")["acceptance"]["mode"], "mechanical")
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "materialize")
        self.assertIsNone(f.ledger.assignment("trial-0")["review"])

    def reusable_delivery(self, *, change_artifact=False, change_source=False):
        f = self.started()
        original, _, _ = f.capture()
        previous = f.admit()
        prior = f.validation_result()
        f.complete(previous, prior)
        materialize = f.admit()
        source = f.config["verification"]["trial-0"]["selection"]["source"]
        f.complete(materialize, {"effect_absent": True, "findings": [
            {"criterion": "ownership", "path": source,
             "reason": "Synthetic publication grouping correction before any target mutation"}]}, outcome="rejected")
        correction = f.admit()
        f.complete(correction, {"native_event": f.owner_record(dispatch=correction["effect_id"])["native_event"]})
        packet = f.packet(candidate="changed-source") if change_source else json.loads(json.dumps(original))
        packet["logical_units"][0]["message"] = "Corrected logical publication description"
        if change_artifact:
            packet["artifacts"]["compile"]["identity"]["sha256"] = "f" * 64
        f.capture(packet=packet, dispatch=correction["effect_id"], measure=change_source)
        action = f.admit()
        result = f.validation_result()
        reference = "synthetic-fresh-reuse-observation-" + action["effect_id"]
        result["reused_from"] = previous["effect_id"]
        result["reuse_evidence"] = dict(source_action_id=previous["effect_id"], binding=dict(action["binding"]),
            evidence_ref=reference, identities=json.loads(json.dumps(prior["check_identities"])),
            output_identities=json.loads(json.dumps(prior["output_identities"])))
        result["check_identities"][reference] = {
            "sha256": hashlib.sha256(reference.encode()).hexdigest(), "size": len(reference)}
        return f, previous, action, result

    def test_intact_native_receipts_reuse_requires_new_delivery_acceptance(self):
        f, previous, action, result = self.reusable_delivery()
        self.assertIsNone(f.ledger.assignment("trial-0")["acceptance"])
        self.assertNotEqual(previous["binding"]["delivery_id"], action["binding"]["delivery_id"])
        f.complete(action, result)
        assignment = f.ledger.assignment("trial-0")
        self.assertEqual(assignment["acceptance"]["mode"], "mechanical")
        self.assertEqual(assignment["acceptance"]["validation_action_id"], action["effect_id"])
        self.assertEqual(assignment["acceptance"]["coverage_identity"], content_identity(result["coverage"]))
        self.assertIsNone(assignment["review"])
        self.assertEqual(assignment["stages"][-1]["initial_count"], 1)
        self.assertEqual(assignment["stages"][-1]["corrections"], 0)
        self.assertEqual(len(assignment["stages"][-1]["attempts"]), 1)
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "materialize")

    def test_reuse_rejects_stale_or_unobserved_proofs_without_reusing_acceptance(self):
        f, previous, action, result = self.reusable_delivery()
        reference = result["checks"]["compile"]
        output = next(iter(result["output_identities"]))
        mutations = [
            lambda value: value.update(reused_from=[]),
            lambda value: value.update(reused_from=action["effect_id"]),
            lambda value: value.pop("reuse_evidence"),
            lambda value: value["reuse_evidence"].update(source_action_id="foreign-validation"),
            lambda value: value["reuse_evidence"].update(binding=previous["binding"]),
            lambda value: value.update(verification_spec_identity="f" * 64),
            lambda value: value["reuse_evidence"].update(identities={"intact": True}),
            lambda value: value["reuse_evidence"]["identities"][reference].update(sha256="f" * 64),
            lambda value: value["reuse_evidence"]["output_identities"][output].update(size=0),
            lambda value: value["output_identities"][output].update(sha256="f" * 64),
            lambda value: value["check_identities"][reference].update(sha256="f" * 64),
            lambda value: value["check_identities"].pop(value["reuse_evidence"]["evidence_ref"]),
            lambda value: value["coverage"].update(binding=previous["binding"]),
        ]
        for number, mutate in enumerate(mutations):
            with self.subTest(boundary=number):
                changed = json.loads(json.dumps(result))
                mutate(changed)
                with self.assertRaises(StateError):
                    f.complete(action, changed)
                self.assertIsNone(f.ledger.assignment("trial-0").get("acceptance"))
        f.complete(action, result)
        self.assertEqual(f.ledger.assignment("trial-0")["acceptance"]["validation_action_id"], action["effect_id"])

    def test_changed_source_or_worker_artifact_cannot_reuse_native_receipts(self):
        for changes in ({"change_artifact": True}, {"change_source": True}):
            with self.subTest(changes=changes):
                f, _, action, result = self.reusable_delivery(**changes)
                with self.assertRaises(StateError):
                    f.complete(action, result)
                self.assertIsNone(f.ledger.assignment("trial-0").get("acceptance"))
                f.complete(action, f.validation_result())
                self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "materialize")

    def test_explicit_judgment_reason_and_fixed_policy_cannot_be_replaced(self):
        def require_abi(fixture):
            fixture.config["verification"]["trial-0"]["judgment_requirements"] = {"abi": "Inspect a specific caller contract"}
        f = self.started(configure=require_abi)
        f.capture()
        action = f.admit()
        result = f.validation_result()
        result["coverage"]["unresolved"]["abi"]["reason"] = "A different invented question"
        with self.assertRaises(StateError):
            f.complete(action, result)
        f.complete(action, f.validation_result())
        self.assertEqual(f.ledger.trial_readiness("trial-0")["binding"]["unresolved_criteria"]["abi"]["reason"],
                         "Inspect a specific caller contract")
        def remove_criterion(fixture):
            fixture.config["acceptance_policy"]["criteria"].pop("ownership")
        with self.assertRaises(StateError):
            WorkflowFixture(configure=remove_criterion)

    def test_independent_mechanical_deliveries_serialize_only_the_shared_publication_target(self):
        f = self.started()
        for index in (0, 1):
            f.capture(index)
            f.validate(index)
            self.assertTrue(f.ledger.trial_readiness(f"trial-{index}")["ready"])
        barrier = Barrier(2)
        def materialize(index):
            barrier.wait()
            try:
                return f.admit(index)["execute"]
            except StateError:
                return False
        with ThreadPoolExecutor(max_workers=2) as pool:
            admitted = list(pool.map(materialize, (0, 1)))
        self.assertEqual(sum(admitted), 1)
        snapshot = f.ledger.snapshot()
        self.assertEqual(sum(action["kind"] == "materialize" for action in
                             snapshot["trial"]["workflow"]["actions"].values()), 1)
        self.assertFalse(any(session["role"] == "review" for session in snapshot["sessions"].values()))

    def test_inflight_mechanical_result_after_stop_is_observation_not_publication_permission(self):
        f = self.started()
        f.capture()
        action = f.admit()
        record = f.record(action, f.validation_result())
        stopped = f.ledger.request_stop(event_id="stop-verification", reason="Do not publish")
        f.ledger.observe_trial_action(effect_id=action["effect_id"], record=record, event_id="late-verification")
        f.ledger.observe_trial_action(effect_id=action["effect_id"], record=record, event_id="late-duplicate")
        self.assertEqual(f.ledger.assignment("trial-0")["acceptance"]["mode"], "mechanical")
        self.assertEqual(f.ledger.trial_readiness("trial-0")["reason"], "explicit_pause")
        self.assertEqual(f.ledger.authorization(), stopped)
        self.assertIsNone(f.ledger.assignment("trial-0")["publication_acknowledgment"])

    def test_changed_inputs_invalidate_mechanical_acceptance_not_historical_ack(self):
        f = self.started()
        f.capture()
        f.validate()
        f.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="changed-before-publication", event_id="invalidate-mechanical")
        self.assertIsNone(f.ledger.assignment("trial-0")["acceptance"])
        self.assertEqual(f.ledger.trial_readiness("trial-0")["kind"], "reconcile")
        accepted = self.started()
        accepted.capture()
        accepted.validate()
        accepted.materialize()
        accepted.publish()
        original = accepted.ledger.assignment("trial-0")["acceptance"]
        accepted.ledger.check_input_identity("trial-0", input_identity="f" * 64,
            evidence_ref="changed-after-ack", event_id="preserve-mechanical-ack")
        self.assertEqual(accepted.ledger.assignment("trial-0")["acceptance"], original)
        self.assertTrue(accepted.ledger.assignment("trial-0")["publication_acknowledgment"]["accepted_matching"])

    def test_exhausted_fallback_can_finish_mechanically_without_matching_credit(self):
        f = self.started(inherited_corrections=9)
        packet = f.packet(candidate="last-best")
        source = f.config["verification"]["trial-0"]["selection"]["source"]
        f.ledger.record_attempt("trial-0", candidate_id=packet["candidate_id"],
            source_ref={"path": str(Path(f.case.manifest["reservations"][0]["workspace"]) / "drafts/last-best.cpp"),
                        "sha256": packet["changes"][source]["raw"]["sha256"]},
            input_identity=packet["inputs"]["identity"], recipe_ref="synthetic-fixed-recipe",
            outcome="nonmatching", evidence_refs=["synthetic-final-comparison"], quality=0.9,
            observation=f.owner_record(), authorization_revision=1, event_id="last-correction")
        f.ledger.exhaust_stage("trial-0", evidence_refs=["synthetic-exhausted-history"],
            observation=f.owner_record(), authorization_revision=1, event_id="actual-fixed-budget-exhausted")
        raw_hash = content_identity(packet)
        record = dict(f.owner_record(), path=str(f.root / "deliveries/raw" / (raw_hash + ".json")),
            original_path=str(Path(f.case.manifest["reservations"][0]["workspace"]) / "evidence/controller-delivery.json"),
            sha256=raw_hash, size=len(json.dumps(packet).encode()))
        f.ledger.record_trial_delivery("trial-0", delivery=packet, record=record, event_id="final-draft-delivery")
        action = f.admit()
        result = f.validation_result()
        result["matching"] = False
        result["source_selection"].update(selected=False, fallback_selected=True)
        f.complete(action, result)
        self.assertEqual(f.ledger.assignment("trial-0")["acceptance"]["mode"], "mechanical")
        f.materialize()
        f.publish()
        assignment = f.ledger.assignment("trial-0")
        self.assertFalse(assignment["publication_acknowledgment"]["accepted_matching"])
        self.assertEqual(assignment["selection"]["accepted_credit"], 0)
        self.assertEqual(assignment["stages"][-1]["corrections"], 10)
        self.assertIsNone(assignment["review"])


if __name__ == "__main__":
    unittest.main()
