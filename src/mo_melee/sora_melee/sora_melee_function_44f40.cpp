#include <types.h>
#pragma force_active on

extern "C" void fn_27_428E0();

class soInnerWork {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
};

class soOuterWork {
public:
    u8 m_pad[0x58];
    soInnerWork* m_inner;
};

extern "C" void fn_27_44F40(soOuterWork* self) {
    self->m_inner->vfunc1();
    fn_27_428E0();
}
