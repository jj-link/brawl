#pragma force_active on
struct fn802CE808Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct fn802CE808Outer {
    char pad[0xc];
    fn802CE808Inner* m_inner;
};

extern "C" void fn_802CE808(fn802CE808Outer* o) {
    o->m_inner->v3();
}
