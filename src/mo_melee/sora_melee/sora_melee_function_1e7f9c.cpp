#pragma force_active on
extern "C" {
    extern unsigned char lbl_27_bss_5248[];
    extern unsigned char lbl_27_data_47AF8[];
    extern unsigned char lbl_27_bss_523C[];

    void fn_27_1E82E8(void*, int);
    void fn_27_1E847C(void*, int, void*);
    void fn_27_1E8018();
    void __register_global_object(void*, void (*)(), void*);

    void fn_27_1E7F9C() {
        fn_27_1E82E8(lbl_27_bss_5248, 0);
        *(void**)(lbl_27_bss_5248 + 8) = lbl_27_data_47AF8;
        *(void**)lbl_27_bss_5248 = lbl_27_data_47AF8 + 8;
        fn_27_1E847C(lbl_27_bss_5248, 0x98, lbl_27_bss_5248);
        __register_global_object(lbl_27_bss_5248, fn_27_1E8018, lbl_27_bss_523C);
    }
}

__declspec(section ".ctors") extern void* const fn_27_1E7F9C_ctor = (void*)fn_27_1E7F9C;
