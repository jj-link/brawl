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
};

class Outer {
public:
    char pad[0x40];
    Inner m_inner;
};

extern "C" {
void fn_27_2B4B08(Outer* self) {
    self->m_inner.v7();
}
}
