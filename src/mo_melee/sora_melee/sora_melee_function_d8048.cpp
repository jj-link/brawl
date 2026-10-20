#include <types.h>
#pragma force_active on

struct fn_27_D8048_Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct fn_27_D8048_Outer {
    u8 pad[0xc];
    fn_27_D8048_Sub sub;
};

extern "C" void fn_27_D8048(fn_27_D8048_Outer* p) {
    p->sub.f4();
}
