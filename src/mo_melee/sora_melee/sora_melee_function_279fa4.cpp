#include <types.h>
#pragma force_active on

struct FooInner {
    u32 unk0;
    u32 flags;
};

struct FooOuter {
    u8 pad[0xd4];
    FooInner* inner;
};

extern "C" void fn_27_279FA4(FooOuter* self) {
    FooInner* p = self->inner;
    p->flags = p->flags & ~7;
    self->inner->flags = self->inner->flags | 8;
}
