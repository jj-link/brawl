#include <types.h>
#pragma force_active on

struct Base1 {
    virtual void f0();
    virtual void f1();
    u32 m_a;
    u32 m_b;
    u32 m_c;
};

struct Base2 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Derived : Base1, Base2 {
};

extern "C" {
void fn_27_D9D94(Derived& p) {
    static_cast<Base2&>(p).f3();
}
}
