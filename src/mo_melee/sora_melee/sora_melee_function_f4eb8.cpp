#include <types.h>
#pragma force_active on

class soGeneralWorkVirtualBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class soGeneralWorkOuter {
public:
    u8 m_pad[0x10];
    soGeneralWorkVirtualBase m_base;
};

extern "C" void fn_27_F4EB8(soGeneralWorkOuter* self) {
    self->m_base.vf1();
}
