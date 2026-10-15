"""Real, independently owned Git publication; never production MAIN mutation."""
from __future__ import annotations

from datetime import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import shlex

from .evidence import file_identity, input_path, reject_links
from .safety import ACTIVE, SafetyError, confined, digest, now, save_json
from .trial_delivery import validate_delivery_files
from .trial_execution import OwnedCommands


class ReconciliationRequired(SafetyError):
    pass


class IndependentRepository:
    def __init__(self, runtime):
        self.runtime = runtime
        self.commands = OwnedCommands(runtime)
        self.config = runtime.ledger.snapshot()["trial"]["workflow"]["config"]
        self.target = self.config["publication_target"]
        self.path = confined(Path(self.target["repository"]))
        self.gitdir = self.path / ".git"
        self.branch = "refs/heads/" + self.target["branch"]
        self.receipts = {}

    def directory(self, action):
        path = confined(self.runtime.root / "workflow" / action["effect_id"], self.runtime.root)
        path.mkdir(parents=True, exist_ok=True)
        return path

    def guard(self):
        reject_links(self.path)
        reject_links(self.gitdir)
        if (self.path == ACTIVE or not self.gitdir.is_dir()
                or Path(self.target["git_dir"]).resolve() != self.gitdir.resolve()):
            raise SafetyError("Publication requires its exact independent Git directory")
        for name in ("commondir", "gitdir", "objects/info/alternates", "objects/info/http-alternates"):
            if (self.gitdir / name).exists():
                raise SafetyError("Shared/linked Git metadata or external object storage is forbidden")
        for directory, children, files in os.walk(self.gitdir, followlinks=False):
            reject_links(Path(directory))
            for name in children + files:
                reject_links(Path(directory) / name)
        # A local config include can otherwise select a foreign index/filter or
        # command. Controller-created repositories never need configuration includes.
        config = (self.gitdir / "config").read_text(encoding="utf-8")
        if any(line.strip().lower().startswith(("[include", "[extensions")) for line in config.splitlines()):
            raise SafetyError("Publication metadata cannot delegate configuration outside the owned repository")
        prepared = self.runtime.ledger.snapshot()["trial"]["workflow"]["target_prepared"]
        if prepared and digest(self.gitdir / "config") != prepared["result"]["config_sha256"]:
            raise SafetyError("Frozen independent Git configuration changed")

    def authentication(self, environment=None):
        authentication = []
        helper = self.target.get("credential_helper")
        extra = dict(environment or {})
        if helper:
            executable = Path(helper["path"])
            reject_links(executable)
            if not executable.is_absolute() or digest(executable) != helper["sha256"]:
                raise SafetyError("Approved native credential helper identity changed")
            authentication = ["-c", "credential.helper=", "-c",
                              "credential.helper=!" + shlex.quote(executable.as_posix())]
            extra.update(GCM_INTERACTIVE="never", GCM_GUI_PROMPT="false", GCM_TRACE="0", GCM_TRACE_SECRETS="0")
        return authentication, extra

    def command(self, arguments, environment=None):
        self.guard()
        hooks = self.runtime.root / "disabled-workflow-hooks"
        if hooks.exists():
            raise SafetyError("Disabled hooks path must remain absent")
        authentication, extra = self.authentication(environment)
        command = ["git", "--git-dir", str(self.gitdir), "--work-tree", str(self.path),
                   "-c", "core.longpaths=true", "-c", "core.autocrlf=false", "-c", "core.eol=lf", "-c", "core.fsmonitor=false",
                   "-c", "core.hooksPath=" + str(hooks), *authentication, *arguments]
        return command, extra

    def git(self, action, arguments, *, data=None, environment=None, check=True):
        command, extra = self.command(arguments, environment)
        result = self.commands.run(action, command, cwd=self.path, data=data, environment=extra, check=check)
        self.receipts.setdefault(action["effect_id"], []).append(str(result.receipt))
        return result

    def prepare_target(self, action):
        pointer = self.target["ownership_evidence"]
        source = confined(Path(pointer["path"]))
        if digest(source) != pointer["sha256"]:
            raise SafetyError("Independent target reservation changed")
        authority = json.loads(source.read_text(encoding="utf-8"))
        if any(authority[key] != self.target[key] for key in ("repository", "remote", "branch")):
            raise SafetyError("Controller target differs from its exact approved reservation")
        helper = authority.get("credential_helper")
        if helper is not None and not isinstance(helper, dict):
            raise SafetyError("Credential authority must be an executable identity and explicit policy")
        identity = None if helper is None else {key: helper.get(key) for key in ("path", "sha256")}
        if self.target.get("credential_helper") != identity:
            raise SafetyError("Credential executable identity must equal the approved target binding")
        if helper is not None and any(helper.get(key) is not False for key in (
                "credential_extraction_or_logging", "global_configuration_changes", "interactive_authentication")):
            raise SafetyError("Credential authority must explicitly prohibit extraction, global changes and interaction")
        prepared = None
        pointer = self.target.get("prepared_repository")
        if pointer is not None:
            receipt_path = confined(Path(pointer["path"]))
            reject_links(receipt_path)
            if digest(receipt_path) != pointer["sha256"]:
                raise SafetyError("Owned engineering publication receipt changed")
            prepared = json.loads(receipt_path.read_bytes())
            if (not isinstance(prepared, dict) or prepared.get("engineering_baseline") != authority["engineering_baseline"]
                    or prepared.get("head") != self.target["baseline"]):
                raise SafetyError("Engineering publication cannot redefine the reconstruction baseline")
        if ((prepared is None and authority["engineering_baseline"] != self.target["baseline"])
                or Path(authority["parent_repository_read_only"]).resolve() != ACTIVE.resolve()
                or authority["scope"]["parent_index_refs_objects_writes"] is not False
                or authority["scope"]["force_push"] is not False):
            raise SafetyError("Independent target authority does not preserve MAIN and non-force publication")
        if prepared is not None:
            result = self.verify_prepared_target(action, prepared)
            result["evidence_refs"].extend([str(source), str(receipt_path)])
            return result
        if self.path.exists():
            raise SafetyError("Unexpected existing target is not automatically adopted or overwritten")
        authentication, environment = self.authentication()
        remote = self.commands.run(action, ["git", *authentication, "ls-remote", "--heads",
                                   self.target["remote"], self.branch],
                                   cwd=self.runtime.root, environment=environment)
        if remote.stdout.strip():
            raise SafetyError("Reserved remote branch is no longer absent")
        self.path.mkdir(parents=True, exist_ok=False)
        inode = self.path.stat().st_ino
        save_json(self.directory(action) / "target-intent.json", {
            "target": self.target, "directory_identity": inode, "remote_observation": str(remote.receipt)})
        clone = self.commands.run(action, ["git", "-c", "core.longpaths=true", "-c", "core.autocrlf=false", "-c", "core.eol=lf",
            "clone", "--no-local", "--no-hardlinks", "--no-checkout", "--no-tags", str(ACTIVE), str(self.path)],
            cwd=self.runtime.root, timeout=300)
        if self.path.stat().st_ino != inode:
            raise SafetyError("Owned publication directory was replaced during initialization")
        self.guard()
        self.git(action, ["remote", "remove", "origin"])
        self.git(action, ["remote", "add", "origin", self.target["remote"]])
        self.git(action, ["checkout", "-b", self.target["branch"], self.target["baseline"]])
        for field in ("name", "email"):
            self.git(action, ["config", "--local", "user." + field, self.target["author"][field]])
        head = self.git(action, ["rev-parse", "HEAD"]).text()
        common = self.git(action, ["rev-parse", "--path-format=absolute", "--git-common-dir"]).text()
        actual_remote = self.git(action, ["remote", "get-url", "origin"]).text()
        actual_branch = self.git(action, ["symbolic-ref", "HEAD"]).text()
        if (head != self.target["baseline"] or Path(common).resolve() != self.gitdir.resolve()
                or actual_remote != self.target["remote"] or actual_branch != self.branch):
            raise SafetyError("Initialized target does not match exact independent Git authority")
        return {"repository": self.target["repository"], "git_dir": self.target["git_dir"],
                "common_git_dir": self.target["git_dir"], "native_common_git_dir": common,
                "remote": actual_remote, "branch": self.target["branch"], "head": head,
                "independent": True, "alternates": [], "directory_identity": inode,
                "config_sha256": digest(self.gitdir / "config"),
                "evidence_refs": [str(source), str(remote.receipt), str(clone.receipt),
                                  *self.receipts.get(action["effect_id"], [])]}

    def verify_prepared_target(self, action, receipt):
        """Observe an owned implementation publication; never clone/checkout/adopt by path alone."""
        self.guard()
        if (receipt.get("schema") != "brawl-owned-engineering-publication/v1"
                or receipt.get("next_run_id") != self.runtime.root.name
                or receipt.get("controller_id") != self.config["controller_id"]
                or any(receipt.get(name) != self.target[name] for name in ("repository", "git_dir", "remote", "branch"))
                or receipt.get("head") != self.target["baseline"] or receipt.get("remote_head") != receipt.get("head")
                or receipt.get("directory_identity") != self.path.stat().st_ino
                or receipt.get("config_sha256") != digest(self.gitdir / "config")):
            raise SafetyError("Existing target lacks its exact owned engineering publication identity")
        baseline, head = receipt.get("engineering_baseline"), receipt["head"]
        if not isinstance(baseline, str) or not re.fullmatch(r"[0-9a-f]{40}", baseline):
            raise SafetyError("Engineering publication requires its original full baseline")
        pointer = receipt.get("source_manifest")
        if not isinstance(pointer, dict) or set(pointer) != {"path", "sha256"}:
            raise SafetyError("Engineering publication must bind reviewed source and documentation identities")
        source_manifest = confined(Path(pointer["path"]))
        reject_links(source_manifest)
        if digest(source_manifest) != pointer["sha256"]:
            raise SafetyError("Reviewed engineering source identities changed")
        manifest = json.loads(source_manifest.read_bytes())
        entries = [*manifest["sources"], *manifest.get("documentation", [])]
        files, units = receipt.get("files"), receipt.get("units")
        if (not isinstance(files, dict) or not files or not isinstance(units, list) or not units
                or len({entry["path"].casefold() for entry in entries}) != len(entries)
                or {entry["path"] for entry in entries} != set(files)):
            raise SafetyError("Publication scope differs from exact reviewed code/documentation paths")
        for entry in entries:
            image = files[entry["path"]]
            if (image.get("raw") != {name: entry[name] for name in ("sha256", "size")}
                    or image.get("mode") != "100644"
                    or file_identity(input_path(self.path, entry["path"])) != image["raw"]):
                raise SafetyError("Existing implementation raw postimages differ from reviewed bytes")
        index_before = file_identity(self.gitdir / "index")
        actual_head = self.git(action, ["rev-parse", "HEAD"]).text()
        common = self.git(action, ["rev-parse", "--path-format=absolute", "--git-common-dir"]).text()
        if (actual_head != head or Path(common).resolve() != self.gitdir.resolve()
                or self.git(action, ["symbolic-ref", "HEAD"]).text() != self.branch
                or self.git(action, ["remote", "get-url", "origin"]).text() != self.target["remote"]
                or self.git(action, ["status", "--porcelain=v1", "--untracked-files=all"]).stdout.strip()):
            raise SafetyError("Owned published target changed its actual HEAD/branch/remote/clean state")
        commits = self.git(action, ["rev-list", "--reverse", baseline + ".." + head]).text().splitlines()
        if commits != [unit.get("commit") for unit in units]:
            raise SafetyError("Actual implementation commit sequence differs from its publication receipt")
        previous, covered = baseline, set()
        for unit in units:
            commit, paths = unit["commit"], unit.get("paths")
            if (not isinstance(paths, list) or not paths or len(set(paths)) != len(paths)
                    or covered.intersection(paths) or not set(paths).issubset(files)
                    or unit.get("parent") != previous
                    or self.git(action, ["show", "-s", "--format=%P", commit]).text() != previous):
                raise SafetyError("Engineering logical units must retain exact parents and disjoint reviewed scope")
            changed = self.git(action, ["diff-tree", "--no-commit-id", "--name-only", "-r", "-z", commit]).stdout
            if set(changed.decode().rstrip("\0").split("\0")) != set(paths):
                raise SafetyError("Actual engineering commit contains missing or undeclared paths")
            for name in paths:
                if self.entry(action, commit, name) != {field: files[name][field] for field in ("mode", "blob")}:
                    raise SafetyError("Actual committed engineering postimage differs from reviewed scope")
            covered.update(paths)
            previous = commit
        if covered != set(files) or previous != head:
            raise SafetyError("Engineering commit sequence does not cover the complete reviewed implementation")
        for name, image in files.items():
            path = input_path(self.path, name)
            if self.git(action, ["hash-object", "--path=" + name, "--stdin"], data=path.read_bytes()).text() != image["blob"]:
                raise SafetyError("Raw and cleaned engineering source identities disagree")
        remote = self.git(action, ["ls-remote", "--heads", "origin", self.branch]).text().splitlines()
        if remote != [head + "\t" + self.branch]:
            raise SafetyError("Actual remote ref does not contain the exact published implementation HEAD")
        if file_identity(self.gitdir / "index") != index_before:
            raise SafetyError("Read-only publication admission unexpectedly changed the target index")
        return {"repository": self.target["repository"], "git_dir": self.target["git_dir"],
                "common_git_dir": self.target["git_dir"], "native_common_git_dir": common,
                "remote": self.target["remote"], "branch": self.target["branch"], "head": head,
                "independent": True, "alternates": [], "directory_identity": receipt["directory_identity"],
                "config_sha256": receipt["config_sha256"], "retained_engineering_publication": True,
                "engineering_baseline": baseline, "evidence_refs": [str(source_manifest),
                    *self.receipts.get(action["effect_id"], [])]}

    def entry(self, action, commit, path):
        raw = self.git(action, ["ls-tree", "-z", commit, "--", path]).stdout
        if not raw:
            return None
        rows = raw.rstrip(b"\0").split(b"\0")
        if len(rows) != 1:
            raise SafetyError("Declared path did not resolve to one Git entry")
        fields, name = rows[0].split(b"\t", 1)
        mode, kind, blob = fields.decode().split()
        if name.decode() != path or kind != "blob" or mode != "100644":
            raise SafetyError("Declared source is not its exact regular Git file")
        return {"mode": mode, "blob": blob}

    def postimages(self, action, delivery):
        rows = []
        for name, change in delivery.payload["changes"].items():
            try:
                path = input_path(self.path, name)
                raw = file_identity(path)
                blob = self.git(action, ["hash-object", "--path=" + name, "--stdin"], data=path.read_bytes()).text()
                rows.append({"path": name, "raw": raw, "blob": blob,
                             "matches": raw == change["raw"] and blob == change["after"]["blob"]})
            except (OSError, ValueError) as error:
                rows.append({"path": name, "matches": False, "error": repr(error)})
        return rows

    def materialize(self, action, delivery, workspace):
        validate_delivery_files(workspace, delivery)
        head = self.git(action, ["rev-parse", self.branch]).text()
        payload = delivery.payload
        changed = [path for path, value in payload["changes"].items()
                   if self.entry(action, head, path) != value["before"]]
        if changed:
            raise ReconciliationRequired("Changed declared preimages require the same owner: " + ", ".join(changed))
        directory = self.directory(action)
        preview = directory / "raw"
        before, after = preview / "before", preview / "after"
        before.mkdir(parents=True, exist_ok=False)
        after.mkdir()
        preimages = {}
        for name, change in payload["changes"].items():
            destination = input_path(self.path, name, must_exist=False)
            if change["before"] is None:
                if destination.exists():
                    raise ReconciliationRequired("Untracked destination already exists: " + name)
                preimages[name] = None
            else:
                raw = destination.read_bytes()
                blob = self.git(action, ["hash-object", "--path=" + name, "--stdin"], data=raw).text()
                if blob != change["before"]["blob"]:
                    raise ReconciliationRequired("Uncommitted destination change: " + name)
                original = before / name
                original.parent.mkdir(parents=True, exist_ok=True)
                original.write_bytes(raw)
                preimages[name] = dict(change["before"],
                                      raw={"sha256": hashlib.sha256(raw).hexdigest(), "size": len(raw)})
            source = input_path(Path(workspace), name)
            post = after / name
            post.parent.mkdir(parents=True, exist_ok=True)
            post.write_bytes(source.read_bytes())
            if file_identity(post) != change["raw"]:
                raise ReconciliationRequired("Source changed during own-only patch preparation: " + name)
        # A ceiling equal to Git's starting directory is ignored. Stop at its
        # parent so enclosing .gitattributes cannot normalize this raw patch.
        diff = self.commands.run(action, ["git", "-C", str(preview), "-c", "core.autocrlf=false",
            "-c", "core.longpaths=true", "-c", "core.eol=lf", "diff", "--no-index", "--binary", "--full-index", "--no-ext-diff",
            "--no-textconv", "before", "after"], cwd=self.runtime.root, check=False,
            environment={"GIT_CEILING_DIRECTORIES": str(preview.parent), "GIT_ATTR_NOSYSTEM": "1"})
        if diff.returncode != 1 or not diff.stdout:
            raise SafetyError("Own-only raw patch generation did not produce the declared changes")
        patch = directory / "raw.patch"
        with patch.open("xb") as stream:
            stream.write(diff.stdout)
        index_before = file_identity(self.gitdir / "index")
        validate_delivery_files(workspace, delivery)
        save_json(directory / "materialization-intent.json", {
            "head": head, "patch_ref": str(patch), "patch_identity": digest(patch),
            "index_identity": index_before, "delivery_id": delivery.delivery_id,
            "preimages": preimages,
            "expected_postimages": {name: dict(change["after"], raw=change["raw"])
                                    for name, change in payload["changes"].items()}})
        result = self.git(action, ["apply", "--binary", "-p2", str(patch)], check=False)
        rows = self.postimages(action, delivery)
        evidence = {"head": head, "patch_ref": str(patch), "patch_identity": digest(patch),
                    "source_identity": delivery.source_identity, "input_identity": payload["inputs"]["identity"],
                    "apply_exit_code": result.returncode, "postimages": rows,
                    "preimages": preimages,
                    "index_unchanged": file_identity(self.gitdir / "index") == index_before,
                    "evidence_refs": [str(diff.receipt), str(result.receipt), *self.receipts[action["effect_id"]]]}
        receipt = directory / "materialization.json"
        save_json(receipt, evidence)
        if result.returncode or not evidence["index_unchanged"] or not all(row["matches"] for row in rows):
            raise SafetyError(f"Partial materialization retained; exit status alone is not acceptance: {receipt}")
        return evidence

    def restored_preimages(self, intent, blob):
        observed = {}
        for name, expected in intent["preimages"].items():
            path = input_path(self.path, name, must_exist=False)
            if expected is None:
                if path.exists():
                    raise SafetyError("Newly materialized source still exists after restoration: " + name)
                observed[name] = None
            else:
                if file_identity(path) != expected["raw"]:
                    raise SafetyError("Restoration did not recover the exact preserved raw preimage: " + name)
                value = blob(name, path)
                if value != expected["blob"]:
                    raise SafetyError("Restored Git preimage differs from its original accepted entry")
                observed[name] = {"mode": expected["mode"], "blob": value}
        return observed

    def restore_materialization(self, action, original, delivery):
        if (original["kind"] != "materialize" or not original.get("recovery_required")
                or original["assignment_id"] != action["assignment_id"]):
            raise SafetyError("Restoration requires its actual superseded materialization")
        previous = self.directory(original)
        intent_path = previous / "materialization-intent.json"
        intent = json.loads(intent_path.read_bytes())
        patch = input_path(previous, "raw.patch")
        if (intent["delivery_id"] != delivery.delivery_id or digest(patch) != intent["patch_identity"]
                or intent.get("preimages") != original["result"].get("preimages")
                or {name: None if image is None else {field: image[field] for field in ("mode", "blob")}
                    for name, image in intent["preimages"].items()}
                    != {name: change["before"] for name, change in delivery.payload["changes"].items()}
                or intent["head"] != action["binding"]["target_head"]
                or self.git(action, ["rev-parse", self.branch]).text() != intent["head"]
                or file_identity(self.gitdir / "index") != intent["index_identity"]):
            raise SafetyError("Superseded materialization identity, ref, patch or index changed")
        if not all(row["matches"] for row in self.postimages(action, delivery)):
            raise SafetyError("Restoration cannot overwrite changed or partial target effects")
        for name, expected in intent["preimages"].items():
            if expected is not None and file_identity(input_path(previous / "raw/before", name)) != expected["raw"]:
                raise SafetyError("Original raw preimage preservation changed")
        directory = self.directory(action)
        preservation = directory / "restore-intent.json"
        save_json(preservation, {"restored_action_id": original["effect_id"], "base_head": intent["head"],
            "materialization_intent_ref": str(intent_path), "materialization_intent_sha256": digest(intent_path),
            "patch_ref": str(patch), "patch_identity": intent["patch_identity"]})
        result = self.git(action, ["apply", "--reverse", "--binary", "-p2", str(patch)], check=False)
        if result.returncode:
            raise SafetyError("Actual restoration did not complete; retain its partial effects and lease")
        images = self.restored_preimages(intent, lambda name, path:
            self.git(action, ["hash-object", "--path=" + name, "--stdin"], data=path.read_bytes()).text())
        if (self.git(action, ["rev-parse", self.branch]).text() != intent["head"]
                or file_identity(self.gitdir / "index") != intent["index_identity"]):
            raise SafetyError("Restoration unexpectedly changed the target ref or ordinary index")
        value = {"restored_action_id": original["effect_id"], "base_head": intent["head"],
                 "restored_preimages": images, "scope_verified": True, "preservation_ref": str(preservation),
                 "command_refs": self.receipts[action["effect_id"]]}
        save_json(directory / "restoration.json", value)
        return value

    def commit(self, action, delivery, expected_parent):
        payload = delivery.payload
        index = int(action["binding"]["logical_unit_id"].removeprefix("unit-"))
        unit = payload["logical_units"][index]
        if self.git(action, ["rev-parse", self.branch]).text() != expected_parent:
            raise ReconciliationRequired("Publication ref changed after exact materialization")
        if not all(row["matches"] for row in self.postimages(action, delivery)):
            raise SafetyError("Materialized raw/source identities changed before commit")
        directory = self.directory(action)
        environment = {"GIT_INDEX_FILE": str(directory / "commit.index")}
        self.git(action, ["read-tree", expected_parent], environment=environment)
        entries = []
        for name in unit["paths"]:
            source = input_path(self.path, name)
            blob = self.git(action, ["hash-object", "-w", "--path=" + name, "--stdin"],
                            data=source.read_bytes()).text()
            if blob != payload["changes"][name]["after"]["blob"]:
                raise SafetyError("Clean source blob differs from the accepted delivery")
            entries.append(f"100644 {blob}\t{name}\n")
        self.git(action, ["update-index", "--index-info"], data="".join(entries).encode(), environment=environment)
        tree = self.git(action, ["write-tree"], environment=environment).text()
        author = self.target["author"]
        if any(any(char in author[key] for char in "\r\n\0<>") for key in ("name", "email")):
            raise SafetyError("Invalid explicit commit author identity")
        epoch = int(datetime.fromisoformat(action["admitted_at"]).timestamp())
        person = f"{author['name']} <{author['email']}> {epoch} +0000"
        body = (f"tree {tree}\nparent {expected_parent}\nauthor {person}\ncommitter {person}\n\n"
                f"{unit['message'].rstrip()}\n\nOMP-Workflow-Effect: {action['effect_id']}\n"
                f"OMP-Delivery: {delivery.delivery_id}\n").encode()
        planned = hashlib.sha1(b"commit " + str(len(body)).encode() + b"\0" + body).hexdigest()
        intent = {"parent": expected_parent, "tree": tree, "commit": planned,
                  "logical_unit_id": action["binding"]["logical_unit_id"], "paths": unit["paths"],
                  "delivery_id": delivery.delivery_id, "effect_id": action["effect_id"]}
        path = directory / "commit-intent.json"
        with path.open("x", encoding="utf-8") as stream:
            json.dump(intent, stream, sort_keys=True)
            stream.flush()
            os.fsync(stream.fileno())
        actual = self.git(action, ["hash-object", "-t", "commit", "-w", "--stdin"], data=body).text()
        if actual != planned:
            raise SafetyError("Actual Git commit identity differs from its durable intent")
        self.git(action, ["update-ref", self.branch, planned, expected_parent])
        if self.git(action, ["rev-parse", self.branch]).text() != planned:
            raise SafetyError("Commit ref observation did not establish the planned effect")
        names = self.git(action, ["diff-tree", "--no-commit-id", "--name-only", "-r", expected_parent, planned]).text().splitlines()
        if set(names) != set(unit["paths"]) or any(
                self.entry(action, planned, name) != payload["changes"][name]["after"] for name in unit["paths"]):
            raise SafetyError("Committed scope/postimages differ from the exact logical unit")
        return {**intent, "intent_ref": str(path), "evidence_refs": self.receipts[action["effect_id"]]}

    def remote_head(self, action):
        result = self.git(action, ["ls-remote", "--heads", self.target["remote"], self.branch])
        rows = result.text().splitlines()
        if not rows:
            return None
        if len(rows) != 1 or rows[0].split()[1] != self.branch:
            raise SafetyError("Remote observation did not identify exactly the reserved branch")
        return rows[0].split()[0]

    def push(self, action, commit, expected_remote):
        query_started = now()
        exit_code = None
        before = self.remote_head(action)
        if before not in (expected_remote, commit):
            raise SafetyError("Remote branch changed outside the recorded publication sequence")
        if before != commit:
            if self.git(action, ["rev-parse", self.branch]).text() != commit:
                raise SafetyError("Local branch no longer identifies the exact logical commit")
            result = self.git(action, ["push", self.target["remote"], commit + ":" + self.branch], check=False)
            exit_code = result.returncode
            if result.returncode:
                raise SafetyError(f"Push outcome needs actual remote observation; retain {result.receipt}")
        after = self.remote_head(action)
        if after != commit:
            raise SafetyError("Successful push exit did not establish exact remote publication")
        return {"commit": commit, "remote_head": after, "remote": self.target["remote"],
                "branch": self.target["branch"], "recovered_from_remote": before == commit,
                "query_started_at": query_started, "push_exit_code": exit_code,
                "evidence_refs": self.receipts[action["effect_id"]]}

    def acknowledge(self, action, delivery, commit):
        remote = self.remote_head(action)
        if remote is None:
            raise SafetyError("Published assignment has no observed remote branch")
        ancestry = self.git(action, ["merge-base", "--is-ancestor", commit, remote], check=False)
        if ancestry.returncode != 0 or any(self.entry(action, commit, name) != change["after"]
                                          for name, change in delivery.payload["changes"].items()):
            raise SafetyError("Remote ancestry and historical own-only committed source are not established")
        return {"commit": commit, "remote_head": remote, "ancestry_verified": True,
                "source_identity": delivery.source_identity, "input_identity": delivery.payload["inputs"]["identity"],
                "evidence_refs": self.receipts[action["effect_id"]]}
