#include <types.h>
#pragma force_active on

struct A {
    u32 f0;
    u32 f4;
    unsigned : 12;
    unsigned target : 1;
    unsigned : 19;
};

extern "C" {
unsigned int fn_27_1D06FC(const struct A *p) {
    return p->target;
}
}
