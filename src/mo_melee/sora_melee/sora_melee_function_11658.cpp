#include <types.h>
#pragma force_active on

struct fnInner {
    u8 pad0[0x0E];
    u8 m_0e;
    u8 pad1[0x20 - 0x0F];
    u8 m_20;
};

struct fnOuter {
    u8 pad0[0x28];
    fnInner* m_inner;
};

extern "C" void fn_27_11658(fnOuter* self, int flag) {
    fnInner* inner = self->m_inner;
    if (inner == 0) {
        return;
    }
    if (inner->m_20 == 0 && flag != 0) {
        inner->m_0e = 1;
    }
    inner->m_20 = flag;
}
