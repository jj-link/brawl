#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    u32 pad[4];
    Inner inl;
};

extern "C" void fn_27_1C5A18(Outer* p) {
    Inner& r = p->inl;
    r.f1();
}
