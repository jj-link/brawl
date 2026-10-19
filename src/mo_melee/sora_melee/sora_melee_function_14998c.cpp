#include <types.h>
#pragma force_active on

extern u8 lbl_27_bss_3210[];

extern "C" u32 fn_27_14998C(u32 p1, s32 p2) {
    switch (p2) {
    case 0x29:
        return *(u32*)(*(u32*)(lbl_27_bss_3210 + 0x1ec) + 0x7c);
    case 5:
        return *(u32*)(*(u32*)(lbl_27_bss_3210 + 0x3c) + 0x104);
    default:
        return 0;
    }
}
