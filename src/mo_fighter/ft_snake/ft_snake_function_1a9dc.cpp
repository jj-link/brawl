#include <stddef.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_122_bss_2CC[];
extern unsigned char lbl_122_bss_2C0[];
void fn_122_1AA24(void* p);
void* fn_122_1A99C(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_122_1A9DC(void) {
    fn_122_1AA24(lbl_122_bss_2CC);
    __register_global_object(lbl_122_bss_2CC, (void*)fn_122_1A99C, lbl_122_bss_2C0);
}

__declspec(section ".ctors") extern void* const fn_122_1A9DC_ctor = (void*)fn_122_1A9DC;
