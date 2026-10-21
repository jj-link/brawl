#include <types.h>
#pragma force_active on

struct S {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

class C {
public:
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual S* f26(int) = 0;
};

extern "C" void fn_27_103540(C* self, int a, int b) {
    S* src = self->f26(a);
    S* dst = self->f26(b);
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
}
