#include <types.h>
#pragma force_active on

extern s32 fn_803D8878(void);

s32 fn_803D72F8(s32 arg1, s32 arg2, s32 *arg3) {
    s32 temp_r3;

    (void)arg1;
    (void)arg2;
    *arg3 = 0;
    temp_r3 = fn_803D8878();
    return temp_r3 & ((s32)(-temp_r3 | temp_r3) >> 0x1F);
}
