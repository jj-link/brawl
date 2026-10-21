#pragma force_active on
struct fnA {
    int x0, x1, x2, x3;
};

struct fnB {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct fnD : fnA, fnB {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

extern "C" {
void fn_27_2EA88C(fnD& p) {
    static_cast<fnB&>(p).f1();
}
}
