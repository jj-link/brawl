#include <types.h>
#pragma force_active on

struct S {
    int a;
    int b;
    s16 c;
    s16 d;
};

class C {
public:
    virtual void f00() { }
    virtual void f01() { }
    virtual void f02() { }
    virtual void f03() { }
    virtual void f04() { }
    virtual void f05() { }
    virtual void f06() { }
    virtual void f07() { }
    virtual void f08() { }
    virtual void f09() { }
    virtual void f10() { }
    virtual void f11() { }
    virtual void f12() { }
    virtual void f13() { }
    virtual void f14() { }
    virtual void f15() { }
    virtual void f16() { }
    virtual void f17() { }
    virtual void f18() { }
    virtual void f19() { }
    virtual void f20() { }
    virtual void f21() { }
    virtual void f22() { }
    virtual void f23() { }
    virtual void f24() { }
    virtual void f25() { }
    virtual S* fm(int) = 0;
};

extern "C" void fn_27_101810(C* self, int a2, int a3) {
    S* p = self->fm(a2);
    S* q = self->fm(a3);
    *q = *p;
}
