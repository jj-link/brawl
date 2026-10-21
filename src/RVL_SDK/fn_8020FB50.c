#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_8020F248(u8 *, s32);

u8 fn_8020FB50(void) {
    u8 sp8;

    if (fn_8020F248(&sp8, 1) == 0) {
        sp8 = 0;
    } else if (sp8 != 1) {
        sp8 = 0;
    }
    return sp8;
}
