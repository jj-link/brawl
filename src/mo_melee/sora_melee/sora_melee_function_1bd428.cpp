#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Sub {
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

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned self_check();

    char pad[12];
    Sub m_sub;
};

extern "C" int fn_27_1BD428(Self* self) {
    if (self->m_sub.check() == 1)
        return 0x7FFF;

    if (self->self_check() == 1)
        return 0;

    int index = self->m_sub.size() - 1;
    if (self->m_sub.get(index)->value < 0x7FFF) {
        index = self->m_sub.size() - 1;
        return self->m_sub.get(index)->value + 1;
    }

    int previous;
    int i = self->m_sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_sub.get(i)->value == 0)
                return -1;
            return self->m_sub.get(i)->value - 1;
        }

        previous = self->m_sub.get(i - 1)->value;
        if (self->m_sub.get(i)->value - 1 > previous)
            return self->m_sub.get(i)->value - 1;

        i--;
    }

    return -1;
}
