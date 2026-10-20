#include <types.h>
#pragma force_active on

struct S {
    u32 a;
    u32 b;
    s32 c;
};

extern "C" int fn_27_1D03B0(struct S *s) {
    return s->c >> 28;
}
