"""Durable bounded-evaluation records, not a scheduler or reconstruction engine.

Every mutation has an immutable event identity and commits with its deduplication
receipt. Evidence fields are attestations/references, never semantic proof inferred
from an engine's success state. Process-exit observations come from the native
runtime; Git observations come from the fixture-only publisher.
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

from .policy import Mode, PolicyError, SlotPolicy, Stage, evaluation_data_path, next_stage, require_allowed


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
        if operation not in {"launch", "publish"} or (operation == "publish" and session_id is not None):
            raise PolicyError("Publication-only processes cannot wake an owner session")
        payload = dict(process_id=process_id, session_id=session_id, identity=identity,
                       authorization_revision=authorization_revision, operation=operation)
        def apply(doc):
            self._require(doc, operation, authorization_revision)
            if session_id is not None and (session_id not in doc["sessions"] or not doc["sessions"][session_id]["active"]):
                raise StateError("Process session is not an active owned session")
            if process_id in doc["processes"]:
                old = doc["processes"][process_id]
                if old["identity"] != identity or old["session_id"] != session_id:
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
                       authorization_revision: int) -> dict:
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
        def apply(doc):
            self._require(doc, "reconstruct", authorization_revision)
            a = self._assignment(doc, assignment_id)
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
                    count = len(stage["candidates"])
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
                      authorization_revision: int) -> dict:
        _refs(evidence_refs)
        def apply(doc):
            self._require(doc, "reconstruct", authorization_revision)
            a = self._assignment(doc, assignment_id)
            stage = a["stages"][-1]
            if a["status"] not in {"reconstructing", "verifying", "exhausted"} or stage["best_candidate"] is None or stage["corrections"] != 10 or any(
                c["outcome"] == "matching" and c.get("input_epoch", 0) == a.get("input_epoch", 0)
                for c in stage["candidates"].values()
            ):
                raise StateError("Exhaustion requires ten unmatched corrections, not a tool failure")
            stage.update(exhausted=True, handoff_evidence_refs=evidence_refs)
            a.update(status="exhausted", updated_at=_now())
            return a
        return self._mutate(event_id, "exhaust_stage", dict(assignment_id=assignment_id,
                            evidence_refs=evidence_refs, authorization_revision=authorization_revision), apply)

    def escalate(self, assignment_id: str, *, event_id: str, stage: str, provider: str, model: str,
                 owner_id: str, session_id: str, authorization_revision: int) -> dict:
        payload = dict(assignment_id=assignment_id, stage=stage, provider=provider, model=model,
                       owner_id=owner_id, session_id=session_id, authorization_revision=authorization_revision)
        def apply(doc):
            self._require(doc, "launch", authorization_revision)
            a = self._assignment(doc, assignment_id)
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
                            input_identity: str, evidence: dict, authorization_revision: int) -> dict:
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
        def apply(doc):
            self._require(doc, "verify", authorization_revision)
            a = self._assignment(doc, assignment_id)
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
            a["accepted_credit"] = 0  # This evaluation never updates live reconstruction accounting.
            a["updated_at"] = _now()
            return a
        return self._mutate(event_id, "record_verification", dict(assignment_id=assignment_id,
                            candidate_id=candidate_id, input_identity=input_identity, evidence=evidence,
                            authorization_revision=authorization_revision), apply)

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
            if not same and previous is not None:
                a["input_epoch"] = a.get("input_epoch", 0) + 1
                if relevant is not None:
                    relevant.update(valid=False, invalidated_at=_now(), invalidation_ref=evidence_ref)
                if verification is not None:
                    verification.update(valid=False, invalidated_at=_now(), invalidation_ref=evidence_ref)
                a["review"] = None
                a["materialization"] = None
                self._refresh_best(a)
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
            old = a["status"]
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
                    if a["stage"] != Stage.ASTRA.value or not a["stages"][-1]["exhausted"]:
                        raise StateError("Nonmatching publication requires exhausted Astra")
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
