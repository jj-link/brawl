#include <types.h>
#pragma force_active on

extern "C" {
    extern s8 lbl_27_bss_1550;
    extern u8 lbl_27_bss_1554[0x8C];
    extern u8 lbl_27_bss_F98[0xC];
    void fn_27_59FD4(void* p);
    void* fn_27_5A09C(void* ptr, int count);
    int __register_global_object(void* obj, void* dtor, void* handle);
}

extern "C" void* fn_27_858E0() {
    if (!lbl_27_bss_1550) {
        fn_27_59FD4(lbl_27_bss_1554);
        __register_global_object(lbl_27_bss_1554, (void*)fn_27_5A09C, lbl_27_bss_F98);
        lbl_27_bss_1550 = 1;
    }
    return lbl_27_bss_1554;
}
