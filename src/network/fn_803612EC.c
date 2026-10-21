#include <types.h>
#pragma force_active on

s32 fn_803612EC(s32 *arg0) {
    s32 temp_r0;
    u8 *var_r3;
    u8 *var_r4;
    u8 temp_r5;

    temp_r0 = *arg0;
    if (temp_r0 == 0) {
        return 1;
    }
    var_r4 = (u8 *)arg0 + 4;
    var_r3 = (u8 *)arg0 + (temp_r0 * 4) + 3;
    while (var_r4 < var_r3) {
        temp_r5 = *var_r4;
        *var_r4 = *var_r3;
        var_r4 += 1;
        *var_r3 = temp_r5;
        var_r3 -= 1;
    }
    return 1;
}
