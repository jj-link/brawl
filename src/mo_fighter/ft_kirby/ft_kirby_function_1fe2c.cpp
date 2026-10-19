#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_FE8;
extern int lbl_96_bss_FEC;
extern char lbl_96_bss_E68[];
void fn_27_32E298(void* p);
void fn_27_32E2A8(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* dso);
}

extern "C" int* fn_96_1FE2C() {
    if (lbl_96_bss_FE8 == 0) {
        fn_27_32E298(&lbl_96_bss_FEC);
        __register_global_object(&lbl_96_bss_FEC, (void*)fn_27_32E2A8, lbl_96_bss_E68);
        lbl_96_bss_FE8 = 1;
    }
    return &lbl_96_bss_FEC;
}
