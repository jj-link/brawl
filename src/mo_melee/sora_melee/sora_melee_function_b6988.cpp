#include <types.h>
#pragma force_active on

struct Flags44 {
    u8 pad_[0x44];
    u8 hi_ : 4;
    u8 f_ : 2;
    u8 lo_ : 2;
};

extern "C" {
void fn_27_B6988(Flags44* self, u32 val) {
    self->f_ = val;
}
}
