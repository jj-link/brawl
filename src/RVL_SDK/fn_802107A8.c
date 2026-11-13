#include <types.h>
#include <revolution/ARC.h>
#include <revolution/OS/OSError.h>

#pragma force_active on

#define ARCNodeIsFolder(node) ((node).packed_type_name & 0xFF000000)
#define ARCNodeGetName(node) ((node).packed_type_name & 0x00FFFFFF)

extern s32 fn_80210A9C(ARCHandle* handle, const char* path);
extern u32 fn_80210D00(ARCHandle* handle, u32 entrynum, char* string, u32 maxlen);
extern char lbl_8047C55C[];

static u32 myStrncpy(char* dst, char* src, u32 maxlen) {
    u32 i;
    for (i = maxlen; i != 0 && src[0] != '\0'; --i) {
        *dst++ = *src++;
    }
    return maxlen - i;
}

static u32 entryToPath3(ARCHandle* handle, u32 entrynum, char* string, u32 maxlen) {
    char* name;
    u32 written;
    ARCNode* nodes = handle->nodes;

    if (entrynum == 0) {
        return 0;
    }

    name = ((char*)handle->strings) + ARCNodeGetName(nodes[entrynum]);
    written = fn_80210D00(handle, nodes[entrynum].folder.parent, string, maxlen);
    if (written == maxlen) {
        return written;
    }
    string[written++] = '/';
    return written + myStrncpy(string + written, name, maxlen - written);
}

static u32 entryToPath2(ARCHandle* handle, u32 entrynum, char* string, u32 maxlen) {
    char* name;
    u32 written;
    ARCNode* nodes = handle->nodes;

    if (entrynum == 0) {
        return 0;
    }

    name = ((char*)handle->strings) + ARCNodeGetName(nodes[entrynum]);
    written = entryToPath3(handle, nodes[entrynum].folder.parent, string, maxlen);
    if (written == maxlen) {
        return written;
    }
    string[written++] = '/';
    return written + myStrncpy(string + written, name, maxlen - written);
}

static u32 entryToPath1(ARCHandle* handle, u32 entrynum, char* string, u32 maxlen) {
    char* name;
    u32 written;
    ARCNode* nodes = handle->nodes;

    if (entrynum == 0) {
        return 0;
    }

    name = ((char*)handle->strings) + ARCNodeGetName(nodes[entrynum]);
    written = entryToPath2(handle, nodes[entrynum].folder.parent, string, maxlen);
    if (written == maxlen) {
        return written;
    }
    string[written++] = '/';
    return written + myStrncpy(string + written, name, maxlen - written);
}

static BOOL ARCConvertEntrynumToPath(ARCHandle* handle, s32 entrynum, char* string, u32 maxlen) {
    ARCNode* nodes = handle->nodes;
    u32 written = entryToPath1(handle, entrynum, string, maxlen);

    if (written == maxlen) {
        string[maxlen - 1] = '\0';
        return FALSE;
    }

    if (ARCNodeIsFolder(nodes[entrynum])) {
        if (written == maxlen - 1) {
            string[written] = '\0';
            return FALSE;
        }
        string[written++] = '/';
    }

    string[written] = '\0';
    return TRUE;
}

static BOOL ARCGetCurrentDir(ARCHandle* handle, char* string, u32 maxlen) {
    return ARCConvertEntrynumToPath(handle, handle->entrynum, string, maxlen);
}

BOOL fn_802107A8(ARCHandle* handle, const char* path, ARCFileInfo* info) {
    ARCNode* nodes = handle->nodes;
    s32 entrynum = fn_80210A9C(handle, path);

    if (entrynum < 0) {
        char dir[128];

        ARCGetCurrentDir(handle, dir, sizeof(dir));
        OSReport(lbl_8047C55C, path, dir);
        return FALSE;
    }

    if (entrynum < 0 || ARCNodeIsFolder(nodes[entrynum])) {
        return FALSE;
    }

    info->handle = handle;
    info->offset = nodes[entrynum].file.offset;
    info->size = nodes[entrynum].file.size;
    return TRUE;
}
