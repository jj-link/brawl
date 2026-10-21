#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad[2];
    u32 : 5;
    u32 field : 5;
    u32 : 22;
};

extern "C" void fn_27_268A14(Obj* p, u32 v) {
    p->field = v;
}
