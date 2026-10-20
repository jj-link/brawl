#pragma force_active on
struct Pre {
    int a;
    int b;
    int c;
};

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct Outer : Pre, Sub {
};

extern "C" void fn_27_1A89FC(Outer& self) {
    Sub& s = self;
    s.f4();
}
