#include <types.h>
#pragma force_active on

s32 fn_8039A260(void);
s32 fn_8039A274(void);
s32 fn_803995F8(s32 *);
s32 fn_8039DCE0(s32 *, s32);
extern s32 lbl_8059FD40;

s32 fn_8039DC18(s32 *arg0) {
    s32 buf[2];
    s32 var_r31;
    s32 temp_r3;

    var_r31 = 0;
    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    temp_r3 = arg0[1];
    if (!(temp_r3 & 0x100) || (temp_r3 & 0x200)) {
        return -7;
    }
    if (lbl_8059FD40 != 0 && (temp_r3 & 1)) {
        fn_803995F8(buf);
        if (*(u8 *)(arg0 + 0x32) == 1 && *(u64 *)(arg0 + 0x22) == *(u64 *)buf) {
            var_r31 = 1;
        }
    }
    return fn_8039DCE0(arg0, var_r31);
}
