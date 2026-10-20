#pragma force_active on
extern "C" {
    extern char lbl_27_bss_1C;
    extern char lbl_27_bss_20[8];
    extern char lbl_27_bss_10[12];
    extern char lbl_27_data_310[0x38];
    extern char lbl_27_data_2B8[0x38];
    void __register_global_object(void*, void*, void*);
    void* fn_27_5378(void*, int);

    void* fn_27_52B4() {
        if (!lbl_27_bss_1C) {
            *(void**)(lbl_27_bss_20 + 4) = lbl_27_data_310;
            lbl_27_bss_20[0] = 1;
            *(void**)(lbl_27_bss_20 + 4) = lbl_27_data_2B8;
            __register_global_object(lbl_27_bss_20, fn_27_5378, lbl_27_bss_10);
            lbl_27_bss_1C = 1;
        }
        return lbl_27_bss_20;
    }
}
