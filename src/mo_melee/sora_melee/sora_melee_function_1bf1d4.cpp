#include <types.h>
#pragma force_active on

struct Entry {
    int pad;
    int value;
};

class Container {
public:
    virtual void c0();
    virtual void c1();
    virtual Entry* c2(int index);
    virtual int c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual unsigned c14();
};

class Outer {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual unsigned o5();
    int pad[3];
    Container m_container;
};

extern "C" int fn_27_1BF1D4(Outer* self) {
    if (self->m_container.c14() == 1) {
        return 0x7FFF;
    }
    if (self->o5() == 1) {
        return 0;
    }

    int n = self->m_container.c3() - 1;
    if (self->m_container.c2(n)->value < 0x7FFF) {
        n = self->m_container.c3() - 1;
        return self->m_container.c2(n)->value + 1;
    }

    int saved;
    int i = self->m_container.c3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.c2(i)->value == 0) {
                return -1;
            }
            return self->m_container.c2(i)->value - 1;
        }
        saved = self->m_container.c2(i - 1)->value;
        if (self->m_container.c2(i)->value - 1 > saved) {
            return self->m_container.c2(i)->value - 1;
        }
        i--;
    }
    return -1;
}
