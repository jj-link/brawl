#include <types.h>
#pragma force_active on

class soInnerObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class soOuterObj {
public:
    u32 m_0;
    u32 m_4;
    u32 m_8;
    soInnerObj m_inner;
};

extern "C" void fn_27_D6E28(soOuterObj* p) {
    p->m_inner.vf4();
}
