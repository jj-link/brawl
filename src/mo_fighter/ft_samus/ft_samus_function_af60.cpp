#include <types.h>
#pragma force_active on

struct FtSamusWork {
    char pad[0x1c];
    u32 *m_intWorks;
};

extern "C" void fn_94_AF60(FtSamusWork *work, u32 mask, u32 index)
{
    work->m_intWorks[index] |= mask;
}
