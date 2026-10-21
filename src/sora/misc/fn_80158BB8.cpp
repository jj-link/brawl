#include <types.h>
#pragma force_active on

struct fn_80158BB8_Work {
    u32 m_00;
    u32 m_04;
    u32 m_08;
    u32 m_0C;
    u32 m_10;
    u8 m_14[0x24 - 0x14];
    u32 m_24;
};

extern "C" void fn_80158BB8(fn_80158BB8_Work* work) {
    work->m_00 = 0;
    work->m_04 = 0;
    work->m_08 = 0;
    work->m_0C = 0;
    work->m_10 = 0;
    work->m_24 |= 0x80000000;
}
