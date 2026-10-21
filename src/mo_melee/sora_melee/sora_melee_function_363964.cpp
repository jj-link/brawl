#include <types.h>
#pragma force_active on

extern "C" {
    void fn_27_1E82E8(void* obj, int arg);
    void fn_27_1E847C(void* obj, int arg, void* obj2);
    void fn_27_3639E0(void* obj);
    void __register_global_object(void* obj, void (*dtor)(void*), void* dso);
    extern void* lbl_27_bss_8220[4];
    extern unsigned char lbl_27_bss_8214[12];
    extern unsigned char lbl_27_data_90ED8[24];

    void fn_27_363964() {
        fn_27_1E82E8(lbl_27_bss_8220, 0);
        lbl_27_bss_8220[2] = lbl_27_data_90ED8;
        lbl_27_bss_8220[0] = lbl_27_data_90ED8 + 8;
        fn_27_1E847C(lbl_27_bss_8220, 0x4d, lbl_27_bss_8220);
        __register_global_object(lbl_27_bss_8220, fn_27_3639E0, lbl_27_bss_8214);
    }
}

__declspec(section ".ctors") extern void* const fn_27_363964_ctor = (void*)fn_27_363964;
