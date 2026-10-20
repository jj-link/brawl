#include <types.h>
#pragma force_active on

struct Flags {
    u8 pad[0x1f];
    u8 a : 4;
    u8 b : 1;
    u8 c : 3;
};

extern "C" bool fn_27_111F7C(Flags** p)
{
    return (*p)->b;
}
