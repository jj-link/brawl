#include <so/so_null.h>
#pragma force_active on

extern "C" {
extern soNullable __vt__10soNullable;
extern unsigned char lbl_27_data_7A238[];
extern unsigned char lbl_27_bss_71A0[];
extern unsigned char lbl_27_bss_7190[];
extern void* fn_27_2BDF4C(void*, int);
extern void __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_2BDFA8() {
    *reinterpret_cast<void**>(lbl_27_bss_71A0) = &__vt__10soNullable;
    lbl_27_bss_71A0[4] = 0;
    *reinterpret_cast<void**>(lbl_27_bss_71A0) = lbl_27_data_7A238;
    __register_global_object(lbl_27_bss_71A0, reinterpret_cast<void*>(fn_27_2BDF4C), lbl_27_bss_7190);
}

__declspec(section ".ctors") extern void* const fn_27_2BDFA8_ctor = (void*)fn_27_2BDFA8;
