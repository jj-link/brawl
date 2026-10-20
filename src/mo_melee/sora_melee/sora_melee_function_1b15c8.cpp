#include <types.h>
#pragma force_active on

class soSubVirtual {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class soOuterHolder {
public:
    u8 pad[0x10];
    soSubVirtual sub;
};

extern "C" {
void fn_27_1B15C8(soOuterHolder* self) {
    soSubVirtual* s = &self->sub;
    s->vf3();
}
}
