#pragma force_active on
extern "C" {
    void fn_27_1E82E8(void*, int);
    void fn_27_1E847C(void*, int, void*);
    void __register_global_object(void*, void (*)(void*), void*);
    void fn_27_2E0C9C(void*);
}

struct soGlobalObj {
    void* m_a;
    int m_pad;
    void* m_b;
};

extern char lbl_27_data_7CA70[];
extern soGlobalObj lbl_27_bss_73E8;
extern char lbl_27_bss_73DC[];

extern "C" void fn_27_2E0C20() {
    fn_27_1E82E8(&lbl_27_bss_73E8, 0);
    lbl_27_bss_73E8.m_b = lbl_27_data_7CA70;
    lbl_27_bss_73E8.m_a = lbl_27_data_7CA70 + 8;
    fn_27_1E847C(&lbl_27_bss_73E8, 4, &lbl_27_bss_73E8);
    __register_global_object(&lbl_27_bss_73E8, (void (*)(void*))fn_27_2E0C9C, lbl_27_bss_73DC);
}

__declspec(section ".ctors") extern void* const fn_27_2E0C20_ctor = (void*)fn_27_2E0C20;
