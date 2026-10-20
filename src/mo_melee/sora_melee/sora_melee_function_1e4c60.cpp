#include <types.h>
#pragma force_active on

struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual s32 f8();
    virtual void f9();
    virtual void f10();
};

struct A {
    virtual void a();
    u32 pad[3];
};

struct D : public A, public B {
};

extern "C" {
s32 fn_27_1E4C60(D& p) {
    return ((B&)p).f8();
}
}
