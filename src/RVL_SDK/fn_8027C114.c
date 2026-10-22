#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_801F6920(void *, s32, s32);

s32 fn_8027C114(s32 *arg0, s32 arg1, s32 arg2) {
    s32 var_r31;

    var_r31 = 0;
    switch (arg2) {
    case 0:
        var_r31 = arg1;
        break;
    case 1:
        var_r31 = arg0[0x11] + arg1;
        break;
    case 2:
        var_r31 = arg0[0x12] + arg1;
        break;
    }
    if (fn_801F6920((u8 *)arg0 + 8, var_r31, 2) == 0) {
        arg0[0x11] = var_r31;
        return 0;
    }
    return 1;
}
