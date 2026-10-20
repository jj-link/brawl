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
};

class Outer {
public:
    u32 pad[4];
    Sub s;
};

extern "C" void fn_27_D8AC0(Outer* o) { o->s.f3(); }
