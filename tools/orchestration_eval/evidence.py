"""Content identities for explicitly declared, complete verification inputs.

A manifest is a dependency declaration, not a dependency scanner or proof of C++
correctness. The owner supplies every source, header, configuration and tool file,
plus the exact recipe. Git HEAD deliberately does not participate in its identity.
"""
from __future__ import annotations

import hashlib
import json
import os
from dataclasses import dataclass
from pathlib import Path, PurePosixPath
from typing import Any, Mapping, Sequence


CATEGORIES = ("source", "header", "config", "tool")


class InputError(ValueError):
    """An input declaration cannot safely identify regular local files."""


def canonical_json(value: Any) -> str:
    return json.dumps(value, sort_keys=True, separators=(",", ":"), ensure_ascii=True, allow_nan=False)


def content_identity(value: Any) -> str:
    return hashlib.sha256(canonical_json(value).encode("utf-8")).hexdigest()


def relative_path(value: str) -> str:
    if not isinstance(value, str) or not value or any(ord(c) < 32 or c in '\\\\:<>\"|?*' for c in value):
        raise InputError(f"Expected a portable relative path: {value!r}")
    path = PurePosixPath(value)
    parts = value.split("/")
    reserved = {"con", "prn", "aux", "nul", *(f"com{i}" for i in range(1, 10)),
                *(f"lpt{i}" for i in range(1, 10))}
    if (path.is_absolute() or str(path) != value or
            any(part.casefold() in (".", "..", ".git") or part.endswith((" ", ".")) or
                part.split(".", 1)[0].casefold() in reserved for part in parts)):
        raise InputError(f"Unsafe or noncanonical input path: {value!r}")
    return value


def reject_links(path: Path) -> None:
    """Reject links and Windows junctions in existing path components."""
    for component in (path, *path.parents):
        if component.is_symlink() or getattr(component, "is_junction", lambda: False)():
            raise InputError(f"Linked path is not an owned regular path: {component}")
        if component.is_file() and component.stat().st_nlink > 1:
            raise InputError(f"Hard-linked file is not exclusively owned: {component}")
        if os.name == "nt" and component.exists():
            if getattr(component.stat(follow_symlinks=False), "st_file_attributes", 0) & 0x400:
                raise InputError(f"Reparse point is not an owned regular path: {component}")


def input_path(root: Path, relative: str, *, must_exist: bool = True) -> Path:
    relative_path(relative)
    root = Path(root).absolute()
    reject_links(root)
    candidate = root.joinpath(*PurePosixPath(relative).parts)
    reject_links(candidate)
    if not candidate.resolve().is_relative_to(root.resolve()):
        raise InputError(f"Input escapes its root: {relative}")
    if must_exist and not candidate.is_file():
        raise InputError(f"Input is not a regular file: {relative}")
    return candidate


def file_identity(path: Path) -> dict[str, Any]:
    digest = hashlib.sha256()
    size = 0
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            size += len(block)
            digest.update(block)
    return {"sha256": digest.hexdigest(), "size": size}


@dataclass(frozen=True)
class InputManifest:
    """Immutable canonical payload; returned dictionaries are independent copies."""

    payload_json: str
    identity: str

    def to_dict(self) -> dict[str, Any]:
        return {**json.loads(self.payload_json), "identity": self.identity}

    @classmethod
    def from_dict(cls, value: Mapping[str, Any]) -> "InputManifest":
        payload = dict(value)
        claimed = payload.pop("identity", None)
        if set(payload) != {"schema", "inputs", "recipe"} or payload["schema"] != 1:
            raise InputError("Unsupported input manifest schema")
        inputs = payload["inputs"]
        if not isinstance(inputs, dict) or set(inputs) != set(CATEGORIES):
            raise InputError("Manifest must declare source/header/config/tool inputs")
        if not isinstance(payload["recipe"], dict) or not payload["recipe"]:
            raise InputError("An exact, nonempty verification recipe is required")
        if not inputs["source"]:
            raise InputError("At least one source input is required")
        spellings: dict[str, str] = {}
        for category in CATEGORIES:
            if not isinstance(inputs[category], dict):
                raise InputError(f"Invalid {category} input map")
            for name, record in inputs[category].items():
                relative_path(name)
                folded = name.casefold()
                if folded in spellings and spellings[folded] != name:
                    raise InputError("Case-colliding input paths are ambiguous on Windows")
                spellings[folded] = name
                if not isinstance(record, dict) or set(record) != {"sha256", "size"}:
                    raise InputError(f"Invalid input identity for {name}")
                sha = record["sha256"]
                if not isinstance(sha, str) or len(sha) != 64 or any(c not in "0123456789abcdef" for c in sha):
                    raise InputError(f"Invalid SHA-256 for {name}")
                if type(record["size"]) is not int or record["size"] < 0:
                    raise InputError(f"Invalid byte count for {name}")
        identity = content_identity(payload)
        if claimed != identity:
            raise InputError("Input manifest identity does not match its contents")
        return cls(canonical_json(payload), identity)

    @property
    def paths(self) -> tuple[str, ...]:
        inputs = self.to_dict()["inputs"]
        return tuple(sorted({path for group in inputs.values() for path in group}))


@dataclass(frozen=True)
class ValidationResult:
    valid: bool
    changed: tuple[str, ...]
    current_identity: str | None


def capture_inputs(root: str | Path, inputs: Mapping[str, Sequence[str]], recipe: Mapping[str, Any]) -> InputManifest:
    """Record raw bytes, paths, dependency roles and recipe, never a HEAD proxy."""
    if set(inputs) != set(CATEGORIES):
        raise InputError("Declare every input category, using [] only when genuinely absent")
    recorded: dict[str, dict[str, Any]] = {}
    for category in CATEGORIES:
        names = list(inputs[category])
        if len(names) != len(set(names)):
            raise InputError(f"Duplicate {category} input path")
        recorded[category] = {name: file_identity(input_path(Path(root), name)) for name in sorted(names)}
    payload = {"schema": 1, "inputs": recorded, "recipe": dict(recipe)}
    return InputManifest.from_dict({**payload, "identity": content_identity(payload)})


def validate_inputs(root: str | Path, manifest: InputManifest) -> ValidationResult:
    """Re-read every declared input; missing/linked inputs invalidate evidence."""
    manifest = InputManifest.from_dict(manifest.to_dict())
    payload = manifest.to_dict()
    changed: set[str] = set()
    complete = True
    current: dict[str, dict[str, Any]] = {}
    for category, records in payload["inputs"].items():
        current[category] = {}
        for name, expected in records.items():
            try:
                actual = file_identity(input_path(Path(root), name))
            except (OSError, InputError):
                changed.add(name)
                complete = False
                continue
            current[category][name] = actual
            if actual != expected:
                changed.add(name)
    identity = content_identity({"schema": 1, "inputs": current, "recipe": payload["recipe"]}) if complete else None
    return ValidationResult(not changed, tuple(sorted(changed)), identity)
