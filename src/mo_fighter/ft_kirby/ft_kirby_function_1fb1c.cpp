#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_FB0;
extern int lbl_96_bss_FB4;
extern char lbl_96_bss_E14[12];
void fn_27_2DE758(void* p);
void fn_27_2DE768(void* p, int n);
void __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_1FB1C() {
    if (!lbl_96_bss_FB0) {
        fn_27_2DE758(&lbl_96_bss_FB4);
        __register_global_object(&lbl_96_bss_FB4, (void*)fn_27_2DE768, lbl_96_bss_E14);
        lbl_96_bss_FB0 = 1;
    }
    return &lbl_96_bss_FB4;
}
