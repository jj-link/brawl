#include <stddef.h>
#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct FighterWork {
    u8 pad[0xc];
    u32 *m_values;
};

extern "C" void fn_94_B098(FighterWork *work, u32 value, u32 index)
{
    work->m_values[index] += value;
}
