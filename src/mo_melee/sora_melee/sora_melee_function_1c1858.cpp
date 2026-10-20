#include <types.h>
#pragma force_active on

class fn27Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
};

class fn27Outer {
public:
    u8 m_pad[0x10];
    fn27Sub m_sub;
};

extern "C" {
void fn_27_1C1858(fn27Outer* p) {
    p->m_sub.f13();
}
}
