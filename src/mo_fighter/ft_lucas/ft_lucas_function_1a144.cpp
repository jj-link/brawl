#include <types.h>
#pragma force_active on

extern "C" {
void fn_114_1A18C(void** vtable);
void* fn_114_1A104(void* object, s16 size);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_114_bss_3D4;
extern u8 lbl_114_bss_3C8[12];

void fn_114_1A144() {
    fn_114_1A18C(&lbl_114_bss_3D4);
    __register_global_object(&lbl_114_bss_3D4, (void*)fn_114_1A104, lbl_114_bss_3C8);
}
}

__declspec(section ".ctors") extern void* const fn_114_1A144_ctor = (void*)fn_114_1A144;
