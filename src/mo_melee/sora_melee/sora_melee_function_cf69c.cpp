#include <types.h>
#pragma force_active on

struct FooBits {
    u32 pad[2];
    u32 a : 6;
    u32 f : 6;
    u32 b : 20;
};

extern "C" void fn_27_CF69C(FooBits* p, u32 v)
{
    p->f = v;
}
