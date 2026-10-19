#pragma force_active on
extern "C" {
extern signed char lbl_95_bss_324;
extern char lbl_95_bss_328[4];
extern char lbl_95_bss_30C[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_95_9F30() {
    if (lbl_95_bss_324 == 0) {
        fn_27_197E44(lbl_95_bss_328);
        __register_global_object(lbl_95_bss_328, (void*)fn_27_197E54, lbl_95_bss_30C);
        lbl_95_bss_324 = 1;
    }
    return lbl_95_bss_328;
}
