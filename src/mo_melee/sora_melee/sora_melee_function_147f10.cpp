#include <types.h>
#pragma force_active on

extern u8 lbl_27_bss_3210[];

extern "C" {
u32 fn_27_147F10(u32 unused, s32 kind) {
    switch (kind) {
    case 2: {
        u8* p = *(u8**)(lbl_27_bss_3210 + 0x18);
        return *(u32*)(p + 0xBC);
    }
    default:
        return 0;
    }
}
}
