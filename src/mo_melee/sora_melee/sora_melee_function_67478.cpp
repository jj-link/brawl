#include <types.h>
#pragma force_active on

struct soStopModuleImpl {
    u8 m_pad[0x10];
    u32 m_10;
    u32 m_14;
    u32 m_18;
    s8 m_1c;
    void end(s32 unused);
};

void soStopModuleImpl::end(s32 unused) {
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c &= ~0xF8;
}
