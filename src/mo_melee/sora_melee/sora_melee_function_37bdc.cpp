#include <types.h>
#pragma force_active on

extern "C" void fn_27_38064();

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 pad[2];
    Inner* inner;
};

extern "C" void fn_27_37BDC(Outer* p) {
    p->inner->f1();
    fn_27_38064();
}
