#include <types.h>
#pragma force_active on

extern "C" void* fn_27_14D594();

struct soSora_109318 {
    u8 pad_00[0x6c];
    u8 m_6c;
    u8 pad_6d[0x6f - 0x6d];
    u8 m_6f;
    u8 pad_70[0x78 - 0x70];
    void* m_78;
};

extern "C" {
void fn_27_109318(soSora_109318* self) {
    self->m_6c |= 0x40;
    self->m_6c &= ~0x20;
    self->m_6f &= ~0x40;
    self->m_78 = fn_27_14D594();
}
}
