#pragma force_active on
extern "C" {
    void fn_27_B15E8(void*);
    void fn_27_B164C(void*, int);
    void __register_global_object(void*, void*, void*);
    extern char lbl_27_bss_1490;
    extern char lbl_27_bss_1494[];
    extern char lbl_27_bss_F68[];
}

extern "C" void* fn_27_85680() {
    if (!lbl_27_bss_1490) {
        fn_27_B15E8(&lbl_27_bss_1494);
        __register_global_object(&lbl_27_bss_1494, fn_27_B164C, &lbl_27_bss_F68);
        lbl_27_bss_1490 = 1;
    }
    return &lbl_27_bss_1494;
}
