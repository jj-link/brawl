#pragma force_active on

struct Element {
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
    virtual unsigned int count();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5();

    int pad[3];
    Container m_container;
};

extern "C" int fn_27_1C5EA0(Self* self) {
    if (self->m_container.count() == 1U) {
        return 0x7FFF;
    }
    if (self->v5() == 1U) {
        return 0;
    }

    int idx = self->m_container.size() - 1;
    if (self->m_container.get(idx)->value < 0x7FFF) {
        idx = self->m_container.size() - 1;
        return self->m_container.get(idx)->value + 1;
    }

    int saved;
    int i = self->m_container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)->value == 0) {
                return -1;
            }
            return self->m_container.get(i)->value - 1;
        }

        int prev_idx = i - 1;
        saved = self->m_container.get(prev_idx)->value;
        if (self->m_container.get(i)->value - 1 > saved) {
            return self->m_container.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
