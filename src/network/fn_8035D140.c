#include <types.h>
#pragma force_active on

u32 fn_803A7AF4(s32);

s32 fn_8035D140(s32 *arg0) {
    u32 temp_r3;
    s32 temp_r0;
    s32 temp_r3_2;

    temp_r3 = fn_803A7AF4(*arg0);
    temp_r0 = (s32) (temp_r3 >> 0x18U);
    temp_r3_2 = (s32) ((temp_r3 >> 0x10U) & 0xFFU);
    if (temp_r0 == 0xA) {
        return 1;
    }
    if (temp_r0 == 0xAC) {
        if (temp_r3_2 >= 0x10 && temp_r3_2 <= 0x1F) {
            return 1;
        }
    }
    if (temp_r0 == 0xC0 && temp_r3_2 == 0xA8) {
        return 1;
    }
    return 0;
}
