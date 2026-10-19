#include <types.h>
#pragma force_active on

struct DiddyTriple {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" DiddyTriple fn_115_A5B4(s32 a, s32 b);

extern "C" const DiddyTriple& fn_115_A6E0(s32 a, s32 b) {
    return fn_115_A5B4(a, b);
}
