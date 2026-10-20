#pragma force_active on
typedef unsigned int u32;

class Inner {
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
    virtual void v10();
};

class Outer {
public:
    u32 m_pad[4];
    Inner m_inner;
};

extern "C" void fn_27_1C13CC(Outer* self) {
    self->m_inner.v8();
}
