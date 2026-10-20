#include <types.h>
#pragma force_active on

class SubIface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

class Outer {
public:
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_c;
    SubIface m_sub;
};

extern "C" void fn_27_1AD090(Outer* p) {
    SubIface* s = &p->m_sub;
    s->vf8();
}
