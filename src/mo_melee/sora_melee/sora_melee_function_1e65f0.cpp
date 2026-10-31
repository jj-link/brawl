#pragma force_active on

class Element {
public:
    int pad;
    int value;
};

class Inner {
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
    virtual unsigned int v14();
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5();

    int pad0;
    int pad1;
    int pad2;
    Inner m_inner;
};

extern "C" int fn_27_1E65F0(Outer* self) {
    if (self->m_inner.v14() == 1) {
        return 0x7FFF;
    }
    if (self->v5() == 1) {
        return 0;
    }

    int idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)->value < 0x7FFF) {
        int idx2 = self->m_inner.size() - 1;
        return self->m_inner.get(idx2)->value + 1;
    }

    int prev_val;
    int i = self->m_inner.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.get(i)->value == 0) {
                return -1;
            }
            return self->m_inner.get(i)->value - 1;
        }

        prev_val = self->m_inner.get(i - 1)->value;
        if (self->m_inner.get(i)->value - 1 > prev_val) {
            return self->m_inner.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
