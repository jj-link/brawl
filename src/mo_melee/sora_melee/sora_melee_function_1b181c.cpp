#include <types.h>
#pragma force_active on

class IFoo {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

class Outer {
public:
    u32 m_0;
    u32 m_4;
    IFoo* m_8;
};

extern "C" void fn_27_1B181C(Outer* p) {
    p->m_8->v4();
}
