#include <types.h>
#pragma force_active on

class fn27IFace {
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
    virtual void f16();
    virtual void f17();
};

class fn27Holder {
public:
    u8 pad[0x40];
    fn27IFace* m_40;
};

class fn27Outer {
public:
    u8 pad[0xd8];
    fn27Holder* m_d8;
};

extern "C" {
void fn_27_192420(void* p1, fn27Outer* p2) {
    p2->m_d8->m_40->f15();
}
}
