#pragma force_active on
extern "C" {
    void fn_27_1E82E8(void*, int);
    void fn_27_1E847C(void*, int, void*);
    void fn_27_2E4E9C(void*);
    void __register_global_object(void*, void*, void*);
    void fn_27_2E4E20();
}

struct SoObj {
    void* m_vt;
    int m_pad;
    void* m_data;
};

extern SoObj lbl_27_bss_7458;
extern unsigned char lbl_27_data_7D010[];
extern unsigned char lbl_27_bss_744C[];

extern "C" void fn_27_2E4E20() {
    fn_27_1E82E8(&lbl_27_bss_7458, 0);
    lbl_27_bss_7458.m_data = lbl_27_data_7D010;
    lbl_27_bss_7458.m_vt = lbl_27_data_7D010 + 8;
    fn_27_1E847C(&lbl_27_bss_7458, 5, &lbl_27_bss_7458);
    __register_global_object(&lbl_27_bss_7458, (void*)fn_27_2E4E9C, lbl_27_bss_744C);
}

__declspec(section ".ctors") extern void* const fn_27_2E4E20_ctor = (void*)fn_27_2E4E20;
