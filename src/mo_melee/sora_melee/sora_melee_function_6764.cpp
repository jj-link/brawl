#include <types.h>
#pragma force_active on

class SubObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(void* p);
};

struct Mid {
    u8 pad[0xc];
    SubObj* sub;
};

struct Outer {
    u8 pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_6764(void* a, Outer* b) {
    return b->mid->sub->f9(b);
}
