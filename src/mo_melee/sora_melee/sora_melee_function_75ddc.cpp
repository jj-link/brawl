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
    virtual void vf7();
};

class soOuter {
public:
    u8 pad[0x2c];
    soInner* m_inner;
};

extern "C" void fn_27_75DDC(soOuter* self) {
    self->m_inner->vf5();
}
