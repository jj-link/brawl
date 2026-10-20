#include <types.h>
#pragma force_active on

struct Bits8 {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_A1BE8(void* p, u32 v)
{
    Bits8* s = (Bits8*)((char*)p + 8);
    s->b = v;
}
