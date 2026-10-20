#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

class Outer {
public:
    s32 pad[3];
    Obj obj;
};

extern "C" {
void fn_27_D6A88(Outer* self) {
    self->obj.v4();
}
}
