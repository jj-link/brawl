#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_4280;

struct FnStruct27 {
    u8 m_rest : 7;
    u8 m_flag : 1;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
};

extern "C" void fn_27_25CF1C(FnStruct27 *p) {
    p->m_rest = 0;
    p->m_f04 = lbl_27_rodata_4280;
    p->m_f08 = lbl_27_rodata_4280;
    p->m_f0C = lbl_27_rodata_4280;
    p->m_f10 = lbl_27_rodata_4280;
    p->m_f14 = lbl_27_rodata_4280;
}
