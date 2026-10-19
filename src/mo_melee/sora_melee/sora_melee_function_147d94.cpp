#include <types.h>
#pragma force_active on

extern u8 lbl_27_bss_3210[];

extern "C" {
u32 fn_27_147D94(u32 unused, s32 id) {
    switch (id) {
    case 2:
        return *(u32*)(*(u32*)(lbl_27_bss_3210 + 0x18) + 0x7c);
    case 5:
        return *(u32*)(*(u32*)(lbl_27_bss_3210 + 0x3c) + 0x100);
    default:
        return 0;
    }
}
}
