#pragma force_active on
extern "C" {
extern signed char lbl_110_bss_174;
extern char lbl_110_bss_178[4];
extern char lbl_110_bss_15C[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_110_8A88() {
    if (lbl_110_bss_174 == 0) {
        fn_27_197E44(lbl_110_bss_178);
        __register_global_object(lbl_110_bss_178, (void*)fn_27_197E54, lbl_110_bss_15C);
        lbl_110_bss_174 = 1;
    }
    return lbl_110_bss_178;
}
