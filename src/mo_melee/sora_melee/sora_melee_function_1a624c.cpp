#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 10;
    u32 f : 10;
    u32 b : 12;
};

struct Outer {
    u32 pad[2];
    Bits w;
};

extern "C" void fn_27_1A624C(Outer* p, u32 v) {
    p->w.f = v;
}
