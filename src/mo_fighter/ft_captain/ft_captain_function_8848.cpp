#pragma force_active on
extern "C" {
extern signed char lbl_100_bss_180;
extern char lbl_100_bss_184[4];
extern char lbl_100_bss_174[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_100_8848() {
    if (lbl_100_bss_180 == 0) {
        fn_27_197E44(lbl_100_bss_184);
        __register_global_object(lbl_100_bss_184, (void*)fn_27_197E54, lbl_100_bss_174);
        lbl_100_bss_180 = 1;
    }
    return lbl_100_bss_184;
}
