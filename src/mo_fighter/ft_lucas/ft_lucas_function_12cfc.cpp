#include <types.h>
#pragma force_active on

extern "C" void fn_114_12D44(void** out);
extern "C" void* fn_114_12CBC(void* p, s16 flag);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void* lbl_114_bss_25C;
extern "C" u32 lbl_114_bss_250[3];

extern "C" void fn_114_12CFC() {
    fn_114_12D44(&lbl_114_bss_25C);
    __register_global_object(&lbl_114_bss_25C, (void*)fn_114_12CBC, lbl_114_bss_250);
}

__declspec(section ".ctors") extern void* const fn_114_12CFC_ctor = (void*)fn_114_12CFC;
