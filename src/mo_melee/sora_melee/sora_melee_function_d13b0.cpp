#include <types.h>
#pragma force_active on

struct Bf {
    u32 unk0;
    u32 unk4;
    u32 a : 16;
    u32 b : 8;
    u32 c : 8;
};

extern "C" void fn_27_D13B0(Bf* p, u32 v)
{
    p->b = v;
}
