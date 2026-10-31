#pragma force_active on

class Element {
public:
    int pad;
    int value;
};

class Container {
public:
    virtual void f0();
    virtual void f1();
    virtual Element* get(int index);
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
    virtual unsigned int full();
};

class Self {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int check();

    int pad[3];
    Container m_container;
};

extern "C" int fn_27_294088(Self* self) {
    if (self->m_container.full() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }

    int idx = self->m_container.size() - 1;
    if (self->m_container.get(idx)->value < 0x7FFF) {
        idx = self->m_container.size() - 1;
        return self->m_container.get(idx)->value + 1;
    }

    int prev;
    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->value == 0) {
                return -1;
            }
            return self->m_container.get(i)->value - 1;
        }
        prev = self->m_container.get(i - 1)->value;
        if (self->m_container.get(i)->value - 1 > prev) {
            return self->m_container.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
