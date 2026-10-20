#pragma force_active on

extern "C" {
    void* fn_66_8F68();
    void* fn_66_902C(void* p, int n);
    void* __register_global_object(void* object, void* destructor, void* chain);
}

typedef struct {
    char type;
    char pad[3];
    void* data;
} EarthObj;

extern char lbl_66_bss_78;
extern EarthObj lbl_66_bss_80;
extern char lbl_66_bss_38[0xC];
extern char lbl_66_data_1A30[];
extern char lbl_66_data_19D8[];

extern "C" void* fn_66_8F68() {
    if (!lbl_66_bss_78) {
        lbl_66_bss_80.data = lbl_66_data_1A30;
        lbl_66_bss_80.type = 1;
        lbl_66_bss_80.data = lbl_66_data_19D8;
        __register_global_object(&lbl_66_bss_80, fn_66_902C, lbl_66_bss_38);
        lbl_66_bss_78 = 1;
    }
    return &lbl_66_bss_80;
}
