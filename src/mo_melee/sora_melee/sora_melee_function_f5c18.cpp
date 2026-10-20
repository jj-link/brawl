#pragma force_active on
struct fn27Inner {
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

struct fn27Outer {
    char pad[0x10];
    fn27Inner m_inner;
};

extern "C" {
void fn_27_F5C18(fn27Outer* p) {
    p->m_inner.v13();
}
}
