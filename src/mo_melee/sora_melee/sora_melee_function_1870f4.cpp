#include <types.h>
#pragma force_active on

struct Target {
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
    virtual void vf11();
    virtual u32 vf12();
};

struct Holder {
    u8 pad[0x40];
    Target* target;
};

struct Outer {
    u8 pad[0xd8];
    Holder* holder;
};

extern "C" u32 fn_27_1870F4(void* unused, Outer* self) {
    return self->holder->target->vf12();
}
