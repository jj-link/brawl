#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

class fn27Outer {
public:
    u32 pad0;
    u32 pad4;
    fn27Inner* inner;
};

extern "C" {
void fn_27_DA858(fn27Outer* p);
}

extern "C" void fn_27_DA858(fn27Outer* p) {
    p->inner->v4();
}
