#include <types.h>
#pragma force_active on

typedef struct Entry {
    u32 handle;
    u8 pad[0xE0];
    u32 flags;
    u8 tail[8];
} Entry;

extern Entry lbl_805980D8[];
extern int lbl_805A1280;
extern void fn_803EC3D4(int);
extern void fn_803EC418(int);
extern int fn_803EC45C(u32, Entry *, int);

static inline Entry *find_entry(u32 handle)
{
    u16 i;
    Entry *entry;
    for (i = 0; i < 23; ++i) {
        entry = &lbl_805980D8[i];
        if (entry->handle == handle && !(entry->flags & 2))
            return entry;
    }
    for (i = 0; i < 23; ++i) {
        entry = &lbl_805980D8[i];
        if (entry->handle == 0 && (s8)entry->pad[0] != 0)
            return entry;
    }
    return 0;
}

int fn_803ED044(u32 handle)
{
    u16 i;
    Entry *candidate;
    Entry *found;
    Entry *entry;
    int status;

    fn_803EC3D4(lbl_805A1280);
    if (handle == 0) {
        fn_803EC418(lbl_805A1280);
        return -20;
    }

    for (i = 0; i < 23; ++i) {
        candidate = &lbl_805980D8[i];
        if (candidate->handle == handle) {
            found = candidate;
            break;
        }
    }

    status = (i == 23) ? -22 : 0;
    if (status == 0 && (found->flags & 2)) {
        fn_803EC418(lbl_805A1280);
        return -21;
    }

    entry = find_entry(handle);
    if (entry == 0) {
        fn_803EC418(lbl_805A1280);
        return -22;
    }
    if (entry->handle != 0) {
        status = 0;
    } else {
        status = fn_803EC45C(handle, entry, 0);
    }
    if (status == 0) {
        entry->flags |= 2;
    }
    fn_803EC418(lbl_805A1280);
    return status;
}
