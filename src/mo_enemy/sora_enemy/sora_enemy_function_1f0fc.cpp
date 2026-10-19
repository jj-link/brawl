#include <types.h>
#pragma force_active on

struct Iface {
    virtual void f0();
    virtual u32* f1();
    virtual void f2();
    virtual void f3();
};

struct Owner {
    u8 pad[0xc8];
    Iface* iface;
};

extern "C" u32 fn_41_1F0FC(Owner* self) {
    return *self->iface->f1();
}
