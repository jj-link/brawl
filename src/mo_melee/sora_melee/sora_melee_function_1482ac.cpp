#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_bss_3210[];
}

extern "C" void* fn_27_1482AC() {
    u8* p = *(u8**)(lbl_27_bss_3210 + 0x174);
    return *(void**)(p + 0x94);
}
