#include <types.h>
#pragma force_active on

extern s32 fn_8037BCD0(u8 *arg0, void *arg1, s32 arg2);
extern s32 SOHtoNl(s32);

s32 fn_8037CB28(u8 *arg0, s32 *arg1) {
    s32 spC;
    u8 sp8;
    s32 var_r0;
    s8 temp_r0;

    sp8 = 0;
    if (fn_8037BCD0(arg0, &sp8, 1) == 0) {
        return 0;
    }
    if ((s32) sp8 != 0x30) {
        return 0;
    }
    if (fn_8037BCD0(arg0, &sp8, 1) == 0) {
        return 0;
    }
    if ((s32) (sp8 & 0x80) == 0x80) {
        temp_r0 = sp8 ^ 0x80;
        spC = 0;
        sp8 = temp_r0;
        if ((u32) temp_r0 > 4U) {
            var_r0 = 0;
        } else if (fn_8037BCD0(arg0, (u8 *) &spC + (4 - temp_r0), temp_r0) == 0) {
            var_r0 = 0;
        } else {
            spC = SOHtoNl(spC);
            var_r0 = 1;
        }
        if (var_r0 == 0) {
            return 0;
        }
        if (spC > *(s32 *) (arg0 + 0x0C) - *(s32 *) (arg0 + 0x10)) {
            return 0;
        }
        *arg1 = spC;
        return 1;
    }
    if ((s8) sp8 > *(s32 *) (arg0 + 0x0C) - *(s32 *) (arg0 + 0x10)) {
        return 0;
    }
    *arg1 = (s32) (s8) sp8;
    return 1;
}
