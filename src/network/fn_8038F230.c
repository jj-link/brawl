#pragma force_active on
typedef int s32;

extern s32 fn_8038E86C(s32 *, s32 *, s32 *);
extern s32 fn_8038EFB8(s32, s32, s32);
extern s32 fn_8038F2B0(s32, s32);

s32 NETGetStartupErrorCode(s32 arg0) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 var_r31;
    s32 var_r30;

    var_r30 = arg0;
    var_r31 = 0x63;
    if (fn_8038E86C(&sp8, &spC, &sp10) >= 0) {
        var_r31 = fn_8038EFB8(sp8, spC, sp10);
    }
    if (var_r31 < 0) {
        var_r30 = 0x80000000;
        var_r31 = 0x63;
    }
    return fn_8038F2B0(var_r30, var_r31) - var_r31;
}
