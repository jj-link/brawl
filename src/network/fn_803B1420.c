#include <types.h>
#pragma force_active on
extern s32 fn_803B5638(void *, void *, void *, s32, s32);
extern void fn_803BBFF8(void *, void **);
s32 fn_803B1420(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 st[0x2b0];
    u8 *sp8;
    u8 fl;
    s32 mask;
    u8 *cursor;
    u8 *r4;
    u32 b2;
    u16 b3;
    u8 *base;
    u32 f;
    u8 *r3;
    s32 ret;
    ret = fn_803B5638(st, st + 0x70, arg0, arg1, 0);
    if (ret != 0) return ret;
    sp8 = 0;
    fl = st[0x28c];
    mask = fl & 0x10;
    if (mask && *(s32 *)(arg0 + 0x15E4) != 0) {
        {
            int i;
            base = *(u8 **)&st[0x29c];
            b2 = *(u32 *)&st[0x2a8];
            b3 = *(u16 *)&st[0x2ac];
            r4 = base + 0xE40;
            sp8 = 0;
            cursor = base;
            for (i = 0; i < 3; i++, cursor += 0x280, r4 += 0x280) {
                f = *(u32 *)(cursor + 0xE00);
                if ((f & 1) && (f & 2) && base == *(u8 **)(cursor + 0x106C) &&
                    b2 == *(u32 *)(cursor + 0x1078) && b3 == *(u16 *)(cursor + 0x107C)) sp8 = r4;
            }
        }
    } else if (!mask && !(fl & 8) && *(s32 *)(arg0 + 0x15E0) != 0) {
        fn_803BBFF8(st + 0x70, (void **)&sp8);
    }
    if (sp8 == 0) sp8 = st + 0x70;
    *(s32 *)arg2 = *(s32 *)(sp8 + 0x228);
    fl = sp8[0x21C];
    *(u8 *)(arg2 + 0x10) = fl;
    if (fl == 0) *(u8 *)(arg2 + 0x10) = 0x40;
    *(u16 *)(arg2 + 6) = *(u16 *)(sp8 + 0x224);
    *(u16 *)(arg2 + 8) = *(u16 *)(sp8 + 0x226);
    *(u16 *)(arg2 + 4) = *(u16 *)(sp8 + 0x222);
    *(u16 *)(arg2 + 0xA) = *(u16 *)(sp8 + 0x21E);
    *(u16 *)(arg2 + 0xC) = *(u16 *)(sp8 + 0x220);
    *(s16 *)(arg2 + 0xE) = sp8[0x21D];
    return 0;
}