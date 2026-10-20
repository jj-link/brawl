#include <types.h>
#pragma force_active on

struct Fld {
    u32 a[2];
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

extern "C" void fn_27_268AA0(Fld* p, u32 v)
{
    p->f = v;
}
