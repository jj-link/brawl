#include <types.h>
#pragma force_active on

class fn_27_D6348_Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

class fn_27_D6348_Outer {
public:
    u32 pad[3];
    fn_27_D6348_Inner inner;
};

extern "C" void fn_27_D6348(fn_27_D6348_Outer* p) {
    p->inner.v4();
}
