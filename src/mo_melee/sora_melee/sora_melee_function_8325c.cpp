#pragma force_active on
extern "C" void* fn_27_84218(void* p, int n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

struct SoGlobalObj {
    int m0;
    int m4;
    short m8;
    short mA;
};

extern signed char lbl_27_bss_1148;
extern SoGlobalObj lbl_27_bss_114C;
extern unsigned char lbl_27_bss_E3C[12];

extern "C" SoGlobalObj* fn_27_8325C() {
    if (lbl_27_bss_1148 == 0) {
        lbl_27_bss_114C.m4 = -1;
        lbl_27_bss_114C.m8 = 0;
        lbl_27_bss_114C.mA = -1;
        __register_global_object(&lbl_27_bss_114C, (void*)fn_27_84218, lbl_27_bss_E3C);
        lbl_27_bss_1148 = 1;
    }
    return &lbl_27_bss_114C;
}
