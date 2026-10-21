#include <types.h>
#pragma force_active on

struct S {
    u32 pad[2];
    u32 value : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1A14B8(S* p, u32 v) {
    p->value = v;
}
