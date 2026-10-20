#include <types.h>
#pragma force_active on

struct Prim {
    virtual void g();
    s32 pad[3];
};

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer : public Prim, public Iface {
};

extern "C" void fn_27_F6280(Outer* p) {
    p->f1();
}
