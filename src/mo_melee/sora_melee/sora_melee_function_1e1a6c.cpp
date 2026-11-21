#pragma force_active on
extern "C" {
extern char lbl_27_data_12AF8[];
extern signed char lbl_27_bss_5228;
extern void* lbl_27_bss_522C;
extern char lbl_27_bss_51DC[];
void fn_27_82B94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_10158(void*, void*, int, void*, int);
}

extern "C" void* fn_27_1E1A6C(void* a, void* b, int c) {
    if (lbl_27_bss_5228 == 0) {
        lbl_27_bss_522C = 0;
        lbl_27_bss_522C = lbl_27_data_12AF8;
        __register_global_object(&lbl_27_bss_522C, (void*)fn_27_82B94, lbl_27_bss_51DC);
        lbl_27_bss_5228 = 1;
    }
    fn_27_10158((char*)a + 4, b, c, &lbl_27_bss_522C, 1);
    return (void*)a;
}
