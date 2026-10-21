#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void fn_27_326538(void*);
extern "C" void __register_global_object(void*, void*, void*);

extern u8 lbl_27_bss_7C80[0x10];
extern u8 lbl_27_bss_7C74[0xC];
extern u8 lbl_27_data_872C8[0x18];

extern "C" void fn_27_3264BC() {
    fn_27_1E82E8(lbl_27_bss_7C80, 0);
    *(void**)(lbl_27_bss_7C80 + 0x8) = lbl_27_data_872C8;
    *(void**)lbl_27_bss_7C80 = lbl_27_data_872C8 + 0x8;
    fn_27_1E847C(lbl_27_bss_7C80, 9, lbl_27_bss_7C80);
    __register_global_object(lbl_27_bss_7C80, (void*)fn_27_326538, lbl_27_bss_7C74);
}

__declspec(section ".ctors") extern void* const fn_27_3264BC_ctor = (void*)fn_27_3264BC;
