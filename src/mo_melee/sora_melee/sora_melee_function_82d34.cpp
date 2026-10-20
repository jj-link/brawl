#pragma force_active on
struct SoObj {
    int m0;
    int m4;
    short m8;
    short mA;
};

extern "C" {
extern signed char lbl_27_bss_10B8;
extern SoObj lbl_27_bss_10BC;
extern char lbl_27_bss_DF4[12];
void fn_27_84098(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_27_82D34() {
    if (!lbl_27_bss_10B8) {
        lbl_27_bss_10BC.m4 = -1;
        lbl_27_bss_10BC.m8 = 0;
        lbl_27_bss_10BC.mA = -1;
        __register_global_object(&lbl_27_bss_10BC, (void*)fn_27_84098, lbl_27_bss_DF4);
        lbl_27_bss_10B8 = 1;
    }
    return &lbl_27_bss_10BC;
}
