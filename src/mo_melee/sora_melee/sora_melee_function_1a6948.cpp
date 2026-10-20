#include <types.h>
#pragma force_active on

struct Bits {
    u32 w0;
    u32 w1;
    u32 f : 10;
    u32 rest : 22;
};

extern "C" void fn_27_1A6948(Bits *p, u32 v)
{
    p->f = v;
}
