#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class soOuter {
public:
    s32 pad[3];
    soInner m_inner;
};

extern "C" {
void fn_27_D6518(soOuter* self) {
    self->m_inner.vf4();
}
}
