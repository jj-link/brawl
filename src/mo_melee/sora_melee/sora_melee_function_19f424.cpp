#include <types.h>
#pragma force_active on

struct BF {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

struct Obj {
    u32 w0;
    u32 w1;
    BF w2;
};

extern "C" void fn_27_19F424(Obj* p, u32 v) {
    p->w2.b = v;
}
