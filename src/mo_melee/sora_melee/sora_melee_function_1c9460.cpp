#pragma force_active on

struct B1 {
    int a, b, c, d;
};

struct B2 {
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
};

struct D : B1, B2 {
};

extern "C" void fn_27_1C9460(D* p) {
    p->v8();
}
