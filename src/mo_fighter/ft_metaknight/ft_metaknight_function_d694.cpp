#include <types.h>
#pragma force_active on

extern "C" void fn_111_D6DC(u32* object);
extern "C" void* fn_111_D654(void* object, s16 deleting);
extern "C" void __register_global_object(void* object, void* (*destructor)(void*, s16), void* handle);
extern "C" u32 lbl_111_bss_1B4;
extern "C" u32 lbl_111_bss_1A8[3];

extern "C" void fn_111_D694() {
    fn_111_D6DC(&lbl_111_bss_1B4);
    __register_global_object(&lbl_111_bss_1B4, fn_111_D654, lbl_111_bss_1A8);
}

__declspec(section ".ctors") extern void* const fn_111_D694_ctor = (void*)fn_111_D694;
