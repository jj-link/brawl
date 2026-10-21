#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[2];
    u32 a : 20;
    u32 b : 10;
    u32 c : 2;
};

extern "C" void fn_27_1A60A8(Obj* p, u32 v) {
    p->b = v;
}
