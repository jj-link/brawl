#pragma force_active on
struct Data {
    int m_head;
    int m_value;
};

struct Inner {
    virtual void f0();
    virtual Data* f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    char pad[0x10];
    Inner m_inner;
};

extern "C" int fn_27_F5BE8(Outer* self) {
    return self->m_inner.f1()->m_value;
}
