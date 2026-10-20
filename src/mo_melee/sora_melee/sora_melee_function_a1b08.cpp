#include <types.h>
#pragma force_active on

struct Bits {
    u32 pad0;
    u32 pad1;
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_A1B08(Bits *p, u32 v)
{
    p->hi = v;
}
