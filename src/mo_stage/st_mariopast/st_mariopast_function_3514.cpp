#pragma force_active on
extern "C" {

void __register_global_object(void* object, void* destructor, void* chain);
void* fn_48_35D8(void* p, int n);

extern char lbl_48_bss_38;
extern int lbl_48_data_10B8[];
extern int lbl_48_data_1060[];
extern int lbl_48_bss_18[];

struct Obj {
    unsigned char flag;
    void* data;
};
extern Obj lbl_48_bss_40;

void* fn_48_3514() {
    if (lbl_48_bss_38 == 0) {
        lbl_48_bss_40.data = &lbl_48_data_10B8;
        lbl_48_bss_40.flag = 1;
        lbl_48_bss_40.data = &lbl_48_data_1060;
        __register_global_object(&lbl_48_bss_40, fn_48_35D8, &lbl_48_bss_18);
        lbl_48_bss_38 = 1;
    }
    return &lbl_48_bss_40;
}

}
