#include <types.h>
#pragma force_active on

struct fn_27_1FA20_obj {
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_c;
    u32 m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    u8 m_24;
};

extern const float lbl_27_rodata_370;
extern const float lbl_27_rodata_374;

extern "C" {
void fn_27_1FFCC(const void*);

void fn_27_1FA20(fn_27_1FA20_obj* p) {
    fn_27_1FFCC(p);
    p->m_0 = 0;
    p->m_4 = 0;
    p->m_8 = 0;
    p->m_c = 0;
    p->m_10 = 0;
    p->m_14 = lbl_27_rodata_370;
    p->m_18 = lbl_27_rodata_370;
    p->m_1c = lbl_27_rodata_370;
    p->m_20 = lbl_27_rodata_374;
    p->m_24 = (p->m_24 & ~0xC0) | 0x20;
}
}
