#pragma force_active on

struct Elem {
    int pad;
    int value;
};

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual Elem* f2(int) const;
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
    virtual bool f14();
};

class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool f5();
};

class Outer : public Base {
public:
    int pad0;
    int pad1;
    int pad2;
    Inner inner;
};

extern "C" int fn_27_F987C(Outer* self) {
    if (self->inner.f14() == 1)
        return 0x7fff;
    if (self->f5() == 1)
        return 0;

    int index = self->inner.f3() - 1;
    if (self->inner.f2(index)->value < 0x7fff) {
        int next = self->inner.f3() - 1;
        return self->inner.f2(next)->value + 1;
    }

    int prev_val;
    int i = self->inner.f3() - 1;
    while (i >= 0) {
        if (i == 0) {
            Elem* e = self->inner.f2(i);
            if (e->value == 0)
                return -1;
            return self->inner.f2(i)->value - 1;
        }
        prev_val = self->inner.f2(i - 1)->value;
        if (self->inner.f2(i)->value - 1 > prev_val)
            return self->inner.f2(i)->value - 1;
        i--;
    }
    return -1;
}
