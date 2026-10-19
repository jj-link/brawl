#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_FE0;
extern char lbl_96_bss_FE4[];
extern char lbl_96_bss_E5C[];
void fn_27_3295D8(void* p);
void* fn_27_3295E8(void* p, int flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_1FDBC() {
    if (lbl_96_bss_FE0 == 0) {
        fn_27_3295D8(lbl_96_bss_FE4);
        __register_global_object(lbl_96_bss_FE4, (void*)fn_27_3295E8, lbl_96_bss_E5C);
        lbl_96_bss_FE0 = 1;
    }
    return lbl_96_bss_FE4;
}
