#include <types.h>
#pragma force_active on

extern s32 lbl_805A0B48;
extern u32 lbl_805A0B4C;
extern u32 lbl_805A0B50;
extern s32 lbl_805A0B54;

s32 fn_802025D4(void) {
    if (lbl_805A0B48 != 0) {
        s32 p = lbl_805A0B54 + lbl_805A0B4C++ * 0x38;
        lbl_805A0B4C %= lbl_805A0B50;
        return p;
    }
    return 0;
}
