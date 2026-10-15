"""Non-executing by default; every mutating action requires explicit pilot authorization."""
from __future__ import annotations

import argparse
import importlib.metadata
import json
import os
from pathlib import Path
import re
import shutil
import sys
import time
import traceback
import urllib.request
import uuid

from .safety import BUILD, WORKTREE, SafetyError, check_worktree, confined, digest, isolated_environment, now, save_json


CATEGORIES = {
    "assigned": "active_work", "reconstructing": "active_work", "verifying": "verification",
    "review_wait": "parent_review_delay", "reconciling": "owner_reconciliation",
    "publication_wait": "parent_publication_delay", "blocked": "tool_infrastructure_failure",
    "committed": "committed_checkpoint_push_pending", "pushed": "pushed_checkpoint_acknowledgment_pending",
    "publication_acknowledged": "owner_cleanup_pending", "cleanup": "owner_cleanup", "closed": "closed",
    "exhausted": "model_handoff_or_nonmatching_publication_pending",
}


def run_root(run_id: str) -> Path:
    if (not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]{0,100}", run_id)
            or run_id.endswith(".") or os.path.isreserved(run_id)):
        raise SafetyError("Run identity must be a single portable path component")
    return confined(BUILD / "runs" / run_id)


def status(root: Path) -> dict:
    from .state import read_snapshot
    database = root / "ledger.sqlite3"
    if not database.is_file():
        return {"run": str(root), "mode": "STOPPED", "state": "not_initialized", "observed_at": now(), "executing": False}
    snapshot = read_snapshot(database)
    mode = snapshot["authorization"]["mode"]
    assignments = []
    for assignment in snapshot["assignments"].values():
        leased = any(p["active"] and p["session_id"] == assignment["session_id"]
                     for p in snapshot["processes"].values())
        execution = (mode.lower() if mode != "RUN" else
                     ("owned_process_leased" if leased else "no_active_process_lease"))
        assignments.append({**assignment, "category": CATEGORIES.get(assignment["status"], "unknown"),
                            "execution_state": execution, "has_active_process_lease": leased})
    return {"run": str(root), "authorization": snapshot["authorization"], "observed_at": now(),
            "assignments": assignments, "publisher": snapshot["publisher"], "processes": snapshot["processes"],
            "policy": snapshot["policy"], "event_count": snapshot["event_count"],
            "execution_claim": "Ledger states do not prove OS process exit; use persisted exit receipts"}


def select_root(run_id: str | None) -> Path:
    if run_id:
        return run_root(run_id)
    runs = BUILD / "runs"
    existing = sorted((p for p in runs.iterdir() if p.is_dir()), key=lambda p: p.stat().st_mtime, reverse=True) if runs.is_dir() else []
    return confined(existing[0]) if existing else run_root("not-initialized")


def configure(root: Path) -> None:
    environment = isolated_environment(root)
    os.environ.clear()
    os.environ.update(environment)
    sys.dont_write_bytecode = True
    if str(WORKTREE) not in sys.path:
        sys.path.insert(0, str(WORKTREE))
    os.chdir(root)


def drain_prefect_clients(root: Path, api_url: str, flow_run_id: str | None) -> dict:
    """Finish this process's queued API work while its owned server is alive."""
    began = time.monotonic()
    deadline = began + 20
    report = {"started_at": now(), "api_url": api_url, "flow_run_id": flow_run_id, "complete": False}
    try:
        from prefect.logging.handlers import APILogWorker
        # Unlike Handler.flush(), this exposes unfinished futures instead of
        # silently returning after a shutdown timeout. It also closes clients.
        done, pending = APILogWorker.drain_all(timeout=max(0, deadline - time.monotonic()), at_exit=False)
        report.update(completed_services=len(done), pending_services=len(pending))
        if pending:
            raise TimeoutError("Prefect client queues did not drain before owned server shutdown")
        for future in done:
            future.result()
        if flow_run_id:
            body = {"logs": {"flow_run_id": {"any_": [flow_run_id]}},
                    "sort": "TIMESTAMP_DESC", "limit": 200, "offset": 0}
            request = urllib.request.Request(api_url + "/logs/filter", data=json.dumps(body).encode("utf-8"),
                                             headers={"Content-Type": "application/json"}, method="POST")
            with urllib.request.urlopen(request, timeout=max(0.001, deadline - time.monotonic())) as response:
                logs = json.load(response)
            terminal = next((entry for entry in logs if entry.get("flow_run_id") == flow_run_id
                             and entry.get("task_run_id") is None
                             and entry.get("message", "").startswith("Finished in state Completed")), None)
            if terminal is None:
                raise SafetyError("Owned Prefect API did not retain the completed flow's terminal log")
            report["terminal_flow_log"] = terminal
            report["server_api_alive_after_drain"] = True
        report["complete"] = True
    except BaseException as exc:
        report.update(error=repr(exc), traceback=traceback.format_exc())
        raise
    finally:
        report.update(finished_at=now(), elapsed_seconds=time.monotonic() - began)
        save_json(root / "prefect-client-shutdown.json", report)
    return report


def exercise(root: Path, executable: Path, astra_capacity: int) -> dict:
    from .policy import SlotPolicy
    from .runtime import EvaluationRuntime
    from .processes import runtime_lock
    from .state import Ledger, read_snapshot
    if importlib.metadata.version("prefect") != "3.8.8":
        raise SafetyError("Use the pinned project environment: Prefect 3.8.8 required")
    ledger = Ledger(root / "ledger.sqlite3", policy=SlotPolicy(astra_capacity=astra_capacity))
    auth = ledger.authorize("RUN", event_id="explicit-evaluation-authorization", reason="User-authorized isolated control-only acceptance exercise", expected_revision=0)
    runtime = EvaluationRuntime(root, ledger)
    result = {"run": str(root), "started_at": now(), "success": False}
    failure = None
    api_url, flow_run_id = None, None
    try:
        with runtime_lock(root):
            ledger.require_operation("launch", authorization_revision=auth["revision"])
            version = runtime.manager.launch([str(executable), "--version"], kind="omp-version", cwd=root,
                                             authorization_revision=auth["revision"])
            runtime.register_process(version, auth["revision"])
        version.process.wait(timeout=30)
        proof = version.stop()
        ledger.record_process_exit(version.process_id, event_id="exit-" + version.process_id, proof=proof)
        stdout = Path(version.record["record_path"]).with_name("stdout.log").read_text(encoding="utf-8")
        if version.process.returncode != 0 or not re.search(r"\b18\.10\.1\b", stdout):
            raise SafetyError(f"This pilot pins OMP v18.10.1; observed {stdout!r}")
        save_json(root / "versions.json", {"python": sys.version, "python_executable": sys.executable,
                                          "prefect": importlib.metadata.version("prefect"), "omp_version_output": stdout,
                                          "omp_executable": str(executable), "omp_sha256": digest(executable),
                                          "dependency_freeze": str(BUILD / "dependencies" / "resolved-requirements.txt")})
        api_url = runtime.start_prefect(auth["revision"])
        # Import Prefect only after the isolated environment and owned API URL exist.
        from .flows import acceptance_flow
        scenarios = acceptance_flow(runtime, str(executable), astra_capacity)
        flow_run_id = scenarios["prefect_flow_run_id"]
        with urllib.request.urlopen(api_url + "/flow_runs/" + scenarios["prefect_flow_run_id"], timeout=15) as response:
            flow_record = json.load(response)
        save_json(root / "prefect-flow.json", flow_record)
        if flow_record["state"]["type"] != "COMPLETED":
            raise RuntimeError("Actual Prefect API does not report the bounded flow as completed")
        result.update(scenarios=scenarios, prefect_state=flow_record["state"], success=True)
    except BaseException as exc:
        failure = exc
        result.update(error=repr(exc), traceback=traceback.format_exc())
    finally:
        if api_url is not None:
            try:
                # Persist STOP/cancel work promptly, but retain the owned API
                # until already-produced client logs/events have been drained.
                runtime.stop(event_id="finite-command-work-stop",
                             reason="Stop work before draining existing Prefect client evidence", include_server=False)
                result["prefect_client_shutdown"] = drain_prefect_clients(root, api_url, flow_run_id)
            except BaseException as exc:
                result.update(success=False, prefect_client_shutdown_error=repr(exc),
                              prefect_client_shutdown_traceback=traceback.format_exc())
                failure = failure or exc
        try:
            runtime.stop(event_id="finite-command-final-stop", reason="Finite evaluation owns and shuts down every resource")
            final = read_snapshot(ledger.path)
            if final["authorization"]["mode"] != "STOPPED" or any(p["active"] for p in final["processes"].values()):
                raise SafetyError("Final shutdown did not prove all registered native processes exited")
            # A fresh ledger object and old authorization event cannot silently resume work.
            restarted = Ledger(ledger.path)
            restarted.authorize("RUN", event_id="explicit-evaluation-authorization", reason="User-authorized isolated control-only acceptance exercise", expected_revision=0)
            if restarted.authorization()["mode"] != "STOPPED":
                raise SafetyError("Queued duplicate authorization undid durable STOP")
            result["final_authorization"] = restarted.authorization()
            result["all_owned_processes_exited"] = True
        except BaseException as exc:
            result.update(success=False, shutdown_error=repr(exc), shutdown_traceback=traceback.format_exc())
            failure = failure or exc
        result["finished_at"] = now()
        save_json(root / "acceptance.json", result)
    if failure:
        raise RuntimeError(f"Evaluation failed; complete evidence retained at {root / 'acceptance.json'}") from failure
    return result


def run_tests(root: Path) -> dict:
    from .runtime import EvaluationRuntime
    from .state import Ledger
    ledger = Ledger(root / "ledger.sqlite3")
    revision = ledger.authorize("RUN", event_id="explicit-test-authorization",
                                reason="Explicit owned native behavioral test run", expected_revision=0)["revision"]
    runtime = EvaluationRuntime(root, ledger)
    runtime.environment.update(OMP_EVAL_TEST_AUTHORIZATION="isolated-fixtures",
                               PYTEST_DISABLE_PLUGIN_AUTOLOAD="1")
    argv = [sys.executable, "-B", "-m", "pytest", str(WORKTREE / "tools" / "orchestration_eval"),
            "-q", "-p", "no:cacheprovider", "--basetemp", str(root / "pytest-work")]
    report = {"argv": argv, "returncode": None, "stdout": "", "stderr": "", "started_at": now()}
    owned, failure = None, None
    try:
        owned = runtime.manager.launch(argv, kind="behavioral-tests", cwd=root, authorization_revision=revision)
        runtime.register_process(owned, revision)
        runtime.snapshot("behavioral-tests-active")
        report["returncode"] = owned.process.wait(timeout=300)
    except BaseException as exc:
        failure = exc
        report.update(error=repr(exc), traceback=traceback.format_exc())
    finally:
        try:
            runtime.stop(event_id="finite-test-final-stop",
                         reason="Finite test run owns and closes its actual pytest job and descendants")
            report["final_authorization"] = ledger.authorization()
            report["all_owned_processes_exited"] = all(
                record.get("exit_proof", {}).get("observed_exit") for record in runtime.manager.records())
            if report["final_authorization"]["mode"] != "STOPPED" or not report["all_owned_processes_exited"]:
                raise SafetyError("Behavioral run did not prove owned native exit")
        except BaseException as exc:
            failure = failure or exc
            report.update(shutdown_error=repr(exc), shutdown_traceback=traceback.format_exc())
        if owned is not None:
            logs = Path(owned.record["record_path"]).parent
            report.update(stdout=(logs / "stdout.log").read_text(encoding="utf-8", errors="replace"),
                          stderr=(logs / "stderr.log").read_text(encoding="utf-8", errors="replace"),
                          process_record=owned.record["record_path"])
        report["at"] = now()
        save_json(root / "behavioral-tests.json", report)
    if failure is not None or report["returncode"] != 0:
        raise RuntimeError(f"Behavioral regressions failed or stopped; retained {root / 'behavioral-tests.json'}") from failure
    return report


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", nargs="?", choices=("status", "exercise", "stop", "test"), default="status")
    parser.add_argument("--run-id")
    parser.add_argument("--authorize-isolated-evaluation", action="store_true")
    parser.add_argument("--astra-capacity", type=int)
    parser.add_argument("--omp", type=Path)
    args = parser.parse_args()
    check_worktree()
    if args.command == "status":
        print(json.dumps(status(select_root(args.run_id)), indent=2))
        return 0
    if not args.authorize_isolated_evaluation:
        parser.error("Mutating commands require --authorize-isolated-evaluation; no resources were started")
    if args.command == "stop":
        if not args.run_id:
            parser.error("Stop requires an exact owned --run-id; latest-run cancellation is forbidden")
        root = run_root(args.run_id)
        if not (root / "ledger.sqlite3").is_file():
            parser.error("No owned ledger exists for that run")
        configure(root)
        from .runtime import EvaluationRuntime
        from .state import Ledger
        result = EvaluationRuntime(root, Ledger(root / "ledger.sqlite3")).stop(event_id="explicit-stop-" + uuid.uuid4().hex,
                                                                             reason="Explicit owned-run cancellation")
    else:
        root = run_root(args.run_id or (args.command + "-" + uuid.uuid4().hex))
        if root.exists():
            parser.error("Run already exists; never overwrite/adopt sessions. Use status or exact-run stop")
        executable = (args.omp or Path(shutil.which("omp") or "omp.exe")).resolve()
        if args.command == "exercise" and (args.astra_capacity is None or args.astra_capacity < 1):
            parser.error("Exercise requires an explicit positive --astra-capacity; the canonical plan supplies none")
        if args.command == "exercise" and (not executable.is_file() or executable.name.lower() != "omp.exe"):
            parser.error("Provide the native OMP v18.10.1 executable via --omp")
        root.mkdir(parents=True)
        configure(root)
        save_json(root / "authorization.json", {"mode": "isolated-evaluation", "command": args.command, "created_at": now(),
                                                "protected_dashboard_port": 6200, "protected_processes": [94768, 11596],
                                                "no_provider_prompts": True, "no_production_mutation": True})
        result = exercise(root, executable, args.astra_capacity) if args.command == "exercise" else run_tests(root)
    print(json.dumps({"run": str(root), "result": result}, indent=2))
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (SafetyError, RuntimeError) as exc:
        print(str(exc), file=sys.stderr)
        raise SystemExit(1)
