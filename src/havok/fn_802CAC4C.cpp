#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Outer {
    char pad[4];
    Inner* m_inner;
};

extern "C" void fn_802CAC4C(Outer* p) {
    p->m_inner->v6();
}
