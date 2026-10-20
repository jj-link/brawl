#include <types.h>
#pragma force_active on

struct Flags {
    u8 pad[0x50];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
};

extern "C" void fn_27_2E7B0(Flags* self, u32 flag) {
    self->b4 = flag;
}
