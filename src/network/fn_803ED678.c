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
extern int fn_8020BC3C(void *);
extern void fn_803D634C(void *, int, u32);

int fn_803ED678(u32 handle)
{
    Entry *entry;
    int result = 0;
    u16 i;

    fn_803EC3D4(lbl_805A1280);
    if (handle == 0) {
        fn_803EC418(lbl_805A1280);
        return -20;
    }

    for (i = 0; i < 23; i++) {
        entry = &lbl_805980D8[i];
        if (entry->handle == handle) {
            result = fn_8020BC3C((char *)entry + 0x58);
            fn_803D634C(entry, 0, 0xF0);
            break;
        }
    }

    fn_803EC418(lbl_805A1280);
    if (result != 0) {
        return -20;
    }
    return i == 23 ? -22 : 0;
}
