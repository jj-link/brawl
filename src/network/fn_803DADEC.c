#include <types.h>
#pragma force_active on

extern s32 fn_803E2414(void *, void *, s32, void *);

typedef struct Fn803DADECCopy {
    u32 words[0x90];
} Fn803DADECCopy;

void *fn_803DADEC(void *arg0, void *arg1) {
    u8 *walk = (u8 *)arg0;
    u8 *candidate = (u8 *)arg0 + 0xE3C;
    u8 *freeEntry = 0;
    int i;

    for (i = 0; i < 3; i++) {
        if (!(*(u32 *)(walk + 0xE3C) & 1) ||
            (((*(u32 *)(walk + 0xE3C) & 1) &&
              ((*(u32 *)(walk + 0xE3C) == 0) & 2)))) {
            if (freeEntry == 0)
                freeEntry = candidate;
        } else if (*(u32 *)((u8 *)arg1 + 0x22C) == *(u32 *)(walk + 0x10A8) &&
                   *(u32 *)((u8 *)arg1 + 0x238) == *(u32 *)(walk + 0x10B4) &&
                   *(u16 *)((u8 *)arg1 + 0x23C) == *(u16 *)(walk + 0x10B8)) {
            return (u8 *)arg0 + i * 0x280 + 0xE3C;
        }
        walk += 0x280;
        candidate += 0x280;
    }

    if (freeEntry == 0)
        return 0;

    *(u32 *)freeEntry = 3;
    *(u16 *)(freeEntry + 4) = 0;
    *(Fn803DADECCopy *)(freeEntry + 0x40) = *(Fn803DADECCopy *)arg1;
    fn_803E2414(freeEntry + 8, 0, *(s32 *)((u8 *)arg1 + 0x22C), freeEntry + 0x274);
    return freeEntry;
}