#include <types.h>
#pragma force_active on

struct FnBase {
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f20(u32 a, u32 b, u16* c, s32 d);
};

extern "C" void fn_27_84748(FnBase* self, u32 a, u32 b) {
    u16 tmp = 0;
    self->f20(a, b, &tmp, -1);
}
