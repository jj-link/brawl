#pragma force_active on
struct Ret {
    int a;
    int b;
};

struct Inner {
    virtual void f0();
    virtual Ret* f1();
};

struct Outer {
    char pad[0x10];
    Inner m_inner;
};

extern "C" {
    int fn_27_1C35D4(Outer* p) {
        return p->m_inner.f1()->b;
    }
}
