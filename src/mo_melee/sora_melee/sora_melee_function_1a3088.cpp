#include <types.h>
#pragma force_active on

struct S {
    u32 pad0;
    u32 pad1;
    u32 a : 3;
    u32 b : 3;
    u32 rest : 26;
};

extern "C" void fn_27_1A3088(S* p, u32 value) {
    p->b = value;
}
