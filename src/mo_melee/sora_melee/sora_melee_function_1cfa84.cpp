#include <types.h>
#pragma force_active on

struct Obj {
    u32 pad;
    u32 pad2;
    u32 : 6;
    u32 field : 6;
    u32 : 20;
};

extern "C" void fn_27_1CFA84(Obj* p, u32 v) {
    p->field = v;
}
