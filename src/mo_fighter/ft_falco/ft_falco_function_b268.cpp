#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

struct FighterWork
{
    char pad[0xc];
    int *m_intWorks;
};

extern "C" void fn_108_B268(FighterWork *work, u32 index)
{
    work->m_intWorks[index]--;
}
