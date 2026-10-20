#include <types.h>
#pragma force_active on

struct S {
    u32 pad[2];
    u32 : 5;
    u32 f : 5;
    u32 : 22;
};

extern "C" {
void fn_27_1A2180(S* p, u32 v) {
    p->f = v;
}
}
