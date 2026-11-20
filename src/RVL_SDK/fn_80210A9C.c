#include <types.h>
#define _current_locale lbl_804942B8
#include <ctype.h>
#include <revolution/ARC.h>
#pragma force_active on

static BOOL isSame(const char* lhs, const char* rhs) {
    while (rhs[0] != '\0') {
        if (tolower(*lhs++) != tolower(*rhs++))
            return FALSE;
    }
    if (lhs[0] == '/' || lhs[0] == '\0') {
        return TRUE;
    }
    return FALSE;
}

s32 fn_80210A9C(ARCHandle* handle, const char* path) {
    const char* name_end;
    BOOL name_delimited_by_slash;
    s32 name_length;
    u32 anchor;
    u32 it = handle->entrynum;
    ARCNode* nodes = handle->nodes;

    while (TRUE) {
        if (path[0] == '\0') {
            return it;
        }
        if (path[0] == '/') {
            it = 0;
            ++path;
            continue;
        }
        if (path[0] == '.') {
            if (path[1] == '.') {
                if (path[2] == '/') {
                    it = nodes[it].folder.parent;
                    path += 3;
                    continue;
                }
                if (path[2] == '\0') {
                    return nodes[it].folder.parent;
                }
                goto compare;
            }
            if (path[1] == '/') {
                path += 2;
                continue;
            }
            if (path[1] == '\0') {
                return it;
            }
        }
    compare:
        name_end = path;
        while (name_end[0] != '\0' && name_end[0] != '/') {
            ++name_end;
        }
        name_delimited_by_slash = (name_end[0] != '\0') ? 1 : 0;
        name_length = name_end - path;
        anchor = it;
        ++it;
        while (it < nodes[anchor].folder.sibling_next) {
            while (TRUE) {
                if ((nodes[it].packed_type_name & 0xFF000000) ||
                    name_delimited_by_slash != TRUE) {
                    char* name_of_it =
                        ((char*)handle->strings) + (nodes[it].packed_type_name & 0x00FFFFFF);
                    if (name_of_it[0] == '.' && name_of_it[1] == '\0') {
                        ++it;
                        continue;
                    }
                    if (isSame(path, name_of_it) == TRUE) {
                        goto descend;
                    }
                }
                if (nodes[it].packed_type_name & 0xFF000000) {
                    it = nodes[it].folder.sibling_next;
                    break;
                }
                ++it;
                break;
            }
        }
        return -1;
    descend:
        if (!name_delimited_by_slash) {
            return it;
        }
        path += name_length + 1;
    }
}
