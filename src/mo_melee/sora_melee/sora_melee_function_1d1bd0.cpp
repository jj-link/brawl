#include <types.h>
#pragma force_active on

struct Obj12 {
    int f0;
    int f1;
    short h0;
    short h1;
};

class Obj {
public:
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual Obj12* vfunc(void* x) = 0;
};

extern "C" void fn_27_1D1BD0(Obj* a, void* b, void* c) {
    Obj12* r1 = a->vfunc(b);
    Obj12* r2 = a->vfunc(c);
    r2->f0 = r1->f0;
    r2->f1 = r1->f1;
    r2->h0 = r1->h0;
    r2->h1 = r1->h1;
}
