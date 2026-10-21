#include <types.h>
#pragma force_active on

extern "C" void fn_111_D20C(void* object);
extern "C" void* fn_111_D184(void* object, s16 deleting);
extern "C" void __register_global_object(void* object, void* (*destructor)(void*, s16), void* handle);
extern "C" u8 lbl_111_bss_1A4[];
extern "C" u8 lbl_111_bss_198[];

extern "C" void fn_111_D1C4() {
    fn_111_D20C(lbl_111_bss_1A4);
    __register_global_object(lbl_111_bss_1A4, fn_111_D184, lbl_111_bss_198);
}

__declspec(section ".ctors") extern void* const fn_111_D1C4_ctor = (void*)fn_111_D1C4;
