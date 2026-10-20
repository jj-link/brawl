#include <types.h>
#pragma force_active on

struct fnInner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct fnOuter {
    u32 unk0;
    u32 unk4;
    fnInner* inner;
};

extern "C" {
void fn_27_DA5D8(fnOuter* p) {
    p->inner->f4();
}
}
