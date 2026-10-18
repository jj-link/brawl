#include <types.h>
#pragma force_active on

struct Flags {
    u32 pad[2];
    u32 flags;

    Flags& operator|=(u32 bits) {
        flags = flags | bits;
        return *this;
    }
};

extern "C" void fn_103_F730(Flags* self)
{
    *self |= 0x2000;
}