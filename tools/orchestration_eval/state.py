"""Durable bounded-evaluation records, not a scheduler or reconstruction engine.

Every mutation has an immutable event identity and commits with its deduplication
receipt. Evidence fields are attestations/references, never semantic proof inferred
from an engine's success state. Process-exit observations come from the native
runtime; fixture Git effects require admissions, while real-trial publication
uses identity-bound external-coordinator observations without evaluator Git authority.
This bounded pilot rewrites its whole ledger JSON per event; production-scale
throughput is neither measured nor claimed.
"""

from contextlib import contextmanager
from datetime import datetime, timezone
import hashlib
import json
import math
from pathlib import Path
import sqlite3
from typing import Callable

from .evidence import InputError, relative_path
from .policy import (Mode, PolicyError, SlotPolicy, Stage, TRIAL_PHASES, TRIAL_STARTS,
                     WORKFLOW_ACTION_OPERATIONS, evaluation_data_path, next_stage, require_allowed,
                     validate_workflow_profile, workflow_acceptance_policy, workflow_model_capacity)
from .trial_delivery import DeliveryError, WorkerDelivery


class StateError(ValueError):
    """Conflicting identity, incomplete evidence, or invalid lifecycle transition."""


def _now() -> str:
    return datetime.now(timezone.utc).isoformat()


def _json(value) -> str:
    return json.dumps(value, sort_keys=True, separators=(",", ":"), allow_nan=False)


def _digest(value) -> str:
    return hashlib.sha256(_json(value).encode("utf-8")).hexdigest()


def _text(value, name: str) -> str:
    if not isinstance(value, str) or not value.strip():
        raise StateError(f"{name} must be a nonempty string")
    return value


def _component(value, name: str) -> str:
    """Portable identities must never become paths or Windows device aliases."""
    _text(value, name)
    reserved = {"CON", "PRN", "AUX", "NUL"} | {f"{prefix}{n}" for prefix in ("COM", "LPT") for n in range(1, 10)}
    if (len(value) > 100 or not value.isascii() or not value[0].isalnum()
        or any(not (c.isalnum() or c in "_-") for c in value) or value.upper() in reserved):
        raise StateError(f"{name} must be one portable non-device component")
    return value


def _refs(value, name="evidence_refs") -> None:
    if not isinstance(value, list) or not value:
        raise StateError(f"{name} must retain at least one evidence reference")
    for ref in value:
        _text(ref, name)


def read_snapshot(db_path: str | Path) -> dict:
    """Read status without creating a database, schema, directory, or journal."""
    path = evaluation_data_path(db_path)
    conn = sqlite3.connect(path.as_uri() + "?mode=ro", uri=True)
    try:
        doc = json.loads(conn.execute("SELECT data FROM ledger WHERE id=1").fetchone()[0])
        if doc.get("schema_version") != 1 or doc.get("evaluation_only") is not True:
            raise StateError("Unrecognized or non-evaluation ledger")
        doc["event_count"] = conn.execute("SELECT COUNT(*) FROM events").fetchone()[0]
        return doc
    finally:
        conn.close()


def _fields(record: dict, names: tuple[str, ...]) -> None:
    if not isinstance(record, dict):
        raise StateError("Expected an evidence record")
    for name in names:
        _text(record.get(name), name)


def _hex(value, length: int, name: str) -> None:
    _text(value, name)
    if len(value) != length or any(c not in "0123456789abcdef" for c in value):
        raise StateError(f"{name} must be a full lowercase {length}-digit identity")


class Ledger:
    """SQLite-backed transactions; opening a ledger never launches or resumes work."""

    def __init__(self, db_path: str | Path, *, policy: SlotPolicy | None = None):
        self.path = evaluation_data_path(db_path)
        self.path.parent.mkdir(parents=True, exist_ok=True)
        with self._connection() as conn:
            conn.execute("CREATE TABLE IF NOT EXISTS ledger (id INTEGER PRIMARY KEY CHECK(id=1), data TEXT NOT NULL)")
            conn.execute("CREATE TABLE IF NOT EXISTS events (event_id TEXT PRIMARY KEY, digest TEXT NOT NULL, operation TEXT NOT NULL, result TEXT NOT NULL, recorded_at TEXT NOT NULL)")
            conn.execute("BEGIN IMMEDIATE")
            row = conn.execute("SELECT data FROM ledger WHERE id=1").fetchone()
            if row is None:
                chosen = policy or SlotPolicy()
                initial = {"schema_version": 1, "evaluation_only": True,
                           "policy": chosen.as_dict(), "created_at": _now(),
                           "authorization": {"mode": Mode.STOPPED.value, "revision": 0,
                                             "reason": "No evaluation authorization", "updated_at": _now()},
                           "assignments": {}, "sessions": {}, "processes": {}, "publisher": None}
                initial["authorization_history"] = [dict(initial["authorization"])]
                conn.execute("INSERT INTO ledger VALUES (1, ?)", (_json(initial),))
                self.policy = chosen
            else:
                saved = json.loads(row[0])
                if saved.get("schema_version") != 1 or saved.get("evaluation_only") is not True:
                    raise StateError("Unrecognized or non-evaluation ledger")
                config = saved["policy"]
                chosen = SlotPolicy(astra_capacity=config["astra"],
                                    overrides=config["overrides"], paused=tuple(config["paused"]))
                if policy is not None and policy.as_dict() != chosen.as_dict():
                    raise PolicyError("Explicit policy differs from the durable policy; do not silently reset overrides")
                self.policy = chosen
            conn.commit()

    @contextmanager
    def _connection(self):
        conn = sqlite3.connect(self.path, timeout=30, isolation_level=None)
        conn.execute("PRAGMA synchronous=FULL")
        try:
            yield conn
        except BaseException:
            if conn.in_transaction:
                conn.rollback()
            raise
        finally:
            conn.close()

    def _mutate(self, event_id: str, operation: str, payload: dict, apply: Callable,
                *, duplicate_result: Callable | None = None) -> dict:
        _text(event_id, "event_id")
        digest = _digest({"operation": operation, "payload": payload})
        with self._connection() as conn:
            conn.execute("BEGIN IMMEDIATE")
            duplicate = conn.execute("SELECT digest, result FROM events WHERE event_id=?", (event_id,)).fetchone()
            if duplicate is not None:
                if duplicate[0] != digest:
                    raise StateError("An event identity cannot be reused for different content")
                # This is a historic receipt, never a new authorization or side effect.
                receipt = json.loads(duplicate[1])
                return duplicate_result(receipt) if duplicate_result is not None else receipt
            doc = json.loads(conn.execute("SELECT data FROM ledger WHERE id=1").fetchone()[0])
            result = apply(doc)
            stamp = _now()
            doc["updated_at"] = stamp
            if "trial" in doc:
                self._trial_capacity(doc, stamp)
            conn.execute("UPDATE ledger SET data=? WHERE id=1", (_json(doc),))
            conn.execute("INSERT INTO events VALUES (?, ?, ?, ?, ?)",
                         (event_id, digest, operation, _json(result), stamp))
            conn.commit()
            return json.loads(_json(result))

    def snapshot(self) -> dict:
        with self._connection() as conn:
            doc = json.loads(conn.execute("SELECT data FROM ledger WHERE id=1").fetchone()[0])
            doc["event_count"] = conn.execute("SELECT COUNT(*) FROM events").fetchone()[0]
            return doc

    def authorization(self) -> dict:
        return self.snapshot()["authorization"]

    def assignment(self, assignment_id: str) -> dict:
        return self._assignment(self.snapshot(), assignment_id)

    def assignments(self) -> list[dict]:
        return list(self.snapshot()["assignments"].values())

    def session(self, session_id: str) -> dict:
        try:
            return self.snapshot()["sessions"][session_id]
        except KeyError as exc:
            raise StateError("Unknown owned session") from exc

    def processes(self) -> list[dict]:
        return list(self.snapshot()["processes"].values())

    def process(self, process_id: str) -> dict:
        try:
            return self.snapshot()["processes"][process_id]
        except KeyError as exc:
            raise StateError("Unknown owned process") from exc

    @staticmethod
    def _assignment(doc, assignment_id):
        try:
            return doc["assignments"][assignment_id]
        except KeyError as exc:
            raise StateError(f"Unknown assignment: {assignment_id}") from exc

    @staticmethod
    def _require(doc, operation, revision=None):
        auth = doc["authorization"]
        require_allowed(auth["mode"], operation)
        if revision is not None and revision != auth["revision"]:
            raise PolicyError("Queued operation has a stale authorization revision")
        if operation in {"launch", "resume", "reconstruct", "verify", "materialize"} and revision is None:
            raise PolicyError("Execution requires the captured authorization revision")
        return auth

    def require_operation(self, operation: str, authorization_revision: int | None = None) -> dict:
        return self._require(self.snapshot(), operation, authorization_revision)

    def authorize(self, mode: str, *, event_id: str, reason: str, expected_revision: int) -> dict:
        mode = Mode(mode).value
        _text(reason, "reason")
        if mode in {Mode.STOPPED.value, Mode.STOPPING.value}:
            raise PolicyError("Use request_stop and verified finish_stop for stopping")
        payload = {"mode": mode, "reason": reason, "expected_revision": expected_revision}
        def apply(doc):
            auth = doc["authorization"]
            if auth["revision"] != expected_revision:
                raise PolicyError("Authorization changed since the explicit request")
            if auth["mode"] == Mode.STOPPING.value:
                raise PolicyError("Owned process exit must be verified before reauthorization")
            doc["authorization"] = {"mode": mode, "revision": expected_revision + 1,
                                    "reason": reason, "event_id": event_id, "updated_at": _now()}
            doc.setdefault("authorization_history", [dict(auth)]).append(dict(doc["authorization"]))
            return doc["authorization"]
        return self._mutate(event_id, "authorize", payload, apply)

    def request_stop(self, *, event_id: str, reason: str) -> dict:
        _text(reason, "reason")
        def apply(doc):
            auth = doc["authorization"]
            if auth["mode"] != Mode.STOPPING.value:
                doc["authorization"] = {"mode": Mode.STOPPING.value,
                                        "revision": auth["revision"] + 1, "reason": reason,
                                        "event_id": event_id, "updated_at": _now()}
                doc.setdefault("authorization_history", [dict(auth)]).append(dict(doc["authorization"]))
            return doc["authorization"]
        return self._mutate(event_id, "request_stop", {"reason": reason}, apply)

    @staticmethod
    def _exit(doc, process_id, proof):
        if process_id not in doc["processes"]:
            raise StateError("Cannot record exit for an unmanaged process")
        process = doc["processes"][process_id]
        for key in ("pid", "creation_time", "token"):
            if proof.get(key) != process["identity"][key]:
                raise StateError(f"Process exit identity mismatch: {key}")
        if proof.get("observed_exit") is not True or type(proof.get("exit_code")) is not int:
            raise StateError("An engine state is not an observed native process exit")
        _fields(proof, ("verified_at", "evidence_ref"))
        if process["exit_proof"] is not None:
            if process["exit_proof"]["exit_code"] != proof["exit_code"]:
                raise StateError("Conflicting observed exit code")
            return process
        process["exit_proof"] = proof
        process["active"] = False
        process["updated_at"] = _now()
        return process

    def finish_stop(self, *, event_id: str, exit_proofs: list[dict]) -> dict:
        def apply(doc):
            if doc["authorization"]["mode"] not in {Mode.STOPPING.value, Mode.STOPPED.value}:
                raise PolicyError("Stop was not requested")
            for proof in exit_proofs:
                self._exit(doc, _text(proof.get("process_id"), "process_id"), proof)
            if any(p["active"] for p in doc["processes"].values()):
                raise StateError("Owned native processes still lack verified exit receipts")
            if doc["authorization"]["mode"] != Mode.STOPPED.value:
                doc["authorization"].update(mode=Mode.STOPPED.value, updated_at=_now())
            return doc["authorization"]
        return self._mutate(event_id, "finish_stop", {"exit_proofs": exit_proofs}, apply)

    def _reserve(self, doc, session_id, owner_id, stage, provider, model, role):
        _fields({"session_id": session_id, "owner_id": owner_id, "provider": provider, "model": model},
                ("session_id", "owner_id", "provider", "model"))
        stage = Stage(stage).value
        if role not in {"reconstruction", "publisher"}:
            raise StateError("Unknown session role")
        if session_id in doc["sessions"] or any(s["owner_id"] == owner_id for s in doc["sessions"].values()):
            raise StateError("A new assignment/stage needs a fresh agent and session identity")
        capacity = self.policy.capacity(stage, publisher=role == "publisher")
        used = sum(s["active"] and s["role"] == role and s["stage"] == stage
                   for s in doc["sessions"].values())
        if used >= capacity:
            raise PolicyError(f"No authorized {role} {stage} slot available")
        session = {"session_id": session_id, "owner_id": owner_id, "stage": stage,
                   "provider": provider, "model": model, "role": role, "active": True,
                   "assignment_id": None, "created_at": _now()}
        doc["sessions"][session_id] = session
        return session

    def register_session(self, *, session_id: str, owner_id: str, stage: str, provider: str,
                         model: str, event_id: str, authorization_revision: int,
                         role: str = "reconstruction") -> dict:
        payload = dict(session_id=session_id, owner_id=owner_id, stage=stage, provider=provider,
                       model=model, role=role, authorization_revision=authorization_revision)
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            if "trial" in doc:
                raise PolicyError("Trial sessions require an immutable reservation and observed native attachment")
            return self._reserve(doc, session_id, owner_id, stage, provider, model, role)
        return self._mutate(event_id, "register_session", payload, apply)

    @staticmethod
    def _stage_record(session):
        return {key: session[key] for key in ("stage", "provider", "model", "owner_id", "session_id")} | {
            "initial_count": 0, "corrections": 0, "candidates": {}, "candidate_inputs": {}, "attempts": [],
            "best_candidate": None, "historical_best_candidate": None, "exhausted": False, "created_at": _now()}

    def create_assignment(self, *, assignment_id: str, function: dict, stage: str, provider: str,
                          model: str, owner_id: str, session_id: str, event_id: str,
                          authorization_revision: int) -> dict:
        _text(assignment_id, "assignment_id")
        if not isinstance(function, dict) or not function:
            raise StateError("Immutable function identity is required")
        payload = dict(assignment_id=assignment_id, function=function, stage=stage, provider=provider,
                       model=model, owner_id=owner_id, session_id=session_id,
                       authorization_revision=authorization_revision)
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            if "trial" in doc:
                raise PolicyError("Trial assignments require the fixed reservation claim API")
            if assignment_id in doc["assignments"]:
                old = doc["assignments"][assignment_id]
                if old["identity"] != payload:
                    raise StateError("Assignment identity cannot be replaced")
                return old
            function_key = _digest(function)
            if any(a["function_key"] == function_key for a in doc["assignments"].values()):
                raise StateError("Function already has an immutable assignment")
            if session_id in doc["sessions"]:
                session = doc["sessions"][session_id]
                expected = dict(stage=Stage(stage).value, provider=provider, model=model,
                                owner_id=owner_id, role="reconstruction")
                if session["assignment_id"] is not None or not session["active"] or any(
                    session[k] != v for k, v in expected.items()
                ):
                    raise StateError("Cannot adopt or reuse an assigned session")
            else:
                session = self._reserve(doc, session_id, owner_id, stage, provider, model, "reconstruction")
            session["assignment_id"] = assignment_id
            assignment = {"assignment_id": assignment_id, "identity": payload, "function": function,
                          "function_key": function_key, "owner_id": owner_id, "session_id": session_id,
                          "stage": Stage(stage).value, "stages": [self._stage_record(session)],
                          "status": "assigned", "history": [], "best_candidate": None,
                          "historical_best_candidate": None, "input_epoch": 0, "current_input_identity": None,
                          "verification": None, "review": None, "materialization": None,
                          "publication": None, "publication_acknowledgment": None,
                          "publication_effects": {},
                          "cleanup": None, "selection": None, "accepted_credit": 0,
                          "created_at": _now(), "updated_at": _now()}
            doc["assignments"][assignment_id] = assignment
            return assignment
        return self._mutate(event_id, "create_assignment", payload, apply)

    def register_process(self, *, process_id: str, session_id: str | None, identity: dict,
                         event_id: str, authorization_revision: int, operation: str = "launch") -> dict:
        _text(process_id, "process_id")
        _fields(identity, ("creation_time", "token", "job_name"))
        if type(identity.get("pid")) is not int or identity["pid"] <= 0:
            raise StateError("Process identity needs a positive native PID")
        payload = dict(process_id=process_id, session_id=session_id, identity=identity,
                       authorization_revision=authorization_revision, operation=operation)
        def apply(doc):
            process_only = {"verify", "materialize", "cleanup", "status"}
            if (operation not in {"launch", "publish"} and
                (operation not in process_only or doc.get("trial", {}).get("workflow") is None)):
                raise PolicyError("Process-only workflow commands require configured workflow authority")
            if operation != "launch" and session_id is not None:
                raise PolicyError("Process-only commands cannot wake an owner session")
            self._require(doc, operation, authorization_revision)
            if session_id is not None and (session_id not in doc["sessions"] or not doc["sessions"][session_id]["active"]):
                raise StateError("Process session is not an active owned session")
            if process_id in doc["processes"]:
                old = doc["processes"][process_id]
                if old["identity"] != identity or old["session_id"] != session_id or old["operation"] != operation:
                    raise StateError("Process identity cannot change")
                return old
            if any(p["identity"]["token"] == identity["token"] or
                   (p["identity"]["pid"] == identity["pid"] and p["identity"]["creation_time"] == identity["creation_time"])
                   for p in doc["processes"].values()):
                raise StateError("Native process identity is already registered")
            process = {"process_id": process_id, "session_id": session_id, "identity": identity,
                       "active": True, "exit_proof": None, "created_at": _now(), "operation": operation}
            doc["processes"][process_id] = process
            return process
        return self._mutate(event_id, "register_process", payload, apply)

    def record_process_exit(self, process_id: str, *, event_id: str, proof: dict) -> dict:
        return self._mutate(event_id, "record_process_exit", {"process_id": process_id, "proof": proof},
                            lambda doc: self._exit(doc, process_id, proof))

    @staticmethod
    def _idle_session(doc, session_id):
        if any(p["active"] and p["session_id"] == session_id for p in doc["processes"].values()):
            raise StateError("Cannot release session while an owned process lacks exit proof")

    @staticmethod
    def _refresh_best(assignment):
        """Keep history intact; only measurements in the current input epoch are eligible."""
        epoch = assignment.get("input_epoch", 0)
        rank = lambda item: ({"compile_failed": 0, "nonmatching": 1, "matching": 2}[item["outcome"]],
                             item["quality"] if item["quality"] is not None else 0)
        current, historical = [], []
        for stage in assignment["stages"]:
            measured = [item for item in stage["attempts"] if item["outcome"] != "tool_failed"]
            eligible = sorted((item for item in stage["candidates"].values()
                               if item.get("input_epoch", 0) == epoch), key=lambda item: item["measured_at"])
            stage["best_candidate"] = max(eligible, key=rank, default=None)
            stage["historical_best_candidate"] = max(measured, key=rank, default=None)
            current.extend(eligible)
            historical.extend(measured)
        assignment["best_candidate"] = max(current, key=rank, default=None)
        assignment["historical_best_candidate"] = max(historical, key=rank, default=None)

    def record_attempt(self, assignment_id: str, *, event_id: str, candidate_id: str,
                       source_ref: dict, input_identity: str, recipe_ref: str, outcome: str,
                       evidence_refs: list[str], quality: float | None = None,
                       authorization_revision: int, observation: dict | None = None) -> dict:
        _text(candidate_id, "candidate_id")
        _fields(source_ref, ("path", "sha256"))
        _hex(source_ref["sha256"], 64, "source sha256")
        _text(input_identity, "input_identity")
        _text(recipe_ref, "recipe_ref")
        _refs(evidence_refs)
        if outcome not in {"compile_failed", "nonmatching", "matching", "tool_failed"}:
            raise StateError("Unknown measured attempt outcome")
        if quality is not None and (type(quality) not in {int, float} or not math.isfinite(quality)):
            raise StateError("Quality must be a finite measured score")
        payload = dict(assignment_id=assignment_id, candidate_id=candidate_id, source_ref=source_ref,
                       input_identity=input_identity, recipe_ref=recipe_ref, outcome=outcome,
                       evidence_refs=evidence_refs, quality=quality, authorization_revision=authorization_revision)
        if observation is not None:
            payload["observation"] = observation
        def apply(doc):
            if observation is None:
                self._require(doc, "reconstruct", authorization_revision)
            a = self._assignment(doc, assignment_id)
            if doc.get("trial", {}).get("workflow") is not None and observation is None:
                raise StateError("Controller measurements require the actual admitted native dispatch observation")
            if observation is not None:
                self._trial_execution_observation(doc, a, observation, authorization_revision)
            if "trial" in doc and a["session_id"] is None:
                raise StateError("A trial measurement requires its actual attached native owner")
            if "trial" in doc and not any(e["assignment_id"] == assignment_id and e["kind"] == "prompt"
                                         for e in doc["trial"]["effects"].values()):
                raise StateError("A trial measurement cannot precede admitted provider reconstruction")
            if a["status"] not in {"assigned", "reconstructing", "verifying", "blocked"}:
                raise StateError("Candidate measurement is outside active reconstruction")
            stage = a["stages"][-1]
            existing = stage["candidates"].get(candidate_id)
            if stage["exhausted"] and (
                existing is None or existing.get("input_epoch", 0) == a.get("input_epoch", 0)
            ):
                raise StateError("An exhausted stage cannot reset its allowance")
            if any(item["candidate_id"] == candidate_id and item["source_ref"] != source_ref
                   for item in stage["attempts"]):
                raise StateError("A candidate's preserved source identity is immutable")
            epoch = a.get("input_epoch", 0)
            if existing is not None and existing.get("input_epoch", 0) == epoch and (
                existing["input_identity"] != input_identity or existing["recipe_ref"] != recipe_ref
            ):
                raise StateError("Changed candidate inputs need a new candidate identity or explicit context invalidation")
            if stage["exhausted"]:
                # Re-verification after changed external inputs does not grant another correction.
                stage["exhausted"] = False
            attempt = dict(payload, stage=a["stage"], input_epoch=epoch, measured_at=_now(), event_id=event_id)
            stage["attempts"].append(attempt)
            stage.setdefault("candidate_inputs", {}).setdefault(candidate_id, {
                "source_ref": source_ref, "input_identity": input_identity, "recipe_ref": recipe_ref,
                "input_epoch": epoch, "recorded_at": attempt["measured_at"]})
            if outcome == "tool_failed":
                a["blocked_from"] = a["status"] if a["status"] != "blocked" else a.get("blocked_from", "reconstructing")
                a["status"] = "blocked"
                a["blocker"] = {"kind": "tool_infrastructure", "evidence_refs": evidence_refs}
            else:
                if existing is None:
                    count = (len(stage["candidates"]) - len(stage.get("inherited_candidate_ids", []))
                             + stage.get("inherited_initial_count", 0) + stage.get("inherited_corrections", 0))
                    if count >= 11:
                        raise StateError("Ten measured corrections already consumed")
                    prior = next((item for item in reversed(stage["attempts"][:-1])
                                  if item["outcome"] != "tool_failed"), None)
                    if prior is not None and all(prior[key] == attempt[key]
                                                 for key in ("source_ref", "input_identity", "recipe_ref")):
                        raise StateError("Unchanged-input remeasurement is not a revised candidate")
                    stage["candidates"][candidate_id] = attempt
                    stage["initial_count"] = 1
                    stage["corrections"] = count
                else:
                    stage["candidates"][candidate_id] = attempt
                self._refresh_best(a)
                a["current_input_identity"] = input_identity
                a["status"] = "verifying" if outcome == "matching" else "reconstructing"
                a.pop("blocker", None)
            a["updated_at"] = _now()
            return a
        return self._mutate(event_id, "record_attempt", payload, apply)

    def exhaust_stage(self, assignment_id: str, *, event_id: str, evidence_refs: list[str],
                      authorization_revision: int, observation: dict | None = None) -> dict:
        _refs(evidence_refs)
        payload = dict(assignment_id=assignment_id, evidence_refs=evidence_refs,
                       authorization_revision=authorization_revision)
        if observation is not None:
            payload["observation"] = observation
        def apply(doc):
            if observation is None:
                self._require(doc, "reconstruct", authorization_revision)
            a = self._assignment(doc, assignment_id)
            if observation is not None:
                self._trial_execution_observation(doc, a, observation, authorization_revision)
            stage = a["stages"][-1]
            if a["status"] not in {"reconstructing", "verifying", "exhausted"} or stage["best_candidate"] is None or stage["corrections"] != 10 or any(
                c["outcome"] == "matching" and c.get("input_epoch", 0) == a.get("input_epoch", 0)
                for c in stage["candidates"].values()
            ):
                raise StateError("Exhaustion requires ten unmatched corrections, not a tool failure")
            stage.update(exhausted=True, handoff_evidence_refs=evidence_refs)
            if observation is not None:
                stage["exhaustion_observation"] = observation
            a.update(status="exhausted", updated_at=_now())
            return a
        return self._mutate(event_id, "exhaust_stage", payload, apply)

    def escalate(self, assignment_id: str, *, event_id: str, stage: str, provider: str, model: str,
                 owner_id: str, session_id: str, authorization_revision: int) -> dict:
        payload = dict(assignment_id=assignment_id, stage=stage, provider=provider, model=model,
                       owner_id=owner_id, session_id=session_id, authorization_revision=authorization_revision)
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            a = self._assignment(doc, assignment_id)
            if "trial" in doc:
                raise PolicyError("The bounded Qwen trial never escalates or replaces its owner")
            if not a["stages"][-1]["exhausted"] or next_stage(a["stage"]) != Stage(stage).value:
                raise StateError("Only exhausted local->Sol or Sol->Astra handoff is authorized")
            self._idle_session(doc, a["session_id"])
            fresh = self._reserve(doc, session_id, owner_id, stage, provider, model, "reconstruction")
            doc["sessions"][a["session_id"]]["active"] = False
            fresh["assignment_id"] = assignment_id
            a["stages"].append(self._stage_record(fresh))
            a.update(stage=Stage(stage).value, owner_id=owner_id, session_id=session_id,
                     status="assigned", verification=None, review=None, materialization=None, updated_at=_now())
            return a
        return self._mutate(event_id, "escalate", payload, apply)

    def record_verification(self, assignment_id: str, *, event_id: str, candidate_id: str,
                            input_identity: str, evidence: dict, authorization_revision: int,
                            observation: dict | None = None) -> dict:
        _text(input_identity, "input_identity")
        checks = evidence.get("checks", {})
        scope = evidence.get("scope")
        if scope not in {"evaluation_fixture", "reconstruction"} or not isinstance(checks, dict) or not checks:
            raise StateError("Verification needs explicit scope and measured evidence checks")
        if scope == "reconstruction" and not {"compile", "object_compare", "data_relocations", "source_link", "binary_hashes"}.issubset(checks):
            raise StateError("Worker success does not establish reconstruction acceptance gates")
        for ref in checks.values():
            _text(ref, "verification check reference")
        if evidence.get("runtime_status") not in {"exercised", "unavailable"}:
            raise StateError("Record runtime verification performed or unavailable")
        if evidence["runtime_status"] == "exercised":
            _text(evidence.get("runtime_ref"), "runtime_ref")
        payload = dict(assignment_id=assignment_id, candidate_id=candidate_id, input_identity=input_identity,
                       evidence=evidence, authorization_revision=authorization_revision)
        if observation is not None:
            payload["observation"] = observation
        def apply(doc):
            if observation is None:
                self._require(doc, "verify", authorization_revision)
            a = self._assignment(doc, assignment_id)
            if observation is not None:
                self._trial_execution_observation(doc, a, observation, authorization_revision)
            if "trial" in doc and scope != "reconstruction":
                raise StateError("A real trial cannot accept fixture verification")
            if "trial" in doc and not any(e["assignment_id"] == assignment_id and e["kind"] == "prompt"
                                         for e in doc["trial"]["effects"].values()):
                raise StateError("Trial verification cannot precede admitted provider reconstruction")
            if "trial" in doc and evidence.get("binary_hash_count") != 127:
                raise StateError("Trial verification must retain all 127 native binary-hash checks")
            if "trial" in doc and evidence["runtime_status"] == "unavailable":
                _text(evidence.get("runtime_reason"), "runtime_reason")
            if a["status"] not in {"assigned", "reconstructing", "verifying", "blocked", "reconciling"}:
                raise StateError("Verification cannot bypass lifecycle reconciliation")
            candidate = a["stages"][-1]["candidates"].get(candidate_id)
            nonmatching = a["selection"] is not None and a["selection"]["candidate_id"] == candidate_id
            if nonmatching:
                selected_stage = a["selection"].get("stage")
                selected = next((s for s in a["stages"] if candidate_id in s["candidates"]
                                 and (selected_stage is None or s["stage"] == selected_stage)), None)
                candidate = selected["candidates"][candidate_id] if selected is not None else None
            if candidate is None or (not nonmatching and (
                candidate["outcome"] != "matching" or candidate["input_identity"] != input_identity
                or candidate.get("input_epoch", 0) != a.get("input_epoch", 0)
            )):
                raise StateError("Verification must bind a measured candidate and full relevant inputs")
            if nonmatching:
                a["selection"].update(input_identity=input_identity, valid=True)
                remeasured = dict(candidate, input_identity=input_identity, input_epoch=a.get("input_epoch", 0),
                                  event_id=event_id, evidence_refs=list(checks.values()), measured_at=_now())
                selected["attempts"].append(remeasured)
                selected["candidates"][candidate_id] = remeasured
                self._refresh_best(a)
            a["current_input_identity"] = input_identity
            a["verification"] = {"candidate_id": candidate_id, "input_identity": input_identity,
                                 "evidence": evidence, "valid": True, "recorded_at": _now()}
            if observation is not None:
                a["verification"]["observation"] = observation
            a["accepted_credit"] = 0  # This evaluation never updates live reconstruction accounting.
            a["updated_at"] = _now()
            return a
        return self._mutate(event_id, "record_verification", payload, apply)

    def check_input_identity(self, assignment_id: str, *, event_id: str, input_identity: str,
                             evidence_ref: str) -> dict:
        _text(input_identity, "input_identity")
        _text(evidence_ref, "evidence_ref")
        def apply(doc):
            a = self._assignment(doc, assignment_id)
            verification = a["verification"]
            relevant = a["selection"] or verification
            previous = a.get("current_input_identity") or (
                relevant["input_identity"] if relevant is not None else None)
            same = previous == input_identity
            acknowledged_workflow = (doc.get("trial", {}).get("workflow") is not None
                                     and a["publication_acknowledgment"] is not None)
            if "trial" in doc and (a["status"] == "closed" or acknowledged_workflow):
                # Later environments cannot rewrite historically accepted inputs;
                # unfinished cleanup/native closure still retains the owner slot.
                stamp = _now()
                observations = "post_closure_input_observations" if a["status"] == "closed" else "post_ack_input_observations"
                a.setdefault(observations, []).append({
                    "event_id": event_id, "input_identity": input_identity, "unchanged": same,
                    "evidence_ref": evidence_ref, "recorded_at": stamp,
                    "timestamp_provenance": {"source": "ledger receipt ingestion", "clock_id": "ledger_utc"}})
                a["updated_at"] = stamp
                return a
            if not same and previous is not None:
                a["input_epoch"] = a.get("input_epoch", 0) + 1
                if relevant is not None:
                    relevant.update(valid=False, invalidated_at=_now(), invalidation_ref=evidence_ref)
                if verification is not None:
                    verification.update(valid=False, invalidated_at=_now(), invalidation_ref=evidence_ref)
                a["review"] = None
                if "acceptance" in a:
                    a["acceptance"] = None
                a["materialization"] = None
                self._refresh_best(a)
                workflow = doc.get("trial", {}).get("workflow")
                state = workflow["assignments"].get(assignment_id) if workflow else None
                if state and state.get("current_delivery_id") and a["publication"] is None:
                    state["correction"] = dict(action_id=event_id, delivery_id=state["current_delivery_id"],
                        changed_input_identity=input_identity,
                        findings=[dict(criterion="relevant_inputs", path="",
                                       reason="Observed relevant inputs changed; retained verification no longer applies",
                                       evidence_ref=evidence_ref)])
                    materialization = state.get("materialization")
                    if materialization is not None:
                        original = workflow["actions"][materialization["action_id"]]
                        original.update(superseded=True, recovery_required=True, invalidated_by=event_id)
                        state["target_recovery"] = original["effect_id"]
                        state["materialization"] = None
                    self._workflow_event(workflow, assignment_id, "inputs_changed", event_id,
                                         input_identity=input_identity, evidence_ref=evidence_ref)
                if a["publication"] is None or not a["publication"].get("commit"):
                    a["status"] = "verifying"
            a["current_input_identity"] = input_identity
            a["input_observation"] = {"input_identity": input_identity, "unchanged": same,
                                      "evidence_ref": evidence_ref, "observed_at": _now()}
            return a
        return self._mutate(event_id, "check_input_identity", dict(assignment_id=assignment_id,
                            input_identity=input_identity, evidence_ref=evidence_ref), apply)

    @staticmethod
    def _require_existing_receipt(doc, receipt):
        """Recording a pre-existing owner action is not permission to execute it."""
        _fields(receipt, ("observed_at",))
        try:
            observed = datetime.fromisoformat(receipt["observed_at"])
            if observed.utcoffset() is None:
                raise ValueError("A receipt needs a timezone")
        except ValueError as exc:
            raise StateError("Receipt observed_at must be a timezone-aware ISO timestamp") from exc
        history = doc.get("authorization_history", [])
        revision = receipt.get("authorization_revision")
        prior = next((i for i, auth in enumerate(history)
                      if auth["revision"] == revision and auth["mode"] == Mode.RUN.value), None)
        if prior is None or prior + 1 >= len(history):
            raise PolicyError("Existing receipt must identify a completed RUN authorization interval")
        started = datetime.fromisoformat(history[prior]["updated_at"])
        ended = datetime.fromisoformat(history[prior + 1]["updated_at"])
        if not started <= observed < ended:
            raise PolicyError("Publication-only mode cannot record new owner execution as an existing receipt")

    def transition(self, assignment_id: str, status: str, *, event_id: str, details: dict,
                   authorization_revision: int | None = None) -> dict:
        payload = dict(assignment_id=assignment_id, status=status, details=details,
                       authorization_revision=authorization_revision)
        def apply(doc):
            operation = "cleanup" if status == "cleanup" else (
                "publish" if status == "publication_acknowledged" else (
                    "record_receipt" if status in {"publication_wait", "closed"} else "review"))
            if status in {"reconstructing", "verifying"}:
                operation = "reconstruct" if status == "reconstructing" else "verify"
            self._require(doc, operation, authorization_revision)
            a = self._assignment(doc, assignment_id)
            workflow = doc.get("trial", {}).get("workflow")
            if workflow is not None:
                activity = workflow["assignments"].get(assignment_id, {}).get("owner_activity")
                if status not in {"blocked", "reconstructing", "verifying"} or not activity or not activity["busy"]:
                    raise PolicyError("Configured controller progress requires its admitted lifecycle action, not a manual transition")
            old = a["status"]
            if "trial" in doc and status in {
                "reconciling", "publication_wait", "publication_acknowledged", "cleanup", "closed"
            }:
                raise StateError("Trial coordinator and cleanup outcomes require identity-bound receipts")
            edges = {"assigned": {"reconstructing", "verifying", "blocked"},
                     "reconstructing": {"verifying", "blocked"}, "verifying": {"review_wait", "reconstructing", "blocked"},
                     "review_wait": {"reconciling", "verifying", "blocked"},
                     "reconciling": {"publication_wait", "verifying", "blocked"},
                     "publication_wait": {"verifying", "blocked"},
                     "committed": set(), "pushed": {"publication_acknowledged"},
                     "publication_acknowledged": {"cleanup"}, "cleanup": {"closed"},
                     "exhausted": {"review_wait"}, "closed": set()}
            allowed = {a.get("blocked_from", "reconstructing")} if old == "blocked" else edges.get(old, set())
            if status not in allowed:
                raise StateError(f"Invalid lifecycle transition: {old} -> {status}")
            if status == "blocked":
                _fields(details, ("kind",))
                _refs(details.get("evidence_refs"))
                a["blocked_from"] = old
                a["blocker"] = details
            if status == "review_wait":
                if old == "exhausted":
                    selection = details.get("selection", {})
                    if (a["stage"] != Stage.ASTRA.value and "trial" not in doc) or not a["stages"][-1]["exhausted"]:
                        raise StateError("Nonmatching publication requires the authorized final exhausted stage")
                    if selection.get("candidate_id") != a["best_candidate"]["candidate_id"] or selection.get("accepted_credit") != 0:
                        raise StateError("Publish the preserved best candidate with zero accepted credit")
                    _fields(selection, ("fallback_ref", "input_identity"))
                    if selection["input_identity"] != a["best_candidate"]["input_identity"]:
                        raise StateError("Selected source must retain its measured input identity")
                    _refs(selection.get("evidence_refs"))
                    selection = dict(selection, valid=True, stage=a["best_candidate"]["stage"])
                    if selection.get("label") != "nonmatching—attempts exhausted":
                        raise StateError("Exhausted publication must be explicitly labeled nonmatching")
                    a["selection"] = selection
                    a["current_input_identity"] = selection["input_identity"]
                elif a["verification"] is None or not a["verification"]["valid"]:
                    raise StateError("Review requires current measured verification evidence")
            if status == "reconciling":
                review = details.get("review", {})
                _fields(review, ("approved_by", "input_identity"))
                _refs(review.get("evidence_refs"))
                self._publication_binding(review)
                expected = (a["selection"] or a["verification"])["input_identity"]
                if review["input_identity"] != expected:
                    raise StateError("Review does not bind the verified input identity")
                a["review"] = review
            if status == "publication_wait":
                materialization = details.get("materialization", {})
                _fields(materialization, ("owner_id", "input_identity", "patch_identity"))
                _refs(materialization.get("evidence_refs"))
                self._publication_binding(materialization)
                if a["review"] is None or any(materialization[key] != a["review"].get(key)
                                              for key in ("publication_target", "request_digest")):
                    raise StateError("Materialization does not bind the exact reviewed request and publication target")
                if doc["authorization"]["mode"] == Mode.PUBLISH_EXISTING.value:
                    self._require_existing_receipt(doc, materialization)
                if a["review"] is None or materialization["owner_id"] != a["owner_id"] or materialization["input_identity"] != a["review"]["input_identity"]:
                    raise StateError("The reviewed owner must materialize the same verified inputs")
                if a["selection"] is None and (a["verification"] is None or not a["verification"]["valid"] or a["verification"]["input_identity"] != materialization["input_identity"]):
                    raise StateError("Materialization needs current measured verification")
                if a["selection"] is not None and not a["selection"].get("valid", False):
                    raise StateError("Selected nonmatching source requires renewed verification")
                a["materialization"] = materialization
            if status == "publication_acknowledged":
                ack = details.get("acknowledgment", {})
                publication = a["publication"] or {}
                _fields(ack, ("commit", "branch", "patch_identity", "input_identity", "acknowledged_by"))
                if not publication.get("pushed") or any(ack[key] != publication.get(key) for key in ("commit", "branch", "patch_identity", "input_identity")):
                    raise StateError("Source acknowledgment must identify actual successful push and accepted inputs")
                a["publication_acknowledgment"] = ack
            if status == "closed":
                receipt = details.get("cleanup", {})
                _refs(receipt.get("retained_evidence_refs"), "retained_evidence_refs")
                _fields(receipt, ("shared_link_checks_ref", "original_input_checks_ref"))
                if doc["authorization"]["mode"] == Mode.PUBLISH_EXISTING.value:
                    self._require_existing_receipt(doc, receipt)
                if not isinstance(receipt.get("removed_paths"), list) or type(receipt.get("removed_bytes")) is not int or receipt["removed_bytes"] < 0:
                    raise StateError("Cleanup needs exact removed paths and byte count")
                self._idle_session(doc, a["session_id"])
                a["cleanup"] = receipt
                doc["sessions"][a["session_id"]]["active"] = False
            a["status"] = status
            a["history"].append({"from": old, "to": status, "details": details, "event_id": event_id, "at": _now()})
            a["updated_at"] = _now()
            return a
        return self._mutate(event_id, "transition", payload, apply)

    def publication(self, assignment_id: str) -> dict | None:
        return self.assignment(assignment_id)["publication"]

    @staticmethod
    def _publication_binding(record):
        """Validate an explicit target identity, without native process calls."""
        _hex(record.get("request_digest"), 64, "request_digest")
        target = record.get("publication_target")
        if not isinstance(target, dict) or set(target) != {"repository", "remote", "branch"}:
            raise StateError("Publication approval must bind repository, remote and branch")
        _fields(target, ("repository", "remote", "branch"))
        for key in ("repository", "remote"):
            path = Path(target[key])
            if not path.is_absolute():
                raise StateError("Publication target paths must be absolute canonical identities")
        if any(ord(char) < 32 for value in target.values() for char in value):
            raise StateError("Publication target identities cannot contain control characters")
        return target

    @staticmethod
    def _approved_publication(assignment, record):
        materialization, review = assignment["materialization"], assignment["review"]
        if materialization is None or review is None:
            raise StateError("Publication was invalidated or lacks approved owner materialization")
        for key in ("publication_target", "request_digest"):
            if record.get(key) != materialization.get(key) or record.get(key) != review.get(key):
                raise StateError(f"Publication does not bind the exact reviewed {key}")
        for key in ("patch_identity", "input_identity"):
            if record.get(key) != materialization.get(key):
                raise StateError(f"Publication does not bind approved materialization: {key}")
        target = record["publication_target"]
        if record.get("remote") != target["remote"] or record.get("branch") != target["branch"]:
            raise StateError("Publication destination differs from its exact approved target")

    def record_publication(self, assignment_id: str, *, event_id: str, record: dict) -> dict:
        """Persist intent only; actual effects require their own admitted observations."""
        self._publication_binding(record)
        if record.get("commit") is not None or record.get("pushed", False) is not False or any(
            key in record for key in ("local_head", "remote_head", "remote_contains_commit", "push_error", "effect_observed")
        ):
            raise StateError("Publication outcomes must be recorded through an admitted effect")
        def apply(doc):
            self._require(doc, "publish")
            if "trial" in doc:
                raise PolicyError("Trial publication is external observation, not evaluator Git authority")
            a = self._assignment(doc, assignment_id)
            if a["status"] not in {"publication_wait", "committed", "pushed", "publication_acknowledged", "cleanup", "closed"}:
                raise StateError("Publication requires parent review and owner materialization")
            previous = a["publication"] or {}
            merged = previous | record
            for key in ("publication_target", "request_digest", "planned_commit", "base_head", "tree",
                        "request", "patch_identity", "input_identity", "branch", "remote",
                        "commit_message", "commit_timestamp"):
                if previous.get(key) is not None and merged.get(key) != previous[key]:
                    raise StateError(f"Publication identity cannot change: {key}")
            self._approved_publication(a, merged)
            if not isinstance(merged.get("request"), dict) or _digest(merged["request"]) != merged["request_digest"]:
                raise StateError("Durable publication request content does not match its approved digest")
            if merged.get("planned_commit") is not None:
                _hex(merged["planned_commit"], 40, "planned_commit")
            # An intent update cannot erase previously observed outcomes.
            merged["commit"] = previous.get("commit")
            merged["pushed"] = bool(previous.get("pushed"))
            merged["updated_at"] = _now()
            a["publication"] = merged
            a["updated_at"] = _now()
            return merged
        return self._mutate(event_id, "record_publication", dict(assignment_id=assignment_id, record=record), apply)

    def publication_effects(self, assignment_id: str) -> list[dict]:
        """Read admitted effects for observation-only recovery, including while stopped."""
        return list(self.assignment(assignment_id).get("publication_effects", {}).values())

    def admit_publication_effect(self, assignment_id: str, *, effect_id: str, kind: str,
                                 request_digest: str, target: dict, planned_commit: str,
                                 authorization_revision: int, event_id: str) -> dict:
        """Order one update-ref or push against STOP; return before any native call.

        Only the first admission returns execute=True. Recovered or duplicate
        receipts are observations, never permission to replay a mutation. Private
        index/unreferenced-object preparation is outside this ref/push boundary.
        """
        _text(effect_id, "effect_id")
        if kind not in {"commit", "push"}:
            raise StateError("An admission covers exactly one commit ref update or push")
        self._publication_binding({"request_digest": request_digest, "publication_target": target})
        _hex(planned_commit, 40, "planned_commit")
        if type(authorization_revision) is not int:
            raise PolicyError("Publication admission requires an exact authorization revision")
        identity = dict(assignment_id=assignment_id, effect_id=effect_id, kind=kind,
                        request_digest=request_digest, target=target, planned_commit=planned_commit,
                        authorization_revision=authorization_revision)
        def apply(doc):
            a = self._assignment(doc, assignment_id)
            effects = a.setdefault("publication_effects", {})
            existing = effects.get(effect_id)
            if existing is not None:
                if any(existing[key] != value for key, value in identity.items()):
                    raise StateError("An admitted effect identity cannot be replaced")
                return dict(existing, execute=False)
            self._require(doc, "publish", authorization_revision)
            if "trial" in doc:
                raise PolicyError("Trial publication cannot manufacture evaluator Git admissions")
            publication = a["publication"]
            if publication is None:
                raise StateError("A publication effect requires durable immutable intent")
            self._approved_publication(a, publication)
            if (publication["request_digest"] != request_digest or
                publication["publication_target"] != target or publication.get("planned_commit") != planned_commit):
                raise StateError("Effect does not match the approved publication intent")
            if kind == "push" and publication.get("commit") != planned_commit:
                raise StateError("Push admission requires an observed committed ref")
            receipt = dict(identity, admitted_at=_now(), observations=[])
            effects[effect_id] = receipt
            return dict(receipt, execute=True)
        return self._mutate(event_id, "admit_publication_effect", identity, apply,
                            duplicate_result=lambda receipt: dict(receipt, execute=False))

    def observe_publication_effect(self, assignment_id: str, *, effect_id: str,
                                   event_id: str, record: dict) -> dict:
        """Record actual admitted outcomes without authorizing work or changing STOP."""
        _text(effect_id, "effect_id")
        _fields(record, ("observation_ref",))
        if type(record.get("effect_observed")) is not bool:
            raise StateError("Effect observations require a measured boolean outcome")
        def apply(doc):
            a = self._assignment(doc, assignment_id)
            effect = a.get("publication_effects", {}).get(effect_id)
            if effect is None:
                raise StateError("Cannot observe an unadmitted publication effect")
            publication = a["publication"]
            if publication is None or any((
                publication["request_digest"] != effect["request_digest"],
                publication["publication_target"] != effect["target"],
                publication.get("planned_commit") != effect["planned_commit"],
            )):
                raise StateError("Observed effect does not match its immutable intent")
            observed = record["effect_observed"]
            if effect["kind"] == "commit":
                if set(record) != ({"local_head", "effect_observed", "observation_ref"} |
                                   ({"commit"} if observed else set())):
                    raise StateError("Commit observation may only describe its actual local ref outcome")
                _hex(record["local_head"], 40, "local_head")
                if observed and record["commit"] != effect["planned_commit"]:
                    raise StateError("Observed commit differs from the admitted commit")
                if observed:
                    publication["commit"] = record["commit"]
                publication["local_head"] = record["local_head"]
            else:
                if set(record) != {"commit", "pushed", "remote_head", "remote_contains_commit",
                                   "push_error", "effect_observed", "observation_ref"}:
                    raise StateError("Push observation may only describe its actual remote outcome")
                if record["commit"] != effect["planned_commit"]:
                    raise StateError("Observed push differs from the admitted commit")
                if (type(record["pushed"]) is not bool or type(record["remote_contains_commit"]) is not bool
                    or record["pushed"] != record["remote_contains_commit"] or observed != record["remote_contains_commit"]):
                    raise StateError("Current push outcome must match actual remote containment")
                if record["remote_head"] is not None:
                    _hex(record["remote_head"], 40, "remote_head")
                if record["push_error"] is not None and not isinstance(record["push_error"], str):
                    raise StateError("Push error must retain actual diagnostic text or None")
                if record["remote_contains_commit"] and record["remote_head"] is None:
                    raise StateError("A contained commit requires an observed remote head")
                publication.update(remote_head=record["remote_head"],
                                   remote_contains_commit=record["remote_contains_commit"],
                                   push_error=record["push_error"],
                                   pushed=bool(publication.get("pushed") or record["pushed"]))
            stamp = _now()
            effect["observations"].append({"event_id": event_id, "observed_at": stamp, "record": record})
            publication.update(observation_ref=record["observation_ref"], updated_at=stamp)
            if a["status"] in {"publication_wait", "committed", "pushed"}:
                a["status"] = ("pushed" if publication.get("pushed") else
                               "committed" if publication.get("commit") else "publication_wait")
            a["updated_at"] = stamp
            return publication
        return self._mutate(event_id, "observe_publication_effect",
                            dict(assignment_id=assignment_id, effect_id=effect_id, record=record), apply)

    def register_publisher(self, *, owner_id: str, session_id: str, provider: str, model: str,
                           event_id: str, authorization_revision: int) -> dict:
        payload = dict(owner_id=owner_id, session_id=session_id, provider=provider, model=model,
                       authorization_revision=authorization_revision)
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            if "trial" in doc:
                raise PolicyError("The real trial retains the external coordinator, not an evaluator publisher")
            if doc["publisher"] is not None:
                raise StateError("The dedicated publisher is retained across checkpoints")
            session = self._reserve(doc, session_id, owner_id, Stage.SOL.value, provider, model, "publisher")
            doc["publisher"] = {"owner_id": owner_id, "session_id": session_id, "provider": provider,
                                "model": model, "status": "awaiting-parent", "checkpoints": {},
                                "created_at": session["created_at"]}
            return doc["publisher"]
        return self._mutate(event_id, "register_publisher", payload, apply)

    def publisher_checkpoint(self, *, event_id: str, checkpoint_id: str, record: dict) -> dict:
        _text(checkpoint_id, "checkpoint_id")
        _fields(record, ("source_commit", "report_ref", "observation_ref"))
        _hex(record["source_commit"], 40, "source_commit")
        def apply(doc):
            self._require(doc, "publish")
            publisher = doc["publisher"]
            if publisher is None:
                raise StateError("No retained publisher is registered")
            previous = publisher["checkpoints"].get(checkpoint_id)
            if previous is not None and previous != record:
                raise StateError("A committed checkpoint identity cannot be rewritten")
            publisher["checkpoints"][checkpoint_id] = record
            publisher.update(status="awaiting-parent", updated_at=_now())
            return publisher
        return self._mutate(event_id, "publisher_checkpoint", dict(checkpoint_id=checkpoint_id, record=record), apply)

    @staticmethod
    def _trial(doc):
        if "trial" not in doc:
            raise StateError("No explicit real-function trial manifest is registered")
        return doc["trial"]

    @staticmethod
    def _timestamp(value):
        try:
            stamp = datetime.fromisoformat(value)
            if stamp.utcoffset() is None:
                raise ValueError("Missing timezone")
            return stamp
        except (TypeError, ValueError) as exc:
            raise StateError("Observation timestamps must be timezone-aware ISO strings") from exc

    @classmethod
    def _observation(cls, record):
        if not isinstance(record, dict):
            raise StateError("An observed evidence record is required")
        cls._timestamp(record.get("observed_at"))
        _fields(record.get("timestamp_provenance"), ("source", "clock_id"))
        _refs(record.get("evidence_refs"))

    @staticmethod
    def _trial_target(target):
        # Observation only: unlike the fixture publisher, the coordinator may
        # publish to a real remote URL. This grants no filesystem or Git effects.
        _fields(target, ("repository", "remote", "branch"))
        if set(target) != {"repository", "remote", "branch"} or not Path(target["repository"]).is_absolute():
            raise StateError("External publication requires its exact absolute repository and destination")
        if any(ord(c) < 32 for value in target.values() for c in value):
            raise StateError("Publication identities cannot contain control characters")

    @classmethod
    def _trial_manifest(cls, manifest):
        _fields(manifest, ("trial_id", "coordinator_id", "confirmed_by"))
        if manifest["confirmed_by"] != manifest["coordinator_id"] or type(manifest.get("slots")) is not int or manifest["slots"] != 4:
            raise StateError("The coordinator must confirm exactly four Qwen slots")
        _refs(manifest.get("confirmation_refs"))
        _fields(manifest.get("execution"), ("provider", "model", "endpoint", "configuration_ref"))
        cls._trial_target(manifest.get("publication_target"))
        reservations = manifest.get("reservations")
        if not isinstance(reservations, list) or len(reservations) != 8:
            raise StateError("The bounded trial requires exactly eight fixed reservations")
        ids, workspaces = set(), set()
        for reservation, start in zip(reservations, TRIAL_STARTS):
            _fields(reservation, ("assignment_id", "workspace", "recipe_ref"))
            _component(reservation["assignment_id"], "assignment_id")
            expected = dict(module=117, symbol=f"fn_117_{start:X}", start=start, end=start + 8, size=8)
            if reservation.get("function") != expected:
                raise StateError("Reservation differs from the canonical eight-function queue")
            if any(type(reservation["function"][key]) is not int for key in ("module", "start", "end", "size")):
                raise StateError("Reserved function boundaries and original byte counts must be integers")
            workspace = Path(reservation["workspace"])
            if not workspace.is_absolute():
                raise StateError("Every owner needs an absolute isolated workspace identity")
            workspace_key = str(workspace).casefold()
            if reservation["assignment_id"].casefold() in ids or workspace_key in workspaces:
                raise StateError("Assignment and workspace reservations must be unique on the native filesystem")
            ids.add(reservation["assignment_id"].casefold())
            workspaces.add(workspace_key)
            _hex(reservation.get("baseline_commit"), 40, "baseline_commit")
            _hex(reservation.get("instruction_revision"), 40, "instruction_revision")
            _hex(reservation.get("input_identity"), 64, "input_identity")
            paths = reservation.get("owned_paths")
            expected_paths = {f"src/mo_fighter/ft_dedede/ft_dedede_function_{start:x}.cpp",
                              "configure.py", "config/RSBE01_02/rels/ft_dedede/splits.txt"}
            if not isinstance(paths, list) or len(paths) != 3 or set(paths) != expected_paths:
                raise StateError("Owned paths must be the exact target source and two registration insertions")
            cls._validate_trial_history(reservation.get("history"))
            if reservation["history"]["status"] == "recorded":
                raise StateError("Bounded recorded history requires an append-only coordinator resolution")

    @classmethod
    def _validate_trial_history(cls, history):
        if not isinstance(history, dict) or history.get("status") not in {"known", "unknown", "recorded"}:
            raise StateError("History must distinguish known lifetime, bounded recorded and unresolved counts")
        _refs(history.get("evidence_refs"))
        if history["status"] == "unknown":
            return
        if history["status"] == "recorded":
            if (history.get("count_scope") != "attributable_recorded_within_inventory"
                or history.get("lifetime_totals") != "unknown"):
                raise StateError("Bounded recorded counts never establish known lifetime totals")
            inventories = history.get("inventories")
            if not isinstance(inventories, dict) or set(inventories) != {"journal", "workspace"}:
                raise StateError("Recorded-count admission needs both bounded inventory identities")
            for inventory in inventories.values():
                _fields(inventory, ("path", "sha256", "coverage"))
                _hex(inventory["sha256"], 64, "inventory sha256")
                if not Path(inventory["path"]).is_absolute() or inventory.get("complete") is not True:
                    raise StateError("Each inventory must identify completed, explicitly bounded coverage")
            paths = {str(Path(inventory["path"]).resolve()).casefold() for inventory in inventories.values()}
            digests = {inventory["sha256"] for inventory in inventories.values()}
            if len(paths) != 2 or len(digests) != 2:
                raise StateError("Journal and workspace coverage require distinct inventory paths and contents")
        elif (history.get("count_scope") == "attributable_recorded_within_inventory"
              or history.get("lifetime_totals") == "unknown"):
            raise StateError("Recorded-scope uncertainty cannot be relabelled known lifetime history")
        stages = history.get("stages")
        if not isinstance(stages, dict) or set(stages) != {s.value for s in Stage}:
            raise StateError("Admitted history preserves every GLM/Qwen/Sol/Astra stage separately")
        for stage in stages.values():
            if not isinstance(stage, dict):
                raise StateError("Each inherited model stage needs a preserved count/evidence record")
            initial, corrections = stage.get("initial_count"), stage.get("corrections")
            if type(initial) is not int or initial not in {0, 1} or type(corrections) is not int or not 0 <= corrections <= 10:
                raise StateError("Inherited initial/correction counts are bounded measured counts")
            if not initial and corrections:
                raise StateError("Corrections cannot precede an initial measurement")
            _refs(stage.get("evidence_refs"))
            best = stage.get("best_candidate")
            if not initial:
                if best is not None:
                    raise StateError("An unmeasured stage cannot have a best candidate")
                continue
            _fields(best, ("candidate_id", "input_identity", "recipe_ref", "outcome"))
            _fields(best.get("source_ref"), ("path", "sha256"))
            _hex(best["source_ref"]["sha256"], 64, "inherited source sha256")
            _refs(best.get("evidence_refs"))
            if best["outcome"] not in {"matching", "nonmatching", "compile_failed"}:
                raise StateError("Tool failures do not consume inherited corrections")
            quality = best.get("quality")
            if quality is not None and (type(quality) not in {int, float} or not math.isfinite(quality)):
                raise StateError("Inherited quality must be a finite observed score")
            if best.get("measured_at"):
                cls._timestamp(best["measured_at"])

    @staticmethod
    def _resolved_history(trial, assignment_id):
        reservation = next((r for r in trial["manifest"]["reservations"] if r["assignment_id"] == assignment_id), None)
        if reservation is None:
            raise StateError("History resolution requires an exact reserved assignment")
        resolution = trial.get("history_resolutions", {}).get(assignment_id)
        return resolution["history"] if resolution is not None else reservation["history"]

    def trial_history(self, assignment_id: str) -> dict:
        """Read effective inherited history without replacing the frozen manifest."""
        return self._resolved_history(self._trial(self.snapshot()), assignment_id)

    def resolve_trial_history(self, assignment_id: str, *, history: dict, record: dict, event_id: str) -> dict:
        """Append coordinator-confirmed recovery before the owner's first dispatch.

        This observation grants no execution authority. Original reservations,
        lifetime uncertainty and already-established counts remain immutable.
        """
        self._validate_trial_history(history)
        if history["status"] == "unknown":
            raise StateError("A resolution needs complete evidence-backed history within its explicit scope")
        self._observation(record)
        if history["status"] == "recorded":
            _text(record.get("interpretation_ack_ref"), "interpretation_ack_ref")
        elif "interpretation_ack_ref" in record:
            raise StateError("A recorded-scope interpretation ACK does not establish lifetime totals")
        def apply(doc):
            trial = self._trial(doc)
            if (record.get("assignment_id") != assignment_id
                or record.get("manifest_digest") != trial["manifest_digest"]
                or record.get("observed_by") != trial["manifest"]["coordinator_id"]):
                raise StateError("History recovery must bind the exact reservation and confirmed coordinator")
            current = self._resolved_history(trial, assignment_id)
            resolutions = trial.setdefault("history_resolutions", {})
            existing = resolutions.get(assignment_id)
            if existing is not None:
                if existing["history"] == history and existing["record"] == record:
                    return existing
                raise StateError("An established history resolution and its counts cannot be replaced")
            if current["status"] != "unknown":
                raise StateError("Only UNKNOWN history can be resolved; established counts cannot reset")
            assignment = doc["assignments"].get(assignment_id)
            if assignment is not None and (
                any(e["assignment_id"] == assignment_id and e["kind"] == "prompt" for e in trial["effects"].values())
                or any(s["attempts"] or s["candidates"] or s["initial_count"] is not None
                       or s["corrections"] is not None for s in assignment["stages"])
            ):
                raise StateError("History admission cannot reset an already started stage")
            resolution = dict(assignment_id=assignment_id, manifest_digest=trial["manifest_digest"],
                              history=history, record=record, event_id=event_id, recorded_at=_now())
            resolutions[assignment_id] = resolution
            if assignment is not None:
                self._seed_trial_history(assignment, history)
                assignment["history_admission"] = resolution
                assignment["updated_at"] = resolution["recorded_at"]
            return resolution
        return self._mutate(event_id, "resolve_trial_history",
                            dict(assignment_id=assignment_id, history=history, record=record), apply)

    def register_trial(self, *, manifest: dict, event_id: str) -> dict:
        """Persist explicit reservations, not activation or provider permission."""
        self._trial_manifest(manifest)
        def apply(doc):
            if "trial" in doc:
                if doc["trial"]["manifest"] != manifest:
                    raise StateError("The confirmed reservation manifest is immutable")
                return doc["trial"]
            if self.policy.as_dict() != SlotPolicy.real_trial().as_dict():
                raise PolicyError("Real-trial policy must be selected explicitly on a fresh ledger")
            if doc["assignments"] or doc["sessions"] or doc["publisher"]:
                raise StateError("A real trial cannot adopt a fixture ledger or prior sessions")
            trial = dict(manifest=manifest, manifest_digest=_digest(manifest), created_at=_now(),
                         preparation=None, activation=None, initial_claimed=False, claims={}, effects={},
                         eligibility={}, history_resolutions={}, events=[], capacity_history=[])
            doc["trial"] = trial
            return trial
        return self._mutate(event_id, "register_trial", {"manifest": manifest}, apply)

    def prepare_trial(self, *, gates: dict, event_id: str, authorization_revision: int) -> dict:
        """Authorize native child preparation with provider forwarding held closed."""
        _fields(gates, ("manifest_digest", "confirmed_by", "coordinator_ref", "execution_ref", "dashboard_ref"))
        _refs(gates.get("evidence_refs"))
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            trial = self._trial(doc)
            if gates["manifest_digest"] != trial["manifest_digest"] or gates["confirmed_by"] != trial["manifest"]["coordinator_id"]:
                raise StateError("Preparation must bind the exact confirmed reservations")
            previous = trial.get("preparation")
            if previous is not None:
                if previous["gates"] != gates:
                    raise StateError("Preparation evidence is immutable")
                return dict(previous, execute=False)
            trial["preparation"] = dict(gates=gates, authorization_revision=authorization_revision, recorded_at=_now())
            return dict(trial["preparation"], execute=False)
        return self._mutate(event_id, "prepare_trial", dict(gates=gates, authorization_revision=authorization_revision), apply)

    def activate_trial(self, *, gates: dict, event_id: str, authorization_revision: int) -> dict:
        _fields(gates, ("manifest_digest", "confirmed_by", "coordinator_ref", "execution_ref", "dashboard_ref"))
        _refs(gates.get("evidence_refs"))
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            trial = self._trial(doc)
            if gates["manifest_digest"] != trial["manifest_digest"] or gates["confirmed_by"] != trial["manifest"]["coordinator_id"]:
                raise StateError("Activation must bind the exact coordinator-confirmed reservations")
            if any(self._resolved_history(trial, r["assignment_id"])["status"] not in {"known", "recorded"}
                   for r in trial["manifest"]["reservations"][:4]):
                raise StateError("All four initial provider releases require their own admitted histories")
            if trial["activation"] is not None:
                if trial["activation"]["gates"] != gates:
                    raise StateError("Activation evidence is immutable")
                return dict(trial["activation"], execute=False)
            initial = trial["manifest"]["reservations"][:4]
            if trial.get("preparation") is None or not trial["initial_claimed"]:
                raise StateError("Provider activation follows the four-child native preparation")
            for reservation in initial:
                claim = trial["claims"][reservation["assignment_id"]]
                process = doc["processes"].get(claim["process_id"])
                if claim["session_id"] is None or process is None or not process["active"]:
                    raise StateError("Provider activation requires all four actual attached native children")
                self._admitted_trial_history(trial, doc["assignments"][reservation["assignment_id"]])
            trial["activation"] = dict(gates=gates, authorization_revision=authorization_revision, recorded_at=_now())
            return dict(trial["activation"], execute=False)
        return self._mutate(event_id, "activate_trial", dict(gates=gates, authorization_revision=authorization_revision), apply)

    @classmethod
    def _trial_capacity(cls, doc, stamp):
        trial = doc["trial"]
        occupied = {c["slot"]: key for key, c in trial["claims"].items()
                    if doc["assignments"][key]["status"] != "closed"}
        waiting = [r for r in trial["manifest"]["reservations"] if r["assignment_id"] not in trial["claims"]]
        reasons = {}
        for reservation in waiting:
            key = reservation["assignment_id"]
            reason = trial["eligibility"].get(key, {}).get("reason", "eligible")
            if cls._resolved_history(trial, key)["status"] not in {"known", "recorded"}:
                reason = "input_wait"
            reasons[key] = reason
        paused = doc["authorization"]["mode"] != Mode.RUN.value or trial["activation"] is None
        free = 4 - len(occupied)
        eligible = 0 if paused else sum(reason == "eligible" for reason in reasons.values())
        sample = dict(at=stamp, clock_id="ledger_utc", occupied=occupied, free_slots=free,
                      eligible_work=eligible, eligible_idle_slots=min(free, eligible),
                      reason="explicit_pause" if paused else "eligible" if eligible else "no_eligible_work",
                      queued_reasons=reasons, authorization_revision=doc["authorization"]["revision"])
        workflow = trial.get("workflow")
        if workflow is not None:
            sample["workflow"] = {}
            for key in trial["claims"]:
                readiness = cls._workflow_readiness(doc, key)
                sample["workflow"][key] = {name: readiness[name] for name in ("kind", "ready", "reason")}
            sample["model_leases"] = [
                dict(capacity, held=cls._workflow_model_use(doc, capacity["provider"], capacity["model"]))
                for capacity in workflow["config"]["profile"]["total_model_capacities"]]
        trial["capacity_history"].append(sample)

    def set_trial_eligibility(self, assignment_id: str, *, reason: str, record: dict, event_id: str) -> dict:
        if reason not in {"eligible", "explicit_pause", "input_wait", "tool_wait", "parent_wait", "publication_wait"}:
            raise StateError("Unknown queue eligibility reason")
        self._observation(record)
        def apply(doc):
            trial = self._trial(doc)
            if assignment_id not in {r["assignment_id"] for r in trial["manifest"]["reservations"]} or assignment_id in trial["claims"]:
                raise StateError("Eligibility describes an unclaimed reserved function")
            if record.get("observed_by") != trial["manifest"]["coordinator_id"]:
                raise StateError("Only the confirmed coordinator can change reserved-work eligibility")
            trial["eligibility"][assignment_id] = dict(reason=reason, record=record)
            return trial["eligibility"][assignment_id]
        return self._mutate(event_id, "set_trial_eligibility", dict(assignment_id=assignment_id, reason=reason, record=record), apply)

    @classmethod
    def _seed_trial_history(cls, assignment, history):
        """Import preserved counts once; a held UNKNOWN stage has null counters."""
        if any(stage["attempts"] or stage["candidates"] for stage in assignment["stages"]):
            raise StateError("History import cannot replace measured work")
        admitted = history["status"] in {"known", "recorded"}
        for stage in assignment["stages"]:
            name = stage["stage"]
            inherited = history["stages"][name] if admitted else {
                "status": "unknown", "initial_count": None, "corrections": None,
                "evidence_refs": history["evidence_refs"]}
            if name != "qwen":
                stage.update({field: inherited.get(field) for field in ("provider", "model", "owner_id", "session_id")})
            stage.update(initial_count=inherited["initial_count"], corrections=inherited["corrections"],
                         inherited_initial_count=inherited["initial_count"], inherited_corrections=inherited["corrections"],
                         inherited_candidate_ids=[], inherited_history=inherited)
            best = inherited.get("best_candidate")
            if best is not None:
                best = dict(best, stage=name,
                            input_epoch=assignment["input_epoch"] if best["input_identity"] == assignment["current_input_identity"] else -1,
                            measured_at=best.get("measured_at") or "", quality=best.get("quality"), inherited=True)
                stage["candidates"][best["candidate_id"]] = best
                stage["attempts"].append(best)
                stage["inherited_candidate_ids"].append(best["candidate_id"])
        assignment["admitted_history"] = history if admitted else None
        cls._refresh_best(assignment)

    @classmethod
    def _admitted_trial_history(cls, trial, assignment):
        history = cls._resolved_history(trial, assignment["assignment_id"])
        if (history["status"] not in {"known", "recorded"}
            or assignment.get("admitted_history", assignment["identity"].get("history")) != history):
            raise StateError("Provider dispatch requires this owner's resolved and imported history")
        for stage in assignment["stages"]:
            inherited = history["stages"][stage["stage"]]
            if (stage.get("inherited_initial_count") != inherited["initial_count"]
                or stage.get("inherited_corrections") != inherited["corrections"]):
                raise StateError("Provider dispatch must preserve every admitted inherited count")
        return history

    def _claim_trial(self, doc, claim):
        trial = self._trial(doc)
        if trial.get("preparation") is None:
            raise PolicyError("The real trial has not passed explicit native preparation gates")
        _fields(claim, ("assignment_id", "owner_id", "root_session_id"))
        if set(claim) != {"assignment_id", "owner_id", "root_session_id", "slot"} or type(claim["slot"]) is not int or not 0 <= claim["slot"] < 4:
            raise StateError("A claim binds one of four slots to one fresh native root and owner")
        key = claim["assignment_id"]
        reservation = next((r for r in trial["manifest"]["reservations"] if r["assignment_id"] == key), None)
        if reservation is None or key in trial["claims"]:
            raise StateError("Only an unclaimed fixed reservation can be dispatched")
        history = self._resolved_history(trial, key)
        if trial["eligibility"].get(key, {}).get("reason", "eligible") != "eligible":
            raise StateError("Reserved work is not currently eligible")
        for other_key, other in trial["claims"].items():
            if other["owner_id"] == claim["owner_id"] or other["root_session_id"] == claim["root_session_id"]:
                raise StateError("Each assignment requires a fresh owner and actual native root")
            if other["slot"] == claim["slot"] and doc["assignments"][other_key]["status"] != "closed":
                raise StateError("A slot is retained through native exit, publication ACK and cleanup")
        execution = trial["manifest"]["execution"]
        session = dict(stage="qwen", provider=execution["provider"], model=execution["model"],
                       owner_id=claim["owner_id"], session_id=None)
        stages = [self._stage_record(dict(session, stage=name)) for name in ("glm", "sol", "astra", "qwen")]
        assignment = dict(assignment_id=key, identity=dict(claim=claim, reservation=reservation, execution=execution,
                                                          history=history,
                                                          history_resolution=trial.get("history_resolutions", {}).get(key)),
                          function=reservation["function"], function_key=_digest(reservation["function"]),
                          owner_id=claim["owner_id"], session_id=None, stage="qwen", stages=stages,
                          status="assigned", history=[], best_candidate=None, historical_best_candidate=None,
                          input_epoch=0, current_input_identity=reservation["input_identity"], verification=None,
                          review=None, materialization=None, publication=None, publication_acknowledgment=None,
                          publication_effects={}, cleanup=None, selection=None, accepted_credit=0,
                          external_receipts={}, created_at=_now(), updated_at=_now())
        self._seed_trial_history(assignment, history)
        assignment["history_admission"] = trial.get("history_resolutions", {}).get(key)
        doc["assignments"][key] = assignment
        trial["claims"][key] = dict(claim, claimed_at=_now(), process_id=None, session_id=None)
        if trial.get("workflow") is not None:
            self._workflow_assignment(trial["workflow"], key)
        return assignment

    def claim_trial_initial(self, *, claims: list[dict], event_id: str, authorization_revision: int) -> dict:
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            trial = self._trial(doc)
            initial = {r["assignment_id"] for r in trial["manifest"]["reservations"][:4]}
            if trial["initial_claimed"] or len(claims) != 4 or {c.get("assignment_id") for c in claims} != initial:
                raise StateError("The four initial reservations must be admitted together exactly once")
            result = [self._claim_trial(doc, claim) for claim in claims]
            trial["initial_claimed"] = True
            return {"assignments": result, "execute": False}
        return self._mutate(event_id, "claim_trial_initial", dict(claims=claims, authorization_revision=authorization_revision), apply)

    def claim_trial_refill(self, *, claim: dict, event_id: str, authorization_revision: int) -> dict:
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            if not self._trial(doc)["initial_claimed"]:
                raise StateError("No single-owner preliminary real-function stage is authorized")
            return self._claim_trial(doc, claim)
        return self._mutate(event_id, "claim_trial_refill", dict(claim=claim, authorization_revision=authorization_revision), apply)

    def attach_trial_session(self, assignment_id: str, *, session_id: str, root_session_id: str,
                             process_id: str, journal_ref: str, registry_ref: str, event_id: str) -> dict:
        """Attach observed native identities, including an already-in-flight launch."""
        _fields(locals(), ("session_id", "root_session_id", "process_id", "journal_ref", "registry_ref"))
        payload = dict(assignment_id=assignment_id, session_id=session_id, root_session_id=root_session_id,
                       process_id=process_id, journal_ref=journal_ref, registry_ref=registry_ref)
        def apply(doc):
            trial = self._trial(doc)
            a = self._assignment(doc, assignment_id)
            claim = trial["claims"][assignment_id]
            old = claim.get("native_attachment")
            if old is not None:
                if old != payload:
                    raise StateError("Native owner attachment is immutable")
                return old
            if claim["root_session_id"] != root_session_id or session_id == root_session_id:
                raise StateError("Observed child ancestry must identify the claimed independent root")
            if session_id in {c["root_session_id"] for c in trial["claims"].values()}:
                raise StateError("A native child cannot adopt another assignment's root identity")
            if not any(e["assignment_id"] == assignment_id and e["kind"] == "launch" for e in trial["effects"].values()):
                raise StateError("Native attachment needs a durable admitted trial launch")
            process = doc["processes"].get(process_id)
            if process is None or process["session_id"] is not None or any(c["process_id"] == process_id for c in trial["claims"].values()):
                raise StateError("Each assignment needs its own registered native process, never an adopted one")
            execution = trial["manifest"]["execution"]
            session = self._reserve(doc, session_id, a["owner_id"], "qwen", execution["provider"], execution["model"], "reconstruction")
            session["assignment_id"] = assignment_id
            process["session_id"] = session_id
            claim.update(session_id=session_id, process_id=process_id, native_attachment=payload)
            a["session_id"] = session_id
            a["stages"][-1]["session_id"] = session_id
            return payload
        return self._mutate(event_id, "attach_trial_session", payload, apply)

    def admit_trial_effect(self, assignment_id: str, *, effect_id: str, kind: str,
                           event_id: str, authorization_revision: int) -> dict:
        if kind not in {"launch", "prompt"}:
            raise StateError("Only the bounded native launch and initial prompt can be admitted")
        _text(effect_id, "effect_id")
        identity = dict(assignment_id=assignment_id, effect_id=effect_id, kind=kind,
                        authorization_revision=authorization_revision)
        def apply(doc):
            if kind == "prompt" and assignment_id in {
                r["assignment_id"] for r in self._trial(doc)["manifest"]["reservations"][:4]
            }:
                raise PolicyError("The four initial provider prompts require one atomic admission")
            return self._admit_trial_effect(doc, identity)
        return self._mutate(event_id, "admit_trial_effect", identity, apply,
                            duplicate_result=lambda result: dict(result, execute=False))

    def _admit_trial_effect(self, doc, identity):
        trial = self._trial(doc)
        assignment_id, effect_id, kind = (identity[key] for key in ("assignment_id", "effect_id", "kind"))
        old = trial["effects"].get(effect_id)
        if old is not None:
            if any(old[k] != v for k, v in identity.items()):
                raise StateError("Effect identity cannot be replaced")
            return dict(old, execute=False)
        self._require(doc, "launch" if kind == "launch" else "reconstruct", identity["authorization_revision"])
        a = self._assignment(doc, assignment_id)
        gate = trial.get("preparation") if kind == "launch" else trial["activation"]
        if gate is None or a["status"] == "closed":
            raise StateError("The effect requires its explicit preparation/provider gate and retained owner")
        if kind == "prompt":
            history = self._admitted_trial_history(trial, a)
            if not any(e["assignment_id"] == assignment_id and e["kind"] == "launch" for e in trial["effects"].values()):
                raise StateError("A prompt requires its admitted native launch")
            claim = trial["claims"][assignment_id]
            process = doc["processes"].get(claim["process_id"])
            if claim["session_id"] is None or process is None or not process["active"]:
                raise StateError("Provider forwarding requires the actual live native owner")
            workflow = trial.get("workflow")
            if workflow is not None:
                if workflow["target_prepared"] is None:
                    raise PolicyError("Provider work waits for the actual independently owned publication target")
                if self._workflow_capacity_reason(doc, "prompt") is not None:
                    raise PolicyError("Aggregate approved model capacity includes every active reconstruction/review request")
        if any(e["assignment_id"] == assignment_id and e["kind"] == kind for e in trial["effects"].values()):
            raise StateError("Uncertain provider effects cannot be retried with a new identity")
        effect = dict(identity, admitted_at=_now(), observations=[])
        if kind == "prompt":
            resolution = trial.get("history_resolutions", {}).get(assignment_id)
            effect.update(history_digest=_digest(history),
                          history_resolution_event_id=resolution["event_id"] if resolution is not None else None)
            if trial.get("workflow") is not None:
                self._workflow_assignment(trial["workflow"], assignment_id)["owner_activity"] = dict(
                    effect_id=effect_id, busy=True, admitted_at=effect["admitted_at"])
        trial["effects"][effect_id] = effect
        return dict(effect, execute=True)

    def admit_trial_prompts(self, *, effect_ids: dict, event_id: str, authorization_revision: int) -> dict:
        """Admit the initial four forwards together; never a single-agent stage."""
        def historic(result):
            return dict(result, execute=False, effects=[dict(effect, execute=False) for effect in result["effects"]])
        def apply(doc):
            trial = self._trial(doc)
            initial = {r["assignment_id"] for r in trial["manifest"]["reservations"][:4]}
            if not isinstance(effect_ids, dict) or set(effect_ids) != initial or len(set(effect_ids.values())) != 4:
                raise StateError("Initial forwarding binds exactly four distinct reserved effects")
            for effect_id in effect_ids.values():
                _text(effect_id, "effect_id")
            effects = [self._admit_trial_effect(doc, dict(assignment_id=key, effect_id=value, kind="prompt",
                                                        authorization_revision=authorization_revision))
                       for key, value in effect_ids.items()]
            if len({effect["execute"] for effect in effects}) != 1:
                raise StateError("Initial forwarding cannot mix replayed and newly admitted effects")
            return {"effects": effects, "execute": effects[0]["execute"]}
        return self._mutate(event_id, "admit_trial_prompts",
                            dict(effect_ids=effect_ids, authorization_revision=authorization_revision), apply,
                            duplicate_result=historic)

    def observe_trial_effect(self, *, effect_id: str, record: dict, event_id: str) -> dict:
        self._observation(record)
        if type(record.get("effect_observed")) is not bool:
            raise StateError("Effect outcomes must be explicit observed booleans")
        def apply(doc):
            effect = self._trial(doc)["effects"].get(effect_id)
            if effect is None:
                raise StateError("No such admitted trial effect")
            if any(item["record"] == record for item in effect["observations"]):
                return dict(effect, execute=False)
            if self._timestamp(record["observed_at"]) < self._timestamp(effect["admitted_at"]):
                raise StateError("Effect outcome predates its admission")
            effect["observations"].append(dict(event_id=event_id, record=record, recorded_at=_now()))
            return dict(effect, execute=False)
        return self._mutate(event_id, "observe_trial_effect", dict(effect_id=effect_id, record=record), apply)

    def trial_event(self, assignment_id: str | None, *, kind: str, record: dict, event_id: str) -> dict:
        """Observations never accept work, release capacity, or authorize effects."""
        return self._trial_event(assignment_id, kind=kind, record=record, event_id=event_id, native=False)

    def observe_trial_interval(self, assignment_id: str, *, record: dict, event_id: str) -> dict:
        """Host-only native collector entry; never exposed by owner envelope routing."""
        return self._trial_event(assignment_id, kind="interval", record=record, event_id=event_id, native=True)

    def _trial_event(self, assignment_id, *, kind, record, event_id, native):
        self._observation(record)
        if kind not in {"phase", "interval", "intervention", "violation", "recovery"}:
            raise StateError("Unknown trial measurement kind")
        if kind in {"phase", "interval"}:
            if assignment_id is None or record.get("phase") not in TRIAL_PHASES:
                raise StateError("An assignment measurement must name a supported observed interval")
            if kind == "interval" and self._timestamp(record.get("started_at")) > self._timestamp(record["observed_at"]):
                raise StateError("An observed interval cannot end before it starts")
        else:
            _text(record.get("description"), "description")
        def apply(doc):
            trial = self._trial(doc)
            if native:
                self._workflow(doc)
            if kind == "interval" and trial.get("workflow") is not None:
                if not native:
                    raise StateError("Owner or coordinator envelopes cannot manufacture native execution intervals")
                assignment = self._assignment(doc, assignment_id)
                reviewer = trial["workflow"]["assignments"].get(assignment_id, {}).get("reviewer") or {}
                actors = {(assignment["owner_id"], assignment["session_id"]),
                          (reviewer.get("owner_id"), reviewer.get("session_id"))}
                actor = (record.get("native_actor_id"), record.get("native_session_id"))
                event = record.get("native_event")
                evidence = record.get("native_evidence")
                _fields(evidence, ("path", "sha256"))
                _hex(evidence["sha256"], 64, "native event evidence SHA-256")
                if (actor not in actors or None in actor or not isinstance(event, dict)
                    or event.get("kind") != "native_interval" or event.get("owner") != actor[0]
                    or event.get("session_id") != actor[1]
                    or any(event.get(key) != record[key] for key in ("phase", "started_at", "observed_at"))
                    or evidence["path"] not in record["evidence_refs"]):
                    raise StateError("Timing must retain the actual host-collected native event and artifact identity")
            if assignment_id is not None:
                a = self._assignment(doc, assignment_id)
                if record.get("owner_id") != a["owner_id"]:
                    raise StateError("Measured assignment events must retain the same owner")
            duplicate = next((e for e in trial["events"] if e["assignment_id"] == assignment_id
                              and e["kind"] == kind and e["record"] == record), None)
            if duplicate is not None:
                return duplicate
            if kind == "phase":
                previous = next((e for e in reversed(trial["events"])
                                 if e["kind"] == "phase" and e["assignment_id"] == assignment_id), None)
                if previous and previous["record"]["timestamp_provenance"]["clock_id"] == record["timestamp_provenance"]["clock_id"] and self._timestamp(previous["record"]["observed_at"]) > self._timestamp(record["observed_at"]):
                    raise StateError("Phase observations cannot move backwards within one clock")
            event = dict(assignment_id=assignment_id, kind=kind, record=record, event_id=event_id,
                         recorded_at=_now(), measurement_origin="native_host" if native else "reported")
            trial["events"].append(event)
            return event
        return self._mutate(event_id, "observe_trial_interval" if native else "trial_event",
                            dict(assignment_id=assignment_id, kind=kind, record=record), apply)

    @classmethod
    def _trial_receipt_interval(cls, doc, receipt, *, owner_action=False):
        """Validate historical ordering, not permission to perform a new effect.

        A coordinator receipt can describe an effect started before STOP whose
        outcome arrived afterward. No evaluator Git admission is fabricated.
        """
        started = cls._timestamp(receipt.get("started_at"))
        observed = cls._timestamp(receipt["observed_at"])
        if started > observed:
            raise StateError("An observed outcome cannot precede its actual start")
        history = doc["authorization_history"]
        revision = receipt.get("authorization_revision")
        index = next((i for i, auth in enumerate(history) if auth["revision"] == revision), None)
        modes = {Mode.RUN.value} if owner_action else {Mode.RUN.value, Mode.PUBLISH_EXISTING.value}
        if index is None or history[index]["mode"] not in modes:
            raise PolicyError("Receipt must identify its actual authorized execution interval")
        lower = cls._timestamp(history[index]["updated_at"])
        upper = cls._timestamp(history[index + 1]["updated_at"]) if index + 1 < len(history) else None
        if started < lower or (upper is not None and started >= upper):
            raise PolicyError("Receipt cannot invent new execution after STOP or in publication-only mode")

    @classmethod
    def _receipt_follows(cls, receipt, predecessor, *, field="started_at"):
        """Causality needs observed completion on the same identified clock."""
        return (predecessor is not None
                and receipt["timestamp_provenance"]["clock_id"] == predecessor["timestamp_provenance"]["clock_id"]
                and cls._timestamp(receipt[field]) >= cls._timestamp(predecessor["observed_at"]))
    def observe_trial_receipt(self, assignment_id: str, *, kind: str, receipt: dict, event_id: str) -> dict:
        """Ingest coordinator/owner evidence; never run Git or grant its authority."""
        if kind not in {"review", "materialization", "commit", "push", "ack", "cleanup", "closed"}:
            raise StateError("Unknown external lifecycle receipt")
        self._observation(receipt)
        _fields(receipt, ("assignment_id", "owner_id", "session_id", "manifest_digest", "observed_by",
                          "request_digest", "patch_identity", "input_identity"))
        for name in ("request_digest", "patch_identity", "input_identity", "manifest_digest"):
            _hex(receipt[name], 64, name)
        self._trial_target(receipt.get("publication_target"))
        def apply(doc):
            if self._trial(doc).get("workflow") is not None:
                raise PolicyError("Controller lifecycle receipts require an admitted workflow action")
            return self._apply_trial_receipt(doc, assignment_id, kind, receipt, event_id)
        return self._mutate(event_id, "observe_trial_receipt", dict(assignment_id=assignment_id, kind=kind, receipt=receipt), apply)

    def _apply_trial_receipt(self, doc, assignment_id, kind, receipt, event_id):
        trial = self._trial(doc)
        a = self._assignment(doc, assignment_id)
        claim = trial["claims"][assignment_id]
        if (receipt["assignment_id"] != assignment_id or receipt["owner_id"] != a["owner_id"]
            or receipt["session_id"] != a["session_id"] or receipt["manifest_digest"] != trial["manifest_digest"]
            or receipt["publication_target"] != trial["manifest"]["publication_target"]):
            raise StateError("Receipt does not bind the exact reserved assignment and native owner")
        observer = a["owner_id"] if kind in {"materialization", "cleanup"} else trial["manifest"]["coordinator_id"]
        if receipt["observed_by"] != observer:
            raise StateError("Receipt is not from the retained owner or confirmed coordinator")
        receipts = a["external_receipts"].setdefault(kind, [])
        if any(item["receipt"] == receipt for item in receipts):
            return {"kind": kind, "receipt": receipt, "duplicate": True, "execute": False}
        recovered = receipt.get("recovered_from_remote") is True or receipt.get("recovered_from_git") is True
        if recovered:
            action = trial.get("workflow", {}).get("actions", {}).get(receipt.get("controller_action_id"))
            if action is None or action["assignment_id"] != assignment_id or action["kind"] != kind or kind not in {"commit", "push"}:
                raise StateError("Publication recovery must observe an existing exact controller Git admission")
            _refs(receipt.get("command_refs"), "owned read-only recovery command references")
        if kind in {"ack", "closed"} or recovered:
            # Acceptance/exit observations are not Git or owner execution.
            # They may be collected after STOP without reopening its gate.
            if self._timestamp(receipt.get("started_at")) > self._timestamp(receipt["observed_at"]):
                raise StateError("Observation cannot precede the start of its collection")
            if not any(auth["revision"] == receipt.get("authorization_revision") for auth in doc["authorization_history"]):
                raise StateError("Observation must retain a known authorization revision")
        else:
            self._trial_receipt_interval(doc, receipt, owner_action=kind in {"materialization", "cleanup"})
        binding = ("assignment_id", "owner_id", "session_id", "manifest_digest",
                   "request_digest", "publication_target", "patch_identity", "input_identity")
        def matches(other):
            return other is not None and all(receipt[key] == other.get(key) for key in binding)
        verification = a["verification"]
        current_verified = (verification is not None and verification["valid"]
                            and verification["input_identity"] == receipt["input_identity"]
                            and verification["evidence"]["scope"] == "reconstruction"
                            and verification["evidence"].get("binary_hash_count") == 127)
        if kind == "review":
            if a["status"] != "review_wait":
                raise StateError("Coordinator review requires a review-ready owner")
            selected = a["selection"]
            if not current_verified and not (selected and selected.get("valid") and selected["input_identity"] == receipt["input_identity"]):
                raise StateError("Model success is not verification or a canonical exhausted selection")
            request = receipt.get("request")
            if not isinstance(request, dict) or _digest(request) != receipt["request_digest"]:
                raise StateError("Review must preserve the exact publication request content")
            if any(request.get(key) != receipt[key] for key in binding if key != "request_digest"):
                raise StateError("Reviewed request must include the complete assignment/patch/input/destination binding")
            a["review"] = receipt
            a["status"] = "reconciling"
        elif kind == "materialization":
            approval = a.get("acceptance") if trial.get("workflow") is not None else a["review"]
            expected_status = "verified" if approval and approval.get("mode") == "mechanical" else "reconciling"
            if a["status"] != expected_status or not matches(approval) or not current_verified:
                raise StateError("Owner materialization requires exact criterion acceptance and current verification")
            if not self._receipt_follows(receipt, approval):
                raise StateError("Materialization cannot start before criterion acceptance on a comparable clock")
            _fields(receipt, ("grant_ref", "preservation_ref", "private_index_ref"))
            a["materialization"] = receipt
            a["status"] = "publication_wait"
        elif kind in {"commit", "push"}:
            # Retain actual in-flight outcomes after invalidation or STOP.
            materialized = any(matches(item["receipt"]) and self._receipt_follows(receipt, item["receipt"])
                               for item in a["external_receipts"].get("materialization", []))
            if not materialized:
                raise StateError("External publication must follow reviewed materialization on a comparable clock")
            _hex(receipt.get("commit"), 40, "commit")
            publication = a["publication"]
            if publication is not None and (not matches(publication) or publication["commit"] != receipt["commit"]):
                raise StateError("External committed identity cannot be replaced")
            if kind == "commit":
                if receipt.get("local_head") != receipt["commit"]:
                    raise StateError("Commit receipt must observe the actual committed ref")
                if publication is None:
                    a["publication"] = dict(receipt, external_coordinator=True, pushed=False,
                                            remote=receipt["publication_target"]["remote"],
                                            branch=receipt["publication_target"]["branch"])
                if a["status"] == "publication_wait":
                    a["status"] = "committed"
            else:
                if publication is None:
                    raise StateError("Push receipt requires its actual observed commit")
                if not self._receipt_follows(receipt, publication):
                    raise StateError("Push cannot start before the actual committed ref on a comparable clock")
                valid_exit = receipt.get("push_exit_code") is None if recovered else type(receipt.get("push_exit_code")) is int
                if not valid_exit or type(receipt.get("pushed")) is not bool or type(receipt.get("remote_contains_commit")) is not bool:
                    raise StateError("Push observations retain native exit or explicitly recovered remote outcome")
                _hex(receipt.get("remote_head"), 40, "remote_head")
                successful = (recovered or receipt["push_exit_code"] == 0) and receipt["remote_contains_commit"]
                if receipt["pushed"] != successful:
                    raise StateError("Successful publication requires native success or bound recovered remote containment")
                publication["pushed"] = publication["pushed"] or successful
                publication["push_receipt"] = receipt
                if successful and a["status"] in {"publication_wait", "committed"}:
                    a["status"] = "pushed"
        elif kind == "ack":
            publication = a["publication"]
            if not matches(publication) or not publication.get("pushed") or receipt.get("commit") != publication["commit"]:
                raise StateError("ACK requires the exact actual successful source commit/push")
            if a["status"] != "pushed" or not current_verified or not matches(a["materialization"]):
                raise StateError("Invalidated or unverified inputs cannot earn acceptance")
            pushed_before_ack = any(
                matches(item["receipt"]) and item["receipt"].get("pushed") is True
                and item["receipt"].get("commit") == receipt.get("commit")
                and self._receipt_follows(receipt, item["receipt"])
                for item in a["external_receipts"].get("push", []))
            if not pushed_before_ack:
                raise StateError("ACK must follow an actual successful push on a comparable clock")
            if type(receipt.get("accepted_matching")) is not bool:
                raise StateError("ACK must explicitly distinguish accepted matching work from exhausted work")
            candidate = next((s["candidates"].get(verification["candidate_id"]) for s in reversed(a["stages"])
                              if verification["candidate_id"] in s["candidates"]), None)
            if receipt["accepted_matching"] and (a["selection"] is not None or candidate is None or candidate["outcome"] != "matching"):
                raise StateError("Only a verified matching candidate can earn trial-only credit")
            if not receipt["accepted_matching"] and a["selection"] is None:
                raise StateError("Unaccepted matching work remains unfinished, not accepted or exhausted")
            a["publication_acknowledgment"] = receipt
            a["status"] = "publication_acknowledged"
        elif kind == "cleanup":
            ack = a["publication_acknowledgment"]
            if a["status"] != "publication_acknowledged" or not matches(ack) or receipt.get("commit") != ack.get("commit"):
                raise StateError("Cleanup must follow the exact canonical publication ACK")
            if not self._receipt_follows(receipt, ack):
                raise StateError("Cleanup cannot start before canonical ACK on a comparable clock")
            _refs(receipt.get("retained_evidence_refs"), "retained_evidence_refs")
            _fields(receipt, ("deletion_manifest_ref", "shared_link_checks_ref", "original_input_checks_ref",
                              "retained_evidence_checks_ref"))
            if receipt.get("tracked_files_preserved") is not True:
                raise StateError("Canonical cleanup preserves tracked source/configuration and Git metadata")
            removed = receipt.get("removed_paths")
            if not isinstance(removed, list) or type(receipt.get("removed_bytes")) is not int or receipt["removed_bytes"] < 0:
                raise StateError("Cleanup requires exact removed paths and content byte totals")
            seen, total = set(), 0
            workspace = Path(a["identity"]["reservation"]["workspace"])
            for item in removed:
                _fields(item, ("path",))
                path = Path(item["path"])
                if not path.is_absolute() or not path.is_relative_to(workspace) or ".." in path.parts:
                    raise StateError("Cleanup entries must stay inside the retained owner workspace")
                if item["path"].casefold() in seen or type(item.get("bytes")) is not int or item["bytes"] < 0:
                    raise StateError("Cleanup paths must be unique with exact nonnegative content bytes")
                seen.add(item["path"].casefold())
                total += item["bytes"]
            if total != receipt["removed_bytes"]:
                raise StateError("Cleanup removed byte total differs from its file manifest")
            a["cleanup"] = receipt
            a["status"] = "cleanup"
        else:
            cleanup = a["cleanup"]
            if a["status"] != "cleanup" or not matches(cleanup) or receipt.get("commit") != cleanup.get("commit"):
                raise StateError("Closure requires canonical owner cleanup and publication ACK")
            if not self._receipt_follows(receipt, cleanup, field="observed_at"):
                raise StateError("Closure cannot precede canonical cleanup on a comparable clock")
            process = doc["processes"].get(claim["process_id"])
            if process is None or process["exit_proof"] is None or process["active"]:
                raise StateError("Closure requires actual identity-verified native exit, not task success")
            if receipt.get("process_id") != process["process_id"] or receipt.get("exit_evidence_ref") != process["exit_proof"]["evidence_ref"]:
                raise StateError("Closure must bind its own exact native exit receipt")
            if receipt["timestamp_provenance"]["clock_id"] == "ledger_utc" and self._timestamp(receipt["observed_at"]) < self._timestamp(process["exit_proof"]["verified_at"]):
                raise StateError("Closure observation cannot precede the actual native exit observation")
            self._idle_session(doc, a["session_id"])
            doc["sessions"][a["session_id"]]["active"] = False
            a["status"] = "closed"
            claim["closed_at"] = _now()
        entry = dict(kind=kind, receipt=receipt, event_id=event_id, recorded_at=_now(), execute=False)
        receipts.append(entry)
        a["history"].append(dict(event_id=event_id, external_receipt=kind, at=entry["recorded_at"], to=a["status"]))
        a["updated_at"] = entry["recorded_at"]
        return entry
    def admit_trial_message(self, assignment_id: str, *, message_id: str, request: dict,
                            event_id: str, authorization_revision: int) -> dict:
        """Admit one exact coordinator lifecycle message to the retained owner."""
        _text(message_id, "message_id")
        _fields(request, ("message", "owner_id", "session_id", "manifest_digest",
                          "coordinator_id", "purpose", "receipt_ref"))
        phases = {"review": {"review_wait"}, "reconciliation": {"reconciling", "verifying", "review_wait"},
                  "publication_ack": {"publication_acknowledged"}, "cleanup": {"publication_acknowledged", "cleanup"}}
        if request["purpose"] not in phases:
            raise PolicyError("A retained-owner message cannot start a new reconstruction stage or retry")
        identity = dict(assignment_id=assignment_id, message_id=message_id, request=request,
                        authorization_revision=authorization_revision)
        def apply(doc):
            trial = self._trial(doc)
            if trial.get("workflow") is not None:
                raise PolicyError("Routine owner instructions require an admitted same-owner controller action")
            messages = trial.setdefault("messages", {})
            old = messages.get(message_id)
            if old is not None:
                if any(old[key] != value for key, value in identity.items()):
                    raise StateError("An admitted message identity cannot change")
                return dict(old, execute=False)
            self._require(doc, "reconstruct", authorization_revision)
            if trial["activation"] is None:
                raise PolicyError("Retained-owner messages cannot bypass provider activation")
            a = self._assignment(doc, assignment_id)
            if (request["owner_id"] != a["owner_id"] or request["session_id"] != a["session_id"]
                or request["manifest_digest"] != trial["manifest_digest"]
                or request["coordinator_id"] != trial["manifest"]["coordinator_id"]):
                raise StateError("Lifecycle message must bind the exact retained native owner and coordinator")
            if a["status"] not in phases[request["purpose"]]:
                raise StateError("Coordinator message is outside its actual lifecycle phase")
            process = doc["processes"].get(trial["claims"][assignment_id]["process_id"])
            if process is None or not process["active"]:
                raise StateError("A lifecycle message cannot revive an exited native owner")
            digest = _digest(request)
            if any(message["request_digest"] == digest for message in messages.values()):
                raise StateError("Changing message IDs cannot replay an identical provider effect")
            admitted = dict(identity, request_digest=digest, admitted_at=_now(), observations=[])
            messages[message_id] = admitted
            return dict(admitted, execute=True)
        return self._mutate(event_id, "admit_trial_message", identity, apply,
                            duplicate_result=lambda result: dict(result, execute=False))

    def observe_trial_message(self, *, message_id: str, record: dict, event_id: str) -> dict:
        """Retain a real in-flight send result even when STOP won afterward."""
        self._observation(record)
        if type(record.get("effect_observed")) is not bool:
            raise StateError("Message outcomes must retain an explicit observed boolean")
        def apply(doc):
            message = self._trial(doc).get("messages", {}).get(message_id)
            if message is None:
                raise StateError("Cannot observe an unadmitted owner message")
            if any(item["record"] == record for item in message["observations"]):
                return dict(message, execute=False)
            if self._timestamp(record["observed_at"]) < self._timestamp(message["admitted_at"]):
                raise StateError("Message outcome predates admission")
            message["observations"].append(dict(event_id=event_id, record=record, recorded_at=_now()))
            return dict(message, execute=False)
        return self._mutate(event_id, "observe_trial_message", dict(message_id=message_id, record=record), apply)

    def _trial_execution_observation(self, doc, assignment, observation, revision):
        trial = self._trial(doc)
        self._observation(observation)
        self._trial_receipt_interval(doc, observation, owner_action=True)
        if (observation.get("authorization_revision") != revision
            or observation.get("assignment_id") != assignment["assignment_id"]
            or observation.get("owner_id") != assignment["owner_id"]
            or observation.get("session_id") != assignment["session_id"]
            or observation.get("manifest_digest") != trial["manifest_digest"]):
            raise StateError("In-flight work evidence must bind its exact retained native owner and authorization")
        prompt = next((e for e in trial["effects"].values()
                       if e["assignment_id"] == assignment["assignment_id"] and e["kind"] == "prompt"), None)
        if prompt is None or self._timestamp(observation["started_at"]) < self._timestamp(prompt["admitted_at"]):
            raise StateError("An in-flight measurement must follow its actual admitted provider work")
        if trial.get("workflow") is not None:
            effect_id = observation.get("dispatch_effect_id")
            effect = trial["effects"].get(effect_id) or trial["workflow"]["actions"].get(effect_id)
            if (effect is None or effect["kind"] not in {"prompt", "reconcile"}
                or effect["assignment_id"] != assignment["assignment_id"]
                or effect["authorization_revision"] != revision
                or self._timestamp(observation["started_at"]) < self._timestamp(effect["admitted_at"])):
                raise StateError("Measurement must retain its exact original or same-owner correction dispatch")
            if effect.get("binding", {}).get("repair_only") is True:
                raise StateError("Delivery-only repair cannot measure candidates or consume reconstruction attempts")
            state = self._workflow_assignment(trial["workflow"], assignment["assignment_id"])
            completion = state["owner_completions"].get(effect_id)
            if completion and self._timestamp(observation["started_at"]) > self._timestamp(completion["record"]["observed_at"]):
                raise StateError("A parked owner cannot start new work under a completed request's authority")

    def trial_delivery(self, event_id: str) -> dict:
        """Read the admitted role/content binding, never trust a role in a file."""
        delivery = self._trial(self.snapshot()).get("deliveries", {}).get(event_id)
        if delivery is None:
            raise StateError("No durable admission exists for this trial delivery")
        return delivery

    def _validate_trial_delivery(self, doc, role, envelope):
        trial = self._trial(doc)
        _text(role, "delivery role")
        if role not in {"coordinator", "owner"}:
            raise StateError("A delivery requires its actual coordinator or owner producer role")
        if not isinstance(envelope, dict) or not isinstance(envelope.get("payload"), dict):
            raise StateError("A delivery requires the exact bounded envelope and payload")
        identifier = _component(envelope.get("event_id"), "event_id")
        if "_" in identifier:
            raise StateError("Delivery event identities use letters, digits and hyphens only")
        if envelope.get("manifest_digest") != trial["manifest_digest"]:
            raise StateError("Delivery belongs to another immutable reservation manifest")
        operation = _text(envelope.get("operation"), "operation")
        if (trial.get("workflow") is not None and operation == "event"
            and envelope["payload"].get("kind") == "interval"):
            raise StateError("Native intervals cannot originate in a submitted owner/coordinator envelope")
        operations = {"activate", "prepare-refill", "activate-refill",
                      "message", "receipt", "close", "event", "eligibility",
                      "attempt", "verification", "transition", "exhaust", "inputs", "history"}
        if operation not in operations:
            raise StateError("Unsupported bounded delivery operation")
        key = envelope.get("assignment_id")
        if key is not None:
            _component(key, "assignment_id")
        if key is not None and key not in {r["assignment_id"] for r in trial["manifest"]["reservations"]}:
            raise StateError("Delivery does not identify a reserved assignment")
        authority = trial["manifest"]["coordinator_id"]
        if role == "owner":
            assignment = self._assignment(doc, key)
            if (not assignment["session_id"] or envelope.get("owner_id") != assignment["owner_id"]
                or envelope.get("session_id") != assignment["session_id"]):
                raise StateError("Owner delivery must bind its retained actual native session")
            authority = assignment["owner_id"]
            if operation not in {"attempt", "verification", "exhaust", "inputs", "event", "transition", "receipt"}:
                raise StateError("An owner delivery cannot acquire coordinator execution or publication authority")
            data = envelope["payload"]
            if operation == "receipt" and data.get("kind") not in {"materialization", "cleanup"}:
                raise StateError("Owner receipts cannot approve review, commit, push, ACK or closure")
            if operation == "transition" and data.get("status") not in {"verifying", "review_wait", "blocked"}:
                raise StateError("Owner transitions cannot replace coordinator publication authority")
            if operation == "event":
                record = data.get("record")
                if not isinstance(record, dict) or record.get("owner_id") != authority:
                    raise StateError("Owner event delivery must preserve its native owner identity")
        effect = operation in {"activate", "prepare-refill",
                               "activate-refill", "message", "close"}
        return authority, effect

    def admit_trial_delivery(self, *, event_id: str, role: str, envelope: dict,
                             content_sha256: str, authorization_revision: int | None = None) -> dict:
        """Bind an actual CLI producer and exact bytes before inbox publication.

        The trusted producer hashes the bytes it publishes. This ledger boundary
        prevents bare/replaced inbox files gaining authority; it is not an OS
        security sandbox against an attacker who can rewrite the SQLite ledger.
        Admission does not permit provider work: native effects retain their own
        authorization/once-only admissions after delivery consumption.
        """
        _component(event_id, "event_id")
        _hex(content_sha256, 64, "content_sha256")
        if not isinstance(envelope, dict) or envelope.get("event_id") != event_id:
            raise StateError("Delivery event identity must equal the exact envelope identity")
        identity = dict(event_id=event_id, role=role, envelope=envelope, content_sha256=content_sha256,
                        envelope_digest=_digest(envelope))
        def apply(doc):
            authority, effect = self._validate_trial_delivery(doc, role, envelope)
            trial = self._trial(doc)
            deliveries = trial.setdefault("deliveries", {})
            if any(key != event_id and key.casefold() == event_id.casefold() for key in deliveries):
                raise StateError("Delivery event identities cannot alias the same native inbox path")
            existing = deliveries.get(event_id)
            if existing is not None:
                if any(existing[key] != value for key, value in identity.items()):
                    raise StateError("A delivery's producer role and exact content cannot be rebound")
                return dict(existing, execute=False)
            if effect:
                if type(authorization_revision) is not int:
                    raise PolicyError("Execution delivery requires its exact captured RUN revision")
                self._require(doc, "launch", authorization_revision)
            delivery = dict(identity, authority_id=authority, effect=effect,
                            authorization_revision=authorization_revision,
                            admitted_at=_now(), consumed_at=None)
            deliveries[event_id] = delivery
            return dict(delivery, execute=False)
        # Namespaces avoid colliding with the later handler's original event ID.
        # A repeated identical admission remains historic even after STOP.
        return self._mutate("trial-delivery-admit:" + event_id, "admit_trial_delivery", identity, apply,
                            duplicate_result=lambda result: dict(result, execute=False))

    def consume_trial_delivery(self, *, event_id: str, role: str, envelope: dict, content_sha256: str) -> dict:
        """Claim once using parsed content and the hash from the same file read.

        ``execute`` permits first routing, not bypassing effect authorization.
        Repeated consumption returns ``replay_observation`` only for ledger-only
        operations. The consumer must retry those with the original handler
        event ID and historical/captured revision: their existing transactions
        either finish the missing observation or return its committed receipt.
        An uncertain provider/native effect is never replayable.
        Handler authorization/evidence checks still apply: an uncommitted
        authorization-sensitive transition can remain rejected after STOP.
        """
        _component(event_id, "event_id")
        _hex(content_sha256, 64, "content_sha256")
        if not isinstance(envelope, dict) or envelope.get("event_id") != event_id:
            raise StateError("Consumed bytes must retain the exact admitted delivery identity")
        identity = dict(event_id=event_id, role=role, envelope=envelope, content_sha256=content_sha256,
                        envelope_digest=_digest(envelope))
        def apply(doc):
            delivery = self._trial(doc).get("deliveries", {}).get(event_id)
            if delivery is None:
                raise StateError("A bare inbox file has no admitted producer authority")
            if any(delivery[key] != value for key, value in identity.items()):
                raise StateError("Current inbox role/content/bytes differ from their durable admission")
            if delivery["consumed_at"] is not None:
                return dict(delivery, execute=False, replay_observation=not delivery["effect"])
            self._validate_trial_delivery(doc, role, envelope)
            if delivery["effect"]:
                self._require(doc, "launch", delivery["authorization_revision"])
            delivery["consumed_at"] = _now()
            return dict(delivery, execute=True, replay_observation=False)
        return self._mutate("trial-delivery-consume:" + event_id, "consume_trial_delivery", identity, apply,
                            duplicate_result=lambda result: dict(result, execute=False,
                                                                 replay_observation=not result["effect"]))

    @staticmethod
    def _workflow(doc):
        workflow = Ledger._trial(doc).get("workflow")
        if workflow is None:
            raise StateError("Automatic lifecycle requires its explicitly configured controller")
        return workflow

    @staticmethod
    def _workflow_assignment(workflow, assignment_id):
        return workflow["assignments"].setdefault(assignment_id, {
            "deliveries": {}, "current_delivery_id": None, "owner_completions": {},
            "owner_activity": None, "reviewer": None, "validation": None, "review": None,
            "materialization": None, "units": {}, "cleanup": None,
        })

    def configure_trial_workflow(self, *, config: dict, event_id: str, authorization_revision: int) -> dict:
        """Freeze controller authority, not permission to execute an unadmitted job."""
        _fields(config, ("run_id", "controller_id"))
        if config.get("schema") != 1:
            raise StateError("Unsupported controller workflow schema")
        if config.get("acceptance_policy") != workflow_acceptance_policy():
            raise StateError("Workflow must bind the exact approved deterministic-first acceptance policy")
        validate_workflow_profile(config.get("profile"))
        target = config.get("publication_target")
        _fields(target, ("repository", "git_dir", "remote", "branch", "baseline"))
        self._trial_target({key: target[key] for key in ("repository", "remote", "branch")})
        _hex(target["baseline"], 40, "publication baseline")
        if Path(target["git_dir"]) != Path(target["repository"]) / ".git":
            raise StateError("Controller publication requires its own repository .git directory")
        _fields(target.get("author"), ("name", "email"))
        ownership = target.get("ownership_evidence")
        _fields(ownership, ("path", "sha256"))
        _hex(ownership["sha256"], 64, "target ownership evidence")
        if not Path(ownership["path"]).is_absolute():
            raise StateError("Target ownership evidence needs an exact absolute retained path")
        if "credential_helper" in target:
            helper = target["credential_helper"]
            _fields(helper, ("path", "sha256"))
            if set(helper) != {"path", "sha256"} or not Path(helper["path"]).is_absolute():
                raise StateError("An optional credential helper needs its exact approved executable identity")
            _hex(helper["sha256"], 64, "credential helper SHA-256")
        verification = config.get("verification")
        if not isinstance(verification, dict):
            raise StateError("Fixed per-assignment verification recipes are required")
        for specification in verification.values():
            if not isinstance(specification, dict) or not isinstance(specification.get("recipe"), dict) or not specification["recipe"]:
                raise StateError("Verification requires the complete approved input recipe")
            judgments = specification.get("judgment_requirements", {})
            if not isinstance(judgments, dict) or not set(judgments).issubset(config["acceptance_policy"]["judgment_criteria"]):
                raise StateError("Explicit source judgment may scope only existing judgment criteria")
            for reason in judgments.values():
                _text(reason, "specific unresolved source judgment")
            command = _text(specification["recipe"].get("native_compile_command"), "fixed native compiler command")
            if "\0" in command or "\n" in command or "\r" in command:
                raise StateError("The approved native compiler command must be one exact Ninja command line")
            commands = specification.get("commands")
            names = {"compile", "object_compare", "data_relocations", "source_link", "progress"}
            if (not isinstance(commands, list) or len(commands) != len(names)
                or any(not isinstance(command, dict) for command in commands)
                or {command.get("name") for command in commands} != names):
                raise StateError("Every fixed mechanical criterion needs its own approved command")
            for command in commands:
                argv, codes = command.get("argv"), command.get("accepted_exit_codes")
                if (not isinstance(argv, list) or not argv
                    or any(not isinstance(arg, str) or not arg or "\0" in arg for arg in argv)
                    or not isinstance(codes, list) or not codes or any(type(code) is not int for code in codes)
                    or type(command.get("timeout_seconds")) is not int or command["timeout_seconds"] < 1):
                    raise StateError("Commands need exact argv, permitted native results and finite deadlines")
            binaries = specification.get("binary_hashes")
            if not isinstance(binaries, dict) or len(binaries) != 127:
                raise StateError("Fixed verification must identify all 127 original native binaries")
            if len({relative_path(path).casefold() for path in binaries}) != 127:
                raise StateError("Fixed verification requires 127 distinct case-insensitive native binary paths")
            for path, digest in binaries.items():
                relative_path(path)
                _hex(digest, 40, "original binary SHA-1")
            selection = specification.get("selection")
            _fields(selection, ("source", "object", "link_output", "ninja", "fallback_object"))
            for key in ("source", "object", "link_output", "fallback_object"):
                relative_path(selection[key])
            if not Path(selection["ninja"]).is_absolute():
                raise StateError("Source selection uses the explicitly pinned native Ninja tool")
            workspace_inputs = specification.get("workspace_inputs")
            if not isinstance(workspace_inputs, list):
                raise StateError("Workspace setup inputs must be an explicit bounded list")
            destinations = set()
            for item in workspace_inputs:
                _fields(item, ("source", "destination"))
                relative_path(item["destination"])
                identity = item.get("identity", {})
                _hex(identity.get("sha256"), 64, "workspace input SHA-256")
                if (not Path(item["source"]).is_absolute() or type(identity.get("size")) is not int
                    or identity["size"] < 0 or item["destination"].casefold() in destinations):
                    raise StateError("Setup inputs need distinct owned destinations and exact readonly source identities")
                destinations.add(item["destination"].casefold())
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            trial = self._trial(doc)
            existing = trial.get("workflow")
            if existing is not None:
                if existing["config"] != config:
                    raise StateError("The approved workflow/profile/target cannot change in place")
                return existing
            if trial["claims"] or trial.get("preparation") is not None:
                raise StateError("Controller ownership must be configured before native preparation")
            if config["controller_id"] != trial["manifest"]["coordinator_id"]:
                raise StateError("Controller identity must match the confirmed trial authority")
            canonical_target = {key: target[key] for key in ("repository", "remote", "branch")}
            if canonical_target != trial["manifest"]["publication_target"]:
                raise StateError("Workflow authority cannot substitute the reserved publication target")
            reconstruction = config["profile"]["reconstruction"]
            execution = trial["manifest"]["execution"]
            if (reconstruction["stage"] != "qwen" or reconstruction["capacity"] != trial["manifest"]["slots"]
                or any(reconstruction.get(key) != execution[key] for key in ("provider", "model", "endpoint"))):
                raise StateError("Reconstruction profile must preserve the four approved native owners")
            if workflow_model_capacity(config["profile"], execution["provider"], execution["model"]) != 4:
                raise StateError("The approved reconstruction model has exactly four aggregate inference slots")
            _text(config["profile"]["review"].get("endpoint"), "review endpoint")
            reservations = trial["manifest"]["reservations"]
            if set(verification) != {row["assignment_id"] for row in reservations}:
                raise StateError("Fixed verification must cover exactly the eight reserved assignments")
            for row in reservations:
                if verification[row["assignment_id"]]["selection"]["source"] != self._trial_source(row):
                    raise StateError("Source-selection evidence must identify the exact reserved C++ source")
            workflow = dict(config=config, config_digest=_digest(config), configured_at=_now(),
                            actions={}, assignments={}, target_lease=None, target_prepared=None, target_head=None, events=[])
            trial["workflow"] = workflow
            return workflow
        return self._mutate(event_id, "configure_trial_workflow",
                            dict(config=config, authorization_revision=authorization_revision), apply)

    @staticmethod
    def _workflow_event(workflow, assignment_id, kind, event_id, **details):
        entry = dict(assignment_id=assignment_id, kind=kind, event_id=event_id, recorded_at=_now(), **details)
        workflow["events"].append(entry)
        return entry

    @staticmethod
    def _workflow_native_event(record, *, kind, owner_id, session_id, root_session_id, request_id=None):
        native = record.get("native_event")
        if not isinstance(native, dict) or any(native.get(key) != value for key, value in (
            ("kind", kind), ("registry_id", owner_id), ("session_id", session_id), ("root_session_id", root_session_id)
        )):
            raise StateError("A native observation must bind its actual retained registry/session/root ancestry")
        if request_id is not None and (native.get("request_id") != request_id or native.get("will_continue") is not False):
            raise StateError("Inference remains reserved until the exact native request actually finishes")
        return native

    def _observe_workflow_owner(self, doc, assignment_id, record, event_id):
        self._observation(record)
        workflow, trial = self._workflow(doc), self._trial(doc)
        assignment = self._assignment(doc, assignment_id)
        state = self._workflow_assignment(workflow, assignment_id)
        effect_id = _text(record.get("dispatch_effect_id"), "dispatch_effect_id")
        effect = trial["effects"].get(effect_id) or workflow["actions"].get(effect_id)
        if (effect is None or effect["assignment_id"] != assignment_id
            or effect["kind"] not in {"prompt", "reconcile", "cleanup"}):
            raise StateError("Native completion requires its admitted original same-owner request")
        if record.get("authorization_revision") != effect["authorization_revision"]:
            raise StateError("Native completion must retain the original request authorization")
        self._trial_receipt_interval(doc, record, owner_action=True)
        if self._timestamp(record["started_at"]) < self._timestamp(effect["admitted_at"]):
            raise StateError("Native work cannot precede its durable request admission")
        self._workflow_native_event(record, kind="owner_turn_end", owner_id=assignment["owner_id"],
            session_id=assignment["session_id"], root_session_id=trial["claims"][assignment_id]["root_session_id"],
            request_id=effect_id)
        previous = state["owner_completions"].get(effect_id)
        if previous is not None:
            if previous["record"]["native_event"] != record["native_event"]:
                raise StateError("A completed native request cannot acquire a different outcome identity")
            return previous
        activity = state["owner_activity"]
        if activity is None or activity["effect_id"] != effect_id:
            raise StateError("A completion cannot release another request's inference reservation")
        activity["busy"] = False
        activity["completed_at"] = record["observed_at"]
        entry = dict(record=record, event_id=event_id, recorded_at=_now())
        state["owner_completions"][effect_id] = entry
        self._workflow_event(workflow, assignment_id, "owner_turn_completed", event_id,
                             effect_id=effect_id, observation=record)
        return entry

    def observe_trial_owner(self, assignment_id: str, *, record: dict, event_id: str) -> dict:
        """Observe actual native completion even if the owner's delivery is invalid."""
        return self._mutate(event_id, "observe_trial_owner", dict(assignment_id=assignment_id, record=record),
                            lambda doc: self._observe_workflow_owner(doc, assignment_id, record, event_id))

    def record_trial_delivery_error(self, assignment_id: str, *, error: dict, record: dict, event_id: str) -> dict:
        """Retain invalid delivery evidence and offer only the original owner a repair."""
        _fields(error, ("reason", "original_path"))
        def apply(doc):
            workflow = self._workflow(doc)
            assignment = self._assignment(doc, assignment_id)
            state = self._workflow_assignment(workflow, assignment_id)
            self._observe_workflow_owner(doc, assignment_id, record, event_id)
            dispatch = record["dispatch_effect_id"]
            failures = state.setdefault("delivery_errors", {})
            previous = failures.get(dispatch)
            if previous is not None:
                if previous["error"] != error:
                    raise StateError("One completed dispatch cannot acquire contradictory capture failures")
                return previous
            activity = state["owner_activity"]
            if activity is None or activity["effect_id"] != dispatch or activity["busy"]:
                raise StateError("Delivery repair must bind the latest actually completed owner turn")
            if assignment["publication"] is not None or assignment["status"] == "closed":
                raise StateError("A capture failure cannot reopen published work")
            if any(entry["record"]["dispatch_effect_id"] == dispatch for entry in state["deliveries"].values()):
                raise StateError("A successful capture cannot become a delivery failure")
            workspace = Path(assignment["identity"]["reservation"]["workspace"])
            original = Path(error["original_path"])
            if not original.is_absolute() or not original.is_relative_to(workspace) or ".." in original.parts:
                raise StateError("Invalid delivery evidence must identify the exact retained owner's inbox")
            archive = error.get("archive")
            if archive is not None:
                _fields(archive, ("path", "sha256"))
                _hex(archive["sha256"], 64, "invalid delivery archive SHA-256")
                if (Path(archive["path"]) != self.path.parent / "deliveries" / "raw" / (archive["sha256"] + ".json")
                    or type(archive.get("size")) is not int or archive["size"] < 0):
                    raise StateError("Malformed bytes must remain in the immutable run-owned archive")
            fingerprint = _digest(dict(path=str(original).casefold(), archive=archive,
                                       input_identity=assignment["current_input_identity"]))
            repeated = any(item["fingerprint"] == fingerprint for item in failures.values())
            entry = dict(error=error, record=record, event_id=event_id, fingerprint=fingerprint,
                         repeated=repeated, recorded_at=_now())
            failures[dispatch] = entry
            state["correction"] = dict(action_id=event_id, delivery_id=state["current_delivery_id"],
                delivery_error=entry, findings=[dict(criterion="ownership", path="", reason=error["reason"])])
            self._workflow_event(workflow, assignment_id, "delivery_invalid", event_id,
                                 dispatch_effect_id=dispatch, observation=entry)
            return entry
        return self._mutate(event_id, "record_trial_delivery_error",
                            dict(assignment_id=assignment_id, error=error, record=record), apply)

    def record_trial_delivery(self, assignment_id: str, *, delivery: dict, record: dict, event_id: str) -> dict:
        """Capture concrete native-owned delivery data, not an approval or transition."""
        try:
            parsed = WorkerDelivery.from_dict(delivery)
        except (DeliveryError, InputError, TypeError) as exc:
            raise StateError(str(exc)) from exc
        self._observation(record)
        _fields(record, ("path", "original_path", "sha256", "dispatch_effect_id"))
        _hex(record["sha256"], 64, "captured delivery SHA-256")
        if type(record.get("size")) is not int or record["size"] < 0:
            raise StateError("Captured delivery needs its actual byte count")
        def apply(doc):
            trial, workflow = self._trial(doc), self._workflow(doc)
            assignment = self._assignment(doc, assignment_id)
            state = self._workflow_assignment(workflow, assignment_id)
            expected = dict(assignment_id=assignment_id, owner_id=assignment["owner_id"],
                            session_id=assignment["session_id"], manifest_digest=trial["manifest_digest"])
            if any(delivery[key] != value for key, value in expected.items()):
                raise StateError("Delivery cannot replace its exact reserved function/owner/session")
            workspace = Path(assignment["identity"]["reservation"]["workspace"])
            captured, original = Path(record["path"]), Path(record["original_path"])
            archive = self.path.parent / "deliveries" / "raw"
            if (not captured.is_absolute() or captured.parent != archive
                or captured.name != record["sha256"] + ".json" or ".." in captured.parts):
                raise StateError("Captured delivery must bind its immutable run-owned raw-byte archive")
            if not original.is_absolute() or not original.is_relative_to(workspace) or ".." in original.parts:
                raise StateError("The original inbox must remain inside its retained owner's workspace")
            self._observe_workflow_owner(doc, assignment_id, record, event_id)
            if record["dispatch_effect_id"] in state.get("delivery_errors", {}):
                raise StateError("A failed dispatch cannot acquire later delivery bytes; complete a same-owner repair first")
            existing = state["deliveries"].get(parsed.delivery_id)
            if existing is not None:
                return existing
            activity = state["owner_activity"]
            if activity is None or activity["effect_id"] != record["dispatch_effect_id"] or activity["busy"]:
                raise StateError("New delivery bytes require the current retained owner's actual completed request")
            if assignment["status"] == "closed" or assignment.get("publication") is not None:
                raise StateError("New delivery content cannot replace historical published work")
            if any(action["assignment_id"] == assignment_id and action["kind"] in {
                "materialize", "commit", "push", "acknowledge", "cleanup", "close"
            } and action["status"] in {"admitted", "succeeded", "uncertain"}
                   and not action.get("restored_by") for action in workflow["actions"].values()):
                raise StateError("An admitted publication generation cannot be replaced by another delivery")
            if any(item["record"]["dispatch_effect_id"] == record["dispatch_effect_id"] for item in state["deliveries"].values()):
                raise StateError("One completed owner request cannot produce conflicting delivery contents")
            owned = assignment["identity"]["reservation"]["owned_paths"]
            source = self._trial_source(assignment["identity"]["reservation"])
            if not set(delivery["changes"]).issubset(owned) or source not in delivery["changes"]:
                raise StateError("Delivery must include its reserved function and no foreign source/registration paths")
            specification = workflow["config"]["verification"][assignment_id]
            if delivery["inputs"]["recipe"] != specification["recipe"]:
                raise StateError("The owner cannot redefine the fixed verification recipe")
            candidates = [stage["candidates"][delivery["candidate_id"]] for stage in assignment["stages"]
                          if delivery["candidate_id"] in stage["candidates"]]
            if len(candidates) != 1:
                raise StateError("A delivery must identify exactly one preserved measured candidate")
            candidate = candidates[0]
            if (candidate["input_identity"] != delivery["inputs"]["identity"]
                or candidate["input_identity"] != assignment["current_input_identity"]
                or candidate["source_ref"]["sha256"] != delivery["changes"][source]["raw"]["sha256"]):
                raise StateError("Delivery source and relevant inputs must match the actual measured candidate")
            if candidate["outcome"] != "matching" and (
                not assignment["stages"][-1]["exhausted"] or candidate != assignment["best_candidate"]
            ):
                raise StateError("Unmatched delivery requires the actual exhausted stage and preserved best source")
            entry = dict(delivery=delivery, delivery_id=parsed.delivery_id, source_identity=parsed.source_identity,
                         input_identity=delivery["inputs"]["identity"], record=record, event_id=event_id, recorded_at=_now())
            state["deliveries"][parsed.delivery_id] = entry
            state["current_delivery_id"] = parsed.delivery_id
            state["materialization"], state["units"] = None, {}
            state["correction"] = None
            assignment["review"], assignment["materialization"] = None, None
            assignment["acceptance"] = None
            if assignment["verification"] is not None:
                assignment["verification"].update(valid=False, invalidated_at=_now(), invalidation_ref=record["path"])
            assignment["status"] = "verifying"
            self._workflow_event(workflow, assignment_id, "delivery_ready", event_id,
                                 delivery_id=parsed.delivery_id, source_identity=parsed.source_identity,
                                 input_identity=entry["input_identity"])
            return entry
        return self._mutate(event_id, "record_trial_delivery",
                            dict(assignment_id=assignment_id, delivery=delivery, record=record), apply)

    @staticmethod
    def _workflow_binding(doc, assignment_id):
        trial = Ledger._trial(doc)
        workflow = Ledger._workflow(doc)
        config = workflow["config"]
        target = {key: config["publication_target"][key] for key in ("repository", "remote", "branch")}
        common = dict(run_id=config["run_id"], manifest_digest=trial["manifest_digest"], publication_target=target,
                      policy_identity=_digest(config["acceptance_policy"]))
        if assignment_id is None:
            return dict(common, baseline=config["publication_target"]["baseline"])
        assignment = Ledger._assignment(doc, assignment_id)
        state = workflow["assignments"].get(assignment_id, {})
        delivery = state.get("deliveries", {}).get(state.get("current_delivery_id"))
        return dict(common, assignment_id=assignment_id, owner_id=assignment["owner_id"],
                    session_id=assignment["session_id"],
                    delivery_id=delivery["delivery_id"] if delivery else None,
                    input_identity=delivery["input_identity"] if delivery else None,
                    source_identity=delivery["source_identity"] if delivery else None)

    @staticmethod
    def _workflow_model_use(doc, provider, model):
        workflow = Ledger._workflow(doc)
        reconstruction = workflow["config"]["profile"]["reconstruction"]
        used = sum(bool(state.get("owner_activity", {}).get("busy")) for state in workflow["assignments"].values()
                   if state.get("owner_activity") is not None) if (
                       reconstruction["provider"], reconstruction["model"]) == (provider, model) else 0
        review = workflow["config"]["profile"]["review"]
        if (review["provider"], review["model"]) == (provider, model):
            used += sum(action["kind"] == "review" and action["status"] in {"admitted", "uncertain"}
                        and not action.get("inference_complete") for action in workflow["actions"].values())
        return used

    @classmethod
    def _workflow_capacity_reason(cls, doc, kind):
        workflow = cls._workflow(doc)
        profile = workflow["config"]["profile"]
        if kind not in {"review", "reconcile", "cleanup", "prompt"}:
            return None
        role = profile["review" if kind == "review" else "reconstruction"]
        if cls._workflow_model_use(doc, role["provider"], role["model"]) >= workflow_model_capacity(
            profile, role["provider"], role["model"]
        ):
            return "model_capacity"
        if kind == "review" and sum(action["kind"] == "review" and action["status"] in {"admitted", "uncertain"}
                                    and not action.get("inference_complete")
                                    for action in workflow["actions"].values()) >= role["capacity"]:
            return "review_capacity"
        return None

    @staticmethod
    def _workflow_reviewer_id(workflow, assignment_id):
        return "Review" + _digest({"run_id": workflow["config"]["run_id"], "assignment_id": assignment_id})[:24]

    @classmethod
    def _workflow_readiness(cls, doc, assignment_id):
        workflow = cls._workflow(doc)
        if assignment_id is None:
            binding = cls._workflow_binding(doc, None)
            if workflow["target_prepared"] is not None:
                return dict(assignment_id=None, ready=False, reason="target_prepared", kind=None, binding=binding)
            kind = "prepare_target"
        else:
            assignment = cls._assignment(doc, assignment_id)
            state = workflow["assignments"].get(assignment_id, {})
            if assignment["status"] == "closed":
                return dict(assignment_id=assignment_id, ready=False, reason="closed", kind=None)
            correction = state.get("correction")
            if not state.get("current_delivery_id") and not correction:
                activity = state.get("owner_activity")
                reason = "owner_execution" if activity and activity["busy"] else "delivery_wait"
                if activity is None:
                    prompt = cls._workflow_prompt_readiness(doc, assignment_id)
                    reason = "provider_dispatch_wait" if prompt["ready"] else prompt["reason"]
                if doc["authorization"]["mode"] != Mode.RUN.value or cls._trial(doc)["activation"] is None:
                    reason = "explicit_pause"
                return dict(assignment_id=assignment_id, ready=False, reason=reason, kind=None)
            binding = cls._workflow_binding(doc, assignment_id)
            delivery_id = binding["delivery_id"]
            if correction and correction.get("delivery_error", {}).get("repeated"):
                return dict(assignment_id=assignment_id, ready=False, reason="unchanged_invalid_delivery",
                            kind=None, binding=binding)
            validation, review = state.get("validation"), state.get("review")
            correction = state.get("correction")
            if state.get("target_recovery") is not None:
                kind = "restore_materialization"
                recovery = workflow["actions"][state["target_recovery"]]
                binding.update(recovery_action_id=recovery["effect_id"], target_head=recovery["binding"]["target_head"])
            elif correction is not None and correction["delivery_id"] == delivery_id:
                kind = "reconcile"
            elif assignment["current_input_identity"] != binding["input_identity"]:
                return dict(assignment_id=assignment_id, ready=False, kind=None, reason="input_wait")
            elif not validation or validation["delivery_id"] != delivery_id:
                kind = "validate_delivery"
            elif validation["result"]["coverage"]["unresolved"] and (
                not review or review["delivery_id"] != delivery_id or review["decision"] != "approve"
            ):
                kind = "reconcile" if review and review["delivery_id"] == delivery_id and review["decision"] == "reject" else (
                    "prepare_review" if state.get("reviewer") is None else "review")
            elif state.get("materialization") is None:
                kind = "materialize"
            else:
                delivery = state["deliveries"][delivery_id]["delivery"]
                pending = next((index for index in range(len(delivery["logical_units"]))
                                if not state["units"].get(f"unit-{index}", {}).get("pushed")), None)
                if pending is not None:
                    unit = f"unit-{pending}"
                    binding["logical_unit_id"] = unit
                    kind = "push" if state["units"].get(unit, {}).get("commit") else "commit"
                elif assignment["publication_acknowledgment"] is None:
                    kind = "acknowledge"
                elif assignment["cleanup"] is None:
                    kind = "cleanup"
                else:
                    kind = "close"
            if validation and validation["delivery_id"] == delivery_id and kind != "validate_delivery":
                binding.update(validation_action_id=validation["action_id"],
                               coverage_identity=validation["coverage_identity"])
            if kind in {"prepare_review", "review"}:
                binding["unresolved_criteria"] = validation["result"]["coverage"]["unresolved"]
            if kind == "prepare_review":
                claim = cls._trial(doc)["claims"][assignment_id]
                binding.update(reviewer_id=cls._workflow_reviewer_id(workflow, assignment_id),
                               root_session_id=claim["root_session_id"])
            elif kind == "review":
                binding["reviewer"] = state["reviewer"]
            elif kind == "reconcile":
                binding["correction_action_id"] = correction["action_id"] if correction else review["action_id"]
                if correction and correction.get("delivery_error") is not None:
                    binding["repair_only"] = True
                if correction and correction.get("changed_input_identity") is not None:
                    binding["changed_input_identity"] = correction["changed_input_identity"]
            elif kind == "push":
                binding["commit"] = state["units"][binding["logical_unit_id"]]["commit"]
            elif kind == "materialize":
                binding["target_head"] = workflow["target_head"]
        matches = [action for action in workflow["actions"].values()
                   if action["assignment_id"] == assignment_id and action["kind"] == kind and action["binding"] == binding]
        if matches:
            action = matches[-1]
            reasons = {"admitted": "action_in_flight", "uncertain": "uncertain_effect",
                       "failed": "tool_wait", "rejected": "rejected_action", "succeeded": "owner_delivery_wait"}
            return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding,
                        reason=reasons[action["status"]], effect_id=action["effect_id"])
        if assignment_id is not None:
            outstanding = next((action for action in workflow["actions"].values()
                                if action["assignment_id"] == assignment_id and action["status"] in {"admitted", "uncertain"}), None)
            if outstanding is not None:
                return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding,
                            reason="uncertain_effect" if outstanding["status"] == "uncertain" else "action_in_flight",
                            effect_id=outstanding["effect_id"])
            if workflow["target_prepared"] is None:
                return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding, reason="target_setup")
            if kind in {"prepare_review", "review", "reconcile", "cleanup"}:
                process = doc["processes"].get(cls._trial(doc)["claims"][assignment_id]["process_id"])
                if process is None or not process["active"]:
                    return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding, reason="native_owner_exit")
        try:
            require_allowed(doc["authorization"]["mode"], WORKFLOW_ACTION_OPERATIONS[kind])
        except PolicyError:
            return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding, reason="explicit_pause")
        capacity = cls._workflow_capacity_reason(doc, kind)
        if capacity:
            return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding, reason=capacity)
        if kind in {"prepare_target", "materialize", "restore_materialization", "commit", "push", "acknowledge"} and workflow["target_lease"] is not None:
            lease = workflow["actions"][workflow["target_lease"]]
            if (lease["assignment_id"] != assignment_id
                or lease["binding"].get("delivery_id") != binding.get("delivery_id")
                or lease["status"] == "uncertain"):
                return dict(assignment_id=assignment_id, ready=False, kind=kind, binding=binding, reason="publication_wait")
        return dict(assignment_id=assignment_id, ready=True, kind=kind, binding=binding, reason="eligible")

    def trial_readiness(self, assignment_id: str | None = None) -> dict:
        """Read eligibility only; no model, tool, Git or lifecycle effects occur."""
        doc = self.snapshot()
        if assignment_id is not None:
            return self._workflow_readiness(doc, assignment_id)
        return {"target": self._workflow_readiness(doc, None),
                "assignments": {key: self._workflow_readiness(doc, key) for key in self._trial(doc)["claims"]},
                "prompt": self._workflow_prompt_readiness(doc, None),
                "authorization": doc["authorization"]}

    def admit_trial_action(self, assignment_id: str | None, *, kind: str, effect_id: str, binding: dict,
                           authorization_revision: int, event_id: str) -> dict:
        _text(effect_id, "effect_id")
        if kind not in WORKFLOW_ACTION_OPERATIONS or (assignment_id is None) != (kind == "prepare_target"):
            raise StateError("Unknown or incorrectly scoped controller action")
        identity = dict(assignment_id=assignment_id, kind=kind, effect_id=effect_id, binding=binding,
                        authorization_revision=authorization_revision)
        def apply(doc):
            workflow = self._workflow(doc)
            previous = workflow["actions"].get(effect_id)
            if previous is not None:
                if any(previous[key] != value for key, value in identity.items()):
                    raise StateError("An admitted action identity cannot change")
                return dict(previous, execute=False)
            self._require(doc, WORKFLOW_ACTION_OPERATIONS[kind], authorization_revision)
            readiness = self._workflow_readiness(doc, assignment_id)
            if not readiness["ready"] or readiness["kind"] != kind or readiness["binding"] != binding:
                raise StateError(f"Action is not the exact currently eligible operation: {readiness['reason']}")
            reviewer = None
            if kind in {"prepare_review", "review", "reconcile", "cleanup"}:
                assignment = self._assignment(doc, assignment_id)
                claim = self._trial(doc)["claims"][assignment_id]
                process = doc["processes"].get(claim["process_id"])
                if process is None or not process["active"] or assignment["session_id"] is None:
                    raise StateError("Native actions cannot replace or revive an exited retained root/owner")
                state = self._workflow_assignment(workflow, assignment_id)
                if kind == "prepare_review":
                    reviewer = dict(owner_id=binding["reviewer_id"], session_id=None,
                                    root_session_id=claim["root_session_id"], process_id=claim["process_id"],
                                    journal_ref=None, registry_ref=None)
                elif kind == "review":
                    reviewer = state["reviewer"]
            stamp = _now()
            action = dict(identity, status="admitted", admitted_at=stamp, reviewer=reviewer,
                          observations=[], result=None)
            workflow["actions"][effect_id] = action
            if kind in {"prepare_target", "materialize", "commit", "push", "acknowledge"}:
                workflow["target_lease"] = effect_id
            elif kind == "restore_materialization":
                workflow["target_lease"] = effect_id
            if kind in {"reconcile", "cleanup"}:
                state["owner_activity"] = dict(effect_id=effect_id, busy=True, admitted_at=stamp)
                if kind == "reconcile":
                    assignment["status"] = "verifying"
            self._workflow_event(workflow, assignment_id, "action_admitted", event_id,
                                 effect_id=effect_id, action_kind=kind, binding=binding)
            return dict(action, execute=True)
        return self._mutate(event_id, "admit_trial_action", identity, apply,
                            duplicate_result=lambda result: dict(result, execute=False))

    @staticmethod
    def _workflow_findings(findings, delivery):
        criteria = workflow_acceptance_policy()["criteria"]
        if not isinstance(findings, list) or not findings:
            raise StateError("Rejection must identify actual failed fixed criteria or changed relevant inputs")
        paths = {path for entries in delivery["inputs"]["inputs"].values() for path in entries}
        paths.update(artifact["path"] for artifact in delivery["artifacts"].values())
        for finding in findings:
            _fields(finding, ("criterion", "reason"))
            if finding["criterion"] not in criteria or not isinstance(finding.get("path"), str):
                raise StateError("A rejection cannot introduce an unrelated acceptance requirement")
            if finding["path"]:
                relative_path(finding["path"])
                if finding["path"] not in paths:
                    raise StateError("A finding must identify this concrete delivery's source or evidence")

    @staticmethod
    def _workflow_receipt(action, record, *, kind, result=None):
        binding = action["binding"]
        request = {key: binding[key] for key in (
            "assignment_id", "owner_id", "session_id", "manifest_digest", "input_identity", "publication_target")}
        # The canonical change-set digest binds every preimage, raw postimage
        # and Git blob; raw patch/command artifacts remain separate evidence.
        request["patch_identity"] = binding["source_identity"]
        for key in ("policy_identity", "validation_action_id", "coverage_identity"):
            request[key] = binding[key]
        receipt = dict(request, request_digest=_digest(request), request=request,
                       controller_action_id=action["effect_id"],
                       authorization_revision=action["authorization_revision"],
                       started_at=record["started_at"], observed_at=record["observed_at"],
                       timestamp_provenance=record["timestamp_provenance"], evidence_refs=record["evidence_refs"])
        if result:
            receipt.update(result)
        return receipt

    def _workflow_coverage(self, doc, action, result, delivery):
        workflow = self._workflow(doc)
        policy = workflow["config"]["acceptance_policy"]
        coverage = result.get("coverage")
        if (not isinstance(coverage, dict) or coverage.get("binding") != action["binding"]
            or coverage.get("producer") != workflow["config"]["controller_id"]
            or coverage.get("policy_identity") != _digest(policy)):
            raise StateError("Coverage requires exact controller, delivery, source, input and approved-policy identities")
        covered, unresolved = coverage.get("covered"), coverage.get("unresolved")
        if (not isinstance(covered, dict) or not isinstance(unresolved, dict)
            or set(covered) & set(unresolved) or set(covered) | set(unresolved) != set(policy["criteria"])
            or not set(unresolved).issubset(policy["judgment_criteria"])):
            raise StateError("All fixed criteria must be covered or explicitly unresolved; mechanical failures cannot be reviewed away")
        checks = result["checks"]
        native_chain = {checks[key] for key in ("object_compare", "data_relocations", "source_link", "binary_hashes")}
        for criterion, evidence in covered.items():
            if not isinstance(evidence, dict) or evidence.get("method") != policy["criteria"][criterion]:
                raise StateError("Coverage must use the approved controller proof, not a worker success or size label")
            _refs(evidence.get("evidence_refs"), "criterion proof references")
            if criterion in checks and checks[criterion] not in evidence["evidence_refs"]:
                raise StateError("Mechanical coverage must reference its actual fixed verification check")
            if criterion in {"abi", "edge_semantics"} and not native_chain.issubset(evidence["evidence_refs"]):
                raise StateError("Native ABI/edge equivalence requires the full pinned image proof chain")
        for evidence in unresolved.values():
            if not isinstance(evidence, dict):
                raise StateError("Unresolved judgment needs its specific reason and retained context")
            _text(evidence.get("reason"), "unresolved criterion reason")
            _refs(evidence.get("evidence_refs"), "unresolved criterion evidence")
        specification = workflow["config"]["verification"][action["assignment_id"]]
        for criterion, reason in specification.get("judgment_requirements", {}).items():
            if criterion not in unresolved or unresolved[criterion]["reason"] != reason:
                raise StateError("A specifically required source judgment cannot be silently covered or replaced")
        assignment = self._assignment(doc, action["assignment_id"])
        source = self._trial_source(assignment["identity"]["reservation"])
        shared = set(delivery["changes"]) - {source}
        if shared and "ownership" not in unresolved:
            proof = result.get("ownership_proof")
            if (not isinstance(proof, dict) or proof.get("schema") != 1 or proof.get("binding") != action["binding"]
                or proof.get("source") != source or proof.get("recipe_identity") != _digest(delivery["inputs"]["recipe"])
                or not isinstance(proof.get("paths"), dict) or set(proof["paths"]) != shared):
                raise StateError("Shared-file coverage needs the exact controller-proven authorized insertion transformation")
            registration = delivery["inputs"]["recipe"].get("registration")
            _fields(registration, ("configure_path", "splits_path"))
            transformations = {
                registration["configure_path"]: "configure-obj-insertion-v1",
                registration["splits_path"]: "splits-section-insertion-v1",
            }
            for path, transformation in proof["paths"].items():
                change = delivery["changes"][path]
                if (not isinstance(transformation, dict)
                    or path not in transformations or transformation.get("transformation") != transformations[path]
                    or any(key not in transformation or transformation[key] != change[key]
                           for key in ("before", "after", "raw"))):
                    raise StateError("Insertion proof must retain every exact preimage, postimage and raw byte identity")
            artifact = proof.get("evidence")
            _fields(artifact, ("path", "sha256"))
            _hex(artifact["sha256"], 64, "host insertion proof SHA-256")
            identities = result.get("check_identities")
            if (type(artifact.get("size")) is not int or artifact["size"] < 0
                or not isinstance(identities, dict)
                or artifact["path"] not in covered["ownership"]["evidence_refs"]
                or identities.get(artifact["path"]) != {
                    "sha256": artifact["sha256"], "size": artifact["size"]}):
                raise StateError("Insertion coverage must retain its actual host proof artifact identity")
        return coverage

    def _workflow_acceptance(self, doc, action, record, *, mode, coverage_identity):
        binding = dict(action["binding"], coverage_identity=coverage_identity,
                       validation_action_id=action["effect_id"] if action["kind"] == "validate_delivery"
                       else action["binding"]["validation_action_id"])
        acceptance = self._workflow_receipt(dict(action, binding=binding), record, kind="acceptance",
                                            result=dict(mode=mode))
        acceptance["observed_by"] = self._workflow(doc)["config"]["controller_id"]
        self._assignment(doc, action["assignment_id"])["acceptance"] = acceptance
        return acceptance

    @staticmethod
    def _workflow_identity_map(identities, name):
        if not isinstance(identities, dict) or not identities:
            raise StateError(f"{name} must retain exact physical evidence identities")
        for path, identity in identities.items():
            _text(path, name + " path")
            if not isinstance(identity, dict):
                raise StateError(f"{name} needs actual file identities")
            _hex(identity.get("sha256"), 64, name + " SHA-256")
            if type(identity.get("size")) is not int or identity["size"] < 0:
                raise StateError(f"{name} needs actual byte counts")

    def _workflow_reuse(self, doc, action, result, state, delivery):
        """Reuse native observations, never an earlier delivery's acceptance."""
        _text(result["reused_from"], "prior validation action")
        previous = self._workflow(doc)["actions"].get(result["reused_from"])
        prior_delivery = state["deliveries"].get(previous["binding"].get("delivery_id")) if previous else None
        specification = self._workflow(doc)["config"]["verification"][action["assignment_id"]]
        if (previous is None or previous["kind"] != "validate_delivery" or previous["status"] != "succeeded"
            or previous.get("superseded") or previous["assignment_id"] != action["assignment_id"]
            or any(previous["binding"].get(key) != action["binding"].get(key)
                   for key in ("policy_identity", "source_identity", "input_identity"))
            or prior_delivery is None or prior_delivery["delivery"]["artifacts"] != delivery["artifacts"]):
            raise StateError("Native receipt reuse requires the exact prior successful source, inputs, artifacts and policy")
        prior = previous["result"]
        witness = result.get("reuse_evidence")
        if (not isinstance(witness, dict) or witness.get("source_action_id") != previous["effect_id"]
            or witness.get("binding") != action["binding"]
            or prior.get("verification_spec_identity") != _digest(specification)
            or result.get("verification_spec_identity") != prior["verification_spec_identity"]
            or prior["checks"] != result["checks"] or prior["matching"] != result["matching"]
            or any(prior["source_selection"].get(key) != result["source_selection"].get(key)
                   for key in ("source", "object", "link_output", "selected", "fallback_selected"))):
            raise StateError("Reuse must retain the exact verification recipe and native observations with a fresh bound witness")
        _text(witness.get("evidence_ref"), "fresh reuse observation")
        previous_checks = prior.get("check_identities")
        current_checks = result.get("check_identities")
        previous_outputs = prior.get("output_identities")
        for identities, name in ((previous_checks, "previous receipt"), (current_checks, "current receipt"),
                                 (previous_outputs, "native output")):
            self._workflow_identity_map(identities, name)
        if (witness.get("identities") != previous_checks
            or witness.get("output_identities") != previous_outputs
            or result.get("output_identities") != previous_outputs
            or any(reference not in previous_checks or current_checks.get(reference) != previous_checks[reference]
                   for reference in prior["checks"].values())
            or witness["evidence_ref"] not in current_checks):
            raise StateError("Every reused receipt and native output must survive actual identity rechecks")

    def _complete_workflow_validation(self, doc, action, record, state, assignment, delivery):
        result = record["result"]
        self._workflow_cleanup_targets(self._workflow(doc), assignment, delivery,
                                       state["deliveries"][action["binding"]["delivery_id"]]["record"])
        required = {"compile", "object_compare", "data_relocations", "source_link", "binary_hashes", "progress"}
        checks = result.get("checks")
        if (result.get("valid") is not True or not isinstance(checks, dict) or set(checks) != required
            or result.get("binary_hash_count") != 127):
            raise StateError("Mechanical acceptance needs every fixed check and all 127 actual binary hashes")
        for reference in checks.values():
            _text(reference, "mechanical check evidence")
        if result.get("runtime_status") == "unavailable":
            _text(result.get("runtime_reason"), "runtime_reason")
        elif result.get("runtime_status") == "exercised":
            _text(result.get("runtime_ref"), "runtime_ref")
        else:
            raise StateError("Runtime verification must be exercised or explicitly unavailable")
        selection = result.get("source_selection", {})
        configured = self._workflow(doc)["config"]["verification"][action["assignment_id"]]["selection"]
        if any(selection.get(key) != configured[key] for key in ("source", "object", "link_output")):
            raise StateError("Actual source/object/link selection must match the fixed recipe")
        _text(selection.get("evidence_ref"), "source selection evidence")
        if type(selection.get("selected")) is not bool or type(selection.get("fallback_selected")) is not bool:
            raise StateError("Source selection must distinguish the real compiled object from original fallback")
        candidate = next(stage["candidates"][delivery["candidate_id"]] for stage in assignment["stages"]
                         if delivery["candidate_id"] in stage["candidates"])
        matching = candidate["outcome"] == "matching"
        if type(result.get("matching")) is not bool or result["matching"] != matching:
            raise StateError("Actual object comparison, not the model's candidate label, determines matching")
        if matching:
            if not selection["selected"] or selection["fallback_selected"]:
                raise StateError("Binary hashes alone cannot credit a source object that was not linked")
            assignment["selection"] = None
        else:
            if (not assignment["stages"][-1]["exhausted"] or candidate != assignment["best_candidate"]
                or selection["selected"] or not selection["fallback_selected"]):
                raise StateError("Exhausted source requires its preserved best draft and actual original fallback")
            assignment["selection"] = dict(candidate_id=candidate["candidate_id"], stage=candidate["stage"],
                input_identity=action["binding"]["input_identity"], valid=True, accepted_credit=0,
                label="nonmatching—attempts exhausted", fallback_ref=selection["evidence_ref"],
                evidence_refs=record["evidence_refs"])
        if result.get("reused_from") is not None:
            self._workflow_reuse(doc, action, result, state, delivery)
        coverage = self._workflow_coverage(doc, action, result, delivery)
        coverage_identity = _digest(coverage)
        evidence = {key: result[key] for key in ("checks", "binary_hash_count", "runtime_status")}
        for key in ("runtime_reason", "runtime_ref"):
            if key in result:
                evidence[key] = result[key]
        evidence.update(scope="reconstruction", source_selection=selection)
        assignment["verification"] = dict(candidate_id=delivery["candidate_id"],
            input_identity=action["binding"]["input_identity"], evidence=evidence, valid=True,
            recorded_at=_now(), controller_action_id=action["effect_id"])
        previous_status = assignment["status"]
        assignment["status"] = "review_wait" if coverage["unresolved"] else "verified"
        assignment["acceptance"] = None
        if not coverage["unresolved"]:
            self._workflow_acceptance(doc, action, record, mode="mechanical", coverage_identity=coverage_identity)
        assignment["history"].append(dict(event_id=action["effect_id"], at=_now(),
                                          **{"from": previous_status, "to": assignment["status"]}))
        state["validation"] = dict(action_id=action["effect_id"], delivery_id=action["binding"]["delivery_id"],
                                   valid=True, result=result, coverage_identity=coverage_identity)

    def _complete_workflow_review_preparation(self, doc, action, record, state):
        reviewer = record["result"].get("reviewer")
        fields = ("owner_id", "session_id", "root_session_id", "process_id", "journal_ref", "registry_ref")
        _fields(reviewer, fields)
        if set(reviewer) != set(fields):
            raise StateError("Review attachment must preserve the exact native identity fields")
        expected = action["reviewer"]
        if any(reviewer[key] != expected[key] for key in ("owner_id", "root_session_id", "process_id")):
            raise StateError("Required review must be a genuine distinct child of the retained root")
        if reviewer["session_id"] in doc["sessions"] or any(
            session["owner_id"] == reviewer["owner_id"] for session in doc["sessions"].values()
        ):
            raise StateError("Review preparation cannot adopt an owner or another reviewer's native session")
        self._workflow_native_event(record["result"], kind="review_gate_wait",
            owner_id=reviewer["owner_id"], session_id=reviewer["session_id"], root_session_id=reviewer["root_session_id"])
        profile = self._workflow(doc)["config"]["profile"]["review"]
        doc["sessions"][reviewer["session_id"]] = dict(
            session_id=reviewer["session_id"], owner_id=reviewer["owner_id"], stage=profile["stage"],
            provider=profile["provider"], model=profile["model"], role="review", active=True,
            assignment_id=action["assignment_id"], created_at=_now())
        state["reviewer"] = reviewer
        action["reviewer"] = reviewer

    def _workflow_correction(self, workflow, state, action, record):
        delivery = state["deliveries"][action["binding"]["delivery_id"]]["delivery"]
        self._workflow_findings(record["result"].get("findings"), delivery)
        state["correction"] = dict(action_id=action["effect_id"], delivery_id=action["binding"]["delivery_id"],
                                   findings=record["result"]["findings"])
        self._workflow_event(workflow, action["assignment_id"], "correction_ready", action["effect_id"],
                             delivery_id=action["binding"]["delivery_id"], findings=record["result"]["findings"])

    @staticmethod
    def _workflow_postimages(result, delivery):
        expected, actual = result.get("expected_postimages"), result.get("actual_postimages")
        if (not isinstance(expected, dict) or expected != actual or set(expected) != set(delivery["changes"])
            or result.get("scope_verified") is not True or result.get("source_binding_verified") is not True):
            raise StateError("Complete declared postimages and source scope, not command exit, establish materialization")
        for path, image in actual.items():
            if not isinstance(image, dict) or set(image) != {"mode", "blob", "raw"} or image["mode"] != "100644":
                raise StateError("Materialized postimages require exact regular Git and working-file identities")
            _hex(image["blob"], 40, "materialized Git blob")
            _hex(image.get("raw", {}).get("sha256"), 64, "materialized working-file SHA-256")
            if type(image["raw"].get("size")) is not int or image["raw"]["size"] < 0:
                raise StateError("Materialized raw-byte counts must be explicit")
            declared = delivery["changes"][path]
            if image != dict(declared["after"], raw=declared["raw"]):
                raise StateError("Every published postimage must be in the exact reviewed and verified delivery")
        return actual

    def _apply_workflow_success(self, doc, action, record, event_id):
        workflow = self._workflow(doc)
        result, kind, key = record["result"], action["kind"], action["assignment_id"]
        if kind == "prepare_target":
            target = workflow["config"]["publication_target"]
            if (any(result.get(field) != target[field] for field in ("repository", "git_dir", "remote", "branch"))
                or result.get("common_git_dir") != target["git_dir"] or result.get("head") != target["baseline"]
                or result.get("independent") is not True or result.get("alternates") != []):
                raise StateError("Setup must prove the actual independent target without shared Git mutation authority")
            workflow["target_prepared"] = dict(action_id=action["effect_id"], result=result, record=record)
            workflow["target_head"] = result["head"]
            return
        assignment = self._assignment(doc, key)
        state = self._workflow_assignment(workflow, key)
        if kind == "reconcile":
            state["reconciliation"] = dict(action_id=action["effect_id"], record=record)
            return
        if kind == "restore_materialization":
            original = workflow["actions"][action["binding"]["recovery_action_id"]]
            previous = state["deliveries"][original["binding"]["delivery_id"]]["delivery"]
            expected = {path: change["before"] for path, change in previous["changes"].items()}
            _refs(result.get("command_refs"), "owned restoration command references")
            _text(result.get("preservation_ref"), "preserved superseded materialization")
            if (state.get("target_recovery") != original["effect_id"]
                or result.get("restored_action_id") != original["effect_id"]
                or result.get("base_head") != action["binding"]["target_head"]
                or result["base_head"] != workflow["target_head"]
                or result.get("restored_preimages") != expected or result.get("scope_verified") is not True):
                raise StateError("Restoration must prove only the actual superseded effects were restored at unchanged HEAD")
            original["restored_by"] = action["effect_id"]
            original["recovery_required"] = False
            state["target_recovery"] = None
            return
        delivery = state["deliveries"][action["binding"]["delivery_id"]]["delivery"]
        if kind == "validate_delivery":
            self._complete_workflow_validation(doc, action, record, state, assignment, delivery)
        elif kind == "prepare_review":
            self._complete_workflow_review_preparation(doc, action, record, state)
        elif kind == "review":
            validation = state.get("validation")
            scope = action["binding"].get("unresolved_criteria")
            reviewed = result.get("reviewed_criteria")
            if (not validation or action["binding"].get("validation_action_id") != validation["action_id"]
                or action["binding"].get("coverage_identity") != validation["coverage_identity"]
                or not scope or scope != validation["result"]["coverage"]["unresolved"]
                or not isinstance(reviewed, list) or any(not isinstance(key, str) for key in reviewed)
                or len(reviewed) != len(set(reviewed)) or set(reviewed) != set(scope)):
                raise StateError("A model decision must address exactly the recorded unresolved judgment and evidence")
            decision = result.get("decision")
            if decision not in {"approve", "reject"}:
                raise StateError("Substantive review requires an actual independent decision")
            decision_file = result.get("decision_file")
            _fields(decision_file, ("path", "sha256"))
            _hex(decision_file["sha256"], 64, "native review decision SHA-256")
            if not Path(decision_file["path"]).is_absolute():
                raise StateError("The actual native review decision file must be identified")
            if decision == "reject":
                if any(finding.get("criterion") not in scope for finding in result.get("findings", [])):
                    raise StateError("Scoped review cannot replace deterministic checks or add unrelated judgment")
                self._workflow_correction(workflow, state, action, record)
                action["status"] = "rejected"
            elif result.get("findings") != []:
                raise StateError("Approval cannot conceal failed acceptance criteria")
            state["review"] = dict(action_id=action["effect_id"], delivery_id=action["binding"]["delivery_id"],
                                   decision=decision, reviewer=action["reviewer"], result=result)
            if decision == "approve":
                receipt = self._workflow_receipt(action, record, kind="review")
                receipt["observed_by"] = workflow["config"]["controller_id"]
                receipt["reviewer"] = action["reviewer"]
                receipt["decision_file"] = decision_file
                self._apply_trial_receipt(doc, key, "review", receipt, event_id)
                self._workflow_acceptance(doc, action, record, mode="model_judgment",
                                          coverage_identity=validation["coverage_identity"])
        elif kind == "materialize":
            postimages = self._workflow_postimages(result, delivery)
            source = self._trial_source(assignment["identity"]["reservation"])
            if postimages[source]["raw"] != delivery["changes"][source]["raw"]:
                raise StateError("Registration reconciliation cannot replace the verified function source")
            _fields(result, ("grant_ref", "preservation_ref", "private_index_ref"))
            _hex(result.get("base_head"), 40, "materialization base commit")
            if result["base_head"] != action["binding"]["target_head"] or result["base_head"] != workflow["target_head"]:
                raise StateError("Materialization cannot replace an unobserved target ref or another source generation")
            receipt = self._workflow_receipt(action, record, kind="materialization",
                result={field: result[field] for field in ("grant_ref", "preservation_ref", "private_index_ref")})
            receipt["observed_by"] = assignment["owner_id"]
            self._apply_trial_receipt(doc, key, "materialization", receipt, event_id)
            state["materialization"] = dict(action_id=action["effect_id"], postimages=postimages,
                                            base_head=result["base_head"], record=record)
        elif kind in {"commit", "push"}:
            unit_id = action["binding"]["logical_unit_id"]
            if result.get("logical_unit_id") != unit_id:
                raise StateError("A Git outcome cannot substitute another logical publication unit")
            index = int(unit_id.removeprefix("unit-"))
            unit = state["units"].setdefault(unit_id, {})
            last = index == len(delivery["logical_units"]) - 1
            _refs(result.get("command_refs"), "owned Git command references")
            _hex(result.get("commit"), 40, "actual unit commit")
            if kind == "commit":
                for field in ("parent", "tree"):
                    _hex(result.get(field), 40, field)
                expected = {path: state["materialization"]["postimages"][path]
                            for path in delivery["logical_units"][index]["paths"]}
                if result.get("local_head") != result["commit"] or result.get("postimages") != expected:
                    raise StateError("Commit completion requires the exact actual ref and every unit postimage")
                if not isinstance(result.get("changed_paths"), list) or set(result["changed_paths"]) != set(expected):
                    raise StateError("A source unit commit cannot omit its paths or commit unrelated changes")
                parent = state["units"][f"unit-{index - 1}"]["commit"] if index else state["materialization"]["base_head"]
                if result["parent"] != parent:
                    raise StateError("Commit must descend directly from the materialized base or preceding unit")
                unit.update(commit=result["commit"], commit_action_id=action["effect_id"], commit_result=result)
                workflow["target_head"] = result["commit"]
                if last:
                    receipt = self._workflow_receipt(action, record, kind="commit",
                        result=dict(commit=result["commit"], local_head=result["local_head"]))
                    receipt["observed_by"] = workflow["config"]["controller_id"]
                    if result.get("recovered_from_git") is True:
                        receipt.update(recovered_from_git=True, timing_scope="local_recovery_query",
                                       command_refs=result["command_refs"])
                    self._apply_trial_receipt(doc, key, "commit", receipt, event_id)
                    assignment["publication"]["external_coordinator"] = False
            else:
                recovered_push = result.get("recovered_from_remote") is True
                valid_exit = result.get("push_exit_code") is None if recovered_push else type(result.get("push_exit_code")) is int and result["push_exit_code"] == 0
                if (result["commit"] != unit.get("commit") or not valid_exit
                    or result.get("pushed") is not True or result.get("remote_contains_commit") is not True):
                    raise StateError("Every logical unit requires its own actual successful push and remote ancestry")
                _hex(result.get("remote_head"), 40, "actual remote head")
                unit.update(pushed=True, push_action_id=action["effect_id"], push_result=result)
                if last:
                    receipt = self._workflow_receipt(action, record, kind="push",
                        result={field: result[field] for field in (
                            "commit", "push_exit_code", "pushed", "remote_contains_commit", "remote_head")})
                    receipt["observed_by"] = workflow["config"]["controller_id"]
                    if recovered_push:
                        receipt.update(recovered_from_remote=True, timing_scope="remote_recovery_query",
                                       command_refs=result["command_refs"])
                    self._apply_trial_receipt(doc, key, "push", receipt, event_id)
        elif kind == "acknowledge":
            if len(state["units"]) != len(delivery["logical_units"]) or not all(
                unit.get("pushed") for unit in state["units"].values()
            ):
                raise StateError("Canonical acceptance follows every actual separate source commit/push")
            publication = assignment["publication"]
            receipt = self._workflow_receipt(action, record, kind="ack",
                result=dict(commit=publication["commit"], accepted_matching=assignment["selection"] is None))
            receipt["observed_by"] = workflow["config"]["controller_id"]
            self._apply_trial_receipt(doc, key, "ack", receipt, event_id)
        elif kind == "cleanup":
            expected_paths = {str(Path(assignment["identity"]["reservation"]["workspace"]) / item["path"]): item["identity"]
                              for item in delivery["cleanup"]}
            removed = result.get("removed_paths")
            if (not isinstance(removed, list) or any(not isinstance(item, dict) for item in removed)
                or {item.get("path") for item in removed} != set(expected_paths)):
                raise StateError("Cleanup must observe exactly the delivered, authorized disposable files")
            for item in removed:
                identity = expected_paths[item["path"]]
                if item.get("bytes") != identity["size"] or item.get("sha256") != identity["sha256"]:
                    raise StateError("Cleanup evidence must bind the actual authorized disposable bytes")
            if result.get("ancestor_links_checked") is not True or result.get("directory_pruning_checked") is not True:
                raise StateError("Cleanup must verify ancestor reparse/link boundaries and every directory prune")
            receipt = self._workflow_receipt(action, record, kind="cleanup",
                result={field: result.get(field) for field in (
                    "retained_evidence_refs", "deletion_manifest_ref", "shared_link_checks_ref",
                    "original_input_checks_ref", "retained_evidence_checks_ref", "tracked_files_preserved",
                    "removed_paths", "removed_bytes")})
            receipt.update(observed_by=assignment["owner_id"], commit=assignment["publication"]["commit"])
            self._apply_trial_receipt(doc, key, "cleanup", receipt, event_id)
            state["cleanup"] = dict(action_id=action["effect_id"], record=record)
        elif kind == "close":
            receipt = self._workflow_receipt(action, record, kind="closed",
                result={field: result.get(field) for field in ("process_id", "exit_evidence_ref")})
            receipt.update(observed_by=workflow["config"]["controller_id"], commit=assignment["publication"]["commit"])
            self._apply_trial_receipt(doc, key, "closed", receipt, event_id)
            if state.get("reviewer") is not None:
                doc["sessions"][state["reviewer"]["session_id"]]["active"] = False
        assignment["updated_at"] = _now()

    def observe_trial_action(self, *, effect_id: str, record: dict, event_id: str) -> dict:
        """Persist an admitted action's actual outcome, including after STOP."""
        self._observation(record)
        if record.get("outcome") not in {"succeeded", "rejected", "failed", "uncertain"} or not isinstance(record.get("result"), dict):
            raise StateError("Action observations require an explicit actual outcome and evidence result")
        def apply(doc):
            workflow = self._workflow(doc)
            action = workflow["actions"].get(effect_id)
            if action is None:
                raise StateError("An outcome cannot manufacture an action admission")
            if record.get("binding") != action["binding"] or record.get("authorization_revision") != action["authorization_revision"]:
                raise StateError("Outcome must bind the exact admitted run/owner/source/input/target and authorization")
            if any(entry["record"] == record for entry in action["observations"]):
                return dict(action, execute=False)
            if action["status"] not in {"admitted", "uncertain"}:
                raise StateError("A completed action outcome is immutable; uncertain effects alone may be resolved")
            if self._timestamp(record.get("started_at")) < self._timestamp(action["admitted_at"]):
                raise StateError("An observed action cannot precede its admission")
            if self._timestamp(record["started_at"]) > self._timestamp(record["observed_at"]):
                raise StateError("An action outcome cannot precede its actual start")
            recovery_flags = {"recovered_from_remote": "push", "recovered_from_git": "commit",
                              "recovered_restoration": "restore_materialization"}
            recovered = any(record["result"].get(flag) is True for flag in recovery_flags)
            if any(record["result"].get(flag) is True and action["kind"] != kind
                   for flag, kind in recovery_flags.items()):
                raise StateError("Read-only recovery cannot invent another kind of admitted effect")
            if action["kind"] not in {"acknowledge", "close"} and not recovered:
                self._trial_receipt_interval(doc, record, owner_action=action["kind"] not in {"commit", "push"})
            result, outcome, kind = record["result"], record["outcome"], action["kind"]
            if kind == "review" and (outcome != "uncertain" or result.get("native_event") is not None):
                reviewer = action["reviewer"]
                self._workflow_native_event(result, kind="reviewer_turn_end",
                    owner_id=reviewer["owner_id"], session_id=reviewer["session_id"],
                    root_session_id=reviewer["root_session_id"], request_id=effect_id)
                action["inference_complete"] = True
            if kind in {"reconcile", "cleanup"} and (outcome != "uncertain" or result.get("native_event") is not None):
                owner_record = {key: record[key] for key in (
                    "authorization_revision", "started_at", "observed_at", "timestamp_provenance", "evidence_refs")}
                owner_record.update(dispatch_effect_id=effect_id, native_event=result.get("native_event"))
                self._observe_workflow_owner(doc, action["assignment_id"], owner_record, event_id)
            entry = dict(record=record, event_id=event_id, recorded_at=_now())
            action["observations"].append(entry)
            action["status"], action["result"] = outcome, result
            mutation = kind in {"prepare_target", "materialize", "restore_materialization", "commit", "push"}
            if outcome in {"failed", "rejected"} and mutation and result.get("effect_absent") is not True:
                action["status"] = "uncertain"
            elif outcome == "succeeded":
                if action["assignment_id"] is not None:
                    current = self._workflow_binding(doc, action["assignment_id"])
                    if kind not in {"reconcile", "restore_materialization"} and any(current[key] != action["binding"][key] for key in (
                        "delivery_id", "input_identity", "source_identity", "owner_id", "session_id"
                    )):
                        action["superseded"] = True
                    elif (self._assignment(doc, action["assignment_id"])["current_input_identity"] != current["input_identity"]
                          and kind not in {"reconcile", "commit", "push", "cleanup", "close", "restore_materialization"}):
                        action["superseded"] = True
                if not action.get("superseded"):
                    self._apply_workflow_success(doc, action, record, event_id)
                elif kind == "prepare_review":
                    # Source validity can lapse, but an observed genuine child still exists.
                    state = self._workflow_assignment(workflow, action["assignment_id"])
                    self._complete_workflow_review_preparation(doc, action, record, state)
                elif kind == "materialize":
                    state = self._workflow_assignment(workflow, action["assignment_id"])
                    delivery = state["deliveries"][action["binding"]["delivery_id"]]["delivery"]
                    self._workflow_postimages(result, delivery)
                    if result.get("base_head") != action["binding"]["target_head"]:
                        raise StateError("Superseded target effects must retain their actual base")
                    state["target_recovery"] = effect_id
                    action["recovery_required"] = True
            elif outcome == "rejected" and kind in {"validate_delivery", "materialize", "review"}:
                state = self._workflow_assignment(workflow, action["assignment_id"])
                if kind == "review":
                    self._apply_workflow_success(doc, action, record, event_id)
                else:
                    self._workflow_correction(workflow, state, action, record)
            if workflow["target_lease"] == effect_id and (
                kind in {"prepare_target", "acknowledge", "restore_materialization"} and action["status"] == "succeeded" and not action.get("superseded")
                or kind in {"prepare_target", "materialize"} and action["status"] in {"failed", "rejected"}
                and result.get("effect_absent") is True
            ):
                workflow["target_lease"] = None
            if action["status"] != "uncertain":
                action["completed_at"] = record["observed_at"]
            self._workflow_event(workflow, action["assignment_id"], "action_observed", event_id,
                effect_id=effect_id, action_kind=kind, outcome=action["status"],
                observation=record, superseded=action.get("superseded", False))
            return dict(action, execute=False)
        return self._mutate(event_id, "observe_trial_action", dict(effect_id=effect_id, record=record), apply,
                            duplicate_result=lambda result: dict(result, execute=False))

    @staticmethod
    def _trial_source(reservation):
        return next(path for path in reservation["owned_paths"] if path.endswith(".cpp"))

    @staticmethod
    def _workflow_cleanup_targets(workflow, assignment, delivery, record):
        """Protect every earlier measurement, not just the latest packet."""
        workspace = Path(assignment["identity"]["reservation"]["workspace"])
        retained = set()
        def retain(value):
            if not isinstance(value, str) or not value or "://" in value:
                return
            path = Path(value)
            if not path.is_absolute():
                try:
                    relative_path(value)
                except InputError:
                    return  # Opaque evidence references are not filesystem authority.
                path = workspace / path
            retained.add(str(path).casefold())
        def references(value):
            if isinstance(value, dict):
                for key, child in value.items():
                    if key == "path" or key.endswith("_ref"):
                        retain(child)
                    elif key.endswith("_refs") and isinstance(child, list):
                        for reference in child:
                            retain(reference)
                    references(child)
            elif isinstance(value, list):
                for child in value:
                    references(child)
        references(assignment["stages"])
        references(workflow["config"])
        retain(record["path"])
        retain(record["original_path"])
        state = workflow["assignments"][assignment["assignment_id"]]
        for packet in [entry["delivery"] for entry in state["deliveries"].values()] + [delivery]:
            for inputs in packet["inputs"]["inputs"].values():
                for path in inputs:
                    retain(path)
            for artifact in packet["artifacts"].values():
                retain(artifact["path"])
        for previous in state["deliveries"].values():
            retain(previous["record"]["path"])
            retain(previous["record"]["original_path"])
        for item in workflow["config"]["verification"][assignment["assignment_id"]]["workspace_inputs"]:
            retain(item["destination"])
        specification = workflow["config"]["verification"][assignment["assignment_id"]]
        for path in specification["selection"].values():
            retain(path)
        for path in specification["binary_hashes"]:
            retain(path)
        for item in delivery["cleanup"]:
            if str(workspace / item["path"]).casefold() in retained:
                raise StateError("Cleanup cannot remove original inputs, any preserved draft, delivery or earlier evidence")

    @classmethod
    def _workflow_prompt_readiness(cls, doc, assignment_id):
        trial, workflow = cls._trial(doc), cls._workflow(doc)
        reason = None
        if assignment_id is not None:
            assignment = cls._assignment(doc, assignment_id)
            previous = next((effect for effect in trial["effects"].values()
                             if effect["assignment_id"] == assignment_id and effect["kind"] == "prompt"), None)
            if previous is not None:
                return dict(assignment_id=assignment_id, ready=False, reason="already_admitted",
                            effect_id=previous["effect_id"], authorization_revision=doc["authorization"]["revision"])
            if assignment["status"] == "closed":
                reason = "closed"
            elif cls._resolved_history(trial, assignment_id)["status"] not in {"known", "recorded"}:
                reason = "input_wait"
            else:
                claim = trial["claims"][assignment_id]
                process = doc["processes"].get(claim["process_id"])
                if claim["session_id"] is None or process is None:
                    reason = "native_preparation_wait"
                elif not process["active"]:
                    reason = "native_owner_exit"
        if reason is None and (doc["authorization"]["mode"] != Mode.RUN.value or trial["activation"] is None):
            reason = "explicit_pause"
        if reason is None and workflow["target_prepared"] is None:
            reason = "target_setup"
        if reason is None:
            reason = cls._workflow_capacity_reason(doc, "prompt")
        return dict(assignment_id=assignment_id, ready=reason is None, reason=reason or "eligible",
                    authorization_revision=doc["authorization"]["revision"])

    def trial_prompt_readiness(self, assignment_id: str | None = None) -> dict:
        """Pre-admission capacity inspection; never permission to replay a forward."""
        return self._workflow_prompt_readiness(self.snapshot(), assignment_id)
