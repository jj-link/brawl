#include <types.h>
#pragma force_active on

extern "C" void fn_27_10E04C(void* p, s32 n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

struct SoGlobalObj {
    u32 m_0;
    s32 m_4;
    s16 m_8;
    s16 m_a;
    u8 m_pad[4];
};

extern "C" s8 lbl_27_bss_31D4;
extern "C" SoGlobalObj lbl_27_bss_31D8;
extern "C" u8 lbl_27_bss_31A8[12];

extern "C" void* fn_27_140290() {
    if (lbl_27_bss_31D4 == 0) {
        lbl_27_bss_31D8.m_4 = -1;
        lbl_27_bss_31D8.m_8 = 0;
        lbl_27_bss_31D8.m_a = -1;
        __register_global_object(&lbl_27_bss_31D8, (void*)fn_27_10E04C, lbl_27_bss_31A8);
        lbl_27_bss_31D4 = 1;
    }
    return &lbl_27_bss_31D8;
}
