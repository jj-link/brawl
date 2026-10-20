#include <types.h>
#pragma force_active on

struct Fn6A1D4Obj {
    u8 pad[0x34];
    u8 f0 : 6;
    u8 f1 : 1;
    u8 f2 : 1;
};

extern "C" {
void fn_27_6A1D4(Fn6A1D4Obj* self, u32 flag) {
    self->f1 = flag;
}
}
