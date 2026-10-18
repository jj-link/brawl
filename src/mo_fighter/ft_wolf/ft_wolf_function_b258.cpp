#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

typedef struct FtWorkHolder
{
    char pad[0x1c];
    u32 *m_flagWorks;
} FtWorkHolder;

extern "C" void fn_125_B258(FtWorkHolder *work, u32 mask, u32 index)
{
    work->m_flagWorks[index] |= mask;
}
