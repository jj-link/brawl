#include <types.h>
#pragma force_active on

struct UnkObj27 {
    u8 pad[0x10];
    u32 m10;
    bool m14;
};

extern "C" {
void fn_27_C3360(UnkObj27* self, u32 val) {
    self->m10 = val;
    self->m14 = true;
}
}
