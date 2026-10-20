#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class soOuter {
public:
    s32 pad[2];
    soInner inner;
};

extern "C" {
void fn_27_91628(soOuter* o) {
    o->inner.f1();
}
}
