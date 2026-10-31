#pragma force_active on

struct Element {
    int a;
    int value;
};

class Container {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(int index);
    virtual int size();
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
    virtual unsigned check();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned check();
    int pad0;
    int pad1;
    int pad2;
    Container m_container;
};

extern "C" int fn_27_FC9F0(Owner* self) {
    if (self->m_container.check() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }
    int index = self->m_container.size() - 1;
    if (self->m_container.get(index)->value < 0x7FFF) {
        index = self->m_container.size() - 1;
        return self->m_container.get(index)->value + 1;
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
