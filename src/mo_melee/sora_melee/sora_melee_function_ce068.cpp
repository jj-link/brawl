#include <types.h>
#pragma force_active on

struct S {
    u32 unk[2];
    u32 flags;
};

extern "C" void fn_27_CE068(S* self) {
    self->flags |= 0x80;
}
