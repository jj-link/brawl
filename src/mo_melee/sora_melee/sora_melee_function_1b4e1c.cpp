#include <types.h>
#pragma force_active on

struct Pair {
    int a, b;
};

class Data {
public:
    Pair p;
    int c;
    float d;
};

class Obj {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
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
    virtual Data* get(Obj*);
};

extern "C" void fn_27_1B4E1C(Obj* self, Obj* x, Obj* other) {
    Data* a = self->get(x);
    Data* b = self->get(other);
    *b = *a;
}
