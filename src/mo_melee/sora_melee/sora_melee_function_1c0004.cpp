#include <types.h>
#pragma force_active on

class fn_27_Inner {
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

struct fn_27_Outer {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    fn_27_Inner inner;
};

extern "C" void fn_27_1C0004(fn_27_Outer* p) {
    p->inner.f8();
}
