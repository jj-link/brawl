#include <types.h>
#pragma force_active on

class soInnerSub {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
};

class soOuterWork {
public:
    u8 m_pad[0x10];
    soInnerSub m_sub;
};

extern "C" void fn_27_1B1598(soOuterWork* self) {
    self->m_sub.vfunc3();
}
