"""Fresh-process publication/recovery exercise, restricted to retained local fixtures."""
from __future__ import annotations

import argparse
from dataclasses import asdict
import json
import os
from pathlib import Path
import time

from .publication import FixtureScope, GitPublisher, InjectedCrash, PublicationRequest
from .safety import ACTIVE, WORKTREE, confined, save_json
from .state import Ledger


class StopAfterAdmissionLedger(Ledger):
    """Native race fixture: STOP is persisted after the real durable admission."""

    def __init__(self, path, *, kind: str, output: Path):
        super().__init__(path)
        self.stop_kind, self.stop_output = kind, output

    def admit_publication_effect(self, assignment_id, **values):
        admission = super().admit_publication_effect(assignment_id, **values)
        if admission["execute"] and values["kind"] == self.stop_kind:
            began = time.monotonic()
            self.request_stop(event_id="native-stop-after-" + self.stop_kind,
                              reason="Owned native fixture STOP after durable Git-effect admission")
            save_json(self.stop_output, {"admission": admission, "authorization": self.authorization(),
                                        "stop_seconds": time.monotonic() - began, "pid": os.getpid(),
                                        "qualification": "STOP precedes the admitted native Git effect; no new step is authorized"})
        return admission


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, required=True)
    parser.add_argument("--request", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--event", required=True)
    parser.add_argument("--fault", choices=("after_commit", "after_push"))
    parser.add_argument("--stop-after-admission", choices=("commit", "push"))
    parser.add_argument("--authorize-isolated-evaluation", action="store_true", required=True)
    args = parser.parse_args()
    root = confined(args.root)
    request = PublicationRequest.from_dict(json.loads(confined(args.request, root).read_text(encoding="utf-8")))
    scope = FixtureScope(root, (ACTIVE, WORKTREE, ACTIVE / ".git"), authorized=True)
    ledger = (StopAfterAdmissionLedger(root / "ledger.sqlite3", kind=args.stop_after_admission,
                                      output=confined(args.output, root).with_name("stop-after-admission.json"))
              if args.stop_after_admission else Ledger(root / "ledger.sqlite3"))
    publisher = GitPublisher(scope, ledger, root / "publication")
    try:
        result = publisher.publish(request, event_id=args.event, fault_at=args.fault)
    except InjectedCrash as exc:
        save_json(confined(args.output, root), {"crash_boundary": args.fault, "detail": str(exc), "pid": os.getpid()})
        # Deliberately do not run Python cleanup: recovery must read durable Git/SQLite outcomes.
        os._exit(75)
    save_json(confined(args.output, root), asdict(result))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
