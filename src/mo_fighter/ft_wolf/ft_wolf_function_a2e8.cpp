#pragma force_active on
extern "C" {
extern signed char lbl_125_bss_1C4;
extern char lbl_125_bss_1C8[8];
extern char lbl_125_bss_1B0[12];
void fn_27_3C7CC4(void* p);
void* fn_27_3C7CD4(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_125_A2E8() {
    if (lbl_125_bss_1C4 == 0) {
        fn_27_3C7CC4(lbl_125_bss_1C8);
        __register_global_object(lbl_125_bss_1C8, (void*)fn_27_3C7CD4, lbl_125_bss_1B0);
        lbl_125_bss_1C4 = 1;
    }
    return lbl_125_bss_1C8;
}
}
