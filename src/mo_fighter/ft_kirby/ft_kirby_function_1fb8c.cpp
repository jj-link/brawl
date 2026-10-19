#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_FB8;
extern char lbl_96_bss_FBC[4];
extern char lbl_96_bss_E20[12];
void fn_27_2FAFD0(void* p);
void* fn_27_2FAFE0(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_1FB8C() {
    if (lbl_96_bss_FB8 == 0) {
        fn_27_2FAFD0(lbl_96_bss_FBC);
        __register_global_object(lbl_96_bss_FBC, (void*)fn_27_2FAFE0, lbl_96_bss_E20);
        lbl_96_bss_FB8 = 1;
    }
    return lbl_96_bss_FBC;
}
