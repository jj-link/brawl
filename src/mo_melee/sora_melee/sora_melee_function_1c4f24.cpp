#pragma force_active on
struct Sec {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};

struct Outer {
    int pad[4];
    Sec sec;
};

extern "C" void fn_27_1C4F24(Outer* p) {
    p->sec.f8();
}
