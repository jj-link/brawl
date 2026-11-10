#pragma force_active on
#include <types.h>

extern void OSReport(const char *, ...);
extern s32 fn_803CB620(s32, u32, s32, s32, s32, void *, s32, s32, s32, s32 *, s32, s32);
extern s32 fn_803CB148(s32 *, s32, s32 *, s32);
extern s32 fn_803CB23C(s32 *, s32, s32 *, s32);
extern char lbl_804927E0[];

s32 fn_803CC5F0(s32 *arg0, s32 arg1)
{
    char *base = lbl_804927E0;
    s32 result;
    s32 mask = ((s32)~((arg1 - 4) | (4 - arg1)) >> 31) & 2;
    s32 sp18;
    s32 buf[4];

    result = fn_803CB620(arg0[0], 0x37, 3, 1, arg0[4], 0, 0, 0, 0, buf, 0, 0);
    if (result != 0) {
        OSReport(base + 0x618);
        OSReport(base + 0x624, base + 0x608, result);
        return result;
    }

    result = fn_803CB620(arg0[0], 6, 3, 1, mask, 0, 0, 0, 0, buf, 0, 0);
    if (result != 0) {
        OSReport(base + 0x638);
        OSReport(base + 0x624, base + 0x608, result);
        return result;
    }

    result = fn_803CB148(arg0, 0x28, &sp18, 1);
    if (result != 0) {
        OSReport(base + 0x648, base + 0x608, 0x28);
        return result;
    }

    if (mask != 0) {
        sp18 |= 2;
    } else {
        sp18 &= ~2;
    }

    result = fn_803CB23C(arg0, 0x28, &sp18, 1);
    if (result != 0) {
        OSReport(base + 0x668, base + 0x608, 0x28);
        return result;
    }

    return result;
}
