#include <types.h>
#pragma force_active on

struct S {
    u32 a;
    u32 b;
    u32 hi : 20;
    u32 mid : 10;
    u32 lo : 2;
};

extern "C" {
void fn_27_1A34FC(S* s, u32 v)
{
    s->mid = v;
}
}
