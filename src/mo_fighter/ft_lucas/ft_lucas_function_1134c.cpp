#include <types.h>
#pragma force_active on

extern "C" {
extern u32 lbl_114_bss_20C;
extern u8 lbl_114_bss_200[12];
void fn_114_11394(void* ptr);
void* fn_114_1130C(void* object, s16 flag);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_114_1134C() {
    fn_114_11394(&lbl_114_bss_20C);
    __register_global_object(&lbl_114_bss_20C, (void*)fn_114_1130C, lbl_114_bss_200);
}
}

__declspec(section ".ctors") extern void* const fn_114_1134C_ctor = (void*)fn_114_1134C;
