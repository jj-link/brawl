#include <types.h>
#pragma force_active on

s32 fn_803B0778(void *, u32 *);

s32 fn_803BBED8(u8 *arg0, u32 *arg1) {
    u8 *inner;
    u8 *disk;
    u32 unit;
    u32 rem;
    s32 r;

    inner = *(u8 **)(arg0 + 8);
    *(u32 *)(inner + 0x34) = (u32)(arg0 + 0xC);
    if (arg0 == 0) {
        disk = 0;
    } else {
        disk = *(u8 **)(*(u8 **)(arg0 + 8) + 0x268);
    }
    arg1[0] = *(u32 *)(*(u8 **)(arg0 + 8) + 0x264);
    arg1[1] = *(u32 *)(arg0 + 0x1C);
    unit = (u32)*(u16 *)disk << disk[0x21];

    inner = *(u8 **)(arg0 + 8);
    if (*(s32 *)(inner + 0x270) != 0) {
        r = fn_803B0778(arg0, arg1 + 3);
        if (r != 0) {
            return r;
        }
        rem = *(u32 *)(*(u8 **)(arg0 + 8) + 0x264) % unit;
        arg1[2] = arg1[3] + (rem != 0 ? unit - rem : 0);
    } else {
        arg1[3] = 0;
        arg1[2] = 0;
    }
    arg1[4] = *(u16 *)(*(u8 **)(arg0 + 8) + 0x27C) & 3;
    arg1[5] = *(u32 *)(*(u8 **)(arg0 + 8) + 0x284);
    arg1[6] = *(u16 *)(arg0 + 0x2C);
    arg1[7] = *(u16 *)(*(u8 **)(arg0 + 8) + 0x27E);
    return 0;
}
