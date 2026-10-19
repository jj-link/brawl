#include <types.h>
#pragma force_active on

extern "C" {
extern const f32 lbl_27_rodata_340;
extern const f32 lbl_27_rodata_344;
}

struct fn_27_1CD0C_t {
    s32 m_0;
    f32 m_4;
    f32 m_8;
    u8 m_c;
    u8 m_d;
    u8 m_e;
    u8 m_f;
};

extern "C" void fn_27_1CD0C(fn_27_1CD0C_t* p) {
    p->m_0 = -1;
    p->m_4 = lbl_27_rodata_344;
    p->m_8 = lbl_27_rodata_340;
    p->m_c = 0;
    p->m_d = 0;
    p->m_e = 0;
    p->m_f = 0;
}
