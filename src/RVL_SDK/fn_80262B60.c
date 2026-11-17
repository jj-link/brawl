#include <types.h>
#pragma force_active on

extern s32 fn_80261004(u16 *, void *);
extern s32 fn_802632F4(u16 *, void *);
extern s32 fn_802638DC(void *);
extern const u8 lbl_8040DD10[];

s32 fn_80262B60(void *arg0) {
    u8 *p;
    s32 r7;
    const u8 *r8;
    u8 *r9;
    s32 i;
    u16 sp8;
    s32 t;

    p = (u8 *)arg0;
    r8 = lbl_8040DD10;
    *(u16 *)(p + 0x1806) = 0;
    p[0x1808] = 0;
    r7 = 0;
    for (i = 0; i < 8; i++) {
        r9 = p + r7;
        r9[0x444] = (r8[0] * 4) & 0xFC;
        r9[0x445] = (r8[1] * 4) & 0xFC;
        r9[0x446] = (r8[2] * 4) & 0xFC;
        r9[0x447] = (r8[3] * 4) & 0xFC;
        r9[0x448] = (r8[4] * 4) & 0xFC;
        r9[0x449] = (r8[5] * 4) & 0xFC;
        r9[0x44A] = (r8[6] * 4) & 0xFC;
        r9[0x44B] = (r8[7] * 4) & 0xFC;
        r8 += 8;
        r7 += 8;
    }

    t = fn_80261004(&sp8, arg0);
    if (t < 0)
        return t;
    if (sp8 != 0xFFD8)
        return -0x20;

    sp8 = 0;
    t = fn_802632F4(&sp8, arg0);
    if (t < 0)
        return t;
    if (sp8 != 0xFFC0)
        return -0x10;

    t = fn_802638DC(arg0);
    return t & (t >> 31);
}
