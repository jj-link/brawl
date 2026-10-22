#pragma force_active on
typedef unsigned int u32;
typedef int s32;

s32 fn_803D7B04(void *, void *);
s32 fn_803D7FD0(s32, u32);

s32 fn_803D8D2C(u32 *arg0, u32 arg1) {
    s32 var_r31 = 0;
    s32 temp_r3;

    if (arg0[0] & 8) {
        temp_r3 = fn_803D7B04((void *)arg0[1], arg0);
        if (temp_r3 != 0) {
            return temp_r3;
        }
        temp_r3 = fn_803D7FD0(arg0[1], arg1);
        if (temp_r3 != 0) {
            var_r31 = temp_r3;
        }
    } else {
        var_r31 = 0xE;
    }
    if (var_r31 == 0 || arg1 == 1) {
        arg0[0] &= 0xFFFFFFFDU;
        arg0[0] &= 0xFFFFFFF7U;
    }
    return var_r31;
}
