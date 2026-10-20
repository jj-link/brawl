#include <types.h>
#pragma force_active on

class Sub {
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
};

class Outer {
public:
    u32 pad[4];
    Sub sub;
};

extern "C" {
void fn_27_1ABC7C(Outer* p) {
    p->sub.f8();
}
}
