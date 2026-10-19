#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1088;
extern int lbl_96_bss_108C;
extern char lbl_96_bss_F58[12];
void fn_27_3A2328(void* p);
void fn_27_3A2338(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_206EC() {
    if (lbl_96_bss_1088 == 0) {
        fn_27_3A2328(&lbl_96_bss_108C);
        __register_global_object(&lbl_96_bss_108C, (void*)fn_27_3A2338, lbl_96_bss_F58);
        lbl_96_bss_1088 = 1;
    }
    return &lbl_96_bss_108C;
}
