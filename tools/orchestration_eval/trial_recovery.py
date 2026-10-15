"""Observe stopped owned effects without replaying a model, apply, commit or push."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import time
import uuid

from .evidence import file_identity, input_path
from .processes import ProcessManager
from .safety import SafetyError, confined, digest, now, save_json
from .trial_cleanup import validate_plan
from .trial_completion import completion, review_decision
from .trial_registration import RegistrationAdapter
from .trial_repository import IndependentRepository
from .trial_workflow import TrialWorkflow
from .trial_identity import validate_child
from .evidence import content_identity


class ReadOnlyGit:
    def __init__(self, runtime, repository):
        self.runtime, self.repository = runtime, repository
        self.references = []

    def query(self, arguments, *, allowed=(0,)):
        if (arguments[0] not in {"rev-parse", "cat-file", "diff-tree", "ls-tree", "ls-remote", "merge-base", "hash-object", "symbolic-ref", "remote", "config"}
                or "-w" in arguments or arguments[0] == "remote" and arguments[:2] != ["remote", "get-url"]
                or arguments[0] == "config" and arguments[:3] != ["config", "--local", "--get"]):
            raise SafetyError("Recovery only observes Git; it cannot mutate or replay publication")
        argv, extra = self.repository.command(arguments)
        argv[1:1] = ["-C", str(self.repository.path)]
        environment = dict(self.runtime.environment, **extra, GIT_OPTIONAL_LOCKS="0")
        revision = self.runtime.ledger.authorization()["revision"]
        manager = ProcessManager(self.runtime.root, environment, authorize=self.runtime.manager.authorize)
        started = now()
        owned = manager.launch(argv, kind="workflow-recovery-observation", cwd=self.runtime.root,
                               authorization_revision=revision, operation="status")
        self.runtime.manager.owned[owned.process_id] = owned
        directory = Path(owned.record["record_path"]).parent
        try:
            self.runtime.register_process(owned, revision, operation="status")
            code = owned.process.wait(timeout=60)
            text = (directory / "stdout.log").read_bytes().decode("utf-8")
            receipt = directory / "recovery-query.json"
            save_json(receipt, {"argv": argv, "process_id": owned.process_id, "started_at": started,
                                "observed_at": now(), "exit_code": code, "stdout_ref": str(directory / "stdout.log"),
                                "stderr_ref": str(directory / "stderr.log"), "mutating": False})
            self.references.append(str(receipt))
            if code not in allowed:
                raise SafetyError(f"Actual read-only Git recovery query failed: {receipt}")
            return code, text.strip()
        finally:
            proof = owned.stop(grace=0, deadline=time.monotonic() + 5)
            if owned.process_id in self.runtime.ledger.snapshot()["processes"]:
                self.runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)

    def value(self, arguments):
        return self.query(arguments)[1]

    def image(self, commit, name, expected_raw):
        raw = self.value(["ls-tree", "-z", commit, "--", name])
        rows = raw.rstrip("\0").split("\0")
        if len(rows) != 1 or "\t" not in rows[0]:
            raise SafetyError("Recovery cannot establish an exact committed path")
        fields, path = rows[0].split("\t", 1)
        mode, kind, blob = fields.split()
        if path != name or mode != "100644" or kind != "blob":
            raise SafetyError("Recovered source has unexpected scope or Git mode")
        # Raw postimages remain tied to the original materialization receipt;
        # historical committed blobs do not invent current working-file bytes.
        return {"mode": mode, "blob": blob, "raw": expected_raw}


def native_events(runtime, key):
    claim = runtime.ledger.snapshot()["trial"]["claims"][key]
    for directory in (runtime.root / "native").glob("*"):
        confined(directory, runtime.root)
        ready_path = directory / "native-ready.json"
        if not ready_path.is_file():
            continue
        ready = json.loads(ready_path.read_text(encoding="utf-8"))
        if ready["root_session_id"] != claim["root_session_id"]:
            continue
        path = directory / "native-events.jsonl"
        if not path.is_file():
            continue
        with path.open("rb") as stream:
            for line in stream:
                if line.endswith(b"\n"):
                    yield ready, path, json.loads(line), line


def native_event_retained(runtime, key, event):
    for ready, path, value, raw in native_events(runtime, key):
        if value == event:
            return str(path)
    raise SafetyError("Recovered native completion is absent from the actual retained root journal")


def recover_owner_delivery(runtime, key, controller):
    doc = runtime.ledger.snapshot()
    state = doc["trial"]["workflow"]["assignments"].get(key, {})
    activity = state.get("owner_activity")
    if not activity:
        return
    effect_id = activity["effect_id"]
    if (effect_id in state.get("delivery_errors", {})
            or any(entry["record"]["dispatch_effect_id"] == effect_id for entry in state["deliveries"].values())):
        return
    effect = doc["trial"]["effects"].get(effect_id) or doc["trial"]["workflow"]["actions"][effect_id]
    assignment = doc["assignments"][key]
    for ready, path, native, raw in native_events(runtime, key):
        if native.get("kind") != "owner_turn_end" or native.get("request_id") != effect_id or native.get("will_continue") is not False:
            continue
        validate_child(ready, native, assignment["owner_id"])
        succeeded = completion(native, path)
        if not native.get("started_at"):
            raise SafetyError("Retained completion has no observed native request start")
        record = {"dispatch_effect_id": effect_id, "authorization_revision": effect["authorization_revision"],
                  "native_event": native, "started_at": native["started_at"], "observed_at": native["observed_at"],
                  "timestamp_provenance": {"source": "retained-native-request-through-owner-end", "clock_id": "host-utc"},
                  "evidence_refs": [str(path)]}
        runtime.ledger.observe_trial_owner(key, record=record, event_id="recovered-owner-" + content_identity(native))
        if not succeeded:
            if effect["kind"] in {"reconcile", "cleanup"} and effect["status"] in {"admitted", "uncertain"}:
                controller.complete(effect, {"error": "Retained native executor or command failed",
                                             "native_event": native}, outcome="failed", refs=[str(path)])
            return
        if effect["kind"] == "cleanup" or assignment.get("publication") is not None:
            return
        if effect["kind"] == "reconcile" and effect["status"] in {"admitted", "uncertain"}:
            controller.complete(effect, {"native_event": native}, refs=[str(path)])
        controller.capture_delivery(key, native, record)
        return


def recover_action(runtime, action, observer):
    repository = observer.repository
    doc = runtime.ledger.snapshot()
    workflow = doc["trial"]["workflow"]
    kind, key = action["kind"], action["assignment_id"]
    directory = confined(runtime.root / "workflow" / action["effect_id"], runtime.root)
    started = now()
    state = workflow["assignments"].get(key)
    if kind == "close":
        claim = doc["trial"]["claims"][key]
        proof = doc["processes"][claim["process_id"]]["exit_proof"]
        if not proof or not proof["observed_exit"]:
            raise SafetyError("Admitted close still lacks verified actual owned-job exit")
        RegistrationAdapter(runtime).close(key, proof)
        return {"process_id": proof["process_id"], "exit_evidence_ref": proof["evidence_ref"]}
    if kind in {"prepare_review", "review", "reconcile", "cleanup"}:
        wanted = "review_gate_wait" if kind == "prepare_review" else "reviewer_turn_end" if kind == "review" else "owner_turn_end"
        for ready, native_path, native, raw in native_events(runtime, key):
            if native.get("kind") != wanted or native.get("request_id") != action["effect_id"]:
                continue
            if kind != "prepare_review" and native.get("will_continue") is not False:
                continue
            expected_owner = (action["reviewer"]["owner_id"] if kind in {"prepare_review", "review"}
                              else doc["assignments"][key]["owner_id"])
            validate_child(ready, native, expected_owner)
            if kind == "prepare_review":
                reviewer = dict(action["reviewer"], session_id=native["session_id"],
                                journal_ref=native["journal_ref"], registry_ref=str(native_path))
                return {"reviewer": reviewer, "native_event": native}
            if not completion(native, native_path):
                raise SafetyError("Retained native executor or command failed")
            if kind == "reconcile":
                return {"native_event": native}
            if kind == "review":
                decision = confined(native_path.parent / "reviews" / action["binding"]["delivery_id"] / "decision.json", runtime.root)
                return dict(review_decision(decision, action), native_event=native)
            result = json.loads((directory / "cleanup-result.json").read_text(encoding="utf-8"))
            if result["binding"] != action["binding"] or result["effect_id"] != action["effect_id"]:
                raise SafetyError("Retained cleanup file does not bind its original owner effect")
            plan = json.loads(Path(result["deletion_manifest_ref"]).read_text(encoding="utf-8"))
            validate_plan(dict(plan, files=[]))
            if any(Path(row["path"]).exists() for row in result["removed_paths"]):
                raise SafetyError("Cleanup absence is not established")
            return dict(result, native_event=native)
    if kind == "commit":
        intent_path = directory / "commit-intent.json"
        intent = json.loads(intent_path.read_text(encoding="utf-8"))
        if intent["effect_id"] != action["effect_id"] or intent["delivery_id"] != action["binding"]["delivery_id"]:
            raise SafetyError("Commit intent does not identify the admitted source generation")
        commit = intent["commit"]
        head = observer.value(["rev-parse", repository.branch])
        body = observer.value(["cat-file", "commit", commit]) + "\n"
        raw = body.encode()
        if hashlib.sha1(b"commit " + str(len(raw)).encode() + b"\0" + raw).hexdigest() != commit or head != commit:
            raise SafetyError("Exact planned commit bytes and actual local ref are not established")
        if f"tree {intent['tree']}\nparent {intent['parent']}\n" not in body:
            raise SafetyError("Recovered commit changed its planned parent/tree")
        names = observer.value(["diff-tree", "--no-commit-id", "--name-only", "-r", intent["parent"], commit]).splitlines()
        if set(names) != set(intent["paths"]):
            raise SafetyError("Recovered commit changed undeclared paths")
        expected = {name: state["materialization"]["postimages"][name] for name in intent["paths"]}
        images = {name: observer.image(commit, name, image["raw"]) for name, image in expected.items()}
        if images != expected:
            raise SafetyError("Recovered committed blobs differ from actual accepted postimages")
        return dict(intent, local_head=head, changed_paths=names, postimages=images,
                    command_refs=observer.references, recovered_from_git=True, query_started_at=started)
    if kind == "push":
        commit = action["binding"]["commit"]
        rows = observer.value(["ls-remote", "--heads", repository.target["remote"], repository.branch]).splitlines()
        if len(rows) != 1 or rows[0].split()[1] != repository.branch:
            raise SafetyError("Exact remote publication remains unobserved")
        remote = rows[0].split()[0]
        observer.query(["merge-base", "--is-ancestor", commit, remote])
        return {"logical_unit_id": action["binding"]["logical_unit_id"], "commit": commit,
                "remote_head": remote, "remote": repository.target["remote"], "branch": repository.target["branch"],
                "push_exit_code": None, "pushed": True, "remote_contains_commit": True,
                "recovered_from_remote": True, "query_started_at": started, "command_refs": observer.references}
    if kind == "restore_materialization":
        preservation = directory / "restore-intent.json"
        restoration = json.loads(preservation.read_bytes())
        original = workflow["actions"][action["binding"]["recovery_action_id"]]
        intent_path = confined(Path(restoration["materialization_intent_ref"]),
                               runtime.root / "workflow" / original["effect_id"])
        if (restoration["restored_action_id"] != original["effect_id"]
                or digest(intent_path) != restoration["materialization_intent_sha256"]):
            raise SafetyError("Restoration intent differs from its original actual materialization")
        intent = json.loads(intent_path.read_bytes())
        if (intent.get("preimages") != original["result"].get("preimages")
                or intent["head"] != action["binding"]["target_head"]
                or observer.value(["rev-parse", repository.branch]) != intent["head"]
                or file_identity(repository.gitdir / "index") != intent["index_identity"]):
            raise SafetyError("Restored target ref, index or original preimages changed")
        images = repository.restored_preimages(intent, lambda name, path:
            observer.value(["hash-object", "--path=" + name, str(path)]))
        return {"restored_action_id": original["effect_id"], "base_head": intent["head"],
                "restored_preimages": images, "scope_verified": True, "preservation_ref": str(preservation),
                "command_refs": observer.references, "recovered_restoration": True, "query_started_at": started}
    if kind == "materialize":
        intent_path = directory / "materialization-intent.json"
        intent = json.loads(intent_path.read_text(encoding="utf-8"))
        if intent["delivery_id"] != action["binding"]["delivery_id"] or digest(Path(intent["patch_ref"])) != intent["patch_identity"]:
            raise SafetyError("Materialization intent or exact raw patch changed")
        if observer.value(["rev-parse", repository.branch]) != intent["head"]:
            raise SafetyError("Target ref changed across incomplete materialization")
        if file_identity(repository.gitdir / "index") != intent["index_identity"]:
            raise SafetyError("Target index changed across incomplete materialization")
        images = {}
        for name, expected in intent["expected_postimages"].items():
            path = input_path(repository.path, name)
            images[name] = {"mode": "100644", "raw": file_identity(path),
                            "blob": observer.value(["hash-object", "--path=" + name, str(path)])}
        if images != intent["expected_postimages"]:
            raise SafetyError("Partial working-file effects retained; no repair/apply replay is authorized")
        return {"base_head": intent["head"], "head": intent["head"], "expected_postimages": images,
                "preimages": intent["preimages"],
                "actual_postimages": images, "scope_verified": True, "source_binding_verified": True,
                "preservation_ref": str(intent_path), "private_index_ref": str(intent_path),
                "grant_ref": str(runtime.root / "workflow-config.json"), "evidence_refs": observer.references}
    # Observations are durable before ledger mutation. Reuse a concrete complete
    # record only with its actual check hashes/native event, never an inferred RPC ACK.
    for path in sorted(directory.glob("observation-*.json")):
        record = json.loads(path.read_text(encoding="utf-8"))
        if record["binding"] != action["binding"] or record["outcome"] != "succeeded":
            continue
        result = record["result"]
        if kind == "validate_delivery":
            if not result.get("check_identities"):
                continue
            for reference, expected in result["check_identities"].items():
                if file_identity(confined(Path(reference), runtime.root)) != expected:
                    raise SafetyError("Retained verification evidence changed before recovery")
        elif kind in {"review", "prepare_review", "reconcile", "cleanup"}:
            reference = native_event_retained(runtime, key, result["native_event"])
            if kind != "prepare_review" and not completion(result["native_event"], reference):
                raise SafetyError("Retained action did not reach successful native settlement")
            if kind == "review":
                actual = review_decision(result["decision_file"]["path"], action)
                if any(result.get(name) != value for name, value in actual.items()):
                    raise SafetyError("Actual review decision changed before recovery")
            if kind == "cleanup":
                plan = json.loads(Path(result["deletion_manifest_ref"]).read_text(encoding="utf-8"))
                validate_plan(dict(plan, files=[]))
                if any(Path(item["path"]).exists() for item in result["removed_paths"]):
                    raise SafetyError("Recovered cleanup still has declared removed files")
        elif kind == "prepare_target":
            repository.guard()
            if (observer.value(["rev-parse", "HEAD"]) != result["head"]
                    or observer.value(["remote", "get-url", "origin"]) != result["remote"]
                    or file_identity(repository.gitdir / "config")["sha256"] != result["config_sha256"]):
                raise SafetyError("Prepared independent target identity changed")
        else:
            continue
        return result
    raise SafetyError("No complete independently observable outcome; preserve uncertainty without replay")


def recover_workflow(runtime):
    snapshot = runtime.ledger.snapshot()
    if "workflow" not in snapshot["trial"]:
        return {"observations": [], "effects_replayed": 0}
    controller = TrialWorkflow(runtime)
    controller.shutdown()
    repository = IndependentRepository(runtime)
    outcomes = []
    for key in snapshot["trial"]["claims"]:
        try:
            for ready, path, native, raw in native_events(runtime, key):
                if native.get("kind") == "native_interval":
                    controller.native_event(key, native, path, raw=raw)
            while controller.events:
                controller.process_native(*controller.events.pop(0))
            recover_owner_delivery(runtime, key, controller)
        except (OSError, ValueError, RuntimeError) as error:
            outcomes.append({"assignment_id": key, "outcome": "delivery_unresolved", "error": repr(error)})
    snapshot = runtime.ledger.snapshot()
    for effect_id, action in snapshot["trial"]["workflow"]["actions"].items():
        if action["status"] not in {"admitted", "uncertain"}:
            continue
        observer = ReadOnlyGit(runtime, repository)
        try:
            result = recover_action(runtime, action, observer)
            controller.complete(action, result, refs=observer.references)
            outcomes.append({"effect_id": effect_id, "outcome": "observed"})
        except (OSError, ValueError, RuntimeError) as error:
            result = {"error": repr(error), "recovery_query_refs": observer.references, "effects_replayed": 0}
            outcome = "uncertain"
            if action["kind"] in {"review", "reconcile", "cleanup"}:
                for ready, path, native, raw in native_events(runtime, action["assignment_id"]):
                    wanted = "reviewer_turn_end" if action["kind"] == "review" else "owner_turn_end"
                    if (native.get("kind") != wanted or native.get("request_id") != effect_id
                            or native.get("will_continue") is not False):
                        continue
                    owner = (action["reviewer"]["owner_id"] if action["kind"] == "review"
                             else snapshot["assignments"][action["assignment_id"]]["owner_id"])
                    try:
                        validate_child(ready, native, owner)
                        completion(native, path)
                    except (OSError, ValueError, RuntimeError):
                        continue
                    result["native_event"] = native
                    observer.references.append(str(path))
                    outcome = "failed"
                    break
            controller.complete(action, result, outcome=outcome, refs=observer.references)
            outcomes.append({"effect_id": effect_id, "outcome": outcome, **result})
    # ACK and closure are observational, even after STOP. They neither resume a
    # native session nor consume another reconstruction/model allowance.
    for key in runtime.ledger.snapshot()["trial"]["claims"]:
        row = runtime.ledger.trial_readiness(key)
        if not row["ready"] or row["kind"] not in {"acknowledge", "close"}:
            continue
        effect_id = "recovery-" + uuid.uuid4().hex
        action = runtime.ledger.admit_trial_action(key, kind=row["kind"], effect_id=effect_id, binding=row["binding"],
            authorization_revision=runtime.ledger.authorization()["revision"], event_id=effect_id + "-admit")
        action.pop("execute")
        try:
            if row["kind"] == "acknowledge":
                result = controller.dispatch(action)
            else:
                doc = runtime.ledger.snapshot()
                claim = doc["trial"]["claims"][key]
                proof = doc["processes"][claim["process_id"]]["exit_proof"]
                if not proof:
                    raise SafetyError("Closure still lacks actual verified owned-job exit")
                RegistrationAdapter(runtime).close(key, proof)
                result = {"process_id": proof["process_id"], "exit_evidence_ref": proof["evidence_ref"]}
            controller.complete(action, result)
            outcomes.append({"effect_id": effect_id, "outcome": "observed"})
        except (OSError, ValueError, RuntimeError) as error:
            controller.complete(action, {"error": repr(error)}, outcome="uncertain")
            outcomes.append({"effect_id": effect_id, "outcome": "uncertain", "error": repr(error)})
    return {"observations": outcomes, "effects_replayed": 0, "native_sessions_resumed": False}
