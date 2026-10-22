#include <types.h>
#pragma force_active on

extern char lbl_80529CF8[];

s32 fn_80237F1C(u32 arg0) {
    char* base;
    s32 var_r5;

    base = lbl_80529CF8;
    var_r5 = 0;
    if (!(*(u8*)(base + 0x14D) != 0 && *(u16*)(base + 0x34) == arg0)) {
        var_r5 = 1;
        if (!(*(u8*)(base + 0x269) != 0 && *(u16*)(base + 0x150) == arg0)) {
            var_r5 = 2;
            if (!(*(u8*)(base + 0x385) != 0 && *(u16*)(base + 0x26C) == arg0)) {
                var_r5 = 3;
                if (!(*(u8*)(base + 0x4A1) != 0 && *(u16*)(base + 0x388) == arg0)) {
                    var_r5 = 4;
                }
            }
        }
    }
    return var_r5;
}
