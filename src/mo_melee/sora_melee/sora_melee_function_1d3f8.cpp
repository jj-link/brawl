#include <types.h>
#pragma force_active on

struct Bf {
    u32 pad[2];
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" {
void fn_27_1D3F8(Bf* p, u32 v)
{
    p->b = v;
}
}
