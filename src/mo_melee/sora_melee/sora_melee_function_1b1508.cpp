#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

class Outer {
public:
    virtual void dummy();
    u32 a;
    u32 b;
    u32 c;
    Sub sub;
};

extern "C" {
void fn_27_1B1508(Outer* self) {
    Sub* p = &self->sub;
    p->v3();
}
}
