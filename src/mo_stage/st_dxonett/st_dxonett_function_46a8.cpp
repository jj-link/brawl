#pragma force_active on
struct Obj {
    unsigned char flag;
    unsigned char pad[3];
    void* ptr;
};

extern "C" {
extern signed char lbl_78_bss_3C;
extern Obj lbl_78_bss_40;
extern unsigned char lbl_78_data_1258[0x38];
extern unsigned char lbl_78_data_1200[0x38];
extern unsigned char lbl_78_bss_18[0x0C];
extern void* fn_78_476C(void*, int);
extern void* __register_global_object(void*, void*, void*);
}

extern "C" Obj* fn_78_46A8() {
    if (lbl_78_bss_3C == 0) {
        lbl_78_bss_40.ptr = lbl_78_data_1258;
        lbl_78_bss_40.flag = 1;
        lbl_78_bss_40.ptr = lbl_78_data_1200;
        __register_global_object(&lbl_78_bss_40, (void*)fn_78_476C, lbl_78_bss_18);
        lbl_78_bss_3C = 1;
    }
    return &lbl_78_bss_40;
}
