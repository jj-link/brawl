#pragma force_active on
#include <types.h>

s32 fn_8039A260(void);
s32 fn_8039A274(void);
extern s32 lbl_80537300[16];

s32 fn_803A0158(void) {
    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    lbl_80537300[0] = 0;
    lbl_80537300[1] = 0;
    lbl_80537300[2] = 0;
    lbl_80537300[3] = 0;
    lbl_80537300[4] = 0;
    lbl_80537300[5] = 1;
    lbl_80537300[7] = 0;
    lbl_80537300[6] = 0;
    lbl_80537300[8] = 0;
    lbl_80537300[9] = 0;
    return 0;
}
