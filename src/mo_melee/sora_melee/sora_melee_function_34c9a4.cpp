#include <types.h>
#pragma force_active on

struct fn27Holder {
    u8 pad[0x18];
    s32 m_18;
    u8 pad2[0x68 - 0x1C];
    void* m_68[1];
};

extern "C" void* fn_27_34C9A4(fn27Holder* self, u32 unused, u32 idx) {
    return self->m_68[idx - self->m_18];
}
