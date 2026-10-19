#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_10A8;
extern int lbl_96_bss_10AC;
extern int lbl_96_bss_F88[3];
void fn_27_3BAEF0(void* p);
void* fn_27_3BAF00(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_208AC() {
    if (lbl_96_bss_10A8 == 0) {
        fn_27_3BAEF0(&lbl_96_bss_10AC);
        __register_global_object(&lbl_96_bss_10AC, (void*)fn_27_3BAF00, lbl_96_bss_F88);
        lbl_96_bss_10A8 = 1;
    }
    return &lbl_96_bss_10AC;
}
