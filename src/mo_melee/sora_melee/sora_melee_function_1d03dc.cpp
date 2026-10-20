#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 4;
    u32 f : 4;
    u32 lo : 24;
};

extern "C" void fn_27_1D03DC(u8* self, u32 value)
{
    Bits* word = (Bits*)(self + 8);
    word->f = value;
}
