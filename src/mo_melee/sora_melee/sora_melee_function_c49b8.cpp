#include <types.h>
#pragma force_active on

struct Inner {
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
    virtual void v10();
};

struct Outer {
    u32 pad[4];
    Inner inner;
};

extern "C" void fn_27_C49B8(Outer* self) {
    self->inner.v8();
}
