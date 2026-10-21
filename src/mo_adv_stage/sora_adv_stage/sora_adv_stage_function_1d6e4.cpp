#pragma force_active on

extern "C" {
    extern signed char lbl_40_bss_CA0;
    extern char lbl_40_bss_C88[0xC];
    extern void* fn_40_1D7A8(void*, int);
    extern char lbl_40_data_5108[0x38];
    extern char lbl_40_data_5160[0x38];
    extern void __register_global_object(void*, void*, void*);

    struct ObjCA8 {
        signed char a;
        int b;
    };

    extern ObjCA8 lbl_40_bss_CA8;
}

extern "C" void* fn_40_1D6E4() {
    if (lbl_40_bss_CA0 == 0) {
        lbl_40_bss_CA8.b = (int)lbl_40_data_5160;
        lbl_40_bss_CA8.a = 1;
        lbl_40_bss_CA8.b = (int)lbl_40_data_5108;
        __register_global_object(&lbl_40_bss_CA8, (void*)fn_40_1D7A8, lbl_40_bss_C88);
        lbl_40_bss_CA0 = 1;
    }
    return &lbl_40_bss_CA8;
}
