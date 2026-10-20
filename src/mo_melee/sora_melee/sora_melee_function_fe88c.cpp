#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
};

struct Obj {
    u32 w0;
    u32 w4;
    Bits w8;
};

extern "C" void fn_27_FE88C(Obj* p, u32 v)
{
    p->w8.f = v;
}
