#include <types.h>
#pragma force_active on

extern s32 lbl_8059F0B8;
extern s32 lbl_8059F0BC;

s32 fn_8033CAC0(s32 arg0, s32 arg1) {
    if (arg1 < arg0) {
        return 0;
    }
    lbl_8059F0B8 = arg0;
    lbl_8059F0BC = arg1;
    return 1;
}
