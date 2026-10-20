#include <types.h>
#pragma force_active on

class Iface {
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
};

struct Outer {
    u32 pad[4];
    Iface inner;
};

extern "C" void fn_27_F6B54(Outer* p) {
    p->inner.f8();
}
