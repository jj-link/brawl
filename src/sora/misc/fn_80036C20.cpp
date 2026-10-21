#pragma force_active on
#include <types.h>

extern "C" s32 fn_80036C20(u8* arg0) {
    s32 temp_r4;
    s32 var_r5;

    temp_r4 = *(s32*)(arg0 + 0xB0);
    var_r5 = 0;
    if ((((s32)((temp_r4 * 0x10) & 0xF8000000)) >> 0x1C) != 1 || !((arg0[0xB1] >> 4) & 1) || (temp_r4 >> 0x1C) != 2) {
        var_r5 = 1;
    }
    return var_r5;
}
