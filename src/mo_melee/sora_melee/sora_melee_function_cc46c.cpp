#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
};

extern "C" void fn_27_CC46C(void* p, u32 v) {
    Bits* w = (Bits*)((char*)p + 8);
    w->f = v;
}
