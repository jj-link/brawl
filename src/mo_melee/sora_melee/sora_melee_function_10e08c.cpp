#pragma force_active on
struct fnA {
    int x0, x1, x2;
};

struct fnB {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct fnD : fnA, fnB {
    virtual void f6();
};

extern "C" {
void fn_27_10E08C(fnD& p) {
    static_cast<fnB&>(p).f4();
}
}
