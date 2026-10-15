"""Fixed mechanical verification of actual candidate outputs and link selection."""
from __future__ import annotations

import json
from pathlib import Path

from .evidence import InputManifest, file_identity, input_path
from .safety import SafetyError, confined, save_json
from .trial_cleanup import delete_exact_file, delivery_plan
from .trial_delivery import DeliveryError, validate_delivery_files, verify_binary_hashes
from .trial_execution import OwnedCommands
from .trial_objects import compare_objects


class VerificationRejected(DeliveryError):
    def __init__(self, criterion, path, reason):
        super().__init__(reason)
        self.findings = [{"criterion": criterion, "path": path, "reason": reason}]


def query_inputs(text):
    """Parse native Ninja query's input section, never its downstream outputs."""
    values = []
    reading = False
    for line in text.splitlines():
        if line.startswith("  input:"):
            reading = True
        elif line.startswith("  ") and not line.startswith("    "):
            reading = False
        elif reading and line.startswith("    "):
            value = line.strip().removeprefix("|| ").removeprefix("| ")
            values.append(value.replace("\\", "/"))
    return values


def pinned_inputs(workspace, specification, delivery):
    manifest = InputManifest.from_dict(delivery.payload["inputs"])
    paths = {name.casefold() for name in manifest.paths}
    approved = {}
    for item in specification["workspace_inputs"]:
        name = item["destination"]
        if name.casefold() not in paths:
            raise VerificationRejected("relevant_inputs", "", "Delivery omits a coordinator-pinned setup dependency: " + name)
        expected = delivery.payload["changes"].get(name, {}).get("raw", item["identity"])
        if file_identity(input_path(workspace, name)) != expected:
            raise VerificationRejected("relevant_inputs", name, "Pinned workspace dependency changed")
        if file_identity(Path(item["source"])) != item["identity"]:
            raise SafetyError("Read-only approved native tool/original input changed")
        for path in (Path(item["source"]), workspace / name):
            approved[str(path.resolve()).casefold()] = item["identity"]
    for executable in [specification["selection"]["ninja"], *[row["argv"][0] for row in specification["commands"]]]:
        path = Path(executable)
        expected = approved.get(str(path.resolve()).casefold()) if path.is_absolute() else None
        if expected is None or file_identity(path) != expected:
            raise SafetyError("Every verification executable must be an actual pinned native input")
    if "build.ninja" not in paths:
        raise VerificationRejected("relevant_inputs", "", "The actual generated compile/link recipe is not bound")
    return manifest


def verify_delivery(runtime, action, delivery):
    doc = runtime.ledger.snapshot()
    assignment = doc["assignments"][action["assignment_id"]]
    workflow = doc["trial"]["workflow"]
    specification = workflow["config"]["verification"][action["assignment_id"]]
    workspace = Path(assignment["identity"]["reservation"]["workspace"])
    try:
        validate_delivery_files(workspace, delivery)
    except DeliveryError as error:
        raise VerificationRejected("relevant_inputs", "", str(error)) from error
    payload = delivery.payload
    pinned_inputs(workspace, specification, delivery)
    candidate = next(stage["candidates"][payload["candidate_id"]] for stage in assignment["stages"]
                     if payload["candidate_id"] in stage["candidates"])
    matching = candidate["outcome"] == "matching"
    commands = OwnedCommands(runtime)
    directory = confined(runtime.root / "workflow" / action["effect_id"], runtime.root)
    directory.mkdir(parents=True, exist_ok=True)
    tracked_names = commands.run(action, ["git", "-C", str(workspace), "ls-files", "-z"], cwd=workspace)
    tracked = {name: file_identity(input_path(workspace, name))
               for name in tracked_names.stdout.decode("utf-8").split("\0") if name}
    try:
        cleanup = delivery_plan(workspace, assignment,
            workflow["assignments"][action["assignment_id"]]["deliveries"], specification, delivery, tracked)
    except (OSError, ValueError, SafetyError) as error:
        raise VerificationRejected("ownership", "", "Unsafe cleanup declaration: " + str(error)) from error
    cleanup_ref = directory / "cleanup-preflight.json"
    save_json(cleanup_ref, cleanup)
    for prior in workflow["actions"].values():
        if (prior["kind"] != "validate_delivery" or prior["status"] != "succeeded"
                or prior["assignment_id"] != action["assignment_id"]):
            continue
        previous = workflow["assignments"][action["assignment_id"]]["deliveries"][prior["binding"]["delivery_id"]]
        if (all(prior["binding"][key] == action["binding"][key] for key in ("source_identity", "input_identity"))
                and previous["delivery"]["artifacts"] == payload["artifacts"]):
            # Relevant identities, not unrelated repository HEAD movement,
            # determine whether already observed verification can be reused.
            for reference in prior["result"]["checks"].values():
                path = input_path(runtime.root, str(Path(reference).relative_to(runtime.root)).replace("\\", "/"))
                if file_identity(path) != prior["result"]["check_identities"][reference]:
                    raise SafetyError("Previously verified controller evidence changed")
            return dict(prior["result"], reused_from=prior["effect_id"], cleanup_preflight_ref=str(cleanup_ref))
    selection = specification["selection"]
    source = input_path(workspace, selection["source"])
    object_path = input_path(workspace, selection["object"], must_exist=False)
    retained = set(InputManifest.from_dict(payload["inputs"]).paths)
    retained.update(artifact["path"] for artifact in payload["artifacts"].values())
    if selection["object"] in retained or selection["object"].casefold().startswith(("orig/", "src/", "include/")):
        raise SafetyError("Forced compilation cannot remove retained source/input/evidence")
    ninja = selection["ninja"]
    object_query = commands.run(action, [ninja, "-t", "query", selection["object"]], cwd=workspace)
    compile_commands = commands.run(action, [ninja, "-t", "commands", selection["object"]], cwd=workspace)
    expected_command = specification["recipe"].get("native_compile_command")
    if not isinstance(expected_command, str) or not expected_command.strip():
        raise SafetyError("Fixed recipe must pin the actual complete native compiler command")
    if expected_command not in compile_commands.text().splitlines():
        raise VerificationRejected("compile", selection["source"], "Generated compiler invocation differs from the approved exact recipe")
    approved_dependencies = {str((workspace / name).resolve()).casefold()
                             for name in InputManifest.from_dict(payload["inputs"]).paths}
    approved_dependencies.update(str(Path(item["source"]).resolve()).casefold()
                                 for item in specification["workspace_inputs"])
    for name in query_inputs(object_query.text()):
        dependency = Path(name) if Path(name).is_absolute() else workspace / name
        if dependency.is_file() and str(dependency.resolve()).casefold() not in approved_dependencies:
            raise VerificationRejected("relevant_inputs", "", "Actual native compiler/tool dependency is not approved: " + name)
    prior_object = None
    runtime.ledger.require_operation("verify", authorization_revision=action["authorization_revision"])
    if object_path.exists():
        prior_object = file_identity(object_path)
        delete_exact_file(object_path, prior_object, {})
    save_json(directory / "compile-inputs.json", {"input_identity": payload["inputs"]["identity"],
              "source": str(source), "source_identity": file_identity(source), "previous_object": prior_object,
              "forced_object_rebuild": True})
    checks = {}
    by_name = {command["name"]: command for command in specification["commands"]}
    for name in ("compile", "object_compare", "data_relocations", "source_link", "progress"):
        command = by_name[name]
        pinned_inputs(workspace, specification, delivery)
        result = commands.run(action, command["argv"], cwd=workspace,
                              timeout=command["timeout_seconds"], check=False)
        checks[command["name"]] = str(result.receipt)
        if result.returncode not in command["accepted_exit_codes"]:
            raise VerificationRejected(command["name"], selection["source"],
                                       f"Native verification command exited {result.returncode}; {result.receipt}")
        if matching and command["name"] in {"compile", "object_compare", "data_relocations"} and result.returncode != 0:
            raise VerificationRejected(command["name"], selection["source"], "A matching delivery requires successful native comparison")
        if command["name"] == "compile" and not object_path.is_file():
            raise VerificationRejected("compile", selection["source"], "Native compile did not produce the exact candidate object")
    validate_delivery_files(workspace, delivery)
    comparison = compare_objects(object_path, input_path(workspace, selection["fallback_object"]))
    comparison_ref = directory / "actual-object-comparison.json"
    save_json(comparison_ref, comparison)
    if comparison["matching"] != matching:
        raise VerificationRejected("object_compare", selection["source"],
                                   "Actual object bytes/relocations disagree with the captured candidate outcome")
    checks["object_compare"] = str(comparison_ref)
    checks["data_relocations"] = str(comparison_ref)
    dependencies = commands.run(action, [ninja, "-t", "deps", selection["object"]], cwd=workspace)
    lines = dependencies.text().splitlines()
    if not lines or "(VALID)" not in lines[0]:
        raise VerificationRejected("source_link", selection["source"], "No current native compiler dependency proof")
    measured_paths = {str((workspace / name).resolve()).casefold() for name in InputManifest.from_dict(payload["inputs"]).paths}
    for line in lines[1:]:
        if not line.startswith("    ") or not line.strip():
            continue
        dependency = Path(line.strip())
        if not dependency.is_absolute():
            dependency = workspace / dependency
        if str(dependency.resolve()).casefold() not in measured_paths:
            raise VerificationRejected("relevant_inputs", "", "Actual compiler dependency omitted: " + str(dependency))
    if selection["source"].replace("\\", "/") not in query_inputs(object_query.text()):
        raise VerificationRejected("source_link", selection["source"], "Candidate object does not depend on the delivered source")
    if selection["source"].replace("\\", "/") not in compile_commands.text().replace("\\", "/"):
        raise VerificationRejected("source_link", selection["source"], "Native compile rule does not name the delivered source")
    graph, pending = {}, [selection["link_output"].replace("\\", "/")]
    targets = {selection["object"].replace("\\", "/"), selection["fallback_object"].replace("\\", "/")}
    reached = set()
    while pending:
        node = pending.pop()
        if node in graph:
            continue
        if node in targets:
            reached.add(node)
            continue
        query = commands.run(action, [ninja, "-t", "query", node], cwd=workspace, check=False)
        if query.returncode:
            raise VerificationRejected("source_link", selection["source"], f"Cannot establish native link dependency {node}")
        dependencies = query_inputs(query.text())
        graph[node] = {"inputs": dependencies, "receipt": str(query.receipt)}
        # Source/header/tool dependencies are leaves. Querying every generated
        # build artifact keeps intermediate archives/link stages explicit.
        pending.extend(item for item in dependencies if item in targets or
                       item.lower().endswith((".o", ".a", ".elf", ".plf", ".rel", ".dol")))
    selected = selection["object"].replace("\\", "/") in reached
    fallback = selection["fallback_object"].replace("\\", "/") in reached
    source_evidence = directory / "source-selection.json"
    proof = {key: selection[key] for key in ("source", "object", "link_output")}
    proof.update(selected=selected, fallback_selected=fallback, evidence_ref=str(source_evidence),
                 input_identity=payload["inputs"]["identity"], source_identity=file_identity(source),
                 object_identity=file_identity(input_path(workspace, selection["object"])),
                 link_identity=file_identity(input_path(workspace, selection["link_output"])),
                 compile_receipt=checks["compile"], object_query_ref=str(object_query.receipt),
                 compile_rule_ref=str(compile_commands.receipt), graph=graph)
    save_json(source_evidence, proof)
    if (matching and (not selected or fallback)) or (not matching and (selected or not fallback)):
        raise VerificationRejected("source_link", selection["source"],
            "Actual source/fallback selection differs from matching or exhausted-final-attempt policy")
    checks["source_link"] = str(source_evidence)
    hashes = verify_binary_hashes(workspace, specification["binary_hashes"])
    hash_path = directory / "binary-hashes.json"
    save_json(hash_path, {"input_identity": payload["inputs"]["identity"], "source_identity": delivery.source_identity,
                          "files": hashes})
    checks["binary_hashes"] = str(hash_path)
    validate_delivery_files(workspace, delivery)
    pinned_inputs(workspace, specification, delivery)
    return {"valid": True, "matching": comparison["matching"], "checks": checks,
            "check_identities": {reference: file_identity(Path(reference)) for reference in checks.values()},
            "binary_hash_count": len(hashes), "source_selection": proof,
            "cleanup_preflight_ref": str(cleanup_ref),
            "runtime_status": "unavailable", "runtime_reason": "No approved in-game runtime command is present in the fixed verification profile"}
