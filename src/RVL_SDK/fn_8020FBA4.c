#pragma force_active on
typedef signed char s8;
typedef int s32;
s32 fn_8020F31C(s8 *, s32);
s8 fn_8020FBA4(void) {
    s8 sp8;
    if (fn_8020F31C(&sp8, 5) == 0) {
        sp8 = 0;
    } else if ((s8) sp8 < -0x20) {
        sp8 = -0x20;
    } else if ((s8) sp8 > 0x20) {
        sp8 = 0x20;
    }
    return (s8)(sp8 & ~1);
}