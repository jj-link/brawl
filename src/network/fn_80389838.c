#include <types.h>

s32 fn_80389F84(s32);
void fn_8038A00C(s32, s32);

#pragma force_active on
void fn_80389838(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_80389F84(arg0 + 0x4C);
    if (temp_r3 != -1) {
        fn_8038A00C(arg0 + 0x4C, temp_r3);
    }
}
