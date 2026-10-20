#include <types.h>
#pragma force_active on

struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

struct Owner {
    u32 pad[4];
    Iface sub;
};

extern "C" void fn_27_1CC5D4(Owner* p) {
    p->sub.v8();
}
