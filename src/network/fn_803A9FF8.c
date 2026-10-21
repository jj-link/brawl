#pragma force_active on
typedef unsigned short u16;
typedef int s32;

s32 fn_803A9FF8(u16 *arg0) {
    u16 *var_r4;
    s32 diff;

    var_r4 = arg0;
    while (*var_r4 != 0) {
        var_r4 += 1;
    }
    diff = (char *)var_r4 - (char *)arg0;
    return diff >> 1;
}
