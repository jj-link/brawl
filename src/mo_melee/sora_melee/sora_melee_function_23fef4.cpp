#include <types.h>
#pragma force_active on
extern "C" {
struct FnInner {
    u8 pad0[0x1a];
    u16 m1a;
    u8 m1c;
};

struct FnOuter {
    u8 pad0[0x40];
    FnInner* m40;
    u8 pad1[0x8c - 0x44];
    u32 m8c;
    u32 m90;
};

bool fn_27_23ABA0(void* self);

bool fn_27_23FEF4(FnOuter* self) {
    if (self->m8c != self->m40->m1a || self->m90 != self->m40->m1c) {
        return false;
    }
    void* arg = self;
    return fn_27_23ABA0(arg);
}
}
