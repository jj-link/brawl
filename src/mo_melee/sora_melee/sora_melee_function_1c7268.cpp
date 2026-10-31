#include <types.h>
#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Container {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(unsigned int index);
    virtual unsigned int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned int v14();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5();
    char pad[0xC];
    Container m_container;
};

extern "C" int fn_27_1C7268(Self* self) {
    if (self->m_container.v14() == 1) {
        return 0x7FFF;
    }
    if (self->v5() == 1) {
        return 0;
    }

    int idx = self->m_container.size() - 1;
    if (self->m_container.get(idx)->value < 0x7FFF) {
        idx = self->m_container.size() - 1;
        return self->m_container.get(idx)->value + 1;
    }

    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->value == 0) {
                return -1;
            }
            return self->m_container.get(i)->value - 1;
        }
        if (self->m_container.get(i)->value - 1 > self->m_container.get(i - 1)->value) {
            return self->m_container.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
