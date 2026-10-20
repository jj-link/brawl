#include <types.h>
#pragma force_active on

class Prim {
public:
    u32 m_data[4];
};

class Iface {
public:
    virtual ~Iface();
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
};

class Derived : public Prim, public Iface {
public:
    virtual void f12();
};

extern "C" {
void fn_27_F20C0(Derived* p) {
    Iface& r = *p;
    r.f12();
}
}
