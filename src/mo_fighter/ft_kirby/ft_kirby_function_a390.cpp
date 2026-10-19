#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_BF4;
extern unsigned char lbl_96_bss_BF8[];
extern unsigned char lbl_96_bss_BE0[];
void fn_27_197E44(void*);
void fn_96_1DDB0(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_96_A390() {
    if (lbl_96_bss_BF4 == 0) {
        fn_27_197E44(lbl_96_bss_BF8);
        __register_global_object(lbl_96_bss_BF8,
            reinterpret_cast<void*>(fn_96_1DDB0), lbl_96_bss_BE0);
        lbl_96_bss_BF4 = 1;
    }
    return lbl_96_bss_BF8;
}
