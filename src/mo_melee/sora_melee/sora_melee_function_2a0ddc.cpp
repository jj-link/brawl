#include <types.h>
#pragma force_active on

extern "C" {
extern s32 lbl_27_rodata_47C8[];

s32 fn_27_2A0DDC(void* unused, s32 idx) {
    s32 valid = 0;
    if (idx > -1 && idx < 0xB2) {
        valid = 1;
    }
    if (valid == 0) {
        return 0;
    }
    s32 v = lbl_27_rodata_47C8[idx];
    return v < 0 ? -v : v;
}
}
