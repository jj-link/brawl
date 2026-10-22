#include <types.h>
#pragma force_active on

s32 fn_8039A260(void);
s32 fn_8039A274(void);
s32 fn_8039C984(s32, s32 **);

s32 fn_8039B1C0(s32 arg0, s32 *arg1) {
    s32 *sp8;
    s32 temp_r3;

    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    temp_r3 = fn_8039C984(arg0, &sp8);
    if (temp_r3 != 0) {
        *arg1 = 0;
        return temp_r3;
    }
    *arg1 = sp8[2];
    return 0;
}
