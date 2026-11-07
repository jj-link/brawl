#include <types.h>
#pragma force_active on

s32 fn_803931A8(s8 *arg0, s32 arg1) {
    u8 temp_r5 = arg0[(arg1 - 2) & 3];
    if ((s8)temp_r5 == 13 && arg0[(arg1 - 1) & 3] == 13) return 1;
    if ((s8)temp_r5 == 10 && arg0[(arg1 - 1) & 3] == 10) return 1;
    if (arg0[(arg1 - 4) & 3] == 13 && arg0[(arg1 - 3) & 3] == 10 && (s8)temp_r5 == 13 && arg0[(arg1 - 1) & 3] == 10) return 1;
    return 0;
}