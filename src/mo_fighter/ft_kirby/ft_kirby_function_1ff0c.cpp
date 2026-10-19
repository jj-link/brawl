#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_FF8;
extern int lbl_96_bss_FFC;
extern char lbl_96_bss_E80[12];
void fn_27_33C514(void* self);
void* fn_27_33C524(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_1FF0C() {
    if (lbl_96_bss_FF8 == 0) {
        fn_27_33C514(&lbl_96_bss_FFC);
        __register_global_object(&lbl_96_bss_FFC, (void*)fn_27_33C524, lbl_96_bss_E80);
        lbl_96_bss_FF8 = 1;
    }
    return &lbl_96_bss_FFC;
}
