#include <types.h>
#pragma force_active on

struct fn_27_FE7D4_Obj {
    u32 pad[2];
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" void fn_27_FE7D4(fn_27_FE7D4_Obj* p, u32 v) {
    p->b = v;
}
