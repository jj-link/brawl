#include <types.h>
#pragma force_active on

struct fn27Inner {
    u8 pad[0x1f];
    u8 a : 2;
    u8 b : 1;
    u8 c : 5;
};

struct fn27Outer {
    fn27Inner* inner;
};

extern "C" void fn_27_111F38(fn27Outer* self, u32 flag) {
    self->inner->b = flag;
}
