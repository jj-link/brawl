#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Container {
public:
    virtual void f0();
    virtual void f1();
    virtual Element* at(int index);
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

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int check2();
    char pad[12];
    Container m_container;
};

extern "C" int fn_27_F5D24(Obj* self) {
    if (self->m_container.check() == 1) {
        return 0x7fff;
    }
    if (self->check2() == 1) {
        return 0;
    }

    int idx = self->m_container.size() - 1;
    if (self->m_container.at(idx)->value < 0x7fff) {
        idx = self->m_container.size() - 1;
        return self->m_container.at(idx)->value + 1;
    }

    int prev;
    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.at(i)->value == 0) {
                return -1;
            }
            return self->m_container.at(i)->value - 1;
        }
        prev = self->m_container.at(i - 1)->value;
        if (self->m_container.at(i)->value - 1 > prev) {
            return self->m_container.at(i)->value - 1;
        }
        i--;
    }
    return -1;
}
