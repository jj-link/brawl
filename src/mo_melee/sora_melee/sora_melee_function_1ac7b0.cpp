#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct soOuter {
    u8 pad[0x10];
    soInner inner;
};

extern "C" void fn_27_1AC7B0(soOuter* p) {
    p->inner.f1();
}
