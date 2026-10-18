#include <types.h>
#pragma force_active on

struct fn_27_B15D0_Work {
    u32 m_00;
    u32 m_04;
    u8 m_08[8];
    s32 m_10;
};

extern "C" {
void fn_27_B15D0(fn_27_B15D0_Work* work) {
    work->m_00 = 0;
    work->m_04 = 0;
    work->m_10 = -1;
}
}
