#pragma force_active on
struct fn_27_Prim {
    int x[4];
};

struct fn_27_Sec {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};

struct fn_27_Derived : public fn_27_Prim, public fn_27_Sec {
};

extern "C" {
void fn_27_F39E0(fn_27_Derived* p) {
    p->f8();
}
}
