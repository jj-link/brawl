#pragma force_active on
struct Obj60 {
    char flag;
    void* ptr;
};

extern "C" {
    extern signed char lbl_63_bss_58;
    extern Obj60 lbl_63_bss_60;
    extern char lbl_63_bss_28[12];
    extern void* __register_global_object(void*, void*, void*);
    extern char lbl_63_data_28C8[];
    extern char lbl_63_data_2870[];
    extern void* fn_63_941C(void*, int);
}

extern "C" void* fn_63_9358() {
    if (!lbl_63_bss_58) {
        lbl_63_bss_60.ptr = lbl_63_data_28C8;
        lbl_63_bss_60.flag = 1;
        lbl_63_bss_60.ptr = lbl_63_data_2870;
        __register_global_object(&lbl_63_bss_60, (void*)fn_63_941C, lbl_63_bss_28);
        lbl_63_bss_58 = 1;
    }
    return &lbl_63_bss_60;
}
