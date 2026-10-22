#pragma force_active on

struct Elem {
    int pad;
    int val;
};

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual Elem* get(int index);
    virtual int size();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual unsigned int f16();
};

class Outer {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual unsigned int g5();
    unsigned char pad[0xC];
    Inner m_inner;
};

extern "C" int fn_27_F17E8(Outer* self) {
    int v;
    int i;

    if (self->m_inner.f16() == 1) {
        return 0x7FFF;
    }
    if (self->g5() == 1) {
        return 0;
    }
    int n = self->m_inner.size() - 1;
    if (self->m_inner.get(n)->val < 0x7FFF) {
        n = self->m_inner.size() - 1;
        return self->m_inner.get(n)->val + 1;
    }
    for (i = self->m_inner.size() - 1; i >= 0; i--) {
        if (i == 0) {
            if (self->m_inner.get(i)->val == 0) {
                return -1;
            }
            return self->m_inner.get(i)->val - 1;
        }
        v = self->m_inner.get(i - 1)->val;
        if (self->m_inner.get(i)->val - 1 > v) {
            return self->m_inner.get(i)->val - 1;
        }
    }
    return -1;
}
