#pragma force_active on

struct Elem {
    int pad0;
    int val;
};

class Container {
public:
    virtual void f0();
    virtual void f1();
    virtual Elem* f2(int idx);
    virtual int f3();
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
    virtual unsigned f14();
};

class Self {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual unsigned s5();
    char pad[12];
    Container m_container;
};

extern "C" int fn_27_1BC060(Self* self) {
    if (self->m_container.f14() == 1U) {
        return 0x7FFF;
    }
    if (self->s5() == 1U) {
        return 0;
    }

    int idx = self->m_container.f3() - 1;
    Elem* elem = self->m_container.f2(idx);
    if (elem->val < 0x7FFF) {
        int idx2 = self->m_container.f3() - 1;
        elem = self->m_container.f2(idx2);
        return elem->val + 1;
    }

    int pv;
    int i = self->m_container.f3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_container.f2(i)->val == 0) {
                return -1;
            }
            return self->m_container.f2(i)->val - 1;
        }
        pv = self->m_container.f2(i - 1)->val;
        if (self->m_container.f2(i)->val - 1 > pv) {
            return self->m_container.f2(i)->val - 1;
        }
        i--;
    }
    return -1;
}