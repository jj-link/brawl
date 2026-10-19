#include <types.h>
#pragma force_active on

extern "C" void fn_27_30130();

class soInnerWork {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
};

class soOuterWork {
public:
    u8 pad[0x28];
    soInnerWork* m_inner;
};

extern "C" void fn_27_2A390(soOuterWork* self) {
    self->m_inner->vfunc1();
    fn_27_30130();
}
