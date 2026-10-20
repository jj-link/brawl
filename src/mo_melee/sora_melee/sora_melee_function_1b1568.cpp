#include <types.h>
#pragma force_active on

class fn27Iface {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};

class fn27Base {
public:
    virtual void g0();
    u32 pad[3];
};

class fn27Derived : public fn27Base, public fn27Iface {
public:
    virtual void f7();
};

extern "C" void fn_27_1B1568(fn27Derived* self) {
    fn27Iface& r = *self;
    r.f5();
}
