#include <types.h>
#pragma force_active on

class soBaseB {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class soBaseA {
public:
    virtual void g0();
    u32 m_a;
    u32 m_b;
    u32 m_c;
};

class soDerived : public soBaseA, public soBaseB {
public:
    virtual void h0();
};

extern "C" {
void fn_27_EFF98(soDerived& self) {
    ((soBaseB&)self).f1();
}
}
