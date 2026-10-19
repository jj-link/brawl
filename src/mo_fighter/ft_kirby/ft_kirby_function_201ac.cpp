#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1028;
extern char lbl_96_bss_102C[4];
extern char lbl_96_bss_EC8[12];
void fn_27_35A09C(void* p);
void* fn_27_35A0AC(void* p, int size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_201AC() {
    if (lbl_96_bss_1028 == 0) {
        fn_27_35A09C(lbl_96_bss_102C);
        __register_global_object(lbl_96_bss_102C, (void*)fn_27_35A0AC, lbl_96_bss_EC8);
        lbl_96_bss_1028 = 1;
    }
    return lbl_96_bss_102C;
}
