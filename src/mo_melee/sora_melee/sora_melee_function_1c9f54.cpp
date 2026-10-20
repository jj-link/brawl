#include <types.h>
#pragma force_active on

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 pad[4];
    Sub sub;
};

extern "C" void fn_27_1C9F54(Outer* p) {
    p->sub.f1();
}
