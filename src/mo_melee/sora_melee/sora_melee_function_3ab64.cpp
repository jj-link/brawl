#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x20];
    u32 f20;
    u32 f24;
};

struct Base {
    virtual void v0() = 0;
    virtual Inner* v3() = 0;
};

struct Outer {
    u8 pad[0x30];
    Base* a;
    Base* b;
};

extern "C" void fn_27_3AB64(Outer* self, u32 unused, u32 value, u32 flag) {
    if (flag == 1) {
        self->b->v3()->f20 = value;
    } else {
        self->a->v3()->f24 = value;
    }
}
