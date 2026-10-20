#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Outer {
    u32 pad0;
    u32 pad4;
    Inner* inner;
};

extern "C" {
void fn_27_DA2B8(Outer* p) {
    p->inner->v4();
}
}
