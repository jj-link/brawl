#include <types.h>
#pragma force_active on

extern s32 fn_803C75FC(u32 *arg0, u32 arg1, u32 arg2, u32 arg3);
extern void *fn_803A976C(void *dest, s32 value, u32 size);

void fn_803C76B4(void *arg0, s32 *arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u8 arg10) {
    u8 *p;
    u32 sp8;

    *arg1 = fn_803C75FC(&sp8, arg2, arg3, arg4);
    p = arg0;
    fn_803A976C(arg0, 0, 0x200);
    p[0x00] = arg5;
    p[0x02] = arg6;
    p[0x1FE] = 0x55;
    p[0x1FF] = 0xAA;
    p[0x18] = arg7;
    p[0x19] = arg7 >> 8;
    p[0x1A] = 0xFF;
    p[0x1B] = 0;
    p[0x0B] = arg4;
    p[0x0C] = arg4 >> 8;
    p[0x0D] = arg3;
    p[0x0E] = arg8;
    p[0x0F] = arg8 >> 8;
    p[0x10] = 2;
    p[0x11] = arg9;
    p[0x12] = arg9 >> 8;
    p[0x15] = arg10;
    if (arg2 < 0x10000) {
        p[0x13] = arg2;
        p[0x14] = arg2 >> 8;
        p[0x20] = 0;
        p[0x21] = 0;
        p[0x22] = 0;
        p[0x23] = 0;
    } else {
        p[0x13] = 0;
        p[0x14] = 0;
        p[0x20] = arg2;
        p[0x21] = arg2 >> 8;
        p[0x22] = arg2 >> 16;
        p[0x23] = arg2 >> 24;
    }
    if (*arg1 == 2) {
        p[0x0E] = 0x20;
        p[0x0F] = 0;
        p[0x11] = 0;
        p[0x12] = 0;
        p[0x24] = sp8;
        p[0x25] = sp8 >> 8;
        p[0x26] = sp8 >> 16;
        p[0x27] = sp8 >> 24;
        p[0x28] = 0;
        p[0x29] = 0;
        p[0x2A] = 0;
        p[0x2B] = 0;
        p[0x2C] = 2;
        p[0x2D] = 0;
        p[0x2E] = 0;
        p[0x2F] = 0;
        p[0x30] = 1;
        p[0x31] = 0;
        p[0x41] = 0;
        p[0x42] = 0x29;
        p[0x43] = 0x34;
        p[0x44] = 0x12;
        p[0x45] = 0;
        p[0x46] = 0;
        p[0x40] = 0x80;
        p[0x32] = 6;
        p[0x33] = 0;
        return;
    }
    p[0x11] = arg9;
    p[0x12] = arg9 >> 8;
    p[0x16] = sp8;
    p[0x17] = sp8 >> 8;
    p[0x25] = 0;
    p[0x26] = 0x29;
    p[0x27] = 0x34;
    p[0x28] = 0x12;
    p[0x29] = 0;
    p[0x2A] = 0;
    p[0x24] = 0x80;
}
