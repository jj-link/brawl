#include <types.h>
#pragma force_active on

class soSubVirtual {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class soOuterWork {
public:
    u8 pad[0x10];
    soSubVirtual sub;
};

extern "C" {
void fn_27_1B1448(soOuterWork* p) {
    p->sub.f3();
}
}
