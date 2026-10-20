#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 f0 : 20;
    s32 f1 : 10;
};

extern "C" s32 fn_27_1A5F94(struct X* x) {
    return x->f1;
}
