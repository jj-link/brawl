#pragma force_active on
struct Sub {
    int pad;
    int value;
};

struct Inner {
    virtual void f0();
    virtual Sub* f1();
};

struct Outer {
    char pad[0x10];
    Inner m_inner;
};

extern "C" int fn_27_1C6748(Outer* self) {
    return self->m_inner.f1()->value;
}
