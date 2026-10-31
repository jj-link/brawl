#include <types.h>
#pragma force_active on

struct Item {
    int pad;
    int value;
};

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual Item* f2(int index);
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

class Outer {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int f5();

    char pad[0xC];
    Inner m_inner;
};

extern "C" int fn_27_1CCB6C(Outer* self) {
    if (self->m_inner.f14() == 1) {
        return 0x7FFF;
    }
    if (self->f5() == 1) {
        return 0;
    }

    int idx = self->m_inner.f3() - 1;
    if (self->m_inner.f2(idx)->value < 0x7FFF) {
        idx = self->m_inner.f3() - 1;
        return self->m_inner.f2(idx)->value + 1;
    }

    int prev;
    int i = self->m_inner.f3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.f2(i)->value == 0) {
                return -1;
            }
            return self->m_inner.f2(i)->value - 1;
        }
        prev = self->m_inner.f2(i - 1)->value;
        if (self->m_inner.f2(i)->value - 1 > prev) {
            return self->m_inner.f2(i)->value - 1;
        }
        i--;
    }
    return -1;
}
