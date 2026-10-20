#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class fn27Outer {
public:
    s32 pad[4];
    fn27Inner m_inner;
};

extern "C" void fn_27_1CB31C(fn27Outer* p) {
    p->m_inner.vf1();
}
