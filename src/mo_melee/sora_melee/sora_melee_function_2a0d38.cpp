#include <types.h>
#pragma force_active on

extern "C" {
extern s32 lbl_27_data_71BF0[];
s32 fn_27_2A0D38(s32, s32);
}

s32 fn_27_2A0D38(s32 a, s32 b) {
    if (b == -3)
        return 1;
    if (b < 0 || b >= 0xB2)
        return -1;
    return lbl_27_data_71BF0[b];
}
