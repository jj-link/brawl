#include <types.h>
#pragma force_active on

struct S {
    u32 x;
    u32 y;
    s32 z;
};

extern "C" s32 fn_27_295FCC(S *s) {
    return s->z >> 27;
}
