#pragma force_active on
#include <types.h>

s32 fn_8039A260(void);
s32 fn_8039A274(void);
extern s32 lbl_80537300[16];

s32 fn_803A0240(s32 arg0) {
    s32 *p;

    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    p = lbl_80537300;
    p[8] = arg0;
    p[4] = p[4] | 0x20;
    return 0;
}
