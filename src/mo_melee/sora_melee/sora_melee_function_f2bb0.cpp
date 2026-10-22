#pragma force_active on

struct Elem {
    int pad;
    int val;
};

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual Elem* get(int i);
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
    virtual unsigned int f14();
};

class Outer {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual unsigned int g5();
    char pad[0xC];
    Inner inner;
};

extern "C" int fn_27_F2BB0(Outer* self) {
    int prev;
    int j;
    int n;

    if (self->inner.f14() == 1) {
        return 0x7FFF;
    }
    if (self->g5() == 1) {
        return 0;
    }
    n = self->inner.count() - 1;
    if (self->inner.get(n)->val < 0x7FFF) {
        n = self->inner.count() - 1;
        return self->inner.get(n)->val + 1;
    }
    j = self->inner.count() - 1;
    while (j >= 0) {
        if (j == 0) {
            if (self->inner.get(j)->val == 0) {
                return -1;
            }
            return self->inner.get(j)->val - 1;
        } else {
            prev = self->inner.get(j - 1)->val;
            if (self->inner.get(j)->val - 1 > prev) {
                return self->inner.get(j)->val - 1;
            }
        }
        j--;
    }
    return -1;
}
