"""The ledger is authority; Prefect state is observation, never an exit proof."""
from __future__ import annotations

import json
import os
from pathlib import Path
import socket
import sys
import time
import urllib.error
import urllib.request
import uuid

from .omp_rpc import OmpControl
from .processes import ProcessManager, owned_listener, runtime_lock
from .safety import SafetyError, confined, isolated_environment, now, save_json
from .state import Ledger


class EvaluationRuntime:
    def __init__(self, root: Path, ledger: Ledger):
        self.root, self.ledger = confined(root), ledger
        self.environment = isolated_environment(self.root)
        self.manager = ProcessManager(
            self.root, self.environment,
            authorize=lambda operation, revision: self.ledger.require_operation(operation, authorization_revision=revision),
        )
        self.controls: dict[str, OmpControl] = {}

    def snapshot(self, label: str) -> dict:
        value = self.ledger.snapshot()
        value.update(observed_at=now(), label=label, process_registry=self.manager.records(),
                     reconstruction_semantics="not evaluated; fixture measurements only")
        save_json(self.root / "status.json", value)
        save_json(self.root / "snapshots" / (label + ".json"), value)
        return value

    def register_process(self, owned, revision: int, session_id: str | None = None, *, operation: str = "launch"):
        record = owned.record
        return self.ledger.register_process(
            process_id=owned.process_id, session_id=session_id,
            identity={k: record[k] for k in ("pid", "creation_time", "token", "job_name")},
            event_id="register-" + owned.process_id, authorization_revision=revision, operation=operation,
        )

    def start_prefect(self, revision: int) -> str:
        with runtime_lock(self.root):
            self.ledger.require_operation("launch", authorization_revision=revision)
            with socket.socket() as sock:
                sock.bind(("127.0.0.1", 0))
                port = sock.getsockname()[1]
            # This is a private server, not an ephemeral Prefect helper or global daemon.
            server = self.manager.launch(
                [sys.executable, "-B", "-m", "prefect", "server", "start", "--host", "127.0.0.1",
                 "--port", str(port), "--no-ui"], kind="prefect-server", cwd=self.root, authorization_revision=revision,
            )
            self.register_process(server, revision)
            api_url = f"http://127.0.0.1:{port}/api"
            deadline = time.monotonic() + 120
            while True:
                self.ledger.require_operation("launch", authorization_revision=revision)
                if server.process.poll() is not None:
                    raise RuntimeError("Owned Prefect server exited; inspect retained process stderr/stdout")
                if not owned_listener(server, port):
                    if time.monotonic() >= deadline:
                        raise TimeoutError("Owned Prefect process never acquired its loopback listener")
                    time.sleep(0.2)
                    continue
                try:
                    with urllib.request.urlopen(api_url + "/health", timeout=1) as response:
                        if response.status == 200:
                            break
                except (urllib.error.URLError, TimeoutError, OSError):
                    pass
                if time.monotonic() >= deadline:
                    raise TimeoutError("Owned Prefect server did not become healthy")
                time.sleep(0.2)
            self.environment["PREFECT_API_URL"] = api_url
            os.environ["PREFECT_API_URL"] = api_url
            save_json(self.root / "prefect-server.json", {"api_url": api_url, "process_id": server.process_id,
                                                         "ready_at": now(), "pid": server.process.pid})
            return api_url

    def launch_assignment(self, assignment_id: str, function: dict, executable: Path, *, revision: int,
                          stage: str = "sol", provider: str = "openai-codex", model: str = "gpt-6.1-sol") -> dict:
        with runtime_lock(self.root):
            self.ledger.require_operation("launch", authorization_revision=revision)
            snapshot = self.ledger.snapshot()
            existing = snapshot["assignments"].get(assignment_id)
            if existing:
                if existing["function"] != function or any(
                    existing["identity"][key] != value
                    for key, value in (("stage", stage), ("provider", provider), ("model", model))
                ):
                    raise SafetyError("Assignment identity cannot change on duplicate delivery")
                # Reconnection is observation, not a new candidate, session, or launch.
                return existing
            if any(a["function"] == function for a in snapshot["assignments"].values()):
                raise SafetyError("Function already has an immutable assignment identity")
            capacity = self.ledger.policy.capacity(stage)
            used = sum(s["active"] and s["role"] == "reconstruction" and s["stage"] == stage
                       for s in snapshot["sessions"].values())
            if used >= capacity:
                raise SafetyError("No authorized model slot is available; no OMP process was launched")
            control = OmpControl(self.manager, executable, provider=provider, model=model, authorization_revision=revision)
            try:
                state = control.fresh_session()
                owner = "evaluation-owner-" + uuid.uuid4().hex
                assignment = self.ledger.create_assignment(
                    assignment_id=assignment_id, function=function, stage=stage, provider=provider, model=model,
                    owner_id=owner, session_id=state["sessionId"], event_id="assign-" + assignment_id,
                    authorization_revision=revision,
                )
                self.register_process(control.owned, revision, state["sessionId"])
                self.controls[assignment_id] = control
                return assignment
            except BaseException:
                control.owned.stop()
                raise

    def stop(self, *, event_id: str, reason: str, include_server: bool = True) -> dict:
        # STOP durability must not depend on the server/RPC startup lock. A
        # distinct short admission fence below covers any in-flight creation.
        self.ledger.request_stop(event_id=event_id, reason=reason)
        deadline = time.monotonic() + 5
        with runtime_lock(self.root / "cancellation", timeout=max(0, deadline - time.monotonic())):
            self.snapshot(event_id + "-stop-persisted")
            errors, cancelling = [], []
            for assignment_id, control in list(self.controls.items()):
                if control.owned.record.get("exit_proof"):
                    continue
                cancelling.append(control)
                try:
                    control.abort_without_wait()
                except Exception as exc:
                    errors.append({"assignment_id": assignment_id, "control_error": repr(exc)})
            # All control replies are optional for STOP. One shared deadline
            # bounds native waits and locks across the entire owned process set.
            receipts = self.manager.stop_all(exclude_kinds=() if include_server else ("prefect-server",),
                                             deadline=deadline)
            proofs = {proof["process_id"]: proof for proof in receipts}
            for control in cancelling:
                control.reader.join(timeout=max(0, deadline - time.monotonic()))
                save_json(control.root / "cancellation.json", {
                    "response_waited": False, "exit_proof": proofs[control.owned.process_id],
                    "shared_shutdown_wait_budget_seconds": 5})
            known = {p["process_id"] for p in self.ledger.processes()}
            ledger_receipts = [p for p in receipts if p["process_id"] in known]
            for proof in ledger_receipts:
                self.ledger.record_process_exit(proof["process_id"], event_id="exit-" + proof["process_id"], proof=proof)
            result = (self.ledger.finish_stop(event_id=event_id + "-verified", exit_proofs=ledger_receipts)
                      if include_server else self.ledger.authorization())
            shutdown = {"authorization": result, "receipts": receipts,
                        "control_errors": errors, "verified_at": now()}
            save_json(self.root / "shutdown-events" / (event_id + ".json"), shutdown)
            save_json(self.root / ("shutdown.json" if include_server else "work-shutdown.json"), shutdown)
            self.snapshot(event_id + ("-stopped" if include_server else "-stopping-work-exited"))
            return result

    def close_control(self, assignment_id: str) -> dict:
        control = self.controls[assignment_id]
        proof = control.cancel()
        self.ledger.record_process_exit(proof["process_id"], event_id="exit-" + proof["process_id"], proof=proof)
        return proof
