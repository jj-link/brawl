"""Actual deterministic measurement/holding processes; never C++ semantic verification."""
from __future__ import annotations

from contextlib import contextmanager, nullcontext
import argparse
import hashlib
import json
import os
from pathlib import Path
import socket
import sys
import threading
import time

from tools.orchestration_eval.safety import confined


@contextmanager
def setup_test_boundary(root: Path, boundary: str):
    """Pause the real initializer after native Git, only for explicit fault fixtures."""
    from tools.orchestration_eval import publication
    from tools.orchestration_eval.safety import save_json
    from tools.orchestration_eval.state import Ledger
    original = publication._git
    calls = 0
    def observed_git(repository, arguments, evidence_dir, **kwargs):
        nonlocal calls
        ledger = Ledger(root / "ledger.sqlite3")
        before = ledger.authorization()
        result = original(repository, arguments, evidence_dir, **kwargs)
        calls += 1
        observation = {"pid": os.getpid(), "arguments": arguments, "returncode": result.returncode,
                       "authorization_before_dispatch": before, "finished_ns": time.time_ns()}
        with (root / "setup-git-observations.jsonl").open("a", encoding="utf-8") as stream:
            stream.write(json.dumps(observation) + "\n")
            stream.flush()
            os.fsync(stream.fileno())
        if (boundary == "during" and calls == 1) or (boundary == "materialization" and arguments[0] == "push"):
            save_json(root / "setup-boundary.json", observation)
            deadline = time.monotonic() + 30
            while not (root / "release-setup.json").exists():
                if time.monotonic() >= deadline:
                    raise TimeoutError("Initial-setup native test gate was not released")
                time.sleep(0.01)
        return result
    publication._git = observed_git
    try:
        yield
    finally:
        publication._git = original


def initial_setup_probe(root: Path, output: Path, boundary: str) -> int:
    """Exercise the production main-flow callsite without requesting an assignment."""
    from tools.orchestration_eval import acceptance, flows
    from tools.orchestration_eval.runtime import EvaluationRuntime
    from tools.orchestration_eval.safety import save_json
    from tools.orchestration_eval.state import Ledger
    root.mkdir(parents=True, exist_ok=True)
    ledger = Ledger(root / "ledger.sqlite3")
    ledger.authorize("RUN", event_id="run", reason="Actual initial-setup boundary reproduction", expected_revision=0)
    runtime = EvaluationRuntime(root, ledger)
    launch = runtime.manager.launch
    def instrumented_launch(argv, **kwargs):
        if kwargs.get("kind") == "fixture-setup":
            argv = [*argv, "--setup-boundary", boundary]
        return launch(argv, **kwargs)
    runtime.manager.launch = instrumented_launch
    entered_assignment = False
    class AssignmentBoundary(Exception):
        pass
    def stop_at_assignment(*args, **kwargs):
        nonlocal entered_assignment
        entered_assignment = True
        raise AssignmentBoundary("Initial main-flow setup completed; no provider call permitted")
    original_assignment = flows.launch_assignment
    flows.launch_assignment = stop_at_assignment
    error = None
    try:
        if boundary == "before":
            ledger.request_stop(event_id="before-setup", reason="STOP before actual exercise_scenarios entry")
        with setup_test_boundary(root, boundary):
            acceptance.exercise_scenarios(runtime, Path(sys.executable), 1)
    except AssignmentBoundary:
        pass
    except Exception as exc:
        error = repr(exc)
    finally:
        flows.launch_assignment = original_assignment
        runtime.stop(event_id="setup-probe-final-stop", reason="Close only actual initial-setup work")
    fixture = root / "fixtures/assignment-publication"
    repo = fixture / "repository"
    def text(path):
        return path.read_text(encoding="utf-8") if path.is_file() else None
    observations = root / "setup-git-observations.jsonl"
    save_json(output, {"boundary": boundary, "entered_assignment": entered_assignment, "error": error,
        "fixture_exists": fixture.exists(), "fixture_sealed": (fixture / "fixture.json").exists(),
        "probe_present": (repo / "probe.py").exists(), "expected": text(repo / "expected.txt"),
        "local_ref": text(repo / ".git/refs/heads/main"), "remote_ref": text(fixture / "remote.git/refs/heads/main"),
        "authorization": ledger.authorization(), "owned_processes": runtime.manager.records(),
        "git_observations": [json.loads(line) for line in observations.read_text(encoding="utf-8").splitlines()]
                            if observations.exists() else [],
        "qualification": "Real exercise_scenarios initial setup and native Git; only first assignment launch is intercepted, with no OMP/provider request."})
    return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("operation", choices=("measure", "stdio-measure", "hold", "listen", "tool-failure",
                                               "rpc-fixture", "test-command-driver", "publication-stop",
                                               "startup-stop", "pre-assignment", "initial-setup-probe", "initialize-fixture"))
    parser.add_argument("--root", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--frame", choices=("agent_start", "host_tool_call", "host_uri_request"))
    parser.add_argument("--crash-test-owner", action="store_true")
    parser.add_argument("--effect", choices=("commit", "push"))
    parser.add_argument("--astra-capacity", type=int)
    parser.add_argument("--setup-boundary", choices=("before", "during", "materialization", "normal"))
    parser.add_argument("--registration", type=Path)
    parser.add_argument("--fixture-name")
    parser.add_argument("--fixture-value", type=int)
    parser.add_argument("--materialize-source", action="store_true")
    args = parser.parse_args()
    args.root = confined(args.root)
    args.output = confined(args.output)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    if args.operation == "initialize-fixture":
        if args.registration is None or args.fixture_name is None or args.fixture_value is None:
            parser.error("Fixture initialization needs its durable registration and exact fixture inputs")
        from tools.orchestration_eval.acceptance import materialize_initial_fixture
        with setup_test_boundary(args.root, args.setup_boundary) if args.setup_boundary else nullcontext():
            materialize_initial_fixture(args.root, args.registration, args.output, args.fixture_name,
                                        args.fixture_value, args.materialize_source)
        return 0
    if args.operation == "initial-setup-probe":
        return initial_setup_probe(args.root, args.output, args.setup_boundary)
    if args.operation in ("publication-stop", "startup-stop", "pre-assignment"):
        from tools.orchestration_eval.acceptance import (
            exercise_pre_assignment_failure, exercise_publication_stop, exercise_stalled_startup)
        from tools.orchestration_eval.safety import save_json
        if args.operation == "publication-stop":
            result = exercise_publication_stop(args.root, args.effect)
        elif args.operation == "startup-stop":
            result = exercise_stalled_startup(args.root, args.astra_capacity)
        else:
            result = exercise_pre_assignment_failure(args.root)
        save_json(args.output, result)
        return 0
    if args.operation == "test-command-driver":
        # Execute the real test-command lifecycle against one bounded native
        # fixture, never recursively collect the evaluator's behavioral suite.
        from tools.orchestration_eval import __main__ as command
        command.WORKTREE = confined(args.root / "focused-worktree")
        os.environ.pop("PYTEST_ADDOPTS", None)
        if args.crash_test_owner:
            def crash_after_pytest_starts():
                while not (args.root / "pytest-ready.json").is_file():
                    time.sleep(0.01)
                args.output.write_text(json.dumps({"owner_exit": 77, "pid": os.getpid()}), encoding="utf-8")
                os._exit(77)
            threading.Thread(target=crash_after_pytest_starts, daemon=True,
                             name="bounded-test-owner-crash").start()
        result = command.run_tests(args.root)
        args.output.write_text(json.dumps(result), encoding="utf-8")
        return 0
    if args.operation == "rpc-fixture":
        args.output.write_text(json.dumps({"pid": os.getpid(), "ready": True,
            "qualification": "Native pipe fault fixture, not an OMP/provider session"}), encoding="utf-8")
        if args.frame:
            trigger = args.root / "send-frame.json"
            while not trigger.exists():
                time.sleep(0.01)
            print(json.dumps({"type": args.frame, "fixture": True}), flush=True)
        else:
            for raw in sys.stdin.buffer:
                with (args.root / "received-commands.jsonl").open("ab") as stream:
                    stream.write(raw)
        # Intentionally ignore EOF as well as control commands. Exit must be
        # established by the actual owned Windows job, not a fixture response.
        while True:
            time.sleep(0.1)
    if args.operation == "stdio-measure":
        request = json.loads(sys.stdin.buffer.readline())
        path = confined(args.root / request["relative_path"], args.root)
        content = path.read_bytes()
        measured = hashlib.sha256(content).hexdigest()
        result = {"pid": os.getpid(), "sha256": measured, "size": len(content),
                  "matches": measured == request["expected_sha256"]}
        args.output.write_text(json.dumps(result), encoding="utf-8")
        print(json.dumps(result), flush=True)
        print(f"Measured {len(content)} bytes; matches={result['matches']}", file=sys.stderr, flush=True)
        return 0 if result["matches"] else 23
    if args.operation == "listen":
        with socket.socket() as listener:
            listener.bind(("127.0.0.1", 0))
            listener.listen()
            args.output.write_text(json.dumps({"pid": os.getpid(), "port": listener.getsockname()[1]}), encoding="utf-8")
            while True:
                time.sleep(1)
    if args.operation == "hold":
        args.output.write_text(json.dumps({"pid": os.getpid(), "ready": True}), encoding="utf-8")
        while True:
            time.sleep(1)
    if args.operation == "tool-failure":
        args.output.write_text(json.dumps({"pid": os.getpid(), "infrastructure_failure": "deliberate owned fixture exit 47"}), encoding="utf-8")
        return 47
    source = (args.root / "source.cpp").read_bytes()
    expected = (args.root / "expected.txt").read_bytes()
    paths = ("source.cpp", "shared.h", "config.json", "tool.txt", "probe.py", "expected.txt")
    result = {
        "scope": "evaluation_fixture", "pid": os.getpid(), "source_matches_target": source == expected,
        "file_hashes": {p: hashlib.sha256((args.root / p).read_bytes()).hexdigest() for p in paths},
        "matching_bytes": sum(a == b for a, b in zip(source, expected)),
        "source_size": len(source), "target_size": len(expected),
        "semantic_qualification": "Byte equality and native process execution only; no C++ acceptance claim",
    }
    args.output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(result))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
