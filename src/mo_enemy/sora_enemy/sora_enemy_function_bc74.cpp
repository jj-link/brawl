#pragma force_active on

struct Reg {
    unsigned char a;
    void* b;
};

extern "C" {
    extern char lbl_41_bss_24;
    extern Reg lbl_41_bss_28;
    extern char lbl_41_data_1454[];
    extern char lbl_41_data_1400[];
    extern char lbl_41_bss_8[];
    void fn_41_BD38(void*, short);
    void __register_global_object(void*, void*, void*);
}

extern "C" Reg* fn_41_BC74() {
    if (!lbl_41_bss_24) {
        lbl_41_bss_28.b = &lbl_41_data_1454;
        lbl_41_bss_28.a = 1;
        lbl_41_bss_28.b = &lbl_41_data_1400;
        __register_global_object(&lbl_41_bss_28, (void*)&fn_41_BD38, &lbl_41_bss_8);
        lbl_41_bss_24 = 1;
    }
    return &lbl_41_bss_28;
}
