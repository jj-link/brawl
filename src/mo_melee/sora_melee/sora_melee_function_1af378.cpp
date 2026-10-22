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
    virtual unsigned v14();
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned v5();
    char pad[12];
    Inner m_inner;
};

extern "C" int fn_27_1AF378(Outer* self) {
    if (self->m_inner.v14() == 1) {
        return 0x7FFF;
    }
    if (self->v5() == 1) {
        return 0;
    }
    int idx = self->m_inner.size() - 1;
    if (self->m_inner.get(idx)[1] < 0x7FFF) {
        int idx2 = self->m_inner.size() - 1;
        return self->m_inner.get(idx2)[1] + 1;
    }
    int m = self->m_inner.size() - 1;
    while (m >= 0) {
        if (m == 0) {
            if (self->m_inner.get(m)[1] == 0) {
                return -1;
            }
            return self->m_inner.get(m)[1] - 1;
        }
        if (self->m_inner.get(m)[1] - 1 > self->m_inner.get(m - 1)[1]) {
            return self->m_inner.get(m)[1] - 1;
        }
        m--;
    }
    return -1;
}
