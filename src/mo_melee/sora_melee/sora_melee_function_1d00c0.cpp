#include <types.h>
#pragma force_active on

struct S {
    u32 a;
    u32 b;
    u32 f : 6;
    u32 g : 3;
    u32 h : 23;
};

extern "C" void fn_27_1D00C0(S* a, u32 b) {
    a->g = b;
}
