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

from .policy import Mode, PolicyError, SlotPolicy
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


if __name__ == "__main__":
    unittest.main()
