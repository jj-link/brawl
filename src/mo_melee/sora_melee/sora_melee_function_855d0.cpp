#pragma force_active on
extern "C" {
    extern signed char lbl_27_bss_1440;
    extern char lbl_27_bss_1448[0x48];
    extern char lbl_27_bss_F5C[0xC];
    void fn_27_13700(void* p);
    void fn_27_1374C(void* p, int flag);
    int __register_global_object(void* obj, void (*dtor)(void*), void* handle);
}

extern "C" void* fn_27_855D0() {
    if (lbl_27_bss_1440 == 0) {
        fn_27_13700(lbl_27_bss_1448);
        __register_global_object(lbl_27_bss_1448, (void (*)(void*)) fn_27_1374C, lbl_27_bss_F5C);
        lbl_27_bss_1440 = 1;
    }
    return lbl_27_bss_1448;
}
