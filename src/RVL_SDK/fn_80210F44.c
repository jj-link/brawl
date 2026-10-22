#include <types.h>
#pragma force_active on

typedef struct Entry {
    u32 flags;
    u32 unk4;
    s32 value;
} Entry;

typedef struct Owner {
    u32 unk0;
    Entry *entries;
} Owner;

typedef struct Result {
    Owner *owner;
    s32 index;
    s32 next;
    s32 value;
} Result;

extern s32 fn_80210A9C(void);

s32 fn_80210F44(Owner *arg0, void *unused, Result *arg2) {
    s32 idx;
    Entry *base;

    idx = fn_80210A9C();
    base = arg0->entries;
    if (idx < 0 || (base[idx].flags & 0xFF000000) == 0) {
        return 0;
    }

    arg2->index = idx;
    arg2->owner = arg0;
    arg2->next = idx + 1;
    arg2->value = base[idx].value;
    return 1;
}
