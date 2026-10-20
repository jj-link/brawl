#pragma force_active on
extern "C" {
    extern signed char lbl_27_bss_12E8;
    extern int lbl_27_bss_12F0[2];
    extern char lbl_27_bss_F14[12];
    void* __register_global_object(void* object, void* destructor, void* chain);
    void __dt__8clTargetFv(void*, int);
}

extern "C" void* fn_27_85204() {
    if (lbl_27_bss_12E8 == 0) {
        lbl_27_bss_12F0[1] = -1;
        lbl_27_bss_12F0[0] = -1;
        __register_global_object(lbl_27_bss_12F0, (void*)__dt__8clTargetFv, lbl_27_bss_F14);
        lbl_27_bss_12E8 = 1;
    }
    return lbl_27_bss_12F0;
}
