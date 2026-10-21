#include <types.h>
#pragma force_active on

extern "C" {
extern u32 lbl_111_bss_184;
extern u32 lbl_111_bss_178[];
void fn_111_C9A8(void*);
void* fn_111_C91C(void*, s16);
void __register_global_object(void*, void* (*)(void*, s16), void*);

void fn_111_C960() {
    fn_111_C9A8(&lbl_111_bss_184);
    __register_global_object(&lbl_111_bss_184, fn_111_C91C, lbl_111_bss_178);
}
}

__declspec(section ".ctors") extern void* const fn_111_C960_ctor = (void*)fn_111_C960;
