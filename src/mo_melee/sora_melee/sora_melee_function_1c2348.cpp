#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual int* get(int index);
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

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned check();
    int pad[3];
    Inner m_inner;
};

extern "C" int fn_27_1C2348(Outer* self) {
    if (self->m_inner.check() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }
    int idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)[1] < 0x7FFF) {
        int idx2 = self->m_inner.size() - 1;
        return self->m_inner.get(idx2)[1] + 1;
    }
    int saved;
    int i = self->m_inner.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.get(i)[1] == 0) {
                return -1;
            }
            return self->m_inner.get(i)[1] - 1;
        }
        saved = self->m_inner.get(i - 1)[1];
        if (self->m_inner.get(i)[1] - 1 > saved) {
            return self->m_inner.get(i)[1] - 1;
        }
        i--;
    }
    return -1;
}
