#include <types.h>
#pragma force_active on

extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void fn_27_841D8(void* a, int b);

struct SoGuardWork {
    s32 m_a;
    s32 m_b;
    s16 m_c;
    s16 m_d;
};

extern s8 lbl_27_bss_1130;
extern SoGuardWork lbl_27_bss_1134;
extern char lbl_27_bss_E30[12];

extern "C" {
void* fn_27_83180() {
    if (!lbl_27_bss_1130) {
        lbl_27_bss_1134.m_b = -1;
        lbl_27_bss_1134.m_c = 0;
        lbl_27_bss_1134.m_d = -1;
        __register_global_object(&lbl_27_bss_1134, (void*)fn_27_841D8, lbl_27_bss_E30);
        lbl_27_bss_1130 = 1;
    }
    return &lbl_27_bss_1134;
}
}
