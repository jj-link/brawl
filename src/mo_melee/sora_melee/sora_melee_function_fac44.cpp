#include <types.h>
#pragma force_active on

struct Element {
    int pad0;
    int value;
};

class Obj {
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
    virtual int f14();
};

class Self {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();
    char pad[12];
    Obj m_obj;
};

extern "C" int fn_27_FAC44(Self* self) {
    if (self->m_obj.f14() == 1U) {
        return 0x7FFF;
    }
    if (self->f5() == 1U) {
        return 0;
    }
    int n = self->m_obj.f3() - 1;
    if (self->m_obj.f2(n)->value < 0x7FFF) {
        n = self->m_obj.f3() - 1;
        return self->m_obj.f2(n)->value + 1;
    }
    int prev;
    for (int i = self->m_obj.f3() - 1; i >= 0; i--) {
        if (i == 0) {
            if (self->m_obj.f2(i)->value == 0) {
                return -1;
            }
            return self->m_obj.f2(i)->value - 1;
        }
        prev = self->m_obj.f2(i - 1)->value;
        if (self->m_obj.f2(i)->value - 1 > prev) {
            return self->m_obj.f2(i)->value - 1;
        }
    }
    return -1;
}
