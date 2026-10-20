#include <types.h>
#pragma force_active on

class Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 a[4];
    Iface iface;
};

extern "C" void fn_27_2945E4(Outer* p) {
    Iface* i = &p->iface;
    i->f1();
}
