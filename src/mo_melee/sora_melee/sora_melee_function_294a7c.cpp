#pragma force_active on

struct Element {
    int pad;
    int value;
};

class Inner {
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
    virtual unsigned f15();
};

class Self {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual unsigned g5();

    char pad[12];
    Inner m_inner;
};

extern "C" int fn_27_294A7C(Self* self) {
    if (self->m_inner.f15() == 1) {
        return 0x7FFF;
    }
    if (self->g5() == 1) {
        return 0;
    }

    int idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)->value < 0x7FFF) {
        idx = self->m_inner.size() - 1;
        return self->m_inner.get(idx)->value + 1;
    }

    int saved;
    int i = self->m_inner.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.get(i)->value == 0) {
                return -1;
            }
            return self->m_inner.get(i)->value - 1;
        }

        saved = self->m_inner.get(i - 1)->value;
        if (self->m_inner.get(i)->value - 1 > saved) {
            return self->m_inner.get(i)->value - 1;
        }
        i--;
    }

    return -1;
}
