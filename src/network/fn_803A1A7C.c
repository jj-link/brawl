#pragma force_active on
#include <types.h>

s32 fn_8039A260(void);
s32 fn_8039A274(void);
s32 fn_803A1DF4(void **);

s32 fn_803A1A7C(s32 *arg0) {
    void *sp8;
    s32 temp_r3;

    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    temp_r3 = fn_803A1DF4(&sp8);
    if (temp_r3 != 0) {
        return temp_r3;
    }
    *arg0 = ((s32 *)sp8)[2];
    return 0;
}
