#include <types.h>
#pragma force_active on

struct Flags {
    u32 pad[2];
    u32 hi : 8;
    u32 nib : 4;
    u32 lo : 20;
};

extern "C" void fn_27_1993E8(Flags *obj, u32 val)
{
    obj->nib = val;
}
