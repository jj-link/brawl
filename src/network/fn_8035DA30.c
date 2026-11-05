#include <types.h>
#pragma force_active on
extern u32 lbl_8059F598;
s32 fn_8035DA30(s32 arg0, s32 arg1) {
    u32 value, product;
    u16 high;
    u32 range;
    range = arg1 - arg0;
    if (range != 0) {
        value = lbl_8059F598;
        high = value >> 16;
        value &= 0xffff;
        product = high * 0x41A7;
        value *= 0x41A7;
        value += (product << 16) & 0x7FFF0000;
        if (value > 0x7FFFFFFF) {
            value &= 0x7FFFFFFF;
            value++;
        }
        value += product >> 15;
        if (value > 0x7FFFFFFF) {
            value &= 0x7FFFFFFF;
            value++;
        }
        lbl_8059F598 = value;
        product = value % range;
        return product + arg0;
    }
    return arg0;
}