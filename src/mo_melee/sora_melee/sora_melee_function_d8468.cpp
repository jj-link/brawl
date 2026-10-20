#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    u32 pad[4];
    Sub sub;
};

extern "C" {
void fn_27_D8468(Outer* p) {
    p->sub.f1();
}
}
