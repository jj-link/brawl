#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_8009E23C(s32 value);
extern const s32 lbl_27_rodata_DE8[5];

s32 fn_27_B49E4(s32 value) {
    s32 v = fn_8009E23C(value);
    for (s32 i = 0; i < 5; i++) {
        if (v == lbl_27_rodata_DE8[i]) {
            return i;
        }
    }
    return -1;
}
}
