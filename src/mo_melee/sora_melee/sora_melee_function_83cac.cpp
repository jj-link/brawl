#pragma force_active on
struct SoGlobalObj {
    int m_0;
    int m_4;
    short m_8;
    short m_a;
};

extern "C" {
extern signed char lbl_27_bss_1268;
extern SoGlobalObj lbl_27_bss_126C;
extern unsigned char lbl_27_bss_ECC[12];
void fn_27_844D8(void* ptr, int size);
void __register_global_object(void* object, void* destructor, void* chain);

SoGlobalObj* fn_27_83CAC() {
    if (lbl_27_bss_1268 == 0) {
        lbl_27_bss_126C.m_4 = -1;
        lbl_27_bss_126C.m_8 = 0;
        lbl_27_bss_126C.m_a = -1;
        __register_global_object(&lbl_27_bss_126C, (void*)fn_27_844D8, lbl_27_bss_ECC);
        lbl_27_bss_1268 = 1;
    }
    return &lbl_27_bss_126C;
}
}
