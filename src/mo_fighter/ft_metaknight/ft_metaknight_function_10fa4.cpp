#include <types.h>
#pragma force_active on

struct MetaKnightU32Triplet {
    u32 pad[2]; // offset 0x00 (member base is at 0x08)
    u32 a;      // offset 0x08
    u32 b;      // offset 0x0c
    u32 c;      // offset 0x10
};

extern "C" void fn_111_10FA4(MetaKnightU32Triplet *triplet, u32 value)
{
    triplet->c = value;
    triplet->b = value;
    triplet->a = value;
}
