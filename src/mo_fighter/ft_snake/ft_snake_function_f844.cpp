#include <types.h>
#pragma force_active on

typedef struct FtSnakeWork {
    char pad[0xc];
    u32 *m_values;
} FtSnakeWork;

extern "C" void fn_122_F844(FtSnakeWork *work, u32 value, u32 index)
{
    work->m_values[index] += value;
}
