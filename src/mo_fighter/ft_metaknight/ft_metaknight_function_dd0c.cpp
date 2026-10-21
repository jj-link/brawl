#include <types.h>
#pragma force_active on

extern "C" u8 lbl_111_bss_1C4[];
extern "C" u8 lbl_111_bss_1B8[];
extern "C" void fn_111_DD54(void*);
extern "C" void fn_111_DCCC(void*, s16);
extern "C" void __register_global_object(void*, void*, void*);

extern "C" void fn_111_DD0C() {
    fn_111_DD54(lbl_111_bss_1C4);
    __register_global_object(lbl_111_bss_1C4, (void*)fn_111_DCCC, lbl_111_bss_1B8);
}

__declspec(section ".ctors") extern void* const fn_111_DD0C_ctor = (void*)fn_111_DD0C;
