#include <types.h>
#pragma force_active on

struct Pair8 {
    u32 a;
    u32 b;
};

extern "C" void fn_8016FB8C(Pair8* dst, const Pair8* src) {
    dst->a = src->a;
    dst->b = src->b;
}
