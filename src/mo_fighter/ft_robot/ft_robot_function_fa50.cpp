#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_120_FA98(void* obj);
void* fn_120_FA10(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_120_bss_2E4[4];
extern char lbl_120_bss_2D8[12];
}

extern "C" void fn_120_FA50() {
    fn_120_FA98(lbl_120_bss_2E4);
    __register_global_object(lbl_120_bss_2E4, (void*)fn_120_FA10, lbl_120_bss_2D8);
}

__declspec(section ".ctors") extern void* const fn_120_FA50_ctor = (void*)fn_120_FA50;
