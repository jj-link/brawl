#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class Outer {
public:
    u32 m_pad[3];
    Inner m_inner;
};

extern "C" void fn_27_1AAB4C(Outer* self) {
    Inner* p = &self->m_inner;
    p->vf4();
}
