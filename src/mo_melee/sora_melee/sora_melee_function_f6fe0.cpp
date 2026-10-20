#include <types.h>
#pragma force_active on

class Sec {
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

class Primary {
public:
    virtual void p0();
    s32 m_a;
    s32 m_b;
    s32 m_c;
};

class Derived : public Primary, public Sec {
public:
    virtual void f13();
};

extern "C" void fn_27_F6FE0(Derived* self) {
    Sec& s = *self;
    s.f13();
}
