#include <types.h>
#pragma force_active on

struct fnResult {
    u32 m_0;
    u32 m_4;
};

class fnInner {
public:
    virtual void vf0();
    virtual fnResult* vf1();
};

class fnOuter {
public:
    u8 m_pad[0x10];
    fnInner m_inner;
};

extern "C" u32 fn_27_1CF1C0(fnOuter* self) {
    fnResult* result = self->m_inner.vf1();
    return result->m_4;
}
