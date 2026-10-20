#include <types.h>
#pragma force_active on

struct FlagHolder {
    u8 pad[0x10];
    u32 m_bits0;
    u32 m_bits1;
};

extern "C" void fn_27_7B560(FlagHolder* self, s32 idx, u32 flag) {
    if (idx <= -1 || idx >= 0x11) {
        return;
    }
    u32 bit = 1 << idx;
    self->m_bits0 |= bit;
    if (flag == 1) {
        self->m_bits1 |= bit;
    } else {
        self->m_bits1 &= ~bit;
    }
}
