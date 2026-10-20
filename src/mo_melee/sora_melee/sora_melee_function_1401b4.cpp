#include <types.h>
#pragma force_active on

extern "C" void* fn_27_11AD84(void* p, int flags);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

struct SoGlobalObj {
    u32 m_0;
    s32 m_4;
    s16 m_8;
    s16 m_a;
};

extern "C" s8 lbl_27_bss_31BC;
extern "C" SoGlobalObj lbl_27_bss_31C0;
extern "C" u32 lbl_27_bss_319C[3];

extern "C" void* fn_27_1401B4(void) {
    if (lbl_27_bss_31BC == 0) {
        lbl_27_bss_31C0.m_4 = -1;
        lbl_27_bss_31C0.m_8 = 0;
        lbl_27_bss_31C0.m_a = -1;
        __register_global_object(&lbl_27_bss_31C0, (void*)fn_27_11AD84, lbl_27_bss_319C);
        lbl_27_bss_31BC = 1;
    }
    return &lbl_27_bss_31C0;
}
