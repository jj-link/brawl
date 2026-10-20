#include <types.h>
#pragma force_active on

struct FnBits {
    u32 pad[2];
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" {
void fn_27_1A5928(FnBits *p, u32 v)
{
    p->b = v;
}
}
