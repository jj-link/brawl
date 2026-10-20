#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 pad[2];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" void fn_27_19F5BC(FieldWord* p, u32 v)
{
    p->b = v;
}
