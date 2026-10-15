"""Finite end-to-end pilot: real RPC, Windows jobs, Prefect, SQLite and local Git."""
from __future__ import annotations

from dataclasses import asdict
import json
from pathlib import Path
import sys
import threading
import time
import uuid

from .evidence import capture_inputs, validate_inputs
from .omp_rpc import OmpControl
from .policy import PolicyError, SlotPolicy
from .processes import ProcessManager, runtime_lock
from .publication import Fixture, FixtureScope, GitPublisher, PublicationError, initialize_fixture, prepare_publication, validate_fixture
from .safety import ACTIVE, WORKTREE, SafetyError, confined, digest, isolated_environment, now, save_json
from .state import Ledger, StateError, read_snapshot


def check(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)


def refused(action, *, exceptions=(SafetyError, PolicyError, StateError, PublicationError)) -> dict:
    try:
        action()
    except exceptions as exc:
        return {"refused": True, "type": type(exc).__name__, "reason": str(exc)}
    raise AssertionError("Unsafe or stale operation was not refused")


def exercise_stalled_startup(root: Path, astra_capacity: int) -> dict:
    """Keep the production startup lock held while a real owned child is stopped."""
    from .runtime import EvaluationRuntime

    root = confined(root)
    root.mkdir(parents=True)
    ledger = Ledger(root / "ledger.sqlite3", policy=SlotPolicy(astra_capacity=astra_capacity))
    revision = ledger.authorize("RUN", event_id="race-run", reason="Explicit stalled-startup process fixture",
                                expected_revision=0)["revision"]
    runtime = EvaluationRuntime(root, ledger)
    entered, release, stopped = threading.Event(), threading.Event(), threading.Event()
    processes, errors = [], []
    ready = root / "fixture-ready.json"

    def startup():
        try:
            # This is the same exclusion used by Prefect, assignment and retained
            # publisher startup. No fake RPC/server responses or workflow states.
            with runtime_lock(root):
                process = runtime.manager.launch(
                    [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "hold",
                     "--root", str(root), "--output", str(ready)],
                    kind="stalled-startup-fixture", cwd=root, authorization_revision=revision)
                processes.append(process)
                runtime.register_process(process, revision)
                deadline = time.monotonic() + 15
                while not ready.exists():
                    check(process.process.poll() is None and time.monotonic() < deadline,
                          "Stalled-startup fixture did not reach its actual native ready point")
                    time.sleep(0.02)
                entered.set()
                check(release.wait(30), "Stalled-startup regression did not release its owned thread")
        except BaseException as exc:
            errors.append(repr(exc))
            entered.set()

    def stopper():
        try:
            runtime.stop(event_id="race-stop", reason="STOP must bypass a stalled startup/handshake")
        except BaseException as exc:
            errors.append(repr(exc))
        finally:
            stopped.set()

    starting = threading.Thread(target=startup, daemon=True, name="owned-stalled-startup")
    stopping = threading.Thread(target=stopper, daemon=True, name="owned-startup-stopper")
    started_stop = False
    starting.start()
    try:
        check(entered.wait(20) and not errors and bool(processes), f"Native startup fixture failed: {errors}")
        began = time.monotonic()
        stopping.start()
        started_stop = True
        check(stopped.wait(12), "STOP waited for the stalled startup lock instead of cancelling its owned child")
        check(not errors, f"Stalled-startup cancellation failed: {errors}")
        check(starting.is_alive() and not release.is_set(), "Startup lock was released before STOP was proved")
        check(ledger.authorization()["mode"] == "STOPPED", "STOP was not durable while startup remained stalled")
        process = processes[0]
        check(process.process.poll() is not None, "Stalled startup's native child is still alive")
        before = json.loads((root / "snapshots" / "race-stop-stop-persisted.json").read_text(encoding="utf-8"))
        check(before["authorization"]["mode"] == "STOPPING" and before["processes"][process.process_id]["active"],
              "STOP was not recorded before native cancellation/lease release")
        queued = refused(lambda: runtime.manager.launch(
            [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "hold",
             "--root", str(root), "--output", str(root / "must-not-start.json")],
            kind="queued-stale-startup", cwd=root, authorization_revision=revision))
        check(len(runtime.manager.records()) == 1, "Queued stale startup created another native process")
        result = {"stop_seconds": time.monotonic() - began, "startup_lock_still_held": True,
                  "authorization": ledger.authorization(), "exit_proof": process.record["exit_proof"],
                  "queued_launch": queued, "evidence_ref": str(root / "stalled-startup-stop.json")}
        save_json(root / "stalled-startup-stop.json", result)
        return result
    finally:
        release.set()
        starting.join(timeout=15)
        if started_stop:
            stopping.join(timeout=20)
        runtime.stop(event_id="race-finalizer", reason="Retain fixture evidence and close all owned race resources")
        check(not starting.is_alive() and not stopping.is_alive(), "An owned race thread failed to exit")


def exercise_pre_assignment_failure(root: Path) -> dict:
    root = confined(root)
    root.mkdir(parents=True)
    manager = ProcessManager(root, isolated_environment(root))
    target_ready = root / "must-not-start.json"
    try:
        refusal = refused(lambda: manager.launch(
            [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "hold",
             "--root", str(root), "--output", str(target_ready)],
            kind="pre-assignment-fixture", cwd=root, fault_at="before_job_assignment"),
            exceptions=(RuntimeError,))
        receipts = list(manager.directory.glob("*/launch-failure.json"))
        check(len(receipts) == 1, "Native wrapper failure did not retain its exit receipt")
        proof = json.loads(receipts[0].read_text(encoding="utf-8"))
        check(proof.get("observed_exit") is True and proof.get("pid", 0) > 0,
              "Uncontained native wrapper exit was not actually observed")
        check(not proof["job_assigned"] and not proof["gate_released"] and not target_ready.exists()
              and not receipts[0].with_name("child.json").exists(),
              "A target escaped the pre-assignment bootstrap gate")
        result = {"refusal": refusal, "wrapper_exit": proof, "evidence_ref": str(receipts[0]),
                  "target_never_admitted": True}
        save_json(root / "pre-assignment-failure.json", result)
        return result
    finally:
        manager.stop_all()


def materialize_initial_fixture(root: Path, registration: Path, output: Path, name: str,
                                value: int, materialize_source: bool) -> None:
    """Run only inside the admitted setup job; checkpoints do not hold Git locks."""
    root, registration, output = confined(root), confined(registration, root), confined(output, root)
    ledger = Ledger(root / "ledger.sqlite3")
    deadline = time.monotonic() + 30
    while not registration.is_file():
        auth = ledger.authorization()
        ledger.require_operation("launch", authorization_revision=auth["revision"])
        if time.monotonic() >= deadline:
            raise TimeoutError("Setup owner did not durably register its contained process")
        time.sleep(0.01)
    admission = json.loads(registration.read_text(encoding="utf-8"))
    revision, process_id = admission["authorization_revision"], admission["process_id"]
    process = ledger.process(process_id)
    if not process["active"] or process["identity"] != admission["identity"] or process["operation"] != "launch":
        raise SafetyError("Fixture setup does not match its durable active process admission")
    sequence = 0
    def before_step(label):
        nonlocal sequence
        sequence += 1
        receipt = {"step": label, "process_id": process_id, "checked_at": now(),
                   "authorization_revision": revision,
                   "boundary": "Authorization checkpoint, not atomic per-step admission; an already checked effect may be in flight until job exit"}
        try:
            receipt["authorization"] = ledger.require_operation("materialize", authorization_revision=revision)
            receipt["allowed"] = True
        except (PolicyError, StateError) as exc:
            receipt.update(allowed=False, error=repr(exc))
            save_json(output.parent / f"step-{sequence:02}.json", receipt)
            raise
        save_json(output.parent / f"step-{sequence:02}.json", receipt)
    scope = FixtureScope(root, (ACTIVE, WORKTREE, ACTIVE / ".git"), authorized=True)
    fixture = initialize_fixture(scope, name, before_step=before_step)
    desired = f"int fixture_value() {{ return {value}; }}\n".encode("ascii")
    if materialize_source:
        before_step("materialize-source")
        (fixture.repository / "source.cpp").write_bytes(desired)
    before_step("materialize-probe")
    (fixture.repository / "probe.py").write_bytes(Path(__file__).with_name("fixture_process.py").read_bytes())
    before_step("materialize-expected")
    (fixture.repository / "expected.txt").write_bytes(desired)
    before_step("complete-setup")
    save_json(output, {"complete": True, "process_id": process_id, "authorization_revision": revision,
                      "fixture": str(fixture.root), "checks": sequence,
                      "boundary": "Whole setup is durably registered and job-contained; later steps check RUN without locks across effects",
                      "partial_failure_policy": "Retain partial roots and evidence; never adopt, overwrite or retry existing fixture roots"})


def initialize_runtime_fixture(runtime, name: str, *, value: int, materialize_source: bool = False) -> Fixture:
    """Own initialization and all initial fixture writes, not just later Git calls."""
    revision = runtime.ledger.authorization()["revision"]
    runtime.ledger.require_operation("launch", authorization_revision=revision)
    invocation = confined(runtime.root / "fixture-setup" / uuid.uuid4().hex)
    output, registration = invocation / "result.json", invocation / "registration.json"
    argv = [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", "initialize-fixture",
            "--root", str(runtime.root), "--output", str(output), "--registration", str(registration),
            "--fixture-name", name, "--fixture-value", str(value)]
    if materialize_source:
        argv.append("--materialize-source")
    owned = runtime.manager.launch(argv, kind="fixture-setup", cwd=runtime.root, authorization_revision=revision)
    try:
        process = runtime.register_process(owned, revision)
        save_json(registration, {"process_id": owned.process_id, "identity": process["identity"],
                                 "authorization_revision": revision})
        code = owned.process.wait(timeout=120)
    finally:
        proof = owned.stop(grace=0)
        if any(p["process_id"] == owned.process_id for p in runtime.ledger.processes()):
            runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)
    if code:
        raise RuntimeError(f"Initial fixture setup failed ({code}); partial evidence retained at {invocation}; process {owned.record['record_path']}")
    result = json.loads(output.read_text(encoding="utf-8"))
    root = confined(runtime.root / "fixtures" / name, runtime.root)
    if result.get("complete") is not True or result.get("process_id") != owned.process_id or result.get("fixture") != str(root):
        raise SafetyError("Initial fixture setup did not return a complete matching owned receipt")
    fixture = Fixture(root / "repository", root / "remote.git", root / "evidence")
    validate_fixture(FixtureScope(runtime.root, (ACTIVE, WORKTREE, ACTIVE / ".git"), authorized=True), fixture)
    return fixture


def fixture_git(runtime, scope, fixture, arguments: list[str], *, bare=False) -> str:
    validate_fixture(scope, fixture)
    if not arguments:
        raise SafetyError("A fixture Git command is required")
    # Existing publication observations may run in PUBLISH_EXISTING; owner
    # preparation (including add/commit) requires RUN. Neither dispatches in STOP.
    operation = "publish" if arguments[0] in ("rev-parse", "rev-list") else "launch"
    revision = runtime.ledger.authorization()["revision"]
    directory = fixture.remote if bare else fixture.repository
    argv = ["git", "-C", str(directory), "-c", "core.autocrlf=false", "-c", "core.fsmonitor=false",
            "-c", "core.longpaths=true", "-c", "user.name=Evaluation fixture",
            "-c", "user.email=evaluation@invalid.local",
            "-c", f"core.hooksPath={fixture.evidence_dir / 'disabled-hooks'}", *arguments]
    owned = runtime.manager.launch(argv, kind="fixture-git", cwd=directory,
                                   authorization_revision=revision, operation=operation)
    try:
        runtime.register_process(owned, revision, operation=operation)
        code = owned.process.wait(timeout=30)
    finally:
        proof = owned.stop(grace=0)
        if any(p["process_id"] == owned.process_id for p in runtime.ledger.processes()):
            runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)
    logs = Path(owned.record["record_path"]).parent
    stdout = (logs / "stdout.log").read_text(encoding="utf-8", errors="replace")
    stderr = (logs / "stderr.log").read_text(encoding="utf-8", errors="replace")
    record = {"at": now(), "argv": argv, "returncode": code, "stdout": stdout, "stderr": stderr,
              "process_id": owned.process_id, "exit_proof": proof, "authorization_revision": revision}
    with (fixture.evidence_dir / "acceptance-git.jsonl").open("a", encoding="utf-8") as stream:
        stream.write(json.dumps(record) + "\n")
    if code:
        raise RuntimeError(f"Fixture Git failed: {record}")
    return stdout.strip()


def slot_exercise(root: Path, astra_capacity: int) -> dict:
    ledger = Ledger(root / "policy-fixtures" / "nominal.sqlite3", policy=SlotPolicy(astra_capacity=astra_capacity))
    revision = ledger.authorize("RUN", event_id="nominal-run", reason="Explicit policy-only fixtures", expected_revision=0)["revision"]
    for stage, count in (("sol", 8), ("glm", 2), ("qwen", 3), ("astra", astra_capacity)):
        for number in range(count):
            ledger.register_session(session_id=f"policy-{stage}-{number}", owner_id=f"policy-owner-{stage}-{number}",
                                    stage=stage, provider="policy-fixture-only", model=stage + "-slot-fixture",
                                    event_id=f"slot-{stage}-{number}", authorization_revision=revision)
        refused(lambda stage=stage: ledger.register_session(
            session_id="overflow-" + stage, owner_id="overflow-owner-" + stage, stage=stage,
            provider="policy-fixture-only", model=stage + "-slot-fixture", event_id="overflow-" + stage,
            authorization_revision=revision))
    ledger.register_publisher(owner_id="policy-publisher", session_id="policy-publisher-session",
                              provider="policy-fixture-only", model="sol-slot-fixture", event_id="publisher-slot",
                              authorization_revision=revision)
    override = Ledger(root / "policy-fixtures" / "override.sqlite3",
                      policy=SlotPolicy(astra_capacity=astra_capacity, overrides={"glm": 3}, paused=("qwen",)))
    rev = override.authorize("RUN", event_id="override-run", reason="Explicit evaluation override fixture", expected_revision=0)["revision"]
    for number in range(3):
        override.register_session(session_id=f"override-glm-{number}", owner_id=f"override-owner-{number}",
                                  stage="glm", provider="policy-fixture-only", model="glm-slot-fixture",
                                  event_id=f"override-{number}", authorization_revision=rev)
    paused = refused(lambda: override.register_session(session_id="paused-qwen", owner_id="paused-owner", stage="qwen",
                                                       provider="policy-fixture-only", model="qwen-slot-fixture",
                                                       event_id="paused", authorization_revision=rev))
    check(Ledger(override.path).policy.as_dict() == override.policy.as_dict(), "Explicit policy did not survive reopening")
    default = SlotPolicy()
    absent_astra = refused(lambda: default.capacity("astra"))
    result = {"nominal": ledger.snapshot(), "explicit_override": override.snapshot(), "paused_refusal": paused,
              "implicit_astra_refusal": absent_astra, "qualification": "Policy metadata fixtures; no live workers or provider sessions consumed"}
    save_json(root / "slot-policy.json", result)
    return result


def run_native_safety_fixture(runtime, operation: str, root: Path, *, astra_capacity=None, effect=None) -> dict:
    """Contain nested fixture jobs in an admitted parent-run process as well."""
    revision = runtime.ledger.authorization()["revision"]
    output = runtime.root / "native-safety-receipts" / (operation + "-" + uuid.uuid4().hex + ".json")
    argv = [sys.executable, "-B", "-m", "tools.orchestration_eval.fixture_process", operation,
            "--root", str(confined(root, runtime.root)), "--output", str(output)]
    if astra_capacity is not None:
        argv += ["--astra-capacity", str(astra_capacity)]
    if effect is not None:
        argv += ["--effect", effect]
    owned = runtime.manager.launch(argv, kind="native-safety-fixture", cwd=runtime.root,
                                   authorization_revision=revision)
    try:
        runtime.register_process(owned, revision)
        code = owned.process.wait(timeout=90)
    finally:
        proof = owned.stop(grace=0)
        if any(p["process_id"] == owned.process_id for p in runtime.ledger.processes()):
            runtime.ledger.record_process_exit(owned.process_id, event_id="exit-" + owned.process_id, proof=proof)
    if code:
        raise RuntimeError(f"Native safety fixture failed ({code}); inspect {owned.record['record_path']}")
    result = json.loads(output.read_text(encoding="utf-8"))
    result.update(parent_run_exit_proof=proof, result_ref=str(output))
    return result


def exercise_publication_stop(root: Path, kind: str) -> dict:
    """Recover real admitted Git effects after a STOP and native hard crash."""
    from .flows import measure_fixture, publish_fixture
    from .runtime import EvaluationRuntime

    if kind not in ("commit", "push"):
        raise ValueError("Native publication race requires commit or push")
    root = confined(root)
    root.mkdir(parents=True)
    ledger = Ledger(root / "ledger.sqlite3")
    revision = ledger.authorize("RUN", event_id="native-publication-run",
                                reason="Independent actual Git/STOP fixture", expected_revision=0)["revision"]
    runtime = EvaluationRuntime(root, ledger)
    scope = FixtureScope(root, (ACTIVE, WORKTREE, ACTIVE / ".git"), authorized=True)
    fixture = initialize_runtime_fixture(runtime, "p", value=7, materialize_source=True)
    repo = fixture.repository
    branch_ref = repo / ".git" / "refs" / "heads" / fixture.branch
    remote_ref = fixture.remote / "refs" / "heads" / fixture.branch
    baseline = branch_ref.read_text(encoding="ascii").strip()
    recipe = {"operation": "native-byte-identity-fixture", "python": str(Path(sys.executable).resolve()),
              "python_sha256": digest(Path(sys.executable)), "scope": "evaluation_fixture"}
    manifest = capture_inputs(repo, {"source": ["source.cpp"], "header": ["shared.h"],
                                    "config": ["config.json", "expected.txt"],
                                    "tool": ["tool.txt", "probe.py"]}, recipe)
    recipe_ref = root / "inputs.json"
    save_json(recipe_ref, manifest.to_dict())
    assignment, owner = "native-stop-" + kind, "native-fixture-owner-" + kind
    ledger.create_assignment(assignment_id=assignment, function={"symbol": assignment, "scope": "evaluation_fixture"},
                             stage="sol", provider="native-fixture-only", model="git-effect-fixture",
                             owner_id=owner, session_id="metadata-only-" + uuid.uuid4().hex,
                             event_id="native-assignment", authorization_revision=revision)
    try:
        # Calling the underlying functions avoids an implicit Prefect server
        # when this same native exercise is used by focused behavioral tests.
        measured = measure_fixture.fn(runtime, str(repo), "native-publication-inputs")
        check(measured["source_matches_target"], "Native publication fixture measurement did not match")
        ledger.record_attempt(assignment, event_id="native-measurement", candidate_id="candidate",
                              source_ref={"path": str(repo / "source.cpp"), "sha256": digest(repo / "source.cpp")},
                              input_identity=manifest.identity, recipe_ref=str(recipe_ref), outcome="matching",
                              evidence_refs=[measured["evidence_ref"]], quality=measured["matching_bytes"],
                              authorization_revision=revision)
        ledger.record_verification(assignment, event_id="native-verification", candidate_id="candidate",
                                   input_identity=manifest.identity, authorization_revision=revision,
                                   evidence={"scope": "evaluation_fixture", "checks": {"native_bytes": measured["evidence_ref"]},
                                             "runtime_status": "exercised", "runtime_ref": measured["evidence_ref"]})
        request = prepare_publication(fixture, assignment, ["source.cpp", "probe.py", "expected.txt"], manifest)
        binding = {"input_identity": manifest.identity, "publication_target": request.publication_target,
                   "request_digest": request.request_digest, "evidence_refs": [measured["evidence_ref"]]}
        ledger.transition(assignment, "review_wait", event_id="native-review-wait", details={}, authorization_revision=revision)
        ledger.transition(assignment, "reconciling", event_id="native-review", authorization_revision=revision,
                          details={"review": {**binding, "approved_by": "evaluation-parent-review-fixture"}})
        ledger.transition(assignment, "publication_wait", event_id="native-materialization", authorization_revision=revision,
                          details={"materialization": {**binding, "owner_id": owner, "patch_identity": request.patch_identity}})
        before_index = digest(repo / ".git/index")
        crashed = publish_fixture.fn(runtime, request, "native-completion", fault_at="after_" + kind,
                                      stop_after_admission=kind)
        stop_ref = Path(crashed["result_ref"]).with_name("stop-after-admission.json")
        stopped = json.loads(stop_ref.read_text(encoding="utf-8"))
        check(stopped["admission"]["execute"] and stopped["authorization"]["mode"] == "STOPPING",
              "Native Git effect was not ordered after durable admission and STOP")
        check(crashed["exit_proof"]["observed_exit"] and crashed["exit_proof"]["exit_code"] == 75,
              "Publication crash did not prove actual native-process exit")
        ledger = runtime.ledger = Ledger(ledger.path)
        authorization_before = ledger.authorization()
        effects_before = ledger.publication_effects(assignment)
        admitted = next(effect for effect in effects_before if effect["kind"] == kind)
        check(not admitted["observations"], "Hard crash did not precede the admitted outcome receipt")
        actual_commit = branch_ref.read_text(encoding="ascii").strip()
        actual_remote = remote_ref.read_text(encoding="ascii").strip()
        check(actual_commit != baseline and actual_commit == admitted["planned_commit"], "Actual local Git effect is missing")
        check(actual_remote == (actual_commit if kind == "push" else baseline), "Actual remote outcome differs from admitted step")
        publisher = GitPublisher(scope, ledger, root / "publication")
        recovered = publisher.recover(request, event_id="native-stopped-recovery")
        repeated = publisher.recover(request, event_id="native-stopped-recovery-duplicate")
        check(recovered is not None and repeated is not None, "STOP recovery lost the admitted Git outcome")
        check(recovered.commit_id == repeated.commit_id == actual_commit and recovered.pushed == (kind == "push"),
              "STOP recovery fabricated or lost actual commit/push state")
        check(ledger.authorization() == authorization_before, "Observation-only recovery changed STOP authorization")
        effects_after = ledger.publication_effects(assignment)
        check(len(effects_after) == len(effects_before) and
              next(effect for effect in effects_after if effect["kind"] == kind)["observations"],
              "STOP recovery failed to record the existing admission or admitted new work")
        process_count = len(runtime.manager.records())
        refused_launch = refused(lambda: publish_fixture.fn(runtime, request, "must-not-launch-after-stop"))
        check(len(runtime.manager.records()) == process_count, "STOP recovery launched a new publication worker")
        check(branch_ref.read_text(encoding="ascii").strip() == actual_commit and
              remote_ref.read_text(encoding="ascii").strip() == actual_remote and
              digest(repo / ".git/index") == before_index, "Recovery mutated Git refs or unrelated staging")
        result = {"kind": kind, "baseline": baseline, "actual_commit": actual_commit, "actual_remote": actual_remote,
                  "stop_receipt": stopped, "crash": crashed, "recovered": asdict(recovered),
                  "effects_before_recovery": effects_before, "effects_after_recovery": effects_after,
                  "fresh_publication_launch_refused": refused_launch, "stop_receipt_ref": str(stop_ref),
                  "qualification": "Actual native Git effects and metadata-only assignment; no OMP/provider session created"}
    finally:
        runtime.stop(event_id="native-publication-final-stop", reason="Close only this actual Git/STOP fixture")
    result["final_authorization"] = ledger.authorization()
    result["all_owned_processes_exited"] = all(record.get("exit_proof", {}).get("observed_exit")
                                               for record in runtime.manager.records())
    check(result["final_authorization"]["mode"] == "STOPPED" and result["all_owned_processes_exited"],
          "Native publication/STOP fixture left owned work alive")
    save_json(root / "publication-stop-recovery.json", result)
    return result


def exercise_scenarios(runtime, executable: Path, astra_capacity: int) -> dict:
    from .flows import launch_assignment, measure_fixture, publish_fixture

    ledger = runtime.ledger
    revision = ledger.authorization()["revision"]
    scope = FixtureScope(runtime.root, (ACTIVE, WORKTREE, ACTIVE / ".git"), authorized=True)
    fixture = initialize_runtime_fixture(runtime, "assignment-publication", value=2)
    repo = fixture.repository
    desired = b"int fixture_value() { return 2; }\n"
    recipe = {"operation": "exact-byte-identity-and-native-process", "python": str(Path(sys.executable).resolve()),
              "python_sha256": digest(Path(sys.executable)), "argv": ["probe.py", "measure", "--root", str(repo)],
              "scope": "evaluation_fixture", "not_cpp_semantic_verification": True}
    recipe_ref = runtime.root / "recipe.json"
    save_json(recipe_ref, recipe)
    inputs = {"source": ["source.cpp"], "header": ["shared.h"], "config": ["config.json", "expected.txt"],
              "tool": ["tool.txt", "probe.py"]}

    function = {"module": "independent-fixture", "symbol": "fixture_value", "scope": "evaluation_fixture"}
    first = launch_assignment(runtime, "function-a", function, str(executable), revision)
    ledger.transition("function-a", "reconstructing", event_id="reconstruction-start", details={}, authorization_revision=revision)
    runtime.snapshot("reconstructing")
    immutable = runtime.root / "candidates"
    immutable.mkdir()
    source0 = immutable / "candidate-0.cpp"
    source0.write_bytes((repo / "source.cpp").read_bytes())
    manifest0 = capture_inputs(repo, inputs, recipe)
    measurement0 = measure_fixture(runtime, str(repo), "initial")
    check(not measurement0["source_matches_target"], "Initial fixture must genuinely differ")
    ledger.record_attempt("function-a", event_id="initial-measurement", candidate_id="candidate-0",
                          source_ref={"path": str(source0), "sha256": digest(source0)}, input_identity=manifest0.identity,
                          recipe_ref=str(recipe_ref), outcome="nonmatching", evidence_refs=[measurement0["evidence_ref"]],
                          quality=measurement0["matching_bytes"], authorization_revision=revision)
    failed = measure_fixture(runtime, str(repo), "infrastructure-failure", operation="tool-failure")
    ledger.record_attempt("function-a", event_id="infrastructure-attempt", candidate_id="candidate-0",
                          source_ref={"path": str(source0), "sha256": digest(source0)}, input_identity=manifest0.identity,
                          recipe_ref=str(recipe_ref), outcome="tool_failed", evidence_refs=[failed["evidence_ref"]],
                          authorization_revision=revision)
    check(ledger.assignment("function-a")["stages"][0]["corrections"] == 0, "Infrastructure failure consumed correction")
    runtime.snapshot("tool-infrastructure-blocked")
    ledger.transition("function-a", "reconstructing", event_id="tool-recovered", details={}, authorization_revision=revision)
    (repo / "source.cpp").write_bytes(desired)  # Fixture owner materialization, not production source integration.
    source1 = immutable / "candidate-1.cpp"
    source1.write_bytes(desired)

    def verify(label):
        manifest = capture_inputs(repo, inputs, recipe)
        measured = measure_fixture(runtime, str(repo), label)
        check(measured["source_matches_target"], "Measured candidate does not equal fixture target")
        ledger.record_attempt("function-a", event_id=label + "-attempt", candidate_id="candidate-1",
                              source_ref={"path": str(source1), "sha256": digest(source1)}, input_identity=manifest.identity,
                              recipe_ref=str(recipe_ref), outcome="matching", evidence_refs=[measured["evidence_ref"]],
                              quality=measured["matching_bytes"], authorization_revision=revision)
        runtime.snapshot(label + "-verifying")
        kwargs = dict(event_id=label + "-verification", candidate_id="candidate-1", input_identity=manifest.identity,
                      evidence={"scope": "evaluation_fixture", "checks": {"fixture_measurement": measured["evidence_ref"]},
                                "runtime_status": "exercised", "runtime_ref": measured["evidence_ref"]},
                      authorization_revision=revision)
        first_receipt = ledger.record_verification("function-a", **kwargs)
        check(ledger.record_verification("function-a", **kwargs) == first_receipt, "Duplicate completion changed receipt")
        ledger.transition("function-a", "review_wait", event_id=label + "-review-wait", details={}, authorization_revision=revision)
        runtime.snapshot(label + "-review-wait")
        return manifest

    manifest1 = verify("corrected")
    duplicate = launch_assignment(runtime, "function-a", function, str(executable), revision)
    check(duplicate["session_id"] == first["session_id"] and len(ledger.assignments()) == 1, "Duplicate completion launched another owner")
    second = launch_assignment(runtime, "function-b", {"module": "independent-fixture", "symbol": "another_value", "scope": "evaluation_fixture"},
                               str(executable), revision)
    check(second["session_id"] != first["session_id"] and second["owner_id"] != first["owner_id"], "New function reused owner/session")
    check(second["stage"] == "sol" and second["stages"][0]["model"] == "gpt-6.1-sol", "Wrong native control model slot")

    head_before = fixture_git(runtime, scope, fixture, ["rev-parse", "HEAD"])
    (repo / "unrelated.txt").write_text("unrelated committed edit\n", encoding="utf-8")
    fixture_git(runtime, scope, fixture, ["add", "--", "unrelated.txt"])
    fixture_git(runtime, scope, fixture, ["commit", "-m", "Unrelated evaluation input change"])
    check(fixture_git(runtime, scope, fixture, ["rev-parse", "HEAD"]) != head_before, "Unrelated fixture commit did not happen")
    unaffected = validate_inputs(repo, manifest1)
    check(unaffected.valid and unaffected.current_identity == manifest1.identity, "HEAD-only change invalidated valid evidence")
    save_json(runtime.root / "unrelated-input-check.json", asdict(unaffected))
    ledger.check_input_identity("function-a", event_id="unrelated-input", input_identity=unaffected.current_identity,
                                evidence_ref=str(runtime.root / "unrelated-input-check.json"))

    def approve(manifest, label, paths):
        request = prepare_publication(fixture, "function-a", paths, manifest)
        approval_ref = runtime.root / (label + "-fixture-review.json")
        save_json(approval_ref, {"qualification": "Deterministic evaluation parent-review fixture, not production approval",
                                "owner_id": first["owner_id"], "inputs": manifest.to_dict(), "request": request.to_dict()})
        ledger.transition("function-a", "reconciling", event_id=label + "-review", authorization_revision=revision,
                          details={"review": {"approved_by": "evaluation-parent-review-fixture", "input_identity": manifest.identity,
                                              "publication_target": request.publication_target,
                                              "request_digest": request.request_digest,
                                              "evidence_refs": [str(approval_ref)]}})
        ledger.transition("function-a", "publication_wait", event_id=label + "-materialized", authorization_revision=revision,
                          details={"materialization": {"owner_id": first["owner_id"], "input_identity": manifest.identity,
                                                       "publication_target": request.publication_target,
                                                       "request_digest": request.request_digest,
                                                       "patch_identity": request.patch_identity, "evidence_refs": [str(approval_ref)]}})
        runtime.snapshot(label + "-publication-wait")
        return request

    stale_request = approve(manifest1, "first", ["source.cpp", "probe.py", "expected.txt"])
    (repo / "shared.h").write_bytes(b"#define FIXTURE_VALUE 2\n")
    changed = validate_inputs(repo, manifest1)
    check(not changed.valid and "shared.h" in changed.changed, "Shared input change failed to invalidate evidence")
    stale_refusal = refused(lambda: GitPublisher(scope, ledger, runtime.root / "publication").publish(stale_request, event_id="stale-publication"))
    save_json(runtime.root / "relevant-input-check.json", {"validation": asdict(changed), "publication_refusal": stale_refusal})
    ledger.check_input_identity("function-a", event_id="relevant-input", input_identity=changed.current_identity,
                                evidence_ref=str(runtime.root / "relevant-input-check.json"))
    check(not ledger.assignment("function-a")["verification"]["valid"], "Ledger kept stale verification valid")
    manifest2 = verify("shared-input-reverified")
    request = approve(manifest2, "reverified", ["source.cpp", "shared.h", "probe.py", "expected.txt"])
    check(ledger.assignment("function-a")["stages"][0]["corrections"] == 1, "Reverification counted a new candidate")

    with runtime_lock(runtime.root):
        ledger.require_operation("launch", authorization_revision=revision)
        publisher_control = OmpControl(runtime.manager, executable, provider="openai-codex", model="gpt-6.1-sol",
                                       authorization_revision=revision)
        publisher_state = publisher_control.fresh_session()
        publisher_identity = ledger.register_publisher(owner_id="evaluation-retained-publisher", session_id=publisher_state["sessionId"],
                                                       provider="openai-codex", model="gpt-6.1-sol", event_id="retained-publisher",
                                                       authorization_revision=revision)
        runtime.register_process(publisher_control.owned, revision, publisher_state["sessionId"])
        runtime.controls["publisher"] = publisher_control

    # A held, independent process proves publication does not take a global work lease.
    hold_output = runtime.root / "held-fixture.json"
    with runtime_lock(runtime.root):
        ledger.require_operation("launch", authorization_revision=revision)
        holder = runtime.manager.launch([sys.executable, "-B", str(repo / "probe.py"), "hold", "--root", str(repo), "--output", str(hold_output)],
                                        kind="held-fixture", cwd=repo, authorization_revision=revision)
        runtime.register_process(holder, revision)
    deadline = time.monotonic() + 15
    while not hold_output.exists():
        check(holder.process.poll() is None and time.monotonic() < deadline, "Owned held fixture never started")
        time.sleep(0.05)
    (repo / "unrelated.txt").write_text("independently staged work remains\n", encoding="utf-8")
    fixture_git(runtime, scope, fixture, ["add", "--", "unrelated.txt"])
    preserved_index, preserved_work = digest(repo / ".git" / "index"), digest(repo / "unrelated.txt")
    before_restart = ledger.assignment("function-a")
    publish_mode = ledger.authorize("PUBLISH_EXISTING", event_id="publish-only", reason="Publish materialized fixture only", expected_revision=revision)
    launch_denied = refused(lambda: runtime.launch_assignment("not-permitted", {"symbol": "no-wake"}, executable, revision=publish_mode["revision"]))
    refused(lambda: ledger.require_operation("resume", authorization_revision=publish_mode["revision"]))
    committed_crash = publish_fixture(runtime, request, "completion-event", fault_at="after_commit")
    actual_commit = fixture_git(runtime, scope, fixture, ["rev-parse", "HEAD"])
    check(fixture_git(runtime, scope, fixture, ["rev-parse", "refs/heads/main"], bare=True) != actual_commit, "Commit-only crash unexpectedly pushed")
    ledger = runtime.ledger = Ledger(ledger.path)
    recovered_before_push = ledger.assignment("function-a")
    check(recovered_before_push["stages"] == before_restart["stages"] and recovered_before_push["best_candidate"] == before_restart["best_candidate"],
          "Restart lost candidate or attempt history")
    pushed_crash = publish_fixture(runtime, request, "completion-event", fault_at="after_push")
    check(fixture_git(runtime, scope, fixture, ["rev-parse", "refs/heads/main"], bare=True) == actual_commit, "Actual push was not observed")
    runtime.snapshot("committed-checkpoint-awaiting-push-ack")
    ledger = runtime.ledger = Ledger(ledger.path)
    recovered = publish_fixture(runtime, request, "completion-event")
    duplicate_publication = publish_fixture(runtime, request, "duplicate-completion-event")
    check(recovered["commit_id"] == duplicate_publication["commit_id"] == actual_commit and recovered["pushed"], "Recovery duplicated or lost commit/push")
    commit_count = fixture_git(runtime, scope, fixture, ["rev-list", "--count", "--grep=OMP-Evaluation-Assignment: function-a", "HEAD"])
    check(commit_count == "1", "Duplicate completion created more than one assignment commit")
    check(digest(repo / ".git" / "index") == preserved_index and digest(repo / "unrelated.txt") == preserved_work,
          "Publication changed unrelated index or working bytes")
    check(holder.process.poll() is None, "Publication serialized/killed independent work")

    checkpoint_report = runtime.root / "checkpoint-report.json"
    save_json(checkpoint_report, {"source_commit": actual_commit, "accepted_credit": 0, "fixture_only": True, "publication": recovered})
    for number in (1, 2):
        ledger.publisher_checkpoint(event_id=f"checkpoint-{number}", checkpoint_id=f"checkpoint-{number}",
                                    record={"source_commit": actual_commit, "report_ref": str(checkpoint_report), "observation_ref": recovered["observation_ref"]})
    retained = ledger.snapshot()["publisher"]
    check(retained["session_id"] == publisher_identity["session_id"] and retained["status"] == "awaiting-parent" and len(retained["checkpoints"]) == 2,
          "Publisher checkpoint closed/replaced its dedicated role")
    runtime.snapshot("published-checkpoint")

    revision = ledger.authorize("RUN", event_id="cleanup-authorized", reason="Fixture acknowledgment and evidence-preserving owner cleanup", expected_revision=publish_mode["revision"])["revision"]
    ledger.transition("function-a", "publication_acknowledged", event_id="source-ack", authorization_revision=revision,
                      details={"acknowledgment": {"commit": actual_commit, "branch": "main", "patch_identity": request.patch_identity,
                                                   "input_identity": manifest2.identity, "acknowledged_by": "evaluation-parent-review-fixture"}})
    ledger.transition("function-a", "cleanup", event_id="owner-cleanup", details={}, authorization_revision=revision)
    close_refusal = refused(lambda: ledger.transition("function-a", "closed", event_id="unsafe-close", authorization_revision=revision,
        details={"cleanup": {"retained_evidence_refs": [str(checkpoint_report)], "shared_link_checks_ref": str(checkpoint_report),
                              "original_input_checks_ref": str(checkpoint_report), "removed_paths": [], "removed_bytes": 0}}))
    runtime.close_control("function-a")
    cleanup = runtime.root / "owner-cleanup.json"
    save_json(cleanup, {"retained_evidence_refs": [str(checkpoint_report), str(source0), str(source1)],
                        "shared_link_checks_ref": recovered["observation_ref"], "original_input_checks_ref": str(recipe_ref),
                        "removed_paths": [], "removed_bytes": 0, "qualification": "All evaluation evidence preserved; no game inputs used"})
    ledger.transition("function-a", "closed", event_id="owner-closed", authorization_revision=revision,
                      details={"cleanup": json.loads(cleanup.read_text(encoding="utf-8"))})

    protected = {"active_checkout": refused(lambda: scope.check_path(ACTIVE)),
                 "active_common_git": refused(lambda: scope.check_path(ACTIVE / ".git")),
                 "active_worktree": refused(lambda: scope.check_path(WORKTREE)),
                 "external_processes": [refused(lambda pid=pid: runtime.manager.terminate_registered("external-pid-" + str(pid))) for pid in (94768, 11596)],
                 "external_session": refused(lambda: publisher_control.request("open_session", sessionDir=str(ACTIVE))),
                 "provider_prompt": refused(lambda: publisher_control.request("prompt", message="not transmitted"))}
    save_json(runtime.root / "protected-refusals.json", protected)
    slot_exercise(runtime.root, astra_capacity)
    stalled_startup = run_native_safety_fixture(runtime, "startup-stop", runtime.root / "startup-stop-race",
                                               astra_capacity=astra_capacity)
    pre_assignment_failure = run_native_safety_fixture(runtime, "pre-assignment", runtime.root / "pre-assignment-failure")
    stopped_publication = {kind: run_native_safety_fixture(runtime, "publication-stop", runtime.root / ("stop-" + kind),
                                                          effect=kind) for kind in ("commit", "push")}
    research = ledger.authorize("RESEARCH", event_id="research-mode", reason="Read-only research fixture", expected_revision=revision)
    ledger.require_operation("research", authorization_revision=research["revision"])
    refused(lambda: ledger.require_operation("publish", authorization_revision=research["revision"]))
    refused(lambda: ledger.require_operation("launch", authorization_revision=research["revision"]))
    runtime.stop(event_id="acceptance-stop", reason="Persist STOP before owned process cancellation", include_server=False)
    stopped_snapshot = read_snapshot(ledger.path)
    check(stopped_snapshot["authorization"]["mode"] == "STOPPING", "Stop was not durable before server shutdown")
    stopped_index = digest(repo / ".git/index")
    refused_fixture_git = refused(lambda: fixture_git(runtime, scope, fixture, ["add", "--", "source.cpp"]))
    check(digest(repo / ".git/index") == stopped_index, "STOP allowed a new fixture Git staging mutation")
    queued = refused(lambda: launch_assignment(runtime, "queued-after-stop", {"symbol": "queued"}, str(executable), revision))
    refused(lambda: Ledger(ledger.path).require_operation("resume", authorization_revision=revision))
    refused(lambda: runtime.launch_assignment("function-a", function, executable, revision=revision))
    check(holder.process.poll() is not None, "STOP relied on workflow status rather than actual held-process exit")
    check(all(not p["active"] for p in ledger.processes() if p["process_id"] != next(r["process_id"] for r in runtime.manager.records() if r["kind"] == "prefect-server")),
          "Work leases released without native process exit")
    result = {"scenarios": {
        "duplicate_completion": {"assignment_count": len(ledger.assignments()), "assignment_commit_count": int(commit_count), "commit": actual_commit},
        "stop_precedes_cancellation": {"queued_launch": queued, "fixture_git_refused": refused_fixture_git,
                                      "fixture_index_preserved": stopped_index,
                                      "work_exit_proofs": str(runtime.root / "work-shutdown.json")},
        "stop_during_stalled_startup": stalled_startup,
        "wrapper_failure_before_job_assignment": pre_assignment_failure,
        "fresh_owner_session_model": {"first": first, "second": second},
        "restart_commit_push_recovery": {"commit_crash": committed_crash, "push_crash": pushed_crash, "recovered": recovered},
        "admitted_git_effect_recovery_after_stop": stopped_publication,
        "unrelated_commit_reuses_evidence": asdict(unaffected), "relevant_input_reverification": asdict(changed),
        "status_distinctions": ["reconstructing", "verifying", "review_wait", "publication_wait", "blocked", "committed", "pushed"],
        "protected_resources": protected, "publisher_retained": retained, "unsafe_close_refused": close_refusal,
        "publication_only_cannot_wake_owner": launch_denied},
        "accepted_reconstruction_credit": 0, "qualification": "Real infrastructure and fixture measurements only; no C++ semantic correctness or production orchestration claim",
        "completed_at": now()}
    save_json(runtime.root / "scenario-results.json", result)
    return result
