#pragma force_active on
extern "C" {
void fn_27_3A2328(void* p);
void fn_27_3A2338(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
extern signed char lbl_120_bss_2A0;
extern int lbl_120_bss_2A4;
extern char lbl_120_bss_284[12];

int* fn_120_7F08(void) {
    if (!lbl_120_bss_2A0) {
        fn_27_3A2328(&lbl_120_bss_2A4);
        __register_global_object(&lbl_120_bss_2A4, (void*)fn_27_3A2338, lbl_120_bss_284);
        lbl_120_bss_2A0 = 1;
    }
    return &lbl_120_bss_2A4;
}
}
