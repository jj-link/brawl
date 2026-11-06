#include <types.h>
#pragma force_active on

void fn_801EFF28(s32, s32, void *, void *, void *);

void fn_801F0194(s32 arg0, s32 *arg1) {
    s32 var_r31;
    s32 *var_r30;

    var_r31 = 9;
    var_r30 = arg1;
    do {
        *var_r30 = var_r31;
        fn_801EFF28(arg0, var_r31, var_r30 + 1, var_r30 + 2, var_r30 + 3);
        var_r31 += 1;
        var_r30 += 4;
    } while (var_r31 <= 0x14);
    *var_r30 = 0xFF;
}
