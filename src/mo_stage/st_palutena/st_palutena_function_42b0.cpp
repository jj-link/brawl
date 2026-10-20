#pragma force_active on
extern "C" {

typedef struct {
    char m_flag;
    char _pad[3];
    void* m_ptr;
} Bss38;

extern Bss38 lbl_67_bss_38;
extern char lbl_67_bss_30;
extern void* lbl_67_bss_18[3];
extern char lbl_67_data_10B8[];
extern char lbl_67_data_1060[];
extern void* fn_67_4374(void*, int);
extern void* __register_global_object(void*, void*, void*);

void* fn_67_42B0() {
    if (!lbl_67_bss_30) {
        lbl_67_bss_38.m_ptr = &lbl_67_data_10B8;
        lbl_67_bss_38.m_flag = 1;
        lbl_67_bss_38.m_ptr = &lbl_67_data_1060;
        __register_global_object(&lbl_67_bss_38, (void*)&fn_67_4374, &lbl_67_bss_18);
        lbl_67_bss_30 = 1;
    }
    return &lbl_67_bss_38;
}

}
