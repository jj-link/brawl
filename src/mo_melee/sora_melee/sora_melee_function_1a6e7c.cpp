#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 10;
    u32 mid : 10;
    u32 lo : 12;
};

extern "C" void fn_27_1A6E7C(void* p, u32 v)
{
    Bits* b = (Bits*)((char*)p + 8);
    b->mid = v;
}
