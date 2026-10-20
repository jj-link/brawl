#pragma force_active on
struct SoSub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct SoOuter {
    int pad[4];
    SoSub sub;
};

extern "C" {
void fn_27_D9DF4(SoOuter* p) {
    p->sub.f3();
}
}
