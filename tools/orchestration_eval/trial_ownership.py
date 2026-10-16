"""Prove only canonical, bound registration insertions; unknown edits need judgment."""
import ast
import difflib
from pathlib import PurePosixPath
import re


def inserted_lines(before, after):
    left, right = before.splitlines(keepends=True), after.splitlines(keepends=True)
    inserted = set()
    for operation, _, _, start, end in difflib.SequenceMatcher(None, left, right, autojunk=False).get_opcodes():
        if operation not in {"equal", "insert"}:
            raise ValueError("Existing registration bytes were removed or rewritten")
        if operation == "insert":
            inserted.update(range(start, end))
    if not inserted:
        raise ValueError("No canonical registration insertion was observed")
    return right, inserted


def configured_object(tree, library, source):
    libraries = []
    for node in ast.walk(tree):
        if isinstance(node, ast.Dict):
            fields = {key.value: value for key, value in zip(node.keys, node.values)
                      if isinstance(key, ast.Constant) and isinstance(key.value, str)}
            if isinstance(fields.get("lib"), ast.Constant) and fields["lib"].value == library:
                libraries.append(fields.get("objects"))
    if len(libraries) != 1 or not isinstance(libraries[0], ast.List):
        raise ValueError("The bound library does not have one literal object list")
    candidates = [node for node in ast.walk(tree) if isinstance(node, ast.Call)
                  and isinstance(node.func, ast.Name) and node.func.id == "Object"
                  and len(node.args) >= 2 and isinstance(node.args[1], ast.Constant)
                  and node.args[1].value == source]
    if len(candidates) != 1 or candidates[0] not in libraries[0].elts:
        raise ValueError("The named source is not registered exactly once in its bound library")
    return libraries[0], candidates[0]


def configure_insertion(before, after, registration, source, matching):
    before_tree, after_tree = ast.parse(before.decode("utf-8")), ast.parse(after.decode("utf-8"))
    objects, node = configured_object(after_tree, registration["library"], source)
    expected = ast.parse(
        f"Object({'Matching' if matching else 'NonMatching'}, {source!r}, "
        f"cflags={registration['cflags']}, extra_cflags={registration['extra_cflags']!r})", mode="eval").body
    if ast.dump(node, include_attributes=False) != ast.dump(expected, include_attributes=False):
        raise ValueError("New Object registration differs from the fixed matching/compiler recipe")
    lines, inserted = inserted_lines(before, after)
    span = set(range(node.lineno - 1, node.end_lineno))
    if not span <= inserted or any(lines[index].strip() for index in inserted - span):
        raise ValueError("Inserted configure bytes include more than the one bound Object entry")
    objects.elts.remove(node)
    if ast.dump(before_tree, include_attributes=False) != ast.dump(after_tree, include_attributes=False):
        raise ValueError("Configure AST changed outside the named library insertion")
    return "configure-obj-insertion-v1"


def split_sections(raw):
    sections, current = {}, None
    for line in raw.decode("utf-8").splitlines():
        if line and not line[0].isspace() and line.endswith(":"):
            current = line[:-1]
            if current in sections:
                raise ValueError("Repeated split section identity")
            sections[current] = []
        elif line.strip():
            if current is None:
                raise ValueError("Unrecognized split-file prefix")
            sections[current].append(line)
    return sections


def split_insertion(before, after, source, start, end):
    previous, current = split_sections(before), split_sections(after)
    if source in previous or source not in current:
        raise ValueError("The named split is not a fresh section insertion")
    lines = current.pop(source)
    if len(lines) != 1:
        raise ValueError("A routine function insertion must contain only its bound text interval")
    interval = re.fullmatch(r"\s+\.text\s+start:(0x[0-9a-fA-F]+)\s+end:(0x[0-9a-fA-F]+)\s*", lines[0])
    if interval is None or tuple(int(value, 16) for value in interval.groups()) != (start, end):
        raise ValueError("Inserted split interval differs from the reserved function range")
    if previous != current:
        raise ValueError("Split entries were moved or changed outside the reserved insertion")
    for rows in previous.values():
        for row in rows:
            match = re.match(r"\s+\.text\s+start:(0x[0-9a-fA-F]+)\s+end:(0x[0-9a-fA-F]+)", row)
            if match and max(start, int(match[1], 16)) < min(end, int(match[2], 16)):
                raise ValueError("Inserted text range overlaps an existing owned split")
    actual, inserted = inserted_lines(before, after)
    additions = [actual[index].decode("utf-8").rstrip("\r\n") for index in sorted(inserted)
                 if actual[index].strip()]
    if additions != [source + ":", lines[0]]:
        raise ValueError("Split insertion contains unrelated bytes or section declarations")
    return "splits-section-insertion-v1"


def prove_registration_insertions(before_images, after_images, reservation, specification, matching):
    """Return exact per-path transformations or a concrete remaining judgment."""
    try:
        registration = specification["recipe"]["registration"]
        function = reservation["function"]
        source = PurePosixPath(specification["selection"]["source"])
        relative = str(source.relative_to("src"))
        library = registration["library"]
        configure, splits = registration["configure_path"], registration["splits_path"]
        if (registration["schema"] != 1 or registration["module"] != function["module"]
                or library != source.parent.name or PurePosixPath(splits).parent.name != library
                or configure != "configure.py" or PurePosixPath(splits).name != "splits.txt"
                or configure not in reservation["owned_paths"] or splits not in reservation["owned_paths"]
                or not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", registration["cflags"])
                or not isinstance(registration["extra_cflags"], list)
                or any(not isinstance(flag, str) for flag in registration["extra_cflags"])
                or type(function["start"]) is not int or type(function["end"]) is not int
                or function["start"] >= function["end"]):
            raise ValueError("Registration recipe does not bind the reserved module/source/text interval")
        if not set(before_images) <= {configure, splits} or set(before_images) != set(after_images):
            raise ValueError("Changed shared paths exceed the canonical registration transformation")
        result = {}
        for name, before in before_images.items():
            if before is None:
                raise ValueError("Canonical registration requires the actual existing bound preimage")
            result[name] = (configure_insertion(before, after_images[name], registration, relative, matching)
                            if name == configure else split_insertion(before, after_images[name], relative,
                                                                     function["start"], function["end"]))
        return result, None
    except (KeyError, TypeError, ValueError, SyntaxError) as error:
        return None, "Canonical registration insertion is not mechanically established: " + str(error)
