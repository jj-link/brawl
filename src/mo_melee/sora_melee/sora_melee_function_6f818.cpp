#include <types.h>
#pragma force_active on

extern "C" {
extern const u8 lbl_27_data_7FF8[0xC];
extern u8 lbl_27_bss_110[0x10];
extern u8 lbl_27_bss_100[0x10];
void* fn_27_6F340(void* p, s32 n);
void __register_global_object(void* obj, void* dtor, void* handle);

void fn_27_6F818() {
    u32 d = (u32)lbl_27_data_7FF8;
    ((u32*)lbl_27_bss_110)[3] = d;
    ((u32*)lbl_27_bss_110)[1] = 0;
    *(u32*)lbl_27_bss_110 = 0;
    ((u32*)lbl_27_bss_110)[2] = 0;
    __register_global_object(lbl_27_bss_110, (void*)fn_27_6F340, lbl_27_bss_100);
}
}

__declspec(section ".ctors") extern void* const fn_27_6F818_ctor = (void*)fn_27_6F818;
