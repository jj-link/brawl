#include <types.h>
#pragma force_active on

struct FF1E4Obj {
    u32 w0;
    u32 w1;
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

extern "C" void fn_27_FF1E4(FF1E4Obj* p, u32 v)
{
    p->f = v;
}
