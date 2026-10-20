#include <types.h>
#pragma force_active on

struct fn27Obj {
    char pad[0x40];
    u8 m_40;
};

extern "C" bool fn_27_250D98(fn27Obj* p)
{
    return p->m_40 == 4;
}
