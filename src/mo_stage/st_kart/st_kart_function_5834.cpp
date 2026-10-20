#pragma force_active on

extern "C" {
    void __register_global_object(void* object, void* destructor, void* chain);
    void* fn_49_58F8(void* p, int n);
}

struct Obj {
    char flag;
    char pad[3];
    void* data;
};

extern char lbl_49_bss_48;
extern struct Obj lbl_49_bss_50;
extern char lbl_49_bss_18[12];
extern char lbl_49_data_DC8[0x38];
extern char lbl_49_data_D70[0x38];

extern "C" void* fn_49_5834() {
    if (!lbl_49_bss_48) {
        lbl_49_bss_50.data = lbl_49_data_DC8;
        lbl_49_bss_50.flag = 1;
        lbl_49_bss_50.data = lbl_49_data_D70;
        __register_global_object(&lbl_49_bss_50, (void*)fn_49_58F8, lbl_49_bss_18);
        lbl_49_bss_48 = 1;
    }
    return &lbl_49_bss_50;
}
