#include <types.h>
#pragma force_active on

class soThunkSub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class soThunkOuter {
public:
    u8 pad[0x10];
    soThunkSub sub;
};

extern "C" void fn_27_1B14A8(soThunkOuter* self) {
    self->sub.vf3();
}
