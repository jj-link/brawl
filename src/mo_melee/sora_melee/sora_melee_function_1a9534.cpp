#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct Outer {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Inner in;
};

extern "C" {
void fn_27_1A9534(Outer* self) {
    self->in.f4();
}
}
