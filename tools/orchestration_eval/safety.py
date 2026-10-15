"""Fail-closed filesystem and environment boundaries for the opt-in pilot."""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import stat
import subprocess
from datetime import datetime, timezone

WORKTREE = Path(__file__).resolve().parents[2]
BUILD = WORKTREE / "build" / "orchestration-eval"
ACTIVE = WORKTREE.parents[2]
NO_WINDOW = getattr(subprocess, "CREATE_NO_WINDOW", 0)


class SafetyError(RuntimeError):
    pass


def now() -> str:
    return datetime.now(timezone.utc).isoformat()


def under(path: Path, root: Path) -> bool:
    return path == root or root in path.parents


def confined(path: Path | str, root: Path = BUILD) -> Path:
    path = Path(os.path.abspath(path))
    root = Path(os.path.abspath(root))
    if not under(path, root):
        raise SafetyError(f"Refusing unowned path: {path}")
    # resolve() alone would silently accept junctions pointing into another owned tree.
    for item in (path, *path.parents):
        if item.exists() or item.is_symlink():
            attrs = item.lstat()
            if item.is_symlink() or getattr(attrs, "st_file_attributes", 0) & stat.FILE_ATTRIBUTE_REPARSE_POINT:
                raise SafetyError(f"Refusing filesystem link/reparse point: {item}")
            if stat.S_ISREG(attrs.st_mode) and attrs.st_nlink != 1:
                raise SafetyError(f"Refusing multiply linked file: {item}")
    if path.resolve() != path:
        raise SafetyError(f"Non-canonical evaluation path: {path}")
    return path


def check_worktree() -> None:
    expected = ACTIVE / "build" / "isolated-workers" / "PrefectOmpEvaluation"
    if os.name != "nt" or WORKTREE != expected or not (WORKTREE / ".git").is_file():
        raise SafetyError("Pilot requires the authorized native-Windows detached evaluation worktree")
    common = subprocess.run(
        ["git", "-C", str(WORKTREE), "rev-parse", "--path-format=absolute", "--git-common-dir"],
        capture_output=True, text=True, check=True, creationflags=NO_WINDOW,
        env=isolated_environment(BUILD / "boundary", create=False),
    ).stdout.strip()
    if Path(common).resolve() != (ACTIVE / ".git").resolve():
        raise SafetyError("Unexpected evaluation common-Git identity")
    confined(BUILD)


def save_json(path: Path, value: object) -> None:
    path = confined(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    # Keep predecessor records, rather than using a disposable staging directory.
    replacement = path.with_name(path.name + ".pending")
    confined(replacement)
    with replacement.open("w", encoding="utf-8", newline="\n") as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write("\n")
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(replacement, path)


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def isolated_environment(root: Path, *, create: bool = True) -> dict[str, str]:
    root = confined(root)
    # Never inherit provider credentials, OMP routes, external Prefect API addresses,
    # Python injection, Git index/config overrides, or the live user's home.
    allowed = {"SYSTEMROOT", "WINDIR", "COMSPEC", "PATH", "PATHEXT", "SYSTEMDRIVE", "PROCESSOR_ARCHITECTURE", "NUMBER_OF_PROCESSORS"}
    result = {k: v for k, v in os.environ.items() if k.upper() in allowed}
    locations = {
        "HOME": "home", "USERPROFILE": "home", "APPDATA": "home/roaming",
        "LOCALAPPDATA": "home/local", "XDG_CONFIG_HOME": "home/config",
        "XDG_CACHE_HOME": "cache", "XDG_DATA_HOME": "home/data",
        "TEMP": "scratch", "TMP": "scratch", "TMPDIR": "scratch",
        "PIP_CACHE_DIR": "cache/pip", "UV_CACHE_DIR": "cache/uv",
        "BUN_INSTALL_CACHE_DIR": "cache/bun", "PYTHONPYCACHEPREFIX": "cache/pycache",
        "PI_CODING_AGENT_DIR": "omp/agent", "PI_NATIVES_DIR": "omp/natives",
        "PREFECT_HOME": "prefect", "PREFECT_LOCAL_STORAGE_PATH": "prefect/results",
    }
    for key, relative in locations.items():
        location = confined(root / relative)
        if create:
            location.mkdir(parents=True, exist_ok=True)
        result[key] = str(location)
    result.update({
        "PI_CONFIG_DIR": ".omp", "PI_NO_TITLE": "1", "PI_NO_PTY": "1",
        "OMP_SKIP_SETUP": "1", "PI_AUTO_QA": "0", "OTEL_SDK_DISABLED": "true",
        "PYTHONDONTWRITEBYTECODE": "1", "PYTHONNOUSERSITE": "1", "PYTHONUTF8": "1",
        "PYTHONPATH": str(WORKTREE), "GIT_CONFIG_NOSYSTEM": "1",
        "GIT_CONFIG_GLOBAL": str(root / "home" / "empty.gitconfig"),
        "GIT_TERMINAL_PROMPT": "0", "GIT_CEILING_DIRECTORIES": str(root),
        "PREFECT_SERVER_ANALYTICS_ENABLED": "false", "PREFECT_SERVER_UI_ENABLED": "false",
        "PREFECT_SERVER_EPHEMERAL_ENABLED": "false", "PREFECT_API_ENABLE_HTTP2": "false",
        "PREFECT_LOGGING_TO_API_ENABLED": "true",
        "PREFECT_SERVER_DATABASE_CONNECTION_URL": "sqlite+aiosqlite:///" + (root / "prefect" / "prefect.db").as_posix(),
    })
    return result
