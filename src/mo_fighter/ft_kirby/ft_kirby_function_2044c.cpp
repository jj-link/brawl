#pragma force_active on
extern "C" {

extern signed char lbl_96_bss_1058;
extern void* lbl_96_bss_105C;
extern void* lbl_96_bss_F10[];
extern void fn_27_368C08(void*);
extern void* fn_27_368C18(void*, int);
extern void* __register_global_object(void*, void*, void*);

void* fn_96_2044C() {
    if (!lbl_96_bss_1058) {
        fn_27_368C08(&lbl_96_bss_105C);
        __register_global_object(&lbl_96_bss_105C, (void*)fn_27_368C18, lbl_96_bss_F10);
        lbl_96_bss_1058 = 1;
    }
    return &lbl_96_bss_105C;
}

}
