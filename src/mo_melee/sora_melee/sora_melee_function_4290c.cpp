#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_3786C(u32);

struct fn_27_4290C_Obj {
    u8 pad[0x2c];
    u32 m_flag;
};

void fn_27_4290C(fn_27_4290C_Obj* self, u32 index) {
    self->m_flag = 1 << fn_27_3786C(index);
}
}
