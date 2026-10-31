#include <types.h>
#pragma force_active on

struct Node {
    int pad;
    int value;
};

class Container {
public:
    virtual void f0();
    virtual void f1();
    virtual Node* get(int index);
    virtual int size();
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
    virtual unsigned int check();
};

class Owner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int check();
    char pad[12];
    Container m_container;
};

extern "C" int fn_27_1ADFA8(Owner* self) {
    if (self->m_container.check() == 1)
        return 0x7FFF;
    if (self->check() == 1)
        return 0;

    int index = self->m_container.size() - 1;
    if (self->m_container.get(index)->value < 0x7FFF) {
        index = self->m_container.size() - 1;
        return self->m_container.get(index)->value + 1;
    }

    int previous;
    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->value == 0)
                return -1;
            return self->m_container.get(i)->value - 1;
        }
        previous = self->m_container.get(i - 1)->value;
        if (self->m_container.get(i)->value - 1 > previous)
            return self->m_container.get(i)->value - 1;
        i--;
    }
    return -1;
}
