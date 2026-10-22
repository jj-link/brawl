#pragma force_active on

class Container {
public:
    virtual void f0();
    virtual void f1();
    virtual int* get(int index);
    virtual int count();
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
    virtual unsigned check();
};

class Self {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual unsigned s7();
    int pad0;
    int pad1;
    int pad2;
    Container m_container;
};

extern "C" int fn_27_1C7C4C(Self* self) {
    if (self->m_container.check() == 1) {
        return 0x7FFF;
    }
    if (self->s7() == 1) {
        return 0;
    }
    int idx = self->m_container.count() - 1;
    if (self->m_container.get(idx)[1] < 0x7FFF) {
        int idx2 = self->m_container.count() - 1;
        return self->m_container.get(idx2)[1] + 1;
    }
    int prev;
    int i = self->m_container.count() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.get(i)[1] == 0) {
                return -1;
            }
            return self->m_container.get(i)[1] - 1;
        }
        prev = self->m_container.get(i - 1)[1];
        if (self->m_container.get(i)[1] - 1 > prev) {
            return self->m_container.get(i)[1] - 1;
        }
        i--;
    }
    return -1;
}
