#include <types.h>
#pragma force_active on

struct FalcoBuf24 {
    u32 v[6];
};

extern "C" FalcoBuf24 fn_108_B430(void* a, void* b);

extern "C" const FalcoBuf24& fn_108_B55C(void* a, void* b) {
    return fn_108_B430(a, b);
}
