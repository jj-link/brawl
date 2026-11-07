#include <types.h>
#pragma force_active on
extern char lbl_8053B248[];
extern s32 fn_803AA040(u16 *, u16 *, s32);
extern void fn_803A9938(u32, s16 *, s16 *);

s32 fn_803BEE24(char *arg0, u16 *arg1) {
    u16 sp10[2];
    u16 spC[2];
    s16 spA;
    s16 sp8;
    u16 *var_r27;
    s32 var_r27_2;

    if ((*(u32 *)(lbl_8053B248 + 0x3C) & 2) == 2) {
        sp10[0] = 0x2E;
        sp10[1] = 0;
        var_r27 = arg1;
        spC[0] = 0x20;
        spC[1] = 0;
        while (*var_r27 != 0) {
            if (fn_803AA040(arg1, sp10, 1) == 0) {
                *arg0 = 0x2E;
            } else if (fn_803AA040(arg1, spC, 1) == 0) {
                *arg0 = 0x20;
            } else {
                *arg0 = 0x5F;
            }
            arg0 += 1;
            arg1 += 1;
            var_r27 += 1;
        }
    } else {
        var_r27_2 = 0;
        while (arg1[var_r27_2] != 0) {
            u32 value = ((u32 (*)(u16 *, char *))(*(s32 *)(lbl_8053B248 + 0x28)))((u16 *)((char *)arg1 + var_r27_2 * 2), arg0);
            fn_803A9938(value, &spA, &sp8);
            arg0 += spA;
            var_r27_2 += sp8 >> 1;
        }
    }
    *arg0 = 0;
    return 0;
}