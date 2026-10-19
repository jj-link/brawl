#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_bss_3210[];

void* fn_27_148BD0(void* p1, s32 p2) {
    switch (p2) {
    case 0x18: {
        u8* a = *(u8**)(lbl_27_bss_3210 + 0x120);
        return *(void**)(a + 0x90);
    }
    case 5: {
        u8* b = *(u8**)(lbl_27_bss_3210 + 0x3c);
        return *(void**)(b + 0x168);
    }
    default:
        return 0;
    }
}
}
