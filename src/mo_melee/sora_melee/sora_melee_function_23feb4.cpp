#include <types.h>
#pragma force_active on

struct FnInner {
    u8 pad0[0x1a];
    u16 m1a;
    u8 m1c;
};

struct FnOuter {
    u8 pad0[0x40];
    FnInner* m40;
    u8 pad1[0x47 - 0x44];
    u8 m47;
    u8 pad2[0x8c - 0x48];
    u32 m8c;
    u32 m90;
};

extern "C" bool fn_27_23FEB4(FnOuter* self) {
    if (self->m47 == 1 || self->m8c != self->m40->m1a || self->m90 != self->m40->m1c) {
        return true;
    }
    return false;
}
