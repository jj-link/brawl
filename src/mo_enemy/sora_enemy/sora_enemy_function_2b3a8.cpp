#pragma force_active on
struct fn41Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
};

struct fn41Outer {
    char pad[0x2c];
    fn41Inner* m_inner;
};

extern "C" int fn_41_2B3A8(fn41Outer* p) {
    return p->m_inner->v3();
}
