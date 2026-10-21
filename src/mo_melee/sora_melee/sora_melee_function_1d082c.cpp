#include <types.h>
#pragma force_active on

struct Obj {
    u32 padding[2];
    u32 pad : 4;
    u32 field : 4;
    u32 rest : 24;
};

extern "C" void fn_27_1D082C(Obj* p, u32 v) {
    p->field = v;
}
