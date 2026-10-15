"""Explicit project-local dependency installation; never changes global Python/config."""
from __future__ import annotations

import argparse
from pathlib import Path
import subprocess
import sys

from .safety import BUILD, NO_WINDOW, WORKTREE, check_worktree, confined, isolated_environment, now, save_json


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--authorize-isolated-install", action="store_true", required=True)
    args = parser.parse_args()
    check_worktree()
    root = confined(BUILD / "dependencies")
    env = isolated_environment(root)
    venv = confined(root / "venv")
    python = venv / "Scripts" / "python.exe"
    steps = []

    def run(argv, label):
        result = subprocess.run(argv, cwd=WORKTREE, env=env, capture_output=True, text=True,
                                creationflags=NO_WINDOW, timeout=900)
        record = {"argv": argv, "returncode": result.returncode, "stdout": result.stdout,
                  "stderr": result.stderr, "completed_at": now()}
        save_json(root / f"{label}.json", record)
        steps.append(record)
        if result.returncode:
            raise RuntimeError(f"{label} failed; retained evidence: {root / (label + '.json')}")
        return result.stdout

    if not python.exists():
        run([sys.executable, "-B", "-m", "venv", "--without-pip", str(venv)], "create-venv")
        run([str(python), "-B", "-m", "ensurepip", "--default-pip"], "bootstrap-pip")
    run([str(python), "-B", "-m", "pip", "--isolated", "install", "--disable-pip-version-check",
         "--prefix", str(venv), "--cache-dir", env["PIP_CACHE_DIR"], "pip==25.2"], "pin-pip")
    run([str(python), "-B", "-m", "pip", "--isolated", "install", "--disable-pip-version-check",
         "--prefix", str(venv), "--cache-dir", env["PIP_CACHE_DIR"], "--only-binary=:all:", "-r",
         str(WORKTREE / "tools" / "orchestration_eval" / "requirements.txt")], "install")
    freeze = run([str(python), "-B", "-m", "pip", "--isolated", "freeze", "--all"], "resolved-packages")
    (root / "resolved-requirements.txt").write_text(freeze, encoding="utf-8")
    save_json(root / "installation.json", {"python": str(python), "finished_at": now(),
                                          "requirements": "prefect==3.8.8; pytest==8.4.2; pip==25.2",
                                          "steps": len(steps)})
    print(str(python))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
