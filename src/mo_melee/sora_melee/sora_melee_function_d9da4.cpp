#include <types.h>
#pragma force_active on

class fn27Sub {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
};

class fn27Outer {
public:
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_c;
    fn27Sub m_10;
};

extern "C" void fn_27_D9DA4(fn27Outer* p) {
    p->m_10.vfn3();
}
