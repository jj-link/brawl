#pragma force_active on

struct Element {
    int a;
    int b;
};

class SubObj {
public:
    virtual void f0();
    virtual void f1();
    virtual Element* get(int i);
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
    virtual unsigned f14();
};

class MainObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned f5();

    int pad0_04;
    int pad0_08;
    int pad0_0C;
    SubObj m_sub;
};

extern "C" int fn_27_FA260(MainObj* self) {
    if (self->m_sub.f14() == 1) {
        return 0x7FFF;
    }

    if (self->f5() == 1) {
        return 0;
    }

    int idx = self->m_sub.size() - 1;
    if (self->m_sub.get(idx)->b < 0x7FFF) {
        idx = self->m_sub.size() - 1;
        return self->m_sub.get(idx)->b + 1;
    }

    int prev;
    int i = self->m_sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_sub.get(i)->b == 0) {
                return -1;
            }
            return self->m_sub.get(i)->b - 1;
        }

        prev = self->m_sub.get(i - 1)->b;
        if (self->m_sub.get(i)->b - 1 > prev) {
            return self->m_sub.get(i)->b - 1;
        }
        i--;
    }

    return -1;
}
