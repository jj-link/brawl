#pragma force_active on
extern "C" {

typedef struct {
    void* a;
    void* b;
} Obj;

extern signed char lbl_105_bss_38C;
extern Obj lbl_105_bss_390;
extern void* lbl_105_bss_3D4[];
extern unsigned char lbl_105_data_31B4[], lbl_105_data_3188[], lbl_105_data_3120[], lbl_105_data_8B7C[];
void fn_105_18384(void*);
void* __register_global_object(void*, void*, void*);

void* fn_105_1ACB0() {
    if (lbl_105_bss_38C == 0) {
        lbl_105_bss_390.a = lbl_105_data_31B4;
        lbl_105_bss_390.b = lbl_105_data_3188;
        lbl_105_bss_390.a = lbl_105_data_3120;
        lbl_105_bss_390.b = lbl_105_data_3120 + 0x10;
        lbl_105_bss_390.a = lbl_105_data_8B7C;
        lbl_105_bss_390.b = lbl_105_data_8B7C + 0x10;
        __register_global_object(&lbl_105_bss_390, reinterpret_cast<void*>(fn_105_18384), &lbl_105_bss_3D4);
        lbl_105_bss_38C = 1;
    }
    return &lbl_105_bss_390;
}

}
