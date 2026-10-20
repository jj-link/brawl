#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_CB534(void *obj, u32 val)
{
    struct Bits {
        u32 a : 2;
        u32 b : 2;
        u32 c : 28;
    };
    Bits *p = (Bits *)((char *)obj + 8);
    p->b = val;
}
}
