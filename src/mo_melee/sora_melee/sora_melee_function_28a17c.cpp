#pragma force_active on
typedef unsigned int u32;

struct Outer;

class Base {
public:
    u32 m_a;
    u32 m_b;
};

class Inner : public Base {
public:
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
    virtual void v12(Outer* p);
};

struct Outer {
    char m_pad[0x8d0];
    Inner* m_inner;
};

extern "C" void fn_27_5F38(Outer* p);

extern "C" void fn_27_28A17C(Outer* p) {
    p->m_inner->v12(p);
    fn_27_5F38(p);
}
