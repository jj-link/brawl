#include <types.h>
#pragma force_active on

extern "C" {
extern u32 lbl_103_bss_1D4;
extern u32 lbl_103_bss_1C8;

void fn_103_FE00(u32* info);
void* fn_103_F4B4(void* object, s32 deleteFlag);
void __register_global_object(void* object, void* destructor, void* guard);

void fn_103_FDB8(void) {
    fn_103_FE00(&lbl_103_bss_1D4);
    __register_global_object(&lbl_103_bss_1D4,
                             reinterpret_cast<void*>(fn_103_F4B4),
                             &lbl_103_bss_1C8);
}
}

__declspec(section ".ctors") extern void* const fn_103_FDB8_ctor = (void*)fn_103_FDB8;
