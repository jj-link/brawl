#include <types.h>
#pragma force_active on

extern s32 lbl_27_bss_3210[];

extern "C" {
s32 fn_27_1484BC(const void* self, s32 kind) {
    switch (kind) {
        case 6:
            return ((s32*)lbl_27_bss_3210[0x12])[0x2a];
        case 0x13:
            return ((s32*)lbl_27_bss_3210[0x39])[0x28];
        case 0x2c:
            return ((s32*)lbl_27_bss_3210[0x84])[0x2a];
        default:
            return 0;
    }
}
}
