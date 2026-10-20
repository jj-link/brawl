#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_19A8A8(void *p, u32 v)
{
    Bits *w = (Bits *)((char *)p + 8);
    w->b = v;
}
