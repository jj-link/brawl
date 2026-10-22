#pragma force_active on

class Inner {
public:
    virtual void s0();
    virtual void s1();
    virtual int* get(int idx);
    virtual int count();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual int s15();
};

class Outer {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s7();
    char pad[0xC];
    Inner inner;
};

extern "C" int fn_27_F8E98(Outer* self) {
    int t;
    int r30;
    int n;
    if ((unsigned)self->inner.s15() == 1U) {
        return 0x7FFF;
    }
    if ((unsigned)self->s7() == 1U) {
        return 0;
    }
    n = self->inner.count() - 1;
    if (self->inner.get(n)[1] < 0x7FFF) {
        n = self->inner.count() - 1;
        return self->inner.get(n)[1] + 1;
    }
    r30 = self->inner.count() - 1;
    while (r30 >= 0) {
        if (r30 == 0) {
            if (self->inner.get(r30)[1] == 0) {
                return -1;
            }
            return self->inner.get(r30)[1] - 1;
        }
        t = self->inner.get(r30 - 1)[1];
        if (self->inner.get(r30)[1] - 1 > t) {
            return self->inner.get(r30)[1] - 1;
        }
        r30--;
    }
    return -1;
}
