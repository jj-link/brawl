#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 6;
    u32 f : 3;
    u32 lo : 23;
};

extern "C" void fn_27_C9620(u32* p, u32 v)
{
    ((Bits*)(p + 2))->f = v;
}
