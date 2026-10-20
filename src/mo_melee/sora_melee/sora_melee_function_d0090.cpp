#include <types.h>
#pragma force_active on

struct Bf {
    u32 a : 14;
    u32 f : 7;
    u32 b : 11;
};

struct Outer {
    u32 w0;
    u32 w1;
    Bf w2;
};

extern "C" void fn_27_D0090(Outer* p, u32 v) {
    p->w2.f = v;
}
