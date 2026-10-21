#pragma force_active on

#include <types.h>

extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void fn_114_10A54(void* p);
extern "C" void* fn_114_109C4(void* p, short flag);

extern u8 lbl_114_bss_1DC[4];
extern u8 lbl_114_bss_1D0[12];

extern "C" void fn_114_10A0C() {
    fn_114_10A54(&lbl_114_bss_1DC);
    __register_global_object(&lbl_114_bss_1DC, fn_114_109C4, &lbl_114_bss_1D0);
}

__declspec(section ".ctors") extern void* const fn_114_10A0C_ctor = (void*)fn_114_10A0C;
