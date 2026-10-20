#include <types.h>
#pragma force_active on

class soSubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class soOuterObj {
public:
    u32 pad[4];
    soSubObj sub;
};

extern "C" {
void fn_27_D9E44(soOuterObj* self) {
    self->sub.vf3();
}
}
