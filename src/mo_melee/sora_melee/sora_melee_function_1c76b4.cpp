#pragma force_active on
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

struct Outer {
    char pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_1C76B4(Outer* self) {
    Inner* p = &self->m_inner;
    p->v8();
}
