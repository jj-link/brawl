#pragma force_active on

class Element {
public:
    char pad[4];
    int value;
};

class Array {
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
    virtual unsigned int full();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int check();
    char pad[12];
    Array m_array;
};

extern "C" int fn_27_1C059C(Self* self) {
    if (self->m_array.full() == 1U) {
        return 0x7FFF;
    }
    if (self->check() == 1U) {
        return 0;
    }

    int index = self->m_array.size() - 1;
    if (self->m_array.get(index)->value < 0x7FFF) {
        index = self->m_array.size() - 1;
        return self->m_array.get(index)->value + 1;
    }

    int previous;
    int i = self->m_array.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_array.get(i)->value == 0) {
                return -1;
            }
            return self->m_array.get(i)->value - 1;
        }

        previous = self->m_array.get(i - 1)->value;
        if (self->m_array.get(i)->value - 1 > previous) {
            return self->m_array.get(i)->value - 1;
        }
        --i;
    }
    return -1;
}
