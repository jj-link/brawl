"""A retained bootstrap: target starts only after the parent assigns its Windows job."""
from __future__ import annotations

import json
import os
from pathlib import Path
import subprocess
import sys
import time

from .safety import NO_WINDOW, confined, now, save_json


def main() -> int:
    spec_path = confined(Path(sys.argv[1]))
    spec = json.loads(spec_path.read_text(encoding="utf-8"))
    directory = confined(Path(spec["directory"]))
    gate = directory / "go.json"
    deadline = time.monotonic() + 30
    while not gate.exists():
        if time.monotonic() >= deadline:
            return 125
        time.sleep(0.02)
    if json.loads(gate.read_text(encoding="utf-8"))["token"] != spec["token"]:
        return 126
    # On Windows all-None stdio skips STARTF_USESTDHANDLES. With a hidden,
    # close-fds child that loses the wrapper's redirected logs/RPC pipes.
    child = subprocess.Popen(
        spec["argv"], cwd=confined(spec["cwd"]), creationflags=NO_WINDOW,
        stdin=sys.stdin.buffer, stdout=sys.stdout.buffer, stderr=sys.stderr.buffer,
        close_fds=True,
    )
    save_json(directory / "child.json", {"pid": child.pid, "host_pid": os.getpid(), "started_at": now(), "token": spec["token"]})
    return child.wait()


if __name__ == "__main__":
    raise SystemExit(main())
