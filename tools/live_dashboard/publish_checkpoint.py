#!/usr/bin/env python3
"""Publish one exact committed-source checkpoint, without rebuilding or services.

Example (run by the source publisher inside its granted checkpoint window)::

    python tools/live_dashboard/publish_checkpoint.py --root REPOSITORY \
      --source FULL_SOURCE_COMMIT --integration-root VERIFIED_BUILD_WORKTREE \
      --evidence SAVED_INTEGRATION_PACKET --receipts RETAINED_RECEIPTS \
      --session ROOT_SESSION --public-url https://PUBLIC_HOST:8444 --publish \
      --expected-head FULL_CURRENT_HEAD --expected-index-sha256 INDEX_SHA256

Without --publish an already published checkpoint is independently checked, with
no report, changelog, index or ref writes. New publication requires both exact
window guards. Inputs, objects and final binaries are frozen before live writes.
Existing counter/classifier/history rules remain authoritative. A duplicate or
post-commit continuation never creates another documentation commit. Failure
receipts describe the actual phase; last-verified.json advances only after Git,
local/public full identity/maps and served/persisted history all agree. A network
failure after a successful push does not undo Git or claim endpoint verification;
rerun the same command to finish that checkpoint before publishing the next one.
All receipts/artifacts are retained; no worker, observer or service is controlled.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path, PurePosixPath
from urllib.request import urlopen

from checkpoint_history import read_checkpoint_publication
from progress import ProgressTracker


class PublicationError(RuntimeError):
    """A concrete binding, ownership or consumer-visible publication failure."""


def require(condition, message):
    if not condition:
        raise PublicationError(message)


def digest(data, algorithm="sha256"):
    return hashlib.new(algorithm, data).hexdigest()


def load(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


def encode(value):
    return (json.dumps(value, indent=2, ensure_ascii=False) + "\n").encode("utf-8")


def relative(value):
    name = str(value).replace("\\", "/")
    path = PurePosixPath(name)
    require(not path.is_absolute() and ".." not in path.parts and ":" not in name,
            f"unsafe artifact path: {value}")
    return path.as_posix()


def retain(path, data):
    """Write immutable evidence, refusing to replace a different prior artifact."""
    path = Path(path)
    if path.exists():
        require(path.read_bytes() == data, f"retained artifact conflict: {path}")
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("xb") as stream:
        stream.write(data)


def atomic(path, data, mtime=None):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    pending = path.with_name(path.name + ".checkpoint-next")
    with pending.open("xb") as stream:
        stream.write(data)
    if mtime is not None:
        os.utime(pending, (mtime, mtime))
    os.replace(pending, path)


def git(root, *args, data=None, index=None, transcript=False):
    env = dict(os.environ, GIT_OPTIONAL_LOCKS="0")
    if index is not None:
        env["GIT_INDEX_FILE"] = str(Path(index).resolve())
    result = subprocess.run(
        ["git", *args], cwd=root, input=data, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, env=env, timeout=120,
        creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
    require(result.returncode == 0,
            f"git {' '.join(args)} exited {result.returncode}: "
            f"{result.stderr.decode('utf-8', errors='replace').strip()}")
    return result.stdout + result.stderr if transcript else result.stdout


def tree_files(root, commit, names):
    """Read exact Git blobs in one batch, never the dirty working source tree."""
    names = sorted(set(relative(name) for name in names))
    request = "".join(f"{commit}:{name}\n" for name in names).encode("utf-8")
    output = git(root, "cat-file", "--batch", data=request)
    position = 0
    files = {}
    for name in names:
        end = output.find(b"\n", position)
        header = output[position:end].split()
        require(end >= 0 and len(header) == 3 and header[1] == b"blob",
                f"committed compiler input missing/not a blob: {commit}:{name}")
        size = int(header[2])
        position = end + 1
        files[name] = output[position:position + size]
        position += size + 1
    return files


def split_records(data):
    records, key = {}, "__preamble__"
    for line in data.decode("utf-8").splitlines():
        text = line.strip()
        if not text or text.startswith(("#", "//")):
            continue
        if not line[0].isspace() and text.endswith(":"):
            key = text[:-1]
            require(key not in records, f"duplicate split record: {key}")
            records[key] = []
        else:
            records.setdefault(key, []).append(" ".join(text.split()))
    return records


def symbols(data):
    """Compare entire DTK symbol declarations, not a substring or line count."""
    result = {}
    for line in data.decode("utf-8").splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        require("=" in line, f"unrecognized symbol declaration: {line}")
        name, declaration = line.split("=", 1)
        name = name.strip()
        require(name not in result, f"duplicate symbol declaration: {name}")
        result[name] = " ".join(declaration.split())
    return result


def link_edges(text):
    """Only complete Ninja link-input tokens establish native source linkage."""
    text = text.replace("$\r\n", "").replace("$\n", "").replace("\\", "/")
    edges = {}
    for line in text.splitlines():
        if not line.startswith("build ") or ": " not in line:
            continue
        output, rule = line[6:].split(": ", 1)
        tokens = rule.split()
        if tokens and tokens[0] == "link":
            edges[output] = set(tokens[1:]) - {"|", "||"}
    return edges


def elf_image(data):
    """Allocated bytes and relocations of an ELF32 big-endian PowerPC object.

    Defined local labels resolve to their actual section/value, allowing the
    already accepted MWCC-local/DTK jump-table naming distinction. Instructions,
    relocation offsets/types/addends, section bytes/flags/alignment are not
    normalized. Undefined external symbol names remain exact.
    """
    require(data[:6] == b"\x7fELF\x01\x02", "not an ELF32 big-endian object")
    header = struct.unpack_from(">HHIIIIIHHHHHH", data, 16)
    require(header[1] == 20 and header[10] == 40, "not the expected PowerPC ELF layout")
    sections = [struct.unpack_from(">IIIIIIIIII", data, header[5] + 40 * i)
                for i in range(header[11])]

    def contents(section):
        return bytes(section[5]) if section[1] == 8 else data[section[4]:section[4] + section[5]]

    def string(table, offset):
        return table[offset:table.index(b"\0", offset)].decode("utf-8")

    names = contents(sections[header[12]])
    section_names = [string(names, s[0]) for s in sections]
    allocated = {section_names[i]: (s[2], s[8], contents(s).hex())
                 for i, s in enumerate(sections) if s[2] & 2}
    relocations = []
    for section in sections:
        if section[1] not in (4, 9):
            continue
        table = sections[section[6]]
        strings = contents(sections[table[6]])
        step = 12 if section[1] == 4 else 8
        for position in range(section[4], section[4] + section[5], step):
            offset, info = struct.unpack_from(">II", data, position)
            addend = struct.unpack_from(">i", data, position + 8)[0] if step == 12 else 0
            sym = struct.unpack_from(">IIIBBH", data, table[4] + (info >> 8) * table[9])
            destination = (("section", section_names[sym[5]], sym[1])
                           if 0 < sym[5] < len(sections)
                           else ("external", string(strings, sym[0]), sym[1]))
            relocations.append((section_names[section[7]], offset, info & 255, destination, addend))
    return allocated, sorted(relocations)


def elf_symbols(data):
    """Read concrete linked symbol addresses/sizes, independent of report flags."""
    header = struct.unpack_from(">HHIIIIIHHHHHH", data, 16)
    require(data[:6] == b"\x7fELF\x01\x02" and header[1] == 20, "invalid linked PowerPC ELF")
    sections = [struct.unpack_from(">IIIIIIIIII", data, header[5] + 40 * i)
                for i in range(header[11])]
    result = {}
    for section in sections:
        if section[1] != 2:
            continue
        strings = sections[section[6]]
        names = data[strings[4]:strings[4] + strings[5]]
        for position in range(section[4], section[4] + section[5], section[9]):
            name, value, size, _, _, index = struct.unpack_from(">IIIBBH", data, position)
            if index and name:
                text = names[name:names.index(b"\0", name)].decode("utf-8")
                result[text] = (value, size)
    return result


def guard(root, expected_head=None, expected_index=None):
    head = git(root, "rev-parse", "HEAD").decode().strip()
    index = Path(git(root, "rev-parse", "--path-format=absolute", "--git-path", "index").decode().strip())
    index_hash = digest(index.read_bytes())
    require(not git(root, "diff", "--cached", "--name-only"), "index contains staged paths; checkpoint window is not exclusive")
    if expected_head:
        require(head == expected_head, f"HEAD guard conflict: expected {expected_head}, actual {head}")
    if expected_index:
        require(index_hash == expected_index, f"index hash guard conflict: expected {expected_index}, actual {index_hash}")
    dirty = git(root, "diff", "--name-only", "-z").decode("utf-8").split("\0")
    return {"head": head, "index_sha256": index_hash,
            "dirty": {name: digest((root / name).read_bytes()) for name in dirty if name != "CHANGELOG.md" and name}}


def bind_prior_source(prior, unit, source_path, source_object, raw_source, raw_object,
                      manifest, exceptions, evidence):
    """Preserve prior identity; require concrete input-bound interface exceptions.

    An exception supplies retained pre/post source bytes, the measured compiled
    object and its complete input snapshot. No prose ``unchanged``/``success``
    flag permits reuse. The prior object remains byte-identical, preserving its
    already accepted local-symbol/ABI qualifications rather than reinterpreting
    those historical comparisons or demanding another build.
    """
    require(prior.get("source_path") == source_path and prior.get("source_object") == source_object,
            f"prior accepted source/object path identity changed: {unit}")
    require(digest(raw_object) == prior.get("source_object_sha256"),
            f"prior accepted object identity changed: {unit}")
    previous = prior.get("source_sha256")
    if digest(raw_source) == previous:
        return "unchanged"
    lf = raw_source.replace(b"\r\n", b"\n")
    if previous in (digest(lf), digest(lf.replace(b"\n", b"\r\n"))):
        return "LF/CRLF only"
    record = exceptions.get(unit)
    require(record is not None, f"prior accepted source binding changed without input-bound exception: {unit}")
    require(record.get("source_path") == source_path and record.get("source_object") == source_object,
            f"prefix exception path identity differs: {unit}")
    pre = (evidence / relative(record["preimage"])).read_bytes()
    post = (evidence / relative(record["postimage"])).read_bytes()
    measured = (evidence / relative(record["compiled_object"])).read_bytes()
    inputs = load(evidence / relative(record["compiled_inputs"]))
    require(digest(pre) == previous and post == raw_source and digest(post) == manifest[source_path],
            f"prefix exception source pre/post binding differs: {unit}")
    require(measured == raw_object and inputs == manifest,
            f"prefix exception compiled object/complete input binding differs: {unit}")
    return "retained pre/post source and measured object/complete inputs bound"


def verify_evidence(args, output):
    root, build, evidence = args.root, args.integration_root, args.evidence
    frozen = output / "frozen-build"
    reused_snapshot = (output / "frozen-complete.json").exists()
    if reused_snapshot:
        build, evidence = frozen, output / "frozen-evidence"
    publication = load(evidence / "source-published.json")
    require(publication.get("commit") == args.source, "source publication receipt names a different full source commit")
    report_bytes = (evidence / "final-report.json").read_bytes()
    report_hash = digest(report_bytes)
    require(report_hash == publication.get("report_sha256"), "saved report hash differs from source publication receipt")
    report = json.loads(report_bytes)
    manifest = load(evidence / "complete-materialized-inputs.json")
    require(isinstance(manifest, dict) and manifest, "complete compiler-input manifest missing/empty")
    committed = tree_files(root, args.source, manifest)
    current = tree_files(root, git(root, "rev-parse", "HEAD").decode().strip(), manifest)
    require(committed == current, "current HEAD compiler inputs differ from the exact requested source commit")
    bindings = []
    committed_root = output / "committed-inputs"
    for name, expected in manifest.items():
        name = relative(name)
        raw = (build / name).read_bytes()
        require(digest(raw) == expected, f"compiled input hash mismatch: {name}")
        saved = committed[name]
        kind = "exact"
        if raw != saved:
            if raw.replace(b"\r\n", b"\n") == saved.replace(b"\r\n", b"\n"):
                kind = "LF/CRLF only"
            elif name.endswith("/splits.txt") and split_records(raw) == split_records(saved):
                kind = "all complete split records/fields/ranges/alignments equal"
            elif name.endswith("/symbols.txt") and symbols(raw) == symbols(saved):
                kind = "all complete symbol declarations equal"
            else:
                raise PublicationError(f"unbound committed compiler input: {name}")
        retain(committed_root / name, saved)
        retain(frozen / name, raw)
        bindings.append({"path": name, "compiled_sha256": expected,
                         "committed_sha256": digest(saved), "equivalence": kind})
    tools = load(evidence / "native-tool-identities.json")
    for name, expected in tools.items():
        tool = output / "frozen-tools" / expected["sha256"]
        raw = tool.read_bytes() if reused_snapshot else Path(name).read_bytes()
        require(digest(raw) == expected["sha256"] and len(raw) == expected["bytes"], f"native tool identity changed: {name}")
        retain(tool, raw)
    retain(output / "complete-input-binding.json", encode(bindings))
    retain(output / "source-publication-receipt.json", encode(publication))
    retain(output / "committed-report.json", report_bytes)
    tracker = ProgressTracker(output / "committed-report.json", committed_root, output / "classification-history.json")
    metrics = tracker._counter.calculate(report, committed_root)
    require(metrics == load(evidence / "source-progress-tool-output.json"), "saved progress differs from authoritative committed-source counter")
    unitmap, missing = tracker._classify_units(report)
    require(not missing, f"committed classification source missing: {missing}")
    unitmap = [{k: row[k] for k in ("id", "module", "bytes", "accepted")} for row in unitmap]
    modulemap = {}
    for row in unitmap:
        m = modulemap.setdefault(row["module"], dict(totalBytes=0, acceptedBytes=0, acceptedUnits=0, units=0))
        m["totalBytes"] += row["bytes"]
        m["units"] += 1
        if row["accepted"]:
            m["acceptedBytes"] += row["bytes"]
            m["acceptedUnits"] += 1
    project_bytes = (build / "objdiff.json").read_bytes()
    retain(frozen / "objdiff.json", project_bytes)
    registration = {u["name"]: u for u in json.loads(project_bytes)["units"]}
    report_units = {u["name"]: u for u in report["units"]}
    graph_bytes = (evidence / "actual-native-source-link-inputs.txt").read_bytes()
    graph = link_edges(graph_bytes.decode("utf-8"))
    require(graph, "saved native graph has no actual link edges")
    ninja_bytes = (build / "build.ninja").read_bytes()
    retain(frozen / "build.ninja", ninja_bytes)
    actual_graph = link_edges(ninja_bytes.decode("utf-8"))
    require(graph == actual_graph, "saved native link graph differs from verified build inputs")
    retain(output / "actual-native-source-link-inputs.txt", graph_bytes)
    prior_rows = load(evidence / "previous-accepted-source-object-identities.json")
    prefix = {r["unit"]: r for r in prior_rows}
    require(len(prefix) == len(prior_rows), "duplicate previous accepted unit identity")
    accepted_ids = {row["id"] for row in unitmap if row["accepted"]}
    require(set(prefix) <= accepted_ids,
            f"previous accepted unit missing or no longer accepted: {sorted(set(prefix) - accepted_ids)}")
    exception_path = evidence / "accepted-prefix-exceptions.json"
    exception_rows = load(exception_path) if exception_path.exists() else []
    exceptions = {row["unit"]: row for row in exception_rows}
    require(len(exceptions) == len(exception_rows) and set(exceptions) <= set(prefix),
            "duplicate or unbound accepted-prefix exception identity")
    proof = []
    for row in unitmap:
        if not row["accepted"]:
            continue
        reg = registration[row["id"]]
        unit = report_units[row["id"]]
        source_path = unit["metadata"]["source_path"]
        require(source_path in manifest, f"accepted source is absent from complete input manifest: {source_path}")
        base, target = relative(reg["base_path"]), relative(reg["target_path"])
        uses = [edge for edge, inputs in graph.items() if base in inputs]
        require(uses and not any(target in inputs for inputs in graph.values()), f"accepted source object not exclusively linked: {row['id']}")
        source_object, target_object = (build / base).read_bytes(), (build / target).read_bytes()
        prior = prefix.get(row["id"])
        binding = None
        if prior is not None:
            binding = bind_prior_source(prior, row["id"], source_path, base,
                                        (build / source_path).read_bytes(), source_object,
                                        manifest, exceptions, evidence)
        reused = prior is not None
        if not reused:
            require(elf_image(source_object) == elf_image(target_object), f"allocated bytes/relocations differ: {row['id']}")
            linked = next((edge for edge in uses if edge.endswith((".elf", ".plf")) and not edge.endswith(".preplf")), None)
            require(linked, f"no final ELF/PLF source link edge: {row['id']}")
            linked_bytes = (build / relative(linked)).read_bytes()
            retain(frozen / relative(linked), linked_bytes)
            definitions = elf_symbols(linked_bytes)
            for function in unit.get("functions", []):
                address = function.get("metadata", {}).get("virtual_address")
                if address is not None:
                    expected_symbol = (int(address), int(function["size"]))
                    require(definitions.get(function["name"]) == expected_symbol,
                            f"final linked symbol identity differs: {function['name']}")
        retain(frozen / base, source_object)
        retain(frozen / target, target_object)
        proof.append({"unit": row["id"], "source_path": source_path,
                      "source_object": base, "source_object_sha256": digest(source_object),
                      "target_object": target, "target_object_sha256": digest(target_object),
                      "native_link_edges": uses, "prior_object_reused": reused,
                      "compiled_source_sha256": manifest[source_path],
                      "prior_source_binding": binding})
    # Incomplete C/C++ drafts must keep their original fallback, not gain credit
    # from a fuzzy percentage or merely appearing in the generated project.
    for unit in report["units"]:
        m = unit.get("metadata", {})
        if m.get("complete") or Path(m.get("source_path") or "").suffix.lower() not in tracker._counter.SOURCE_SUFFIXES:
            continue
        reg = registration.get(unit["name"])
        if not reg:
            continue
        base, target = relative(reg["base_path"]), relative(reg["target_path"])
        require(not any(base in inputs for inputs in graph.values()) and any(target in inputs for inputs in graph.values()),
                f"nonmatching draft fallback/link exclusion failed: {unit['name']}")
        retain(frozen / target, (build / target).read_bytes())
    hashes = []
    manifest_name = "config/RSBE01_02/build.sha1"
    require(manifest_name in committed, "expected native hash manifest not bound to source commit")
    for line in committed[manifest_name].decode().splitlines():
        expected, name = line.split(None, 1)
        name = relative(name.strip())
        raw = (build / name).read_bytes()
        require(digest(raw, "sha1") == expected, f"native final hash mismatch: {name}")
        retain(frozen / name, raw)
        hashes.append({"path": name, "sha1": expected, "sha256": digest(raw)})
    require(len(hashes) == len(modulemap), "native artifact count differs from complete module map")
    retain(output / "native-final-hashes.json", encode(hashes))
    retain(output / "source-provenance-link-proof.json", encode(proof))
    retain(output / "expected-unit-map.json", encode(unitmap))
    retain(output / "expected-module-accounting.json", encode(modulemap))
    for name in ("source-published.json", "final-report.json", "complete-materialized-inputs.json",
                 "source-progress-tool-output.json", "native-tool-identities.json",
                 "actual-native-source-link-inputs.txt", "previous-accepted-source-object-identities.json"):
        retain(output / "frozen-evidence" / name, (evidence / name).read_bytes())
    if exception_rows:
        retain(output / "frozen-evidence" / "accepted-prefix-exceptions.json", encode(exception_rows))
        for record in exception_rows:
            for key in ("preimage", "postimage", "compiled_object", "compiled_inputs"):
                name = relative(record[key])
                retain(output / "frozen-evidence" / name, (evidence / name).read_bytes())
    retain(output / "frozen-complete.json", encode({"source": args.source, "report_sha256": report_hash}))
    return report_bytes, report_hash, metrics, unitmap, modulemap, len(manifest), len(hashes)


def expected_headline(source, metrics):
    return dict(acceptedBytes=metrics["accepted_source_code_bytes"], totalBytes=metrics["total_code_bytes"],
                remainingBytes=metrics["remaining_code_bytes"], percent=round(metrics["percent_complete"], 6),
                acceptedUnits=metrics["accepted_source_units"], commit=source)


def checkpoint_entry(source, report_hash, metrics, previous, inputs, artifacts, units, modules):
    return (f"## Committed-source checkpoint {source[:8]}\n\n"
            f"- Verified committed snapshot `{source}`; report SHA-256 `{report_hash}`. "
            f"Saved complete-input/object/link evidence and **{artifacts}/{artifacts} native hashes** "
            f"are independently checked; **{inputs} compiler inputs** bind this exact source. "
            "No unchanged build/report regeneration or mutable future-output substitution.\n"
            f"- **{metrics['percent_complete']:.6f}%** complete: **{metrics['accepted_source_code_bytes']} / "
            f"{metrics['total_code_bytes']} accepted code bytes**, **{metrics['remaining_code_bytes']} code bytes remaining**, "
            f"**{metrics['accepted_source_units']} accepted source units**.\n"
            f"- Delta from `{previous['commit']}`: **+{metrics['accepted_source_code_bytes'] - previous['acceptedBytes']} "
            f"accepted code bytes / +{metrics['accepted_source_units'] - previous['acceptedUnits']} source units**. "
            f"The complete map has **{units} units across {modules} modules**. "
            "Assembly/inline assembly, incomplete drafts and original fallback code retain their existing credit exclusions.\n"
            "- Original unit attempt, ABI, prefix, EOL, runtime and adaptive qualifications remain in their source-assignment "
            "entries and retained evidence. Gameplay was not exercised by checkpoint publication; no worker/model/service "
            "or original-input changes were made. All original/copy/junction/evidence HOLDs remain.\n\n")


def observe(args, output, expected, unitmap, modulemap, report_hash):
    deadline = time.monotonic() + args.timeout
    error = "endpoint agreement not observed"
    while True:
        responses = {}
        try:
            for label, url in (("local", args.local_url), ("public", args.public_url)):
                for route in ("state", "units"):
                    with urlopen(url.rstrip("/") + "/api/" + route, timeout=min(10, args.timeout)) as response:
                        responses[label + "-" + route] = json.load(response)
            history = load(args.history)
            require(history, "persisted progress history is empty")
            for label in ("local", "public"):
                state, units = responses[label + "-state"], responses[label + "-units"]
                require(state["session"] == args.session, f"{label} dashboard root/session mismatch")
                p = state["progress"]
                require(all(p.get(k) == v for k, v in expected.items()), f"{label} full-source/headline mismatch: {p}")
                require(p.get("available") and p.get("error") is None and not p.get("lastGood") and not state["warnings"],
                        f"{label} unavailable/stale/warning checkpoint")
                provenance = state["unitsProvenance"]
                require(not provenance["stale"] and provenance["acceptedBytes"] == expected["acceptedBytes"]
                        and provenance["acceptedUnits"] == expected["acceptedUnits"], f"{label} report provenance mismatch")
                actual = [{k: u[k] for k in ("id", "module", "bytes", "accepted")} for u in units["units"]]
                require(actual == unitmap, f"{label} complete unit/module classifications differ")
                require(units["acceptedBytes"] == expected["acceptedBytes"] and units["acceptedUnits"] == expected["acceptedUnits"],
                        f"{label} unit-map totals differ")
                require(state["history"] and state["history"][-1] == history[-1]
                        and history[-1]["acceptedBytes"] == expected["acceptedBytes"], f"{label} served/persisted history mismatch")
            require(responses["local-units"] == responses["public-units"], "local/public complete unit responses differ")
            require(digest((args.root / "build/RSBE01_02/report.json").read_bytes()) == report_hash, "published report bytes changed")
            for key, value in responses.items():
                atomic(output / ("final-" + key + ".json"), encode(value))
            atomic(output / "final-persisted-history.json", encode(history))
            return {"source_commit": args.source, "report_sha256": report_hash, "endpoints": {
                label: {"headline": responses[label + "-state"]["progress"], "root": args.session,
                        "unit_count": len(unitmap), "module_count": len(modulemap),
                        "all_unit_module_classifications_agree": True,
                        "latest_served_history": responses[label + "-state"]["history"][-1],
                        "latest_persisted_history": history[-1]} for label in ("local", "public")}}
        except (OSError, ValueError, KeyError, PublicationError) as exc:
            error = str(exc)
            atomic(output / "last-endpoint-observation.json", encode({"error": error, "responses": responses}))
        if time.monotonic() >= deadline:
            raise PublicationError(error)
        time.sleep(min(0.5, max(0, deadline - time.monotonic())))


def run(args):
    require(re.fullmatch(r"[0-9a-f]{40}", args.source), "source must be the exact full 40-character commit")
    output = args.receipts / args.source
    output.mkdir(parents=True, exist_ok=True)
    phase = "preflight"
    rollback = None
    try:
        require(not args.publish or (args.expected_head and args.expected_index_sha256),
                "checkpoint writes require exact HEAD/index window guards, including duplicate pushes")
        initial = guard(args.root, args.expected_head, args.expected_index_sha256)
        git(args.root, "merge-base", "--is-ancestor", args.source, initial["head"])
        clog_path = args.root / "CHANGELOG.md"
        clog_raw = clog_path.read_bytes()
        old_blob = git(args.root, "rev-parse", "HEAD:CHANGELOG.md").decode().strip()
        clean_blob = git(args.root, "hash-object", "--path=CHANGELOG.md", "--stdin", data=clog_raw).decode().strip()
        require(old_blob == clean_blob, "CHANGELOG has uncommitted bytes; checkpoint insertion is not owned")
        previous = ProgressTracker._parse_checkpoint(clog_raw.decode("utf-8"))
        report, report_hash, metrics, unitmap, modulemap, inputs, artifacts = verify_evidence(args, output)
        expected = expected_headline(args.source, metrics)
        same = previous["commit"] == args.source
        require(not same or all(previous[k] == v for k, v in expected.items()), "existing source checkpoint has inconsistent counters")
        if not same:
            require(args.publish, "new checkpoint requires --publish and exact HEAD/index window guards")
            remote = git(args.root, "ls-remote", "origin", "refs/heads/main").decode().split()
            require(remote and remote[0] == initial["head"], "origin/main does not equal the granted HEAD; source push/publication is incomplete")
            entry = checkpoint_entry(args.source, report_hash, metrics, previous, inputs, artifacts, len(unitmap), len(modulemap)).encode()
            canonical = git(args.root, "show", "HEAD:CHANGELOG.md")
            match = re.search(rb"(?m)^## ", canonical)
            require(match is not None, "CHANGELOG insertion anchor missing")
            new_canonical = canonical[:match.start()] + entry + canonical[match.start():]
            raw_anchor = re.search(rb"(?m)^## ", clog_raw)
            raw_entry = entry.replace(b"\n", b"\r\n") if clog_raw.count(b"\r\n") == clog_raw.count(b"\n") else entry
            new_raw = clog_raw[:raw_anchor.start()] + raw_entry + clog_raw[raw_anchor.start():]
            doc_blob = git(args.root, "hash-object", "-w", "--no-filters", "--stdin", data=new_canonical).decode().strip()
            index = output / "checkpoint.index"
            git(args.root, "read-tree", initial["head"], index=index)
            git(args.root, "update-index", "--cacheinfo", f"100644,{doc_blob},CHANGELOG.md", index=index)
            patch = git(args.root, "diff", "--cached", "--binary", "--full-index", initial["head"], "--", "CHANGELOG.md", index=index)
            retain(output / "checkpoint.patch", patch)
            validated = output / "validated.index"
            git(args.root, "read-tree", initial["head"], index=validated)
            git(args.root, "apply", "--cached", "--binary", str(output / "checkpoint.patch"), index=validated)
            require(git(args.root, "diff", "--cached", "--name-only", index=validated).decode().splitlines() == ["CHANGELOG.md"], "private checkpoint patch is not own-only")
            require(guard(args.root, args.expected_head, args.expected_index_sha256) == initial, "MAIN dirty-byte guards changed during private verification")
            require(clog_path.read_bytes() == clog_raw, "CHANGELOG changed during checkpoint preparation")
            retain(output / "previous-changelog.bin", clog_raw)
            live_report = args.root / "build/RSBE01_02/report.json"
            if live_report.exists():
                retain(output / "previous-report.json", live_report.read_bytes())
            phase = "validated-report-publication"
            index_path = Path(git(args.root, "rev-parse", "--path-format=absolute", "--git-path", "index").decode().strip())
            rollback = {"index_path": index_path, "index_bytes": index_path.read_bytes(),
                        "report_path": live_report, "report_bytes": live_report.read_bytes() if live_report.exists() else None,
                        "clog_path": clog_path, "clog_bytes": clog_raw,
                        "new_clog": new_raw, "new_report": report,
                        "original_entries": git(args.root, "ls-files", "--stage"), "owned_entries": None}
            atomic(live_report, report, (args.evidence / "final-report.json").stat().st_mtime)
            atomic(clog_path, new_raw)
            git(args.root, "apply", "--cached", "--binary", str(output / "checkpoint.patch"))
            rollback["owned_entries"] = git(args.root, "ls-files", "--stage")
            require(git(args.root, "diff", "--cached", "--name-only").decode().splitlines() == ["CHANGELOG.md"], "unexpected staged paths after checkpoint staging")
            phase = "checkpoint-staged"
            commit_output = git(args.root, "commit", "-m", f"Record verified source checkpoint {args.source[:8]}", transcript=True)
            rollback = None
            retain(output / "commit-output.txt", commit_output)
            require(git(args.root, "diff-tree", "--no-commit-id", "--name-only", "-r", "HEAD").decode().splitlines() == ["CHANGELOG.md"],
                    "checkpoint commit contains unexpected paths")
            require(git(args.root, "rev-parse", "HEAD:CHANGELOG.md").decode().strip() == doc_blob,
                    "checkpoint commit differs from validated changelog postimage")
        else:
            section = re.split(r"(?m)^## ", clog_raw.decode("utf-8"))[1]
            require(report_hash in section, "existing source checkpoint has a different report hash")
            require(digest((args.root / "build/RSBE01_02/report.json").read_bytes()) == report_hash,
                    "existing published report hash differs; no duplicate publication performed")
        phase = "checkpoint-committed"
        doc_head = git(args.root, "rev-parse", "HEAD").decode().strip()
        # Push only when the caller granted writes. A duplicate read-only proof
        # cannot silently publish somebody else's pending documentation commit.
        if args.publish:
            push_output = git(args.root, "push", "origin", "HEAD:main", transcript=True)
            atomic(output / "push-output.txt", push_output)
        remote = git(args.root, "ls-remote", "origin", "refs/heads/main").decode().split()
        require(remote and remote[0] == doc_head, "checkpoint documentation is not pushed at the current HEAD")
        phase = "checkpoint-pushed"
        checkpoint = ProgressTracker._parse_checkpoint(clog_path.read_text(encoding="utf-8"))
        dated, warning = read_checkpoint_publication(args.root, clog_path.read_text(encoding="utf-8"), checkpoint)
        require(dated and not warning, f"actual checkpoint Git publication date unavailable: {warning}")
        expected.update({"checkpointTitle": checkpoint["checkpointTitle"], "acceptedBytesDelta": checkpoint["acceptedBytesDelta"],
                         "acceptedUnitsDelta": checkpoint["acceptedUnitsDelta"], "updatedAt": dated["at"]})
        final = observe(args, output, expected, unitmap, modulemap, report_hash)
        after = guard(args.root)
        require(after["dirty"] == initial["dirty"], "unrelated tracked dirty bytes changed during checkpoint publication")
        final.update(status="checkpoint-verified", documentation_commit=dated.get("commit"), root_head=doc_head, duplicate=same,
                     observed_at=datetime.now(timezone.utc).isoformat(), native_artifacts=artifacts,
                     compiler_inputs=inputs, metrics=metrics, cachedempty=True, unrelated_dirty_bytes_preserved=True)
        atomic(output / "final-endpoint-agreement.json", encode(final))
        atomic(args.receipts / "last-verified.json", encode(final))
        return final
    except Exception as exc:
        rollback_error = None
        if rollback is not None:
            try:
                require(git(args.root, "rev-parse", "HEAD").decode().strip() == initial["head"],
                        "HEAD changed; cannot restore pre-commit publication")
                # A failed Git commit may refresh stat/cache extensions without
                # changing ownership. Compare all actual stage-0 entries before
                # restoring the exact original index bytes, not refreshed bytes.
                require(git(args.root, "ls-files", "--stage") in {
                    rollback["original_entries"], rollback["owned_entries"]},
                    "index entries changed; cannot restore pre-commit publication")
                require(rollback["clog_path"].read_bytes() in (rollback["clog_bytes"], rollback["new_clog"]),
                        "changelog ownership changed; cannot restore pre-commit publication")
                require(rollback["report_bytes"] is not None, "no prior report to restore; retain failed publication evidence")
                require(rollback["report_path"].read_bytes() in (rollback["report_bytes"], rollback["new_report"]),
                        "report ownership changed; cannot restore pre-commit publication")
                atomic(rollback["report_path"], rollback["report_bytes"])
                atomic(rollback["clog_path"], rollback["clog_bytes"])
                atomic(rollback["index_path"], rollback["index_bytes"])
            except (OSError, PublicationError) as restore_error:
                rollback_error = str(restore_error)
        atomic(output / f"failure-{time.time_ns()}.json", encode({"phase": phase, "source_commit": args.source,
               "error": f"{type(exc).__name__}: {exc}", "last_verified_receipt_unchanged": True,
               "precommit_restore_blocker": rollback_error}))
        raise


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    for name in ("root", "integration-root", "evidence", "receipts"):
        parser.add_argument("--" + name, type=Path, required=True)
    parser.add_argument("--source", required=True)
    parser.add_argument("--session", required=True)
    parser.add_argument("--public-url", required=True)
    parser.add_argument("--local-url", default="http://127.0.0.1:8765")
    parser.add_argument("--history", type=Path)
    parser.add_argument("--publish", action="store_true")
    parser.add_argument("--expected-head")
    parser.add_argument("--expected-index-sha256")
    parser.add_argument("--timeout", type=float, default=30)
    args = parser.parse_args(argv)
    args.history = args.history or args.root / "build/live-dashboard/history.json"
    try:
        result = run(args)
    except (OSError, ValueError, KeyError, PublicationError) as exc:
        print(f"checkpoint publication failed: {exc}", file=sys.stderr)
        return 1
    print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
