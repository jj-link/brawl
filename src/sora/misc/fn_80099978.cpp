#include <types.h>
#pragma force_active on

struct fn_80099978_Work {
    u32 m_00;
    u32 m_04;
    u32 m_08;
    u32 m_0C;
};

extern "C" {
void fn_80099978(fn_80099978_Work* work) {
    work->m_00 = 0;
    work->m_04 = 0;
    work->m_08 = 0x80000000;
    work->m_0C = 0;
}
}
