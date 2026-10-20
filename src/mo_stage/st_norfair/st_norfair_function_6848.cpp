#include "gm/gm_lib.h"
#pragma force_active on

struct NorfairModule
{
    int field_0x0;
    int field_0x4;
    struct
    {
        unsigned field_0x8 : 4;
        int bitfield_0xC : 2;
        unsigned field_0xE : 26;
    };
};

extern "C" int fn_54_6848(const NorfairModule *self)
{
    return self->bitfield_0xC;
}
