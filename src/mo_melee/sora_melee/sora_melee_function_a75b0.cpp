#include <types.h>
#pragma force_active on

struct Fn27Inner {
    u8 pad[0x10];
    void* m_target;
};

struct Fn27Outer {
    u32 m_unk0;
    Fn27Inner* m_inner;
    u8 m_pad8[0x15];
    u8 m_flags;
};

extern "C" {
void* fn_27_A75B0(Fn27Outer* self) {
    if ((self->m_flags >> 6) & 1) {
        return self->m_inner->m_target;
    }
    return 0;
}
}
