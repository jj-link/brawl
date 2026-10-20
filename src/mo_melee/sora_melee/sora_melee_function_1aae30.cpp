#include <types.h>
#pragma force_active on

class fn27_Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class fn27_Outer {
public:
    u32 m_pad[3];
    fn27_Inner m_inner;
};

extern "C" {
void fn_27_1AAE30(fn27_Outer* self) {
    self->m_inner.vf4();
}
}
