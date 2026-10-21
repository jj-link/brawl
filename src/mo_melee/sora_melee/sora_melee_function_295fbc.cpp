#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[2];
    u32 bits0 : 6;
    u32 field : 3;
    u32 rest : 23;
};

extern "C" void fn_27_295FBC(Obj* p, u32 v) {
    p->field = v;
}
