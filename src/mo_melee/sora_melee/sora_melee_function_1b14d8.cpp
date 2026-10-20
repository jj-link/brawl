#pragma force_active on
struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Holder {
    int pad[4];
    Sub sub;
};

extern "C" {
void fn_27_1B14D8(Holder* h) {
    return h->sub.f3();
}
}
