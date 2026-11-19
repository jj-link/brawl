#pragma force_active on
typedef int bool;
typedef struct OSModuleHeader OSModuleHeader;
#include <revolution/OS/OSThread.h>
#include <revolution/NAND/nand.h>
extern int lbl_805A1228;
extern int lbl_805A122C;
extern int fn_8020A710(const char *, u8, u8);
extern int fn_8020A784(const char *, u8, u8);
extern int fn_8020A870(const char *);
extern int fn_8020A920(const char *);
extern int fn_8020B9BC(const char *, NANDFileInfo *, u8);
extern int fn_8020BA48(const char *, NANDFileInfo *, u8);
extern int fn_8020AB58(NANDFileInfo *, const void *, u32);
extern int fn_8020BC3C(NANDFileInfo *);
extern void *fn_803A976C(void *, int, u32);
extern void fn_803C74C8(void *, u32, u32, int);
typedef struct Entry {
    int (*create)(const char *, u8, u8);
    int (*open)(const char *, NANDFileInfo *, u8);
    int (*read)(NANDFileInfo *, void *, u32);
    int (*remove)(const char *);
} Entry;
extern Entry lbl_80563798[];

static inline int create_public(const char *path, u8 perm, u8 attr) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020A710(path, perm, attr);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int create_private(const char *path, u8 perm, u8 attr) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020A784(path, perm, attr);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int open_public(const char *path, NANDFileInfo *file, u8 mode) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020B9BC(path, file, mode);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int open_private(const char *path, NANDFileInfo *file, u8 mode) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020BA48(path, file, mode);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int write_retry(NANDFileInfo *file, const void *data, u32 size) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020AB58(file, data, size);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int close_retry(NANDFileInfo *file) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020BC3C(file);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int delete_public(const char *path) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020A870(path);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline int delete_private(const char *path) {
    int count = lbl_805A1228;
    int status = 0;
    while (count-- > 0) {
        status = fn_8020A920(path);
        if (status == -3) goto sleep;
        if (status == -2) goto sleep;
        return status;
sleep:
        OSSleepTicks(lbl_805A122C * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
    }
    return status;
}

static inline s16 create_dispatch(const char *path, u8 perm, u32 type) {
    if (type < 26) {
        if (lbl_80563798[type].create)
            return lbl_80563798[type].create(path, perm, 0);
        return create_public(path, perm, 0);
    }
    if (type == (u32)-10)
        return create_public(path, perm, 0);
    return create_private(path, perm, 0);
}
static inline int open_dispatch(const char *path, NANDFileInfo *file, u32 type) {
    if (type < 26) {
        if (lbl_80563798[type].open)
            return lbl_80563798[type].open(path, file, 2);
        return open_public(path, file, 2);
    }
    if (type == (u32)-10)
        return open_public(path, file, 2);
    return open_private(path, file, 2);
}
static inline void delete_dispatch(const char *path, u32 type) {
    if (type < 26) {
        if (lbl_80563798[type].remove)
            lbl_80563798[type].remove(path);
        else
            delete_public(path);
    } else if (type == (u32)-10) {
        delete_public(path);
    } else {
        delete_private(path);
    }
}
static inline void cleanup(NANDFileInfo *file, const char *path, u32 type) {
    close_retry(file);
    delete_dispatch(path, type);
}
static inline u8 convert_perms(u32 flags) {
    u8 perm;
    perm = 0;
    if (flags & 1) perm |= 0x10;
    if (flags & 2) perm |= 0x20;
    if (flags & 4) perm |= 4;
    if (flags & 8) perm |= 8;
    if (flags & 16) perm |= 1;
    if (flags & 32) perm |= 2;
    return perm;
}
int fn_803C9168(u32 size, const char *path, u32 value, u32 flags, u32 type) {
    NANDFileInfo file;
    int status;
    u8 buffer[512] __attribute__((aligned(64)));
    u8 perm;
    s16 created;
    u32 remaining;
    if (size & 31)
        return -8;
    perm = convert_perms(flags);
    {
        int result;
        if (type < 26) {
            if (lbl_80563798[type].create)
                result = lbl_80563798[type].create(path, perm, 0);
            else
                result = create_public(path, perm, 0);
        } else if (type == (u32)-10) {
            result = create_public(path, perm, 0);
        } else {
            result = create_private(path, perm, 0);
        }
        created = result;
    }
    if (created != 0) return created;
    {
        NANDFileInfo *filep = &file;
        status = open_dispatch(path, filep, type);
    }
    if (status != 0) return (s16)status;
    fn_803C74C8(buffer, size, value, 0);
    status = write_retry(&file, buffer, 32);
    remaining = size - 32;
    if (status < 0) {
        cleanup(&file, path, type);
        return status;
    }
    fn_803A976C(buffer, 0, 512);
    while (remaining >= 512) {
        status = write_retry(&file, buffer, 512);
        if (status < 0) {
            cleanup(&file, path, type);
            return status;
        }
        remaining -= 512;
    }
    if (remaining != 0) {
        status = write_retry(&file, buffer, remaining);
        if (status < 0) {
            cleanup(&file, path, type);
            return status;
        }
    }
    close_retry(&file);
    return 0;
}
