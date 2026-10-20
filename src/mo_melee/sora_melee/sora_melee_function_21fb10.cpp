#include <types.h>
#pragma force_active on

struct Inner {
    char pad[0x168];
    u32 flags;
};

struct Outer {
    Inner* inner;
};

extern "C" bool fn_27_21FB10(Outer* self, u32 bit) {
    return (self->inner->flags & (1u << bit)) != 0;
}
