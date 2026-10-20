#include <types.h>
#pragma force_active on

struct Fn13A4Bits {
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" {
void fn_27_1A13A4(void *p, unsigned long x)
{
    Fn13A4Bits *w = (Fn13A4Bits *)((char *)p + 8);
    w->b = x;
}
}
