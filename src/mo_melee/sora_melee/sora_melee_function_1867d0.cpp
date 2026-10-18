#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void* f15();
};

struct fn27Mid {
    u8 pad[0x40];
    fn27Inner* inner;
};

struct fn27Outer {
    u8 pad[0xd8];
    fn27Mid* mid;
};

extern "C" {
void* fn_27_1867D0(void* unused, fn27Outer* obj) {
    return obj->mid->inner->f15();
}
}
