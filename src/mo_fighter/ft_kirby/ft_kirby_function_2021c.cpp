#pragma force_active on
extern "C" {
extern unsigned char lbl_96_bss_1030;
extern unsigned char lbl_96_bss_1034[];
extern unsigned char lbl_96_bss_ED4[];
void fn_27_35A264(void*);
void* fn_27_35A274(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" unsigned char* fn_96_2021C() {
    if ((signed char)lbl_96_bss_1030 == 0) {
        fn_27_35A264(lbl_96_bss_1034);
        __register_global_object(lbl_96_bss_1034, (void*)fn_27_35A274, lbl_96_bss_ED4);
        lbl_96_bss_1030 = 1;
    }
    return lbl_96_bss_1034;
}
