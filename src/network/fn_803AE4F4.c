#include <types.h>
#pragma force_active on

extern s32 fn_803ACDE4(void);

s32 fn_803AE4F4(s32 arg0) {
    s32 temp_r3;
    if (arg0 == 0) {
        return 1;
    }
    temp_r3 = fn_803ACDE4();
    return temp_r3 & ((-temp_r3 | temp_r3) >> 0x1F);
}
