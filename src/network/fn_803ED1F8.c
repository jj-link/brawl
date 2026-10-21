#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Entry {
    u32 handle;
    unsigned char pad[0xE0];
    u32 flags;
    unsigned char tail[8];
} Entry;

extern Entry lbl_805980D8[];
extern int lbl_805A1280;

extern void fn_803EC3D4(int);
extern void fn_803EC418(int);
extern int fn_803EC45C(u32, Entry *, int);

int fn_803ED1F8(u32 handle)
{
    Entry *entry = 0;
    u16 i;
    int status;
    Entry *candidate;

    fn_803EC3D4(lbl_805A1280);
    if (handle == 0) {
        fn_803EC418(lbl_805A1280);
        return -20;
    }

    for (i = 0; i < 23; ++i) {
        candidate = &lbl_805980D8[i];
        if (candidate->handle == handle) {
            entry = candidate;
            break;
        }
    }

    status = i == 23 ? -22 : 0;
    if (status != 0) {
        fn_803EC418(lbl_805A1280);
        return -20;
    }

    entry->flags |= 4;
    status = fn_803EC45C(handle, entry, 1);
    entry->flags &= ~4;
    fn_803EC418(lbl_805A1280);
    return status;
}
