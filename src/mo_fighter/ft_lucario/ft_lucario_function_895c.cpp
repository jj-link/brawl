#pragma force_active on
extern "C" void fn_27_197E44(void*);
extern "C" void fn_27_197E54(void*, short);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" signed char lbl_118_bss_234;
extern "C" unsigned char lbl_118_bss_238[];
extern "C" unsigned char lbl_118_bss_21C[];

extern "C" void* fn_118_895C() {
    if (lbl_118_bss_234 != 0) {
    } else {
        fn_27_197E44(lbl_118_bss_238);
        __register_global_object(lbl_118_bss_238, (void*)fn_27_197E54, lbl_118_bss_21C);
        lbl_118_bss_234 = 1;
    }
    return lbl_118_bss_238;
}
