#include <types.h>
#pragma force_active on

class A {
public:
    virtual void a();
    u32 pad[3];
};

class B2 {
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
};

class D : public A, public B2 {
public:
    virtual void a();
};

extern "C" void fn_27_1C53B0(D* p) {
    p->f13();
}
