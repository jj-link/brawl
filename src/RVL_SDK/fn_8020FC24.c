#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
s32 fn_8020F248(u8 *, s32);
s8 fn_80210284(void);
u8 fn_8020FC24(void) {
    u8 sp8;
    if (fn_8020F248(&sp8, 0xB) == 0) {
        if (fn_80210284() == 0) {
            sp8 = 0;
        } else {
            sp8 = 1;
        }
    } else if (sp8 > 9U) {
        sp8 = 1;
    }
    return sp8;
}