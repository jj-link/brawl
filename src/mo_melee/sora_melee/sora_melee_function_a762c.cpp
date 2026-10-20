#include <types.h>
#pragma force_active on

struct Inner {
    u32 pad0;
    u32 pad4;
    u32 target;
};

struct Outer {
    u32 pad0;
    Inner* ptr;
};

extern "C" void fn_27_A762C(Outer* self, u32 value) {
    self->ptr->target = value;
}
