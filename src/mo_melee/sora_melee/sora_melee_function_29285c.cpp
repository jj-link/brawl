#include <types.h>
#pragma force_active on

struct soInner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct soOuter {
    u8 pad[0x10];
    soInner inner;
};

extern "C" {
void fn_27_29285C(soOuter* p);
}

void fn_27_29285C(soOuter* p) {
    p->inner.f3();
}
