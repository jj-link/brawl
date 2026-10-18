#include <types.h>
#pragma force_active on

struct GeneralWorkMulInt {
    char pad[0xc];
    s32* m_intWorks;
};

extern "C" void fn_113_CD7C(GeneralWorkMulInt* work, s32 value, u32 index) {
    work->m_intWorks[index] *= value;
}
