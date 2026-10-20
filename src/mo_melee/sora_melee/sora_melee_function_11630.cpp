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

extern "C" bool fn_27_11630(fnOuter* self) {
    fnInner* inner = self->m_inner;
    if (inner) {
        return inner->m_20 != 0;
    }
    return false;
}
