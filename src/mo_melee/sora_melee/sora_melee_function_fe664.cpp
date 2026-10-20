#include <types.h>
#pragma force_active on

struct S {
    u32 pad[2];
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" {
void fn_27_FE664(S* p, u32 v) {
    p->b = v;
}
}
