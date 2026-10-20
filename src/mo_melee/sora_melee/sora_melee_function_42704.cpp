#include <types.h>
#pragma force_active on

struct FnObj27 {
    u8 pad_00[0x20];
    s32 m_20;
    s32 m_24;
    s32 m_28;
    u8 pad_2c[0x31 - 0x2c];
    u8 m_31;
    u8 m_32;
};

extern "C" {
void fn_27_42704(FnObj27* self) {
    self->m_32 = 0;
    u32 r = self->m_32;
    if (self->m_31 == 1 || self->m_24 != 0) {
        self->m_20 = 2;
        return;
    }
    if (r == 1 || self->m_28 != 0) {
        self->m_20 = 1;
        return;
    }
    self->m_20 = r;
}
}
