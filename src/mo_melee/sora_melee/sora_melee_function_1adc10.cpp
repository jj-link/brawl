#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class Pad {
public:
    virtual void p0();
    u32 a, b, c;
};

class Outer : public Pad, public Sub {
public:
    virtual void f5();
};

extern "C" {
void fn_27_1ADC10(Outer* self) {
    Sub& s = *self;
    s.f3();
}
}
