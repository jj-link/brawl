#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u32 w0;
    u32 w1;
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
};

extern "C" {
void fn_27_A1BAC(Fn27Obj* p, u32 v)
{
    p->f = v;
}
}
