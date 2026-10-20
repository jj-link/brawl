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

class Obj {
public:
    u32 pad[4];
    Sub sub;
};

extern "C" void fn_27_D9D24(Obj* p) {
    p->sub.f3();
}
