#include <types.h>
#pragma force_active on

struct S {
    u8 pad[8];
    unsigned int : 6;
    unsigned int f : 6;
};

extern "C" void fn_27_2960C0(S* s, int b) {
    s->f = b;
}
