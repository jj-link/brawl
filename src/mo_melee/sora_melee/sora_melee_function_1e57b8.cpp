#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class Base0 {
public:
    virtual void g0();
    u32 pad[3];
};

class Derived : public Base0, public Inner {
public:
};

extern "C" {
void fn_27_1E57B8(Derived& p) {
    Inner& r = p;
    r.f5();
}
}
