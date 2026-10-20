#include <types.h>
#pragma force_active on

class fn27SubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class fn27Outer {
public:
    u32 pad[4];
    fn27SubObj sub;
};

extern "C" {
void fn_27_1ABDE8(fn27Outer* self) {
    self->sub.vf3();
}
}
