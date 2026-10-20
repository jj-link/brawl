#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 pad[4];
    Inner inner;
};

extern "C" void fn_27_1BD984(Outer* o) {
    o->inner.f1();
}
