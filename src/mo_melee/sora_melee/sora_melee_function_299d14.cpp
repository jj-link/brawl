#include <types.h>
#pragma force_active on

struct fnVirtIface {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4(u32 p);
};

struct fnMidB {
    u8 pad[0x64];
    fnVirtIface* iface;
};

struct fnMidA {
    u8 pad[0xd8];
    fnMidB* b;
};

struct fnOwner {
    u8 pad[0x60];
    fnMidA* a;
};

extern "C" {
u32 fn_27_299D14(void* unused, fnOwner* owner) {
    return owner->a->b->iface->vf4(0x10000000);
}
}
