#pragma force_active on
extern "C" {
void fn_27_197E44(void*);
void* fn_27_197E54(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);

extern signed char lbl_120_bss_298;
extern int lbl_120_bss_29C;
extern char lbl_120_bss_278[0xC];

void* fn_120_7A20() {
    if (lbl_120_bss_298 == 0) {
        fn_27_197E44(&lbl_120_bss_29C);
        __register_global_object(&lbl_120_bss_29C, (void*)fn_27_197E54, lbl_120_bss_278);
        lbl_120_bss_298 = 1;
    }
    return &lbl_120_bss_29C;
}
}
