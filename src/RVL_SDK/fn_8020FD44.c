#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_8020F248(u8 *, s32);

u8 fn_8020FD44(void) {
    u8 sp8;

    if (fn_8020F248(&sp8, 0x11) == 0) {
        sp8 = 1;
    } else if (sp8 != 0 && sp8 != 1 && sp8 != 2) {
        sp8 = 1;
    }
    return sp8;
}