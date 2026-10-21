#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
    virtual void f4();
    virtual void f5();
};

extern "C" void* fn_801ADEBC(Inner* arg0) {
    return (char*)arg0->f3() + 4;
}
