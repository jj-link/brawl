#include <types.h>
#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual Element* f2(int index);
    virtual int f3();
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
    virtual unsigned int f14();
};

class OuterBase {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual unsigned int g5();
};

class Outer : public OuterBase {
public:
    int pad0;
    int pad1;
    int pad2;
    Inner inner;
};

extern "C" int fn_27_1CADC0(Outer* self) {
    if (self->inner.f14() == 1U) {
        return 0x7FFF;
    }
    if (self->g5() == 1U) {
        return 0;
    }

    int idx = self->inner.f3() - 1;
    if (self->inner.f2(idx)->value < 0x7FFF) {
        idx = self->inner.f3() - 1;
        return self->inner.f2(idx)->value + 1;
    }

    int prev;
    int i = self->inner.f3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->inner.f2(i)->value == 0) {
                return -1;
            }
            return self->inner.f2(i)->value - 1;
        }

        prev = self->inner.f2(i - 1)->value;
        int curr = self->inner.f2(i)->value;
        if (curr - 1 > prev) {
            return self->inner.f2(i)->value - 1;
        }
        i--;
    }
    return -1;
}
