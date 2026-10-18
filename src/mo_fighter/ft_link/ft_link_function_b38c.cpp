#include <stddef.h>
#pragma force_active on

struct FnWork {
    char pad[0xc];
    int *m_values;
};

extern "C" void fn_93_B38C(FnWork *work, int value, unsigned int index)
{
    work->m_values[index] += value;
}
