#include <types.h>
#pragma force_active on

struct First {
    virtual void f0();
};

struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v12(u32* p);
};

struct Outer : public First, public Iface {
};

extern "C" {
void fn_27_C41B0(Outer* self, u32 x) {
    self->v12(&x);
}
}
