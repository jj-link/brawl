#include <types.h>
#pragma force_active on

struct S {
    u32 a;
    u32 b;
    unsigned : 4;
    int v : 4;
};

extern "C" int fn_27_19F3B0(const S* p) { return p->v; }
