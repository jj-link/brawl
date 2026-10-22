#include <types.h>
#pragma force_active on

s32 fn_80214A98(s32, s32 *, s32 *);

s32 fn_8020D844(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 spC;
    s32 sp8;
    s32 *var_r30;
    s32 var_r3;

    var_r30 = arg2;
    *arg0 = 0;
    var_r3 = -0x75;
    *arg1 = 0;
    while (*var_r30 != 0) {
        spC = 0;
        sp8 = 0;
        var_r3 = fn_80214A98(*var_r30, &spC, &sp8);
        if (var_r3 == 0) {
            *arg0 += spC;
            *arg1 += sp8;
        } else if (var_r3 == -0x6A) {
            var_r3 = 0;
        } else {
            break;
        }
        var_r30++;
    }
    return var_r3;
}
