#include <types.h>
#pragma force_active on

struct fnVirtC {
    virtual ~fnVirtC() { }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3(u32 p);
};

struct fnVirtB {
    u8 pad[0x64];
    fnVirtC* c;
};

struct fnVirtA {
    u8 pad[0xd8];
    fnVirtB* b;
};

struct fnVirtOuter {
    u8 pad[0x60];
    fnVirtA* a;
};

extern "C" {
s32 fn_27_29A104(void*, fnVirtOuter* o) {
    return o->a->b->c->f3(0x10000000);
}
}
