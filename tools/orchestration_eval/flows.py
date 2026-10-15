"""Real Prefect tasks; explicit retries only after measured native-process exit."""
from __future__ import annotations

import json
from pathlib import Path
import sys
import uuid

from prefect import flow, task
from prefect.cache_policies import NO_CACHE

from .processes import runtime_lock
from .safety import confined, save_json


@task(name="owned-omp-fresh-control-session", retries=0, cache_policy=NO_CACHE, persist_result=False)
def launch_assignment(runtime, assignment_id: str, function: dict, executable: str, revision: int):
    return runtime.launch_assignment(assignment_id, function, Path(executable), revision=revision)


@task(name="owned-native-fixture-measurement", retries=0, cache_policy=NO_CACHE, persist_result=False)
def measure_fixture(runtime, repository: str, label: str, *, operation: str = "measure") -> dict:
    repository_path = confined(repository, runtime.root)
    output = confined(runtime.root / "measurements" / (label + ".json"))
    output.parent.mkdir(parents=True, exist_ok=True)
    revision = runtime.ledger.authorization()["revision"]
    with runtime_lock(runtime.root):
        runtime.ledger.require_operation("verify", authorization_revision=revision)
        owned = runtime.manager.launch(
            [sys.executable, "-B", str(repository_path / "probe.py"), operation,
             "--root", str(repository_path), "--output", str(output)],
            kind="fixture-measurement", cwd=repository_path, authorization_revision=revision,
        )
        runtime.register_process(owned, revision)
    try:
        code = owned.process.wait(timeout=30)
    finally:
        proof = owned.stop()
        runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)
    expected = 47 if operation == "tool-failure" else 0
    if code != expected:
        raise RuntimeError(f"Owned fixture returned {code}, expected {expected}; inspect {owned.record['record_path']}")
    result = json.loads(output.read_text(encoding="utf-8"))
    result.update(evidence_ref=str(output), exit_proof=proof, returncode=code)
    save_json(output.with_name(output.stem + "-receipt.json"), result)
    return result


@task(name="owned-git-publication-recovery", retries=0, cache_policy=NO_CACHE, persist_result=False)
def publish_fixture(runtime, request, event_id: str, *, fault_at: str | None = None,
                    stop_after_admission: str | None = None) -> dict:
    invocation = uuid.uuid4().hex
    directory = confined(runtime.root / "publication-invocations" / invocation)
    directory.mkdir(parents=True)
    request_path = directory / "request.json"
    output = directory / "result.json"
    save_json(request_path, request.to_dict())
    argv = [sys.executable, "-B", "-m", "tools.orchestration_eval.publication_child",
            "--root", str(runtime.root), "--request", str(request_path), "--output", str(output),
            "--event", event_id, "--authorize-isolated-evaluation"]
    if fault_at:
        argv.extend(["--fault", fault_at])
    if stop_after_admission:
        argv.extend(["--stop-after-admission", stop_after_admission])
    revision = runtime.ledger.authorization()["revision"]
    with runtime_lock(runtime.root):
        runtime.ledger.require_operation("publish", authorization_revision=revision)
        owned = runtime.manager.launch(argv, kind="publication", cwd=runtime.root,
                                       authorization_revision=revision, operation="publish")
        runtime.register_process(owned, revision, operation="publish")
    try:
        code = owned.process.wait(timeout=120)
    finally:
        proof = owned.stop()
        runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)
    expected = 75 if fault_at else 0
    if code != expected:
        raise RuntimeError(f"Publication returned {code}, expected {expected}; inspect {owned.record['record_path']}")
    result = json.loads(output.read_text(encoding="utf-8"))
    result.update(exit_proof=proof, result_ref=str(output))
    return result


@flow(name="bounded-native-prefect-omp-evaluation", retries=0, persist_result=False, validate_parameters=False)
def acceptance_flow(runtime, executable: str, astra_capacity: int) -> dict:
    from prefect.runtime import flow_run
    from .acceptance import exercise_scenarios
    result = exercise_scenarios(runtime, Path(executable), astra_capacity)
    result["prefect_flow_run_id"] = str(flow_run.id)
    return result
