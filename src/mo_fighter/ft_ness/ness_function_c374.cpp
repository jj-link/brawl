#pragma force_active on
extern "C" {
void fn_27_3295D8(void* p);
void* fn_27_3295E8(void* p, int flags);
void __register_global_object(void*, void*, void*);
extern signed char lbl_101_bss_1C4;
extern unsigned char lbl_101_bss_1C8[8];
extern unsigned char lbl_101_bss_1B0[12];
}

extern "C" void* fn_101_C374() {
    if (lbl_101_bss_1C4 == 0) {
        fn_27_3295D8(lbl_101_bss_1C8);
        __register_global_object(lbl_101_bss_1C8,
            reinterpret_cast<void*>(fn_27_3295E8), lbl_101_bss_1B0);
        lbl_101_bss_1C4 = 1;
    }
    return lbl_101_bss_1C8;
}
