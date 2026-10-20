#pragma force_active on
extern "C" {
    extern signed char lbl_27_bss_1178;
    extern unsigned char lbl_27_bss_117C[];
    extern unsigned char lbl_27_bss_E54[];
    void* __register_global_object(void* object, void* destructor, void* chain);
    void fn_27_505E0(void* ptr, int count);
}

extern "C" void* fn_27_83414() {
    if (lbl_27_bss_1178 == 0) {
        *(int*)(lbl_27_bss_117C + 4) = -1;
        *(short*)(lbl_27_bss_117C + 8) = 0;
        *(short*)(lbl_27_bss_117C + 10) = -1;
        __register_global_object(lbl_27_bss_117C, (void*)fn_27_505E0, lbl_27_bss_E54);
        lbl_27_bss_1178 = 1;
    }
    return lbl_27_bss_117C;
}
