#include <types.h>
#pragma force_active on

struct UnkSoObj {
    u8 pad_0[4];
    s32 m_4;
    s16 m_8;
    s16 m_a;
};

extern "C" void fn_27_EF1D4(UnkSoObj* p) {
    p->m_4 = -1;
    p->m_8 = 0;
    p->m_a = -1;
}
