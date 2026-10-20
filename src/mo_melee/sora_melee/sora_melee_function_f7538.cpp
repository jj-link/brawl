#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};

class Outer {
public:
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    Sub sub;
};

extern "C" {
void fn_27_F7538(Outer* p) {
    p->sub.f8();
}
}
