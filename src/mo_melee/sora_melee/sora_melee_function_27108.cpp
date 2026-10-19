#include <types.h>
#pragma force_active on

class soInnerWork {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

class soOuterWork {
public:
    u8 pad[0x28];
    soInnerWork* m_inner;
};

extern "C" void fn_27_2EF68();

extern "C" void fn_27_27108(soOuterWork* self) {
    self->m_inner->vfunc1();
    fn_27_2EF68();
}
