#include <types.h>
#pragma force_active on
void fn_803C73F8(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    s32 temp_r0;
    s32 temp_r10;
    s32 temp_r11;
    temp_r11 = arg0 & 0x1F;
    *arg5 = 0;
    *arg3 = 0;
    *arg6 = 0;
    *arg4 = 0;
    *arg2 = 0;
    if (temp_r11 == 0) {
        *arg2 = 0;
        *arg3 = arg0;
        *arg4 = arg1;
        *arg5 = 0;
        *arg6 = 0;
        return;
    }
    temp_r10 = arg1 - 0x20;
    temp_r0 = 0x20 - temp_r11;
    *arg2 = temp_r0;
    if (temp_r10 != 0) {
        *arg3 = arg0 + temp_r0;
        *arg4 = temp_r10;
    }
    *arg6 = temp_r11;
    *arg5 = (arg0 + arg1) - temp_r11;
}