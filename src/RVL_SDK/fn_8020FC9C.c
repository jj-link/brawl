#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_8020F248(u8 *, int);

u8 fn_8020FC9C(void) {
    u8 sp8;

    if (fn_8020F248(&sp8, 0xE) == 0) {
        sp8 = 0;
    } else if (sp8 != 1) {
        sp8 = 0;
    }
    return sp8;
}
