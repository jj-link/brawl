"""Fixed mechanical verification of actual candidate outputs and link selection."""
from __future__ import annotations

import json
from pathlib import Path

from .evidence import InputError, InputManifest, content_identity, file_identity, input_path
from .safety import SafetyError, confined, save_json
from .trial_cleanup import delete_exact_file, delivery_plan
from .trial_delivery import DeliveryError, validate_delivery_files, verify_binary_hashes
from .trial_execution import OwnedCommands
from .trial_objects import compare_objects
from .trial_ownership import prove_registration_insertions
from .policy import workflow_acceptance_policy


class VerificationRejected(DeliveryError):
    def __init__(self, criterion, path, reason):
        super().__init__(reason)
        self.findings = [{"criterion": criterion, "path": path, "reason": reason}]


def checked_delivery_files(workspace, delivery):
    try:
        return validate_delivery_files(workspace, delivery)
    except (DeliveryError, InputError) as error:
        raise VerificationRejected("relevant_inputs", "", str(error)) from error


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


def fixed_native_equivalence(comparison, selection, expected_hashes, hash_rows, *, symbol, exhausted):
    """Cover only this emitted native image, not source portability or a game run."""
    if (len(expected_hashes) != 127 or len(hash_rows) != 127
            or {row["path"]: row["expected"] for row in hash_rows} != expected_hashes
            or any(row["observed"] != row["expected"] for row in hash_rows)):
        raise VerificationRejected("binary_hashes", "", "Native hash evidence does not cover the complete fixed image")
    original = comparison["original_contents"]
    matching = comparison["candidate_contents"] == original
    if comparison["matching"] is not matching:
        raise VerificationRejected("object_compare", "", "Object comparison label contradicts actual bytes/exports/relocations")
    original_export = any(row[0] == symbol and row[1] & 15 == 2 for row in original["exports"])
    executable = any(section["flags"] & 4 and section["size"] for section in original["sections"].values())
    return bool(original_export and executable
                and ((matching and selection["selected"] and not selection["fallback_selected"])
                     or (not matching and exhausted and not selection["selected"] and selection["fallback_selected"])))


def apply_judgment_requirements(policy, requirements, covered, unresolved):
    for criterion, reason in requirements.items():
        if criterion not in policy["judgment_criteria"] or not isinstance(reason, str) or not reason.strip():
            raise SafetyError("Unsupported or unexplained substantive judgment requirement")
        evidence = covered.pop(criterion, None) or unresolved[criterion]
        previous = unresolved.get(criterion, {}).get("reason")
        unresolved[criterion] = {"reason": reason, "evidence_refs": evidence["evidence_refs"]}
        if previous:
            unresolved[criterion]["context"] = previous


def delivery_ownership(runtime, action, delivery, specification, commands, directory, *, matching, cleanup_ref):
    assignment = runtime.ledger.assignment(action["assignment_id"])
    reservation = assignment["identity"]["reservation"]
    workspace, payload = Path(reservation["workspace"]), delivery.payload
    allowed = set(reservation["owned_paths"])
    if not set(payload["changes"]) <= allowed:
        raise VerificationRejected("ownership", "", "Delivery exceeds reserved file ownership")
    if payload["inputs"]["recipe"] != specification["recipe"]:
        raise VerificationRejected("relevant_inputs", "", "Delivery recipe differs from the fixed verification recipe")
    shared = sorted(set(payload["changes"]) - {specification["selection"]["source"]})
    ownership = {"binding": action["binding"], "reserved_paths": sorted(allowed),
                 "source": specification["selection"]["source"], "changes": payload["changes"],
                 "cleanup_preflight_ref": cleanup_ref, "preimage_receipts": {}, "postimage_receipts": {}}
    before_images, after_images = {}, {}
    for name in shared:
        before = payload["changes"][name]["before"]
        before_images[name] = None
        if before is not None:
            original = commands.run(action, ["git", "-C", str(workspace), "cat-file", "blob", before["blob"]],
                                    cwd=workspace)
            ownership["preimage_receipts"][name] = str(original.receipt)
            before_images[name] = original.stdout
        after_images[name] = input_path(workspace, name).read_bytes()
        postimage = commands.run(action, ["git", "-C", str(workspace), "hash-object", "--path=" + name, "--stdin"],
                                 cwd=workspace, data=after_images[name])
        ownership["postimage_receipts"][name] = str(postimage.receipt)
        if postimage.text() != payload["changes"][name]["after"]["blob"]:
            raise VerificationRejected("ownership", name, "Declared Git postimage differs from actual delivered bytes")
    transformations, reason = (prove_registration_insertions(
        before_images, after_images, reservation, specification, matching) if shared else ({}, None))
    ownership.update(transformations=transformations, unresolved_reason=reason, function=reservation["function"],
                     registration_recipe=specification["recipe"].get("registration"))
    path = directory / "ownership.json"
    save_json(path, ownership)
    proof = None
    if shared and transformations is not None:
        proof = {"schema": 1, "binding": action["binding"],
                 "recipe_identity": content_identity(payload["inputs"]["recipe"]),
                 "source": specification["selection"]["source"],
                 "paths": {name: {"transformation": method, **payload["changes"][name]}
                           for name, method in transformations.items()},
                 "evidence": {"path": str(path), **file_identity(path)}}
    return {"shared": shared, "proof": proof, "reason": reason, "evidence_ref": str(path),
            "command_refs": [*ownership["preimage_receipts"].values(), *ownership["postimage_receipts"].values()]}


def delivery_coverage(runtime, action, delivery, result, directory, commands):
    """Attribute fixed criteria to actual controller evidence, never worker labels."""
    doc = runtime.ledger.snapshot()
    workflow = doc["trial"]["workflow"]
    specification = workflow["config"]["verification"][action["assignment_id"]]
    assignment = doc["assignments"][action["assignment_id"]]
    workspace = Path(assignment["identity"]["reservation"]["workspace"])
    payload = delivery.payload
    policy = workflow_acceptance_policy()
    if workflow["config"]["acceptance_policy"] != policy:
        raise SafetyError("Verification acceptance policy changed")
    inputs = checked_delivery_files(workspace, delivery)
    pinned_inputs(workspace, specification, delivery)
    input_ref = directory / "bound-inputs.json"
    save_json(input_ref, {"binding": action["binding"], "validation": inputs,
                         "inputs": payload["inputs"], "artifacts": payload["artifacts"]})
    stage = next(item for item in assignment["stages"] if payload["candidate_id"] in item["candidates"])
    candidate = stage["candidates"][payload["candidate_id"]]
    if (stage["initial_count"] != 1 or type(stage["corrections"]) is not int
            or not 0 <= stage["corrections"] <= 10
            or candidate["input_identity"] != payload["inputs"]["identity"]
            or (candidate["outcome"] != "matching" and
                (not stage["exhausted"] or candidate != assignment["best_candidate"]))):
        raise VerificationRejected("attempt_rules", "", "Delivery lacks its bounded measured candidate/history")
    attempts_ref = directory / "attempt-rules.json"
    save_json(attempts_ref, {"binding": action["binding"], "candidate": candidate,
                            "stages": assignment["stages"],
                            "qualification": "Preserved recorded history only; no lifetime-count inference"})
    ownership = delivery_ownership(runtime, action, delivery, specification, commands, directory,
                                   matching=result["matching"], cleanup_ref=result["cleanup_preflight_ref"])
    checks = result["checks"]
    covered = {name: {"method": policy["criteria"][name], "evidence_refs": [reference]}
               for name, reference in checks.items()}
    covered.update({
        "ownership": {"method": policy["criteria"]["ownership"],
                      "evidence_refs": [ownership["evidence_ref"], result["cleanup_preflight_ref"]]},
        "attempt_rules": {"method": policy["criteria"]["attempt_rules"], "evidence_refs": [str(attempts_ref)]},
        "relevant_inputs": {"method": policy["criteria"]["relevant_inputs"], "evidence_refs": [str(input_ref)]},
    })
    chain = list(dict.fromkeys(checks[name] for name in
                             ("object_compare", "data_relocations", "source_link", "binary_hashes")))
    comparison = json.loads(Path(checks["object_compare"]).read_bytes())
    hash_rows = json.loads(Path(checks["binary_hashes"]).read_bytes())["files"]
    equivalent = fixed_native_equivalence(
        comparison, result["source_selection"], specification["binary_hashes"], hash_rows,
        symbol=assignment["identity"]["reservation"]["function"]["symbol"], exhausted=stage["exhausted"])
    unresolved = {}
    for criterion in ("abi", "edge_semantics"):
        if equivalent:
            covered[criterion] = {"method": policy["criteria"][criterion], "evidence_refs": chain}
        else:
            unresolved[criterion] = {
                "reason": "The fixed native evidence does not establish the reserved exported function's "
                          "complete executable image equivalence; inspect its original ABI/edge behavior.",
                "evidence_refs": chain}
    if ownership["shared"] and ownership["proof"] is None:
        covered.pop("ownership")
        unresolved["ownership"] = {
            "reason": ownership["reason"],
            "evidence_refs": [ownership["evidence_ref"], *ownership["command_refs"]]}
    apply_judgment_requirements(policy, specification.get("judgment_requirements", {}), covered, unresolved)
    coverage = {"policy_identity": content_identity(policy), "binding": action["binding"],
                "producer": workflow["config"]["controller_id"], "covered": covered, "unresolved": unresolved}
    coverage_ref = directory / "criterion-coverage.json"
    save_json(coverage_ref, coverage)
    references = {reference for item in [*covered.values(), *unresolved.values()]
                  for reference in item["evidence_refs"]}
    references.add(str(coverage_ref))
    references.update(ownership["command_refs"])
    if result.get("reuse_evidence"):
        references.add(result["reuse_evidence"]["evidence_ref"])
    return dict(result, coverage=coverage, coverage_ref=str(coverage_ref), ownership_proof=ownership["proof"],
                check_identities={reference: file_identity(Path(reference)) for reference in references})


def verification_outputs(workspace, specification):
    names = {specification["selection"][key] for key in ("object", "fallback_object", "link_output")}
    names.update(specification["binary_hashes"])
    return {str(input_path(workspace, name)): file_identity(input_path(workspace, name)) for name in sorted(names)}


def reusable_evidence(previous, workspace, specification, root):
    if previous.get("verification_spec_identity") != content_identity(specification):
        return None
    identities = previous.get("check_identities")
    if not identities or not previous.get("output_identities"):
        return None
    try:
        observed = {reference: file_identity(confined(Path(reference), root)) for reference in identities}
        outputs = verification_outputs(workspace, specification)
    except (InputError, FileNotFoundError):
        return None
    if observed != identities or outputs != previous["output_identities"]:
        return None
    return {"identities": observed, "output_identities": outputs}


def verify_delivery(runtime, action, delivery):
    doc = runtime.ledger.snapshot()
    assignment = doc["assignments"][action["assignment_id"]]
    workflow = doc["trial"]["workflow"]
    specification = workflow["config"]["verification"][action["assignment_id"]]
    workspace = Path(assignment["identity"]["reservation"]["workspace"])
    checked_delivery_files(workspace, delivery)
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
    for prior in reversed(list(workflow["actions"].values())):
        if (prior["kind"] != "validate_delivery" or prior["status"] != "succeeded" or prior.get("superseded")
                or prior["assignment_id"] != action["assignment_id"]
                or any(prior["binding"].get(key) != action["binding"].get(key)
                       for key in ("source_identity", "input_identity", "policy_identity"))):
            continue
        previous_delivery = workflow["assignments"][action["assignment_id"]]["deliveries"][prior["binding"]["delivery_id"]]
        if previous_delivery["delivery"]["artifacts"] != payload["artifacts"]:
            continue
        witness = reusable_evidence(prior["result"], workspace, specification, runtime.root)
        if witness is None:
            continue
        witness.update(source_action_id=prior["effect_id"], binding=action["binding"],
                       evidence_ref=str(directory / "rechecked-native-evidence.json"))
        save_json(Path(witness["evidence_ref"]), witness)
        result = {key: prior["result"][key] for key in
                  ("valid", "matching", "checks", "binary_hash_count", "source_selection",
                   "runtime_status", "runtime_reason", "verification_spec_identity", "output_identities")}
        result.update(reused_from=prior["effect_id"], reuse_evidence=witness,
                      cleanup_preflight_ref=str(cleanup_ref))
        return delivery_coverage(runtime, action, delivery, result, directory, commands)
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
    checked_delivery_files(workspace, delivery)
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
    try:
        hashes = verify_binary_hashes(workspace, specification["binary_hashes"])
    except (DeliveryError, InputError) as error:
        raise VerificationRejected("binary_hashes", "", str(error)) from error
    hash_path = directory / "binary-hashes.json"
    save_json(hash_path, {"input_identity": payload["inputs"]["identity"], "source_identity": delivery.source_identity,
                          "files": hashes})
    checks["binary_hashes"] = str(hash_path)
    checked_delivery_files(workspace, delivery)
    pinned_inputs(workspace, specification, delivery)
    result = {"valid": True, "matching": comparison["matching"], "checks": checks,
              "binary_hash_count": len(hashes), "source_selection": proof,
              "cleanup_preflight_ref": str(cleanup_ref),
              "verification_spec_identity": content_identity(specification),
              "output_identities": verification_outputs(workspace, specification),
              "runtime_status": "unavailable",
              "runtime_reason": "No approved in-game runtime command is present in the fixed verification profile"}
    return delivery_coverage(runtime, action, delivery, result, directory, commands)
