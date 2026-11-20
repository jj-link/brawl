#include <types.h>
#define _current_locale lbl_804942B8
#include <ctype.h>
#pragma force_active on

typedef struct DVDNode {
    u32 packed_type_name;
    u32 parent;
    u32 sibling_next;
} DVDNode;

extern const DVDNode *lbl_805A08E8;
extern char *lbl_805A08E4;
extern s32 lbl_805A08D0;
extern int lbl_8059EAC8;
extern char lbl_8059EAD0[8];
extern char lbl_80476640[];
extern void fn_801D8690(const char *, int, const char *, ...);

static int isSame(const char *lhs, const char *rhs) {
    while (*rhs != '\0') {
        if (tolower(*lhs++) != tolower(*rhs++)) {
            return 0;
        }
    }
    if (*lhs == '/' || *lhs == '\0') {
        return 1;
    }
    return 0;
}

s32 fn_801F5F08(const char *path) {
    const DVDNode *new_var;
    const char *name_end;
    u32 it;
    u32 anchor;
    const char *item_name;
    int name_delimited_by_slash;
    s32 name_length;
    const char *backup_path;
    const char *extension_start;
    int illegal_format;
    int has_extension;

    backup_path = path;
    it = lbl_805A08D0;
    while (1) {
        if (*path == '\0') return it;
        if (*path == '/') {
            it = 0;
            path++;
            continue;
        }
        if (path[0] == '.') {
            if (path[1] == '.') {
                if (path[2] == '/') {
                    it = lbl_805A08E8[it].parent;
                    path += 3;
                    continue;
                }
                if (path[2] == '\0') return lbl_805A08E8[it].parent;
                goto check_format;
            }
            if (path[1] == '/') {
                path += 2;
                continue;
            }
            if (path[1] == '\0') return it;
        }
    check_format:
        if (!lbl_8059EAC8) {
            has_extension = 0;
            illegal_format = 0;
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') {
                if (*name_end == '.') {
                    if (name_end - path > 8 || has_extension == 1) {
                        illegal_format = 1;
                        goto validate_format;
                    } else {
                        has_extension = 1;
                        extension_start = name_end + 1;
                    }
                } else if (*name_end == ' ') {
                    illegal_format = 1;
                }
                name_end++;
            }
        validate_format:
            if (has_extension == 1 && name_end - extension_start > 3) illegal_format = 1;
            if (illegal_format) fn_801D8690(lbl_8059EAD0, 0x1bb, lbl_80476640, backup_path);
        } else {
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') name_end++;
        }
        name_delimited_by_slash = (*name_end == '\0') ? 0 : 1;
        name_length = name_end - path;
        anchor = it + 1;
        new_var = lbl_805A08E8;
        while (anchor < new_var[it].sibling_next) {
            while (1) {
                if ((lbl_805A08E8[anchor].packed_type_name & 0xff000000) ||
                    name_delimited_by_slash != 1) {
                    item_name = lbl_805A08E4 + (lbl_805A08E8[anchor].packed_type_name & 0xffffff);
                    if (isSame(path, item_name) == 1) goto descend;
                }
                if (lbl_805A08E8[anchor].packed_type_name & 0xff000000) {
                    anchor = lbl_805A08E8[anchor].sibling_next;
                    break;
                }
                anchor++;
                break;
            }
        }
        return -1;
    descend:
        if (!name_delimited_by_slash) return anchor;
        it = anchor;
        path += name_length + 1;
    }
}