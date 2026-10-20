#pragma force_active on
extern "C" {
struct SoStaticObj {
    int m_0;
    int m_4;
    short m_8;
    short m_a;
};

extern signed char lbl_27_bss_11F0;
extern SoStaticObj lbl_27_bss_11F4;
extern char lbl_27_bss_E90[12];
void* __register_global_object(void* object, void* destructor, void* chain);
void* fn_27_84398(void* ptr, int size);

void* fn_27_83860(void) {
    if (lbl_27_bss_11F0 == 0) {
        lbl_27_bss_11F4.m_4 = -1;
        lbl_27_bss_11F4.m_8 = 0;
        lbl_27_bss_11F4.m_a = -1;
        __register_global_object(&lbl_27_bss_11F4, (void*)fn_27_84398, lbl_27_bss_E90);
        lbl_27_bss_11F0 = 1;
    }
    return &lbl_27_bss_11F4;
}
}
