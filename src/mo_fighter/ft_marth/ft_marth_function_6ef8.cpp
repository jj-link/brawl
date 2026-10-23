#pragma force_active on
extern "C" {
extern signed char lbl_106_bss_190;
extern char lbl_106_bss_194[4];
extern char lbl_106_bss_184[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_106_6EF8() {
    if (lbl_106_bss_190 == 0) {
        fn_27_197E44(lbl_106_bss_194);
        __register_global_object(lbl_106_bss_194, (void*)fn_27_197E54, lbl_106_bss_184);
        lbl_106_bss_190 = 1;
    }
    return lbl_106_bss_194;
}
