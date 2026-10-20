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
    u8 pad[8];
    Inner* inner;
};

extern "C" {
void fn_27_11B84C(Outer* p) {
    p->inner->v4();
}
}
