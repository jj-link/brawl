#pragma force_active on

class Element {
public:
    int pad;
    int value;
};

class Container {
public:
    virtual void p0();
    virtual void p1();
    virtual Element* get(int index);
    virtual int size();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual unsigned int check();
};

class Outer {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual unsigned int o7();
    int pad[3];
    Container m_container;
};

extern "C" int fn_27_1C0F80(Outer* self) {
    if (self->m_container.check() == 1) {
        return 0x7FFF;
    }
    if (self->o7() == 1) {
        return 0;
    }

    int lastIndex = self->m_container.size() - 1;
    if (self->m_container.get(lastIndex)->value < 0x7FFF) {
        int nextIndex = self->m_container.size() - 1;
        return self->m_container.get(nextIndex)->value + 1;
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
