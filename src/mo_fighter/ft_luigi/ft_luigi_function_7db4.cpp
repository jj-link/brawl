#pragma force_active on
extern "C" {
extern signed char lbl_99_bss_1AC;
extern unsigned char lbl_99_bss_1B0[];
extern unsigned char lbl_99_bss_194[];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_99_7DB4() {
    if (lbl_99_bss_1AC == 0) {
        fn_27_197E44(lbl_99_bss_1B0);
        __register_global_object(lbl_99_bss_1B0,
            reinterpret_cast<void*>(fn_27_197E54), lbl_99_bss_194);
        lbl_99_bss_1AC = 1;
    }
    return lbl_99_bss_1B0;
}
