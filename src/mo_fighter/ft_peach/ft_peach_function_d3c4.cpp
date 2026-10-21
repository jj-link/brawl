#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_D40C(u32* info);
void* fn_103_D384(void* object, s32 deleteFlag);
void __register_global_object(void* object, void* (*destructor)(void*, s32), void* handle);
extern u32 lbl_103_bss_1C4;
extern u8 lbl_103_bss_1B8[];

void fn_103_D3C4(void) {
    fn_103_D40C(&lbl_103_bss_1C4);
    __register_global_object(&lbl_103_bss_1C4, fn_103_D384, lbl_103_bss_1B8);
}
}

__declspec(section ".ctors") extern void* const fn_103_D3C4_ctor = (void*)fn_103_D3C4;
