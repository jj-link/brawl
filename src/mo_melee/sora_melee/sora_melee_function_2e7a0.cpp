#include <types.h>
#pragma force_active on

struct fn_27_2E7A0_Obj {
    u8 pad[0x50];
    struct {
        u8 a : 3;
        u8 bit : 1;
        u8 b : 4;
    } m_flags;
};

extern "C" {
void fn_27_2E7A0(fn_27_2E7A0_Obj* self, u32 flag) {
    self->m_flags.bit = flag;
}
}
