#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_803A9864(u8 *arg0) {
    u8 *var_r4;

    var_r4 = arg0;
    goto check;
loop_2:
    var_r4 += 1;
check:
    if ((signed char)*var_r4 != 0) {
        goto loop_2;
    }
    return var_r4 - arg0;
}
