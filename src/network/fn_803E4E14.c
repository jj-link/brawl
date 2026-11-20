#pragma force_active on
#include <revolution/VF/pf_entry_iterator.h>
#include <revolution/VF/pf_entry.h>
#include <revolution/VF/pf_fat.h>

typedef struct VolumeView VolumeView;
typedef struct FileCache {
    u32 flags;
    u8 pad4[0x260];
    u32 size;
    VolumeView *volume;
    u8 pad26c[8];
    u32 sector;
    u16 offset;
    u8 pad27a[0x1e];
    u16 refs;
    u16 pad29a;
} FileCache;
typedef struct FileHandle {
    u32 flags;
    u32 mode;
    FileCache *cache;
    u8 context[0xc];
    u32 field18;
    u32 position;
    u32 field20;
    u32 sector;
    u16 offset;
    u16 pad2a;
    u16 field2c;
    u16 pad2e;
} FileHandle;
struct VolumeView {
    u16 sectorSize;
    u8 pad2[0x1e];
    u8 shift;
    u8 pad21[0x1f];
    FileCache caches[5];
    FileHandle handles[5];
};
extern int fn_803E7224(PF_STR *, PF_STR *, PF_STR *);
extern u32 fn_803D66F4(PF_STR *);
extern void fn_803D66FC(PF_STR *, void *);
extern void *fn_803D6724(PF_STR *, u32);
extern u16 fn_803D68CC(PF_STR *, u32);
extern int fn_803E7C50(char *, void *);
extern int fn_803E2414(void *, void *, void *, u32 *);
extern int fn_803DD64C(void *, PF_DIR_ENT *, int, PF_STR *, int, int);
extern int fn_803E4968(PF_VOLUME *, PF_DIR_ENT *, PF_STR *);
extern FileCache *fn_803E47A4(VolumeView *, PF_DIR_ENT *);
extern void fn_803E23C0(void *);

static inline int is_open(PF_DIR_ENT *ent) {
    u32 flags;
    VolumeView *volume;
    u16 offset;
    u32 sector;
    FileCache *cache;
    int i;
    volume = ent->cache;
    sector = ent->sector;
    cache = volume->caches;
    offset = *(u16 *)((u8 *)ent + 0x23c);
    for (i = 0; i < 5; i++, cache++) {
        flags = cache->flags;
        if ((flags & 1) && (flags & 2) && volume == cache->volume &&
            sector == cache->sector && offset == cache->offset)
            return 1;
    }
    return 0;
}
static FileHandle *get_handle(VolumeView *volume) {
    int i;
    for (i = 0; i < 5; i++) {
        if (!(volume->handles[i].flags & 1))
            return &volume->handles[i];
    }
    return 0;
}
static VolumeView *get_volume(FileHandle *file) {
    if (file == 0)
        return 0;
    return file->cache->volume;
}
static void update_position(FileHandle *file) {
    VolumeView *volume = get_volume(file);
    file->sector = file->position >> volume->shift;
    file->offset = file->position & (volume->sectorSize - 1);
}
#define ATTR(e) ((u8)(e)._0x0[0x21c])
#define DATE(e, n) (*(u16 *)((u8 *)&(e) + (n)))
int fn_803E4E14(PF_VOLUME *arg0, PF_STR *arg1, u32 mode, FileHandle **out) {
    PF_DIR_ENT ent;
    char name[0x200];
    PF_ENT_ITER iter;
    u8 context[0x38];
    PF_STR str;
    PF_STR rest;
    u8 cursor[0xc];
    u16 time;
    int result;
    FileCache *cache;
    VolumeView *volume;
    FileHandle *file;
    *out = 0;
    if (fn_803E7224(arg1, &rest, &str) != 0)
        return 1;
    result = PFENT_ITER_GetEntryOfPath(&iter, &ent, arg0, arg1, 1);
    if (result != 0)
        return result;
    if (!(ATTR(ent) & 0x10))
        return 1;
    if (fn_803D66F4(&str) == 2U) {
        if ((int)fn_803D68CC(&str, 1) > 0xff)
            return 1;
        fn_803E7C50(name, fn_803D6724(&str, 1));
    }
    fn_803D66FC(&str, name);
    if (mode & 2) {
        fn_803E2414(context, cursor, ent.cache, &ent._0x234);
        if (fn_803DD64C(context, &ent, 0, &str, 0x7f, 0) != 0)
            return 3;
        if ((mode & 8) && (ATTR(ent) & 1))
            return 10;
        if (ATTR(ent) & 0x10)
            return 23;
        PFENT_getcurrentDateTimeForEnt(&DATE(ent, 0x222), &time);
    } else {
        result = fn_803E4968(arg0, &ent, &str);
        if (result == 8) {
            u32 truncate;
            if (mode & 0x10)
                return 8;
            truncate = mode & 1;
            if (truncate && is_open(&ent))
                return 8;
            if ((ATTR(ent) & 1) && (truncate || (mode & 4) || (mode & 8)))
                return 10;
            if (ATTR(ent) & 0x10)
                return 23;
            if (truncate) {
                if (ent._0x234 >= 2 && ent._0x234 != 0xffffffffU &&
                    ent._0x228 != 0)
                    PFFAT_FreeChain((u8 *)&iter + 8, ent._0x234, -1, ent._0x228);
                ent._0x234 = 0;
                ent._0x228 = 0;
                PFENT_getcurrentDateTimeForEnt(&DATE(ent, 0x226), &DATE(ent, 0x224));
                DATE(ent, 0x222) = DATE(ent, 0x226);
            } else {
                PFENT_getcurrentDateTimeForEnt(&DATE(ent, 0x222), &time);
            }
        } else if (result != 0) {
            return result;
        }
    }
    arg0 = (PF_VOLUME *)ent.cache;
    cache = fn_803E47A4((VolumeView *)arg0, &ent);
    if (cache == 0)
        return 21;
    file = get_handle((VolumeView *)arg0);
    if (file == 0)
        return 22;
    file->cache = cache;
    file->flags = 1;
    file->mode = mode;
    file->field18 = 0;
    file->field2c = 0;
    fn_803E23C0(file->context);
    file->field20 = -1;
    file->position = 0;
    update_position(file);
    if (mode & 1)
        file->cache->flags |= 4;
    if (file->mode & 4) {
        file->position = file->cache->size;
        update_position(file);
    }
    cache->refs++;
    *out = file;
    return 0;
}
