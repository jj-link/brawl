#include <types.h>
#pragma force_active on

struct Bf {
    u32 pad0;
    u32 pad1;
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" {
void fn_27_1A3EC0(Bf* p, u32 v)
{
    p->b = v;
}
}
