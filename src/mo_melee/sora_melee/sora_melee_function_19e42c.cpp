#include <types.h>
#pragma force_active on

struct S {
    u32 w0;
    u32 w1;
    u32 pad : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" {
void fn_27_19E42C(S* p, u32 v)
{
    p->f = v;
}
}
