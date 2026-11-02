#include <types.h>
#pragma force_active on

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 state);
extern void fn_80260074(u32 addr, void *buf, u32 size);
extern s32 fn_8026037C(u32 addr, void *buf, u32 size);
extern s32 fn_80260198(u32 addr, void *buf, u32 size);
extern u8 lbl_8059EE48;

s32 fn_8025FBB8(void *arg0, u32 arg1) {
    u32 addr;
    u32 size;
    u8 spA;
    u8 sp9;
    u8 sp8;
    u32 spC;
    s32 enabled;
    u8 idx;
    u32 val;

    enabled = OSDisableInterrupts();
    do {
        fn_80260074(0x34000000, &spA, 1);
    } while (spA & 4);
    size = (arg1 + 3) & ~3;
    idx = lbl_8059EE48 + 1;
    lbl_8059EE48 = idx;
    addr = (((((-(idx & 1)) & 0x800) + 0xD10000) << 6) & 0x3FFFFF00) | 0x80000000;
    do {
    } while (fn_8026037C(addr, arg0, size) == 0);
    do {
        fn_80260074(0x34000000, &sp9, 1);
    } while (sp9 & 4);
    val = ((lbl_8059EE48 << 16) & 0xFF0000) | (((arg1 & 0x1FFF) | 0x1F000000) & ~0xFF0000);
    do {
        spC = val;
    } while (fn_80260198(0xB4000100, &spC, 4) == 0);
    do {
        fn_80260074(0x34000000, &sp8, 1);
    } while (sp8 & 4);
    OSRestoreInterrupts(enabled);
    return 0;
}
