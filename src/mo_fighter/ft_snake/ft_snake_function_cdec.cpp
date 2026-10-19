#pragma force_active on
extern "C" {
extern signed char lbl_122_bss_15C;
extern int lbl_122_bss_160;
extern int lbl_122_bss_144[3];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void* fn_122_CDEC() {
    if (!lbl_122_bss_15C) {
        fn_27_197E44(&lbl_122_bss_160);
        __register_global_object(&lbl_122_bss_160, (void*)fn_27_197E54, lbl_122_bss_144);
        lbl_122_bss_15C = 1;
    }
    return &lbl_122_bss_160;
}
