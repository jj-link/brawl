#pragma force_active on
struct B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};

struct A {
    int pad[4];
};

struct Outer : public A, public B {
};

extern "C" {
void fn_27_F2AA4(Outer& self) {
    static_cast<B&>(self).v13();
}
}
