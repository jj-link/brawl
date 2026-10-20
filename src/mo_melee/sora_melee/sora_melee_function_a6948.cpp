#include <types.h>
#pragma force_active on

struct UnkObj27 {
    u32 m_00;
    u32 m_04;
    s32 m_08;
    u8 m_0c[0x1d - 0x0c];
    u8 m_1d_hi : 4;
    u8 m_1d_lo : 4;
    u8 m_1e[0x20 - 0x1e];
    const void* m_20;
};

extern "C" {
extern u8 lbl_27_data_157E0[];

void fn_27_A6948(UnkObj27* obj) {
    obj->m_20 = lbl_27_data_157E0;
    obj->m_00 = 0;
    obj->m_04 = 0;
    obj->m_08 = -1;
    obj->m_1d_hi = 0;
}
}
