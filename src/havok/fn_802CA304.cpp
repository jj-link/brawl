#pragma force_active on
struct Inner {
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
};

struct Outer {
    char pad[0x0c];
    Inner* m_inner;
};

extern "C" void fn_802CA304(Outer* o) {
    o->m_inner->v11();
}
