#include <types.h>
#pragma force_active on

class soSubObject {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
};

class soOwner {
public:
    u8 m_pad[0x16fc];
    soSubObject m_sub;
};

extern "C" {
void fn_27_3371D0(soOwner* self) {
    soSubObject* p = &self->m_sub;
    p->vfunc6();
}
}
