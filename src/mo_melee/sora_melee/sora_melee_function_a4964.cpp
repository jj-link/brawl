#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Outer {
    char pad[0x34];
    Inner* m_34;
};

extern "C" void fn_27_A4964(Outer* p) {
    return p->m_34->v1();
}
