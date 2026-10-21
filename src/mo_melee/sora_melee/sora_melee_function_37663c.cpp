#pragma force_active on
struct soStaticWork {
    void* m_vt;
    int m_pad;
    void* m_data;
};

extern "C" {
    void fn_27_1E82E8(soStaticWork*, int);
    void fn_27_1E847C(soStaticWork*, int, soStaticWork*);
    void fn_27_3766B8(void*);
    void __register_global_object(void*, void*, void*);
    extern unsigned char lbl_27_data_937D0[0x18];
    extern soStaticWork lbl_27_bss_83E8;
    extern unsigned char lbl_27_bss_83DC[0xC];

    void fn_27_37663C() {
        soStaticWork* obj = &lbl_27_bss_83E8;
        fn_27_1E82E8(&lbl_27_bss_83E8, 0);
        obj->m_data = lbl_27_data_937D0;
        lbl_27_bss_83E8.m_vt = lbl_27_data_937D0 + 8;
        fn_27_1E847C(obj, 0x5f, obj);
        __register_global_object(obj, (void*)fn_27_3766B8, lbl_27_bss_83DC);
    }
}

__declspec(section ".ctors") extern void* const fn_27_37663C_ctor = (void*)fn_27_37663C;
