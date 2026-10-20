#include <types.h>
#pragma force_active on

class fn27Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

class fn27Outer {
public:
    u8 pad[0x10];
    fn27Base m_base;
};

extern "C" void fn_27_10E470(fn27Outer* p) {
    fn27Base* b = &p->m_base;
    b->v3();
}
