#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1018;
extern int lbl_96_bss_101C;
extern char lbl_96_bss_EB0[12];
void fn_27_3521BC(void* p);
void fn_27_3521CC(void* p, int count);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_200CC() {
    if (!lbl_96_bss_1018) {
        fn_27_3521BC(&lbl_96_bss_101C);
        __register_global_object(&lbl_96_bss_101C, (void*)fn_27_3521CC, lbl_96_bss_EB0);
        lbl_96_bss_1018 = 1;
    }
    return &lbl_96_bss_101C;
}
}
