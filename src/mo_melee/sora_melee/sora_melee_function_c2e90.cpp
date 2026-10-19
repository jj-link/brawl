#include <types.h>
#pragma force_active on

struct fn_27_C2E90_Obj {
    u8 pad_0x0[0x8];
    s32 m_08;
    s32 m_0c;
    s32 m_10;
    f32 m_14;
    f32 m_18;
    f32 m_1c;
    u8 m_20;
};

extern "C" {
extern const f32 lbl_27_rodata_ED0;

void fn_27_C2E90(fn_27_C2E90_Obj* p) {
    p->m_20 = 0;
    p->m_08 = 0xc;
    p->m_0c = 0x8;
    p->m_14 = lbl_27_rodata_ED0;
    p->m_18 = lbl_27_rodata_ED0;
    p->m_1c = lbl_27_rodata_ED0;
    p->m_10 = 0x3e7;
}
}
