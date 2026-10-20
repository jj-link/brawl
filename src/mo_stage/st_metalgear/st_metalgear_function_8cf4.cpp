#pragma force_active on
extern "C" {

void __register_global_object(void* object, void* destructor, void* chain);
void* fn_71_8DB8(void* p, int n);

struct _BssObj {
    char flag;
    void* ptr;
};

extern char lbl_71_bss_30[8];
extern _BssObj lbl_71_bss_38;
extern void* lbl_71_bss_18[3];
extern char lbl_71_data_1EF8[];
extern char lbl_71_data_1EA0[];

void* fn_71_8CF4() {
    if (lbl_71_bss_30[0] == 0) {
        lbl_71_bss_38.ptr = lbl_71_data_1EF8;
        lbl_71_bss_38.flag = 1;
        lbl_71_bss_38.ptr = lbl_71_data_1EA0;
        __register_global_object(&lbl_71_bss_38, fn_71_8DB8, lbl_71_bss_18);
        lbl_71_bss_30[0] = 1;
    }
    return &lbl_71_bss_38;
}

}
