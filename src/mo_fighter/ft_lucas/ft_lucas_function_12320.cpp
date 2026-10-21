#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_114_bss_21C;
extern void* lbl_114_bss_210[3];

void fn_114_12368(void** obj);
void* fn_114_122E0(void* object, s16 flags);
void* __register_global_object(void* object, void* (*destructor)(void*, s16), void* chain);

void fn_114_12320(void) {
    fn_114_12368(&lbl_114_bss_21C);
    __register_global_object(&lbl_114_bss_21C, fn_114_122E0, lbl_114_bss_210);
}
}

__declspec(section ".ctors") extern void* const fn_114_12320_ctor = (void*)fn_114_12320;
