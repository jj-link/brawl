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
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    Sub sub;
};

extern "C" void fn_27_1C5034(Outer* o) {
    Sub* s = &o->sub;
    s->f1();
}
