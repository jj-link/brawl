#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 6;
    u32 f : 6;
    u32 b : 20;
};

extern "C" void fn_27_1D054C(void* p, u32 v) {
    Bits* w = (Bits*)((char*)p + 8);
    w->f = v;
}
