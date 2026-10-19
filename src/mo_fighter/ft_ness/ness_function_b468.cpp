#pragma force_active on
extern "C" {
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
extern signed char lbl_101_bss_1BC;
extern unsigned char lbl_101_bss_1C0[];
extern unsigned char lbl_101_bss_1A4[];
}

extern "C" void* fn_101_B468() {
    if (lbl_101_bss_1BC == 0) {
        fn_27_197E44(lbl_101_bss_1C0);
        __register_global_object(lbl_101_bss_1C0,
            reinterpret_cast<void*>(fn_27_197E54), lbl_101_bss_1A4);
        lbl_101_bss_1BC = 1;
    }
    return lbl_101_bss_1C0;
}
