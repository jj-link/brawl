#include <types.h>
#pragma force_active on

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v10(u32 arg);
};

struct Mid {
    u8 pad[0x64];
    Base* base;
};

struct Outer {
    u8 pad[0xD8];
    Mid* mid;
};

extern "C" {
void fn_27_170A84(void* p1, Outer* p2) {
    p2->mid->base->v10(0x20000000);
}
}
