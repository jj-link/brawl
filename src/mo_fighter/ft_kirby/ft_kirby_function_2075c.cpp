#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1090;
extern char lbl_96_bss_1094[];
extern char lbl_96_bss_F64[];
void fn_27_3BE670(void* p);
void fn_27_3BE680(void* p, int shouldDelete);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_96_2075C() {
    if (!lbl_96_bss_1090) {
        fn_27_3BE670(lbl_96_bss_1094);
        __register_global_object(lbl_96_bss_1094, (void*)fn_27_3BE680, lbl_96_bss_F64);
        lbl_96_bss_1090 = 1;
    }
    return lbl_96_bss_1094;
}
