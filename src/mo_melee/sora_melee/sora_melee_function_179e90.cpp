#include <types.h>
#pragma force_active on

class fn27VirtTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11(s32 value);
};

struct fn27Mid {
    u8 pad[0x40];
    fn27VirtTarget* target;
};

struct fn27Outer {
    u8 pad[0xd8];
    fn27Mid* mid;
};

extern "C" {
void fn_27_179E90(void* unused, fn27Outer* self) {
    self->mid->target->vf11(0x3f);
}
}
