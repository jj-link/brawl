#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct Tbl {
    u32 *items;
    u32 pad4;
    s32 count;
} Tbl;

s32 fn_8027DD98(Tbl *t, s32 idx) {
    s32 n = t->count;
    s32 i;

    for (i = idx + 1; i <= n; i++) {
        if (t->items[i] != 0xFFFFFFFFu) {
            break;
        }
    }

    return i;
}
