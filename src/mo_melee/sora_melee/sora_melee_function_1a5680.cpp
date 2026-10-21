#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[2];
    u32 x : 8;
    u32 f : 4;
    u32 rest : 20;
};

extern "C" void fn_27_1A5680(Obj* p, u32 v) {
    p->f = v;
}
