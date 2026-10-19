#pragma force_active on
extern "C" {
extern signed char lbl_113_bss_D0;
extern char lbl_113_bss_D4[4];
extern char lbl_113_bss_C4[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_113_9E30() {
    if (lbl_113_bss_D0 == 0) {
        fn_27_197E44(lbl_113_bss_D4);
        __register_global_object(lbl_113_bss_D4, (void*)fn_27_197E54, lbl_113_bss_C4);
        lbl_113_bss_D0 = 1;
    }
    return lbl_113_bss_D4;
}
