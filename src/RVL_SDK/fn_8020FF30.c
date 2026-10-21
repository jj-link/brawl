#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_8020F248(u8 *p, s32 n);

u8 fn_8020FF30(void)
{
    u8 sp8;

    if (fn_8020F248(&sp8, 0x1F) == 0) {
        sp8 = 0x59;
    } else if (sp8 > 0x7F) {
        sp8 = 0x7F;
    }
    return sp8;
}
