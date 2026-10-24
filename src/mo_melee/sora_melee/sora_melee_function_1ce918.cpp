#pragma force_active on

struct Element {
    int field0;
    int field4;
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
    virtual unsigned int check();
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int check();
    int pad[3];
    Inner m_inner;
};

extern "C" int fn_27_1CE918(Outer* self) {
    if (self->m_inner.check() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }
    int idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)->field4 < 0x7FFF) {
        idx = self->m_inner.size() - 1;
        return self->m_inner.get(idx)->field4 + 1;
    }
    int saved;
    int i = self->m_inner.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.get(i)->field4 == 0) {
                return -1;
            }
            return self->m_inner.get(i)->field4 - 1;
        }
        saved = self->m_inner.get(i - 1)->field4;
        if (self->m_inner.get(i)->field4 - 1 > saved) {
            return self->m_inner.get(i)->field4 - 1;
        }
        i--;
    }
    return -1;
}
