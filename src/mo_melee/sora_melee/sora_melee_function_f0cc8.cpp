#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void f0();
    virtual s32* f1();
};

class soOuter {
public:
    u32 m_pad[4];
    soInner m_inner;
};

extern "C" s32 fn_27_F0CC8(soOuter* self) {
    return self->m_inner.f1()[1];
}
