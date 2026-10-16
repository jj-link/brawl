"""Aggregate retained publication units into complete launch inputs, never Git authority."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

from .__main__ import run_root
from .evidence import reject_links
from .safety import SafetyError, check_worktree, confined, digest, save_json


def load_record(path):
    path = confined(Path(path))
    reject_links(path)
    raw = path.read_bytes()
    return json.loads(raw), {"path": str(path), "sha256": hashlib.sha256(raw).hexdigest()}


def cumulative_source_manifest(receipt):
    """Use every retained unit's final image, not just the last unit's input list.

    These are retained publication identities. The normal repository admission
    still independently verifies actual Git history, raw files, index and remote.
    """
    if receipt.get("schema") != "brawl-owned-engineering-publication/v2":
        raise SafetyError("Cumulative inputs require the actual v2 publication history")
    pointer = receipt["source_manifest"]
    declared, declaration_identity = load_record(pointer["path"])
    if declaration_identity != pointer:
        raise SafetyError("Publication input declaration changed")
    units, files = receipt["units"], receipt["files"]
    if not isinstance(units, list) or not units or not isinstance(files, dict) or not files:
        raise SafetyError("Publication needs retained units and final postimages")
    images, origins, evidence = {}, {}, []
    previous = receipt["engineering_baseline"]
    for unit in units:
        published, identity = load_record(unit["receipt"])
        paths = unit["paths"]
        if (not isinstance(paths, list) or not paths or len(paths) != len(set(paths))
                or unit["parent"] != previous
                or any(published.get(key) != unit[key] for key in ("commit", "parent", "paths"))
                or published.get("remote") != receipt["remote"]
                or published.get("branch") != "refs/heads/" + receipt["branch"]
                or published.get("remote_head") != unit["commit"]
                or set(published.get("files", {})) != set(paths)
                or set(unit.get("postimages", {})) != set(paths)):
            raise SafetyError("Retained published unit changed its exact parent/scope/remote binding")
        for name in paths:
            image = published["files"][name]
            if (image.get("mode") != "100644" or not isinstance(image.get("raw"), dict)
                    or set(image["raw"]) != {"sha256", "size"}
                    or {key: image.get(key) for key in ("mode", "blob")} != unit["postimages"][name]):
                raise SafetyError("Historical unit raw identity and committed postimage disagree")
            images[name], origins[name] = image, identity
        previous = unit["commit"]
        evidence.append(identity)
    if previous != receipt["head"] or receipt.get("remote_head") != previous or images != files:
        raise SafetyError("Retained units do not produce the complete final publication")
    entries = [*declared["sources"], *declared.get("documentation", [])]
    if len({entry["path"].casefold() for entry in entries}) != len(entries):
        raise SafetyError("Publication declaration aliases a final path")
    for entry in entries:
        if (entry["path"] not in files
                or {key: entry[key] for key in ("sha256", "size")} != files[entry["path"]]["raw"]):
            raise SafetyError("Latest reviewed declaration disagrees with final published identities")
    if len({name.casefold() for name in files}) != len(files):
        raise SafetyError("Cumulative publication aliases a final path")
    # The sole engineering documentation path is also retained when the latest
    # delta is source-only. No fixed number of files or one-time migration list.
    complete = [{"path": name, **files[name]["raw"], "publication_receipt": origins[name]}
                for name in sorted(files)]
    return {"schema": "reviewed-engineering-cumulative-postimages/v1",
            "baseline": receipt["engineering_baseline"], "implementation_head": receipt["head"],
            "sources": [entry for entry in complete if entry["path"] != "ORCHESTRATION_PLAN.md"],
            "documentation": [entry for entry in complete if entry["path"] == "ORCHESTRATION_PLAN.md"],
            "latest_reviewed_declaration": declaration_identity, "historical_publication_receipts": evidence,
            "qualification": "Retained per-unit final identities; not a replacement for actual Git/remote/index admission"}


def build_publication_inputs(publication, *, run_id, output):
    run_root(run_id)  # Reuse the existing portable run-name/confinement contract.
    output = confined(Path(output))
    reject_links(output)
    if output.exists():
        raise SafetyError("Publication input output must be fresh; preserve preceding packets")
    receipt, original_identity = load_record(publication)
    manifest = cumulative_source_manifest(receipt)
    output.mkdir(parents=True, exist_ok=False)
    manifest_path = output / "source-identities.json"
    save_json(manifest_path, manifest)
    observation = dict(receipt, next_run_id=run_id,
        source_manifest={"path": str(manifest_path), "sha256": digest(manifest_path)},
        input_aggregation={"original_publication": original_identity,
                           "method": "complete-retained-unit-postimages", "git_effects_replayed": False})
    receipt_path = output / "engineering-publication.json"
    save_json(receipt_path, observation)
    return {"publication": {"path": str(receipt_path), "sha256": digest(receipt_path)},
            "source_manifest": observation["source_manifest"], "final_paths": len(receipt["files"]),
            "historical_units": len(receipt["units"]), "head": receipt["head"]}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--publication", type=Path, required=True)
    parser.add_argument("--run-id", required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--authorize-publication-inputs", action="store_true")
    args = parser.parse_args(argv)
    if not args.authorize_publication_inputs:
        parser.error("Explicit owned publication-input preparation is required")
    check_worktree(control_plane=True)
    result = build_publication_inputs(args.publication, run_id=args.run_id, output=args.output)
    print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
