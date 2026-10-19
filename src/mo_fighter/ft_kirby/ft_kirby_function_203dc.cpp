#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1050;
extern int lbl_96_bss_1054;
extern unsigned char lbl_96_bss_F04[];
void fn_27_364100(void* p);
void* fn_27_364110(void* p, int count);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_203DC() {
    if (!lbl_96_bss_1050) {
        fn_27_364100(&lbl_96_bss_1054);
        __register_global_object(&lbl_96_bss_1054, (void*)fn_27_364110, lbl_96_bss_F04);
        lbl_96_bss_1050 = 1;
    }
    return &lbl_96_bss_1054;
}
}
