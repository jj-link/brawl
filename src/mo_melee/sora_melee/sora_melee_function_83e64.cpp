#pragma force_active on
struct Holder {
    int m0;
    int m4;
    short m8;
    short mA;
};

extern "C" void* fn_27_84558(void* ptr, int count);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern signed char lbl_27_bss_1298;
extern Holder lbl_27_bss_129C;
extern Holder lbl_27_bss_EE4;

extern "C" void* fn_27_83E64() {
    if (lbl_27_bss_1298 == 0) {
        lbl_27_bss_129C.m4 = -1;
        lbl_27_bss_129C.m8 = 0;
        lbl_27_bss_129C.mA = -1;
        __register_global_object(&lbl_27_bss_129C, (void*)fn_27_84558, &lbl_27_bss_EE4);
        lbl_27_bss_1298 = 1;
    }
    return &lbl_27_bss_129C;
}
