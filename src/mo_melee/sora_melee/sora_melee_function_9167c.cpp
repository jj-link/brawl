#include <types.h>
#pragma force_active on

struct SubObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct OuterObj {
    u32 unk0;
    u32 unk4;
    SubObj sub;
};

extern "C" void fn_27_9167C(OuterObj* p) {
    p->sub.f4();
}
