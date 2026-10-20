#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class soOuter {
public:
    u8 m_pad[0x18];
    soInner* m_inner;
};

extern "C" {
void fn_27_B3170(soOuter* self) {
    self->m_inner->vf1();
}
}
