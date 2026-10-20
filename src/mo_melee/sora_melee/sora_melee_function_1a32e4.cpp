#include <types.h>
#pragma force_active on

struct fn_27_Outer {
    u32 pad[2];
    u32 a : 20;
    s32 f : 10;
    u32 b : 2;
};

extern "C" {
s32 fn_27_1A32E4(fn_27_Outer* p) {
    return p->f;
}
}
