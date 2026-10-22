#pragma force_active on

class Element {
public:
    int pad;
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
    virtual unsigned int v14();
};

class Parent {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual unsigned int p5();
    int pad[3];
    Array m_array;
};

extern "C" int fn_27_11B5EC(Parent* self) {
    if (self->m_array.v14() == 1) {
        return 0x7FFF;
    }
    if (self->p5() == 1) {
        return 0;
    }
    int idx = self->m_array.size() - 1;
    if (self->m_array.get(idx)->value < 0x7FFF) {
        idx = self->m_array.size() - 1;
        return self->m_array.get(idx)->value + 1;
    }
    int saved;
    int i = self->m_array.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_array.get(i)->value == 0) {
                return -1;
            }
            return self->m_array.get(i)->value - 1;
        }
        int prev_idx = i - 1;
        saved = self->m_array.get(prev_idx)->value;
        if (self->m_array.get(i)->value - 1 > saved) {
            return self->m_array.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
