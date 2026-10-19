#include <types.h>
#pragma force_active on

struct fn_27_301A0_Inner {
    u8 pad_0[0x70];
    u8 flags;
};

struct fn_27_301A0_Outer {
    u32 pad_0;
    fn_27_301A0_Inner* inner;
};

extern "C" void fn_27_301A0(fn_27_301A0_Outer* self, u8* a, u8* b, u8* c, u8* d) {
    fn_27_301A0_Inner* in = self->inner;
    *a = (in->flags >> 7) & 1;
    *b = (in->flags >> 6) & 1;
    *c = (in->flags >> 5) & 1;
    *d = (in->flags >> 4) & 1;
}
