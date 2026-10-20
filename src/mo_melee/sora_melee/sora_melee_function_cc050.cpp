#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 pad[2];
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_CC050(Fn27Bits* p, u32 v)
{
    p->b = v;
}
