#include <types.h>
#pragma force_active on

extern "C" {
void fn_114_20E94(void** self);
void* fn_114_20E0C(void* p, s16 n);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_114_bss_50C;
extern u8 lbl_114_bss_500[];
}

extern "C" void fn_114_20E4C() {
    fn_114_20E94(&lbl_114_bss_50C);
    __register_global_object(&lbl_114_bss_50C, (void*)fn_114_20E0C, lbl_114_bss_500);
}

__declspec(section ".ctors") extern void* const fn_114_20E4C_ctor = (void*)fn_114_20E4C;
