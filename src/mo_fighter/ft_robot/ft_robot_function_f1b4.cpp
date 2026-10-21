#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_120_F1FC(void* p);
void* fn_120_F174(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_120_bss_2D4[4];
extern char lbl_120_bss_2C8[12];
}

extern "C" void fn_120_F1B4(void) {
    fn_120_F1FC(lbl_120_bss_2D4);
    __register_global_object(lbl_120_bss_2D4, (void*)fn_120_F174, lbl_120_bss_2C8);
}

__declspec(section ".ctors") extern void* const fn_120_F1B4_ctor = (void*)fn_120_F1B4;
