#include <types.h>
#pragma force_active on
typedef struct Entry {
    u32 flags;
    void *arg;
    void *other;
    char pad[28];
} Entry;
typedef struct Global {
    u16 count;
    char pad[0x61a];
    Entry entries[26];
} Global;
extern Global lbl_805639C0;
extern s32 fn_803D7B04(void *, void *);
s32 fn_803D8878(void *arg0, void *arg1, Entry **out) {
    u16 i;
    int j;
    int result;
    *out = 0;
    if (lbl_805639C0.count >= 26) return 10;
    i = 0;
    for (j = 0; j < 13; j++) {
        if (!(lbl_805639C0.entries[i].flags & 1)) break;
        i++;
        if (!(lbl_805639C0.entries[i].flags & 1)) break;
        i++;
    }
    if (i == 26) return 10;
    result = fn_803D7B04(arg0, &lbl_805639C0.entries[i]);
    if (result != 0) return result;
    lbl_805639C0.count++;
    lbl_805639C0.entries[i].flags |= 1;
    lbl_805639C0.entries[i].arg = arg0;
    lbl_805639C0.entries[i].other = arg1;
    *out = &lbl_805639C0.entries[i];
    return 0;
}