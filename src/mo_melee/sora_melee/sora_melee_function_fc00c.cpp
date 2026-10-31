#pragma force_active on

struct Element {
    int pad;
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
    virtual unsigned int count();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int check();
    int pad[3];
    Container m_container;
};

extern "C" int fn_27_FC00C(Owner* self) {
    if (self->m_container.count() == 1U)
        return 0x7FFF;

    if (self->check() == 1U)
        return 0;

    int idx = self->m_container.size() - 1;
    if (self->m_container.get(idx)->value < 0x7FFF) {
        idx = self->m_container.size() - 1;
        return self->m_container.get(idx)->value + 1;
    }

    int saved;
    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->value == 0)
                return -1;
            return self->m_container.get(i)->value - 1;
        }

        saved = self->m_container.get(i - 1)->value;
        if (self->m_container.get(i)->value - 1 > saved)
            return self->m_container.get(i)->value - 1;

        i--;
    }

    return -1;
}
