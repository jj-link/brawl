#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_bss_3210[];

extern "C" u32 fn_27_1497CC(u32 unused, s32 kind) {
    switch (kind) {
    case 0x30: {
        u8* p = *(u8**)(lbl_27_bss_3210 + 0x240);
        return *(u32*)(p + 0x90);
    }
    default:
        return 0;
    }
}
