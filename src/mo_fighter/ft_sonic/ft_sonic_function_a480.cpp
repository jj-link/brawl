#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

struct FtSonicWork {
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_123_A480(FtSonicWork *work, u32 index, float value)
{
    work->m_floatWorks[index] -= value;
}
