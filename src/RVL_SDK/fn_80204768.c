#include <types.h>
#pragma force_active on

extern void OSLockMutex(void*);
extern void OSUnlockMutex(void*);
extern s32 fn_8020437C(void*, s32, s32);
extern s32 fn_80204458(void*, s32, s32);

struct H {
    char pad[0x20];
    char mutex[0x18];
    u32 flags;
};

s32 fn_80204768(struct H* h, s32 size, s32 align) {
    s32 r;
    if (size == 0) size = 1;
    size = (size + 3) & ~3;
    if (h->flags & 4) OSLockMutex(h->mutex);
    if (align >= 0) r = fn_8020437C(h, size, align);
    else r = fn_80204458(h, size, -align);
    if (h->flags & 4) OSUnlockMutex(h->mutex);
    return r;
}
