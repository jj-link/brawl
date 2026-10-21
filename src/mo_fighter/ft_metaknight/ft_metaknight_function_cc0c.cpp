#include <types.h>
#pragma force_active on

extern "C" void* fn_111_CC54(void* info);
extern "C" void* fn_111_CBCC(void* object, s16 deleting);
extern "C" void __register_global_object(void* object, void* (*destructor)(void*, s16), void* handle);
extern "C" u8 lbl_111_bss_194[];
extern "C" u8 lbl_111_bss_188[];

extern "C" void fn_111_CC0C() {
    fn_111_CC54(lbl_111_bss_194);
    __register_global_object(lbl_111_bss_194, fn_111_CBCC, lbl_111_bss_188);
}

__declspec(section ".ctors") extern void* const fn_111_CC0C_ctor = (void*)fn_111_CC0C;
