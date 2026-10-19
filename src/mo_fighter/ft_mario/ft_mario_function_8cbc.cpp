#pragma force_active on
extern "C" {
extern signed char lbl_91_bss_1C8;
extern unsigned char lbl_91_bss_1CC[];
extern unsigned char lbl_91_bss_1B0[];
void fn_27_197E44(void*);
void* fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
void* fn_91_8CBC() {
    if (lbl_91_bss_1C8 == 0) {
        fn_27_197E44(lbl_91_bss_1CC);
        __register_global_object(lbl_91_bss_1CC, reinterpret_cast<void*>(fn_27_197E54), lbl_91_bss_1B0);
        lbl_91_bss_1C8 = 1;
    }
    return lbl_91_bss_1CC;
}
}
