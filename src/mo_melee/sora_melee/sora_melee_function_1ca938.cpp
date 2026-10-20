#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    u8 pad[0x10];
};

extern "C" {
void fn_27_1CA938(Outer* self) {
    reinterpret_cast<Sub*>(reinterpret_cast<u8*>(self) + 0x10)->f1();
}
}
