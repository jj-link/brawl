#pragma force_active on

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};

extern "C" void* fn_8019B8CC(Obj* p) {
    return (char*)p->f3() + 4;
}
