#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_5B70[];
extern u8 lbl_27_bss_D0[];
extern u8 lbl_27_bss_C0[];
void* fn_27_57E48(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_27_57E88() {
    *(u8**)lbl_27_bss_D0 = lbl_27_data_5B70;
    *(u32*)(lbl_27_bss_D0 + 0x8) = 0;
    *(u32*)(lbl_27_bss_D0 + 0x10) = 0;
    *(u32*)(lbl_27_bss_D0 + 0xC) = 0;
    *(u32*)(lbl_27_bss_D0 + 0x14) = 0;
    __register_global_object(lbl_27_bss_D0, (void*)fn_27_57E48, lbl_27_bss_C0);
}
}

__declspec(section ".ctors") extern void* const fn_27_57E88_ctor = (void*)fn_27_57E88;
