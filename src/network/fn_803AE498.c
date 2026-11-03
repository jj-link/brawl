#include <types.h>
#pragma force_active on

extern s32 fn_803ACCC8(s32, u16);

s32 fn_803AE498(s32 arg0, s32 arg1, s32 *arg2) {
    s32 temp_r3;

    if (arg0 == 0) {
        return 1;
    }
    if (arg2 == NULL) {
        return 1;
    }
    *arg2 = 0;
    temp_r3 = fn_803ACCC8(arg0, (u16)arg1);
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 0x1F);
}
