#include <types.h>
#pragma force_active on

extern s32 fn_8039A260(void);
extern s32 fn_8039A274(void);
extern s32 lbl_80537300[16];

s32 fn_803A01D0(s32 arg0) {
    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    if (arg0 != 0 && arg0 != 1) {
        return -3;
    }
    lbl_80537300[5] = arg0;
    return 0;
}