#include <types.h>
#pragma force_active on

struct WorkStub {
    char pad[0x1c];
    u32* m_flagWorks;
};

extern "C" void fn_107_C534(WorkStub* work, u32 mask, u32 index) {
    work->m_flagWorks[index] &= ~mask;
}
