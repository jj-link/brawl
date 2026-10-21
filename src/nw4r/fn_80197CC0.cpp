#pragma force_active on
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};

extern "C" void* fn_80197CC0(Inner* p) {
    return (char*)p->f3() + 4;
}
