"""Explicit, evaluation-only authorization and canonical model-stage limits."""

from dataclasses import dataclass
from enum import Enum
from pathlib import Path
from types import MappingProxyType


class PolicyError(ValueError):
    """An operation is outside the durable evaluation authorization."""


class Mode(str, Enum):
    RUN = "RUN"
    PUBLISH_EXISTING = "PUBLISH_EXISTING"
    RESEARCH = "RESEARCH"
    STOPPING = "STOPPING"
    STOPPED = "STOPPED"


class Stage(str, Enum):
    GLM = "glm"
    QWEN = "qwen"
    SOL = "sol"
    ASTRA = "astra"


_ALLOWED = {
    Mode.RUN: frozenset({"status", "launch", "resume", "reconstruct", "verify", "materialize",
                         "review", "record_receipt", "publish", "research", "stop", "cleanup"}),
    Mode.PUBLISH_EXISTING: frozenset({"status", "review", "record_receipt", "publish", "stop"}),
    Mode.RESEARCH: frozenset({"status", "research", "stop"}),
    Mode.STOPPING: frozenset({"status", "stop"}),
    Mode.STOPPED: frozenset({"status", "stop"}),
}


def require_allowed(mode: str, operation: str) -> None:
    """There is deliberately no provider-request or production-activation operation."""
    if operation not in _ALLOWED[Mode(mode)]:
        raise PolicyError(f"{operation!r} is not authorized in {mode}")


@dataclass(frozen=True)
class SlotPolicy:
    """Astra has no implicit capacity; publisher is not a ninth Sol worker."""

    astra_capacity: int | None = None
    overrides: dict[str, int] | None = None
    paused: tuple[str, ...] = ()

    def __post_init__(self) -> None:
        if self.astra_capacity is not None and (
            type(self.astra_capacity) is not int or self.astra_capacity < 1
        ):
            raise PolicyError("Astra capacity must be an explicitly positive integer")
        for stage, count in (self.overrides or {}).items():
            Stage(stage)
            if type(count) is not int or count < 0:
                raise PolicyError("Explicit worker count overrides must be nonnegative integers")
        for stage in self.paused:
            Stage(stage)
        object.__setattr__(self, "overrides", MappingProxyType(dict(self.overrides or {})))
        object.__setattr__(self, "paused", tuple(self.paused))

    def capacity(self, stage: str, *, publisher: bool = False) -> int:
        stage = Stage(stage)
        if publisher:
            if stage is not Stage.SOL:
                raise PolicyError("The retained publisher must occupy its separate Sol slot")
            return 1
        if stage.value in self.paused:
            return 0
        if stage.value in (self.overrides or {}):
            return self.overrides[stage.value]
        if stage is Stage.ASTRA:
            if self.astra_capacity is None:
                raise PolicyError("Astra needs an explicit evaluation capacity")
            return self.astra_capacity
        return {Stage.SOL: 8, Stage.GLM: 2, Stage.QWEN: 3}[stage]

    @classmethod
    def real_trial(cls) -> "SlotPolicy":
        """Explicit, isolated four-Qwen policy; never a change to production slots."""
        return cls(overrides={"qwen": 4, "glm": 0, "sol": 0, "astra": 0})

    def as_dict(self) -> dict:
        return {"sol": 8, "glm": 2, "qwen": 3, "publisher": 1,
                "astra": self.astra_capacity, "correction_limit": 10,
                "overrides": dict(self.overrides or {}), "paused": sorted(self.paused)}


def next_stage(stage: str) -> str | None:
    return {Stage.GLM: Stage.SOL.value, Stage.QWEN: Stage.SOL.value,
            Stage.SOL: Stage.ASTRA.value, Stage.ASTRA: None}[Stage(stage)]


TRIAL_STARTS = (0xE228, 0xE230, 0xE238, 0xE240, 0xE248, 0xE250, 0xE258, 0xE260)
TRIAL_PHASES = frozenset({
    "reconstruction", "verification", "parent_review_wait", "owner_reconciliation",
    "publication_wait", "commit", "push", "ack_wait", "cleanup", "closure_wait",
    "input_wait", "tool_wait", "explicit_pause", "unobserved",
    "model_execution", "model_queue", "tool_execution", "tool_queue",
    "review_execution", "controller_wait", "instrumentation",
})


WORKFLOW_ACTION_OPERATIONS = MappingProxyType({
    "prepare_target": "launch", "validate_delivery": "verify", "prepare_review": "launch", "review": "reconstruct",
    "reconcile": "reconstruct", "materialize": "materialize", "commit": "publish",
    "push": "publish", "acknowledge": "status", "cleanup": "cleanup", "close": "stop",
    "restore_materialization": "materialize",
})


def validate_workflow_profile(profile: dict) -> None:
    """Keep retained assignment slots separate from explicitly bounded inference."""
    if not isinstance(profile, dict):
        raise PolicyError("The controller needs an explicit immutable model profile")
    capacities = profile.get("total_model_capacities")
    if not isinstance(capacities, list) or not capacities:
        raise PolicyError("Total provider/model inference capacities must be explicit")
    totals = {}
    for row in capacities:
        if (not isinstance(row, dict) or any(not isinstance(row.get(key), str) or not row[key].strip()
                                            for key in ("provider", "model"))
            or type(row.get("capacity")) is not int or row["capacity"] < 1):
            raise PolicyError("Each approved provider/model needs a positive total capacity")
        key = (row["provider"], row["model"])
        if key in totals:
            raise PolicyError("A model cannot acquire capacity through duplicate profile entries")
        totals[key] = row["capacity"]
    for role in ("reconstruction", "review"):
        row = profile.get(role)
        if (not isinstance(row, dict) or any(not isinstance(row.get(key), str) or not row[key].strip()
                                            for key in ("stage", "provider", "model"))
            or type(row.get("capacity")) is not int or row["capacity"] < 1):
            raise PolicyError("Reconstruction and substantive review require explicit model capacities")
        Stage(row["stage"])
        if row["capacity"] > totals.get((row["provider"], row["model"]), 0):
            raise PolicyError("Role capacity cannot exceed its approved total inference capacity")


def workflow_model_capacity(profile: dict, provider: str, model: str) -> int:
    return next((row["capacity"] for row in profile["total_model_capacities"]
                 if row["provider"] == provider and row["model"] == model), 0)


def evaluation_data_path(path: str | Path) -> Path:
    """Refuse an escaped state file before SQLite or mkdir can mutate anything."""
    root = Path(__file__).resolve().parents[2] / "build" / "orchestration-eval"
    if root.resolve() != root:
        raise PolicyError("The evaluation data root cannot redirect through a filesystem link")
    resolved = Path(path).resolve()
    # Resolve existing junctions/symlinks in both paths, including a file symlink.
    if resolved == root.resolve() or not resolved.is_relative_to(root.resolve()):
        raise PolicyError(f"Evaluation state must be a file below {root}")
    if any(part.casefold() in {"tmp", "temp"} for part in resolved.relative_to(root.resolve()).parts):
        raise PolicyError("Temporary directories are not permitted for retained evidence")
    return resolved
