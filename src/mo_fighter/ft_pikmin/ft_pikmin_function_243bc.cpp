#pragma force_active on
struct A {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

extern "C" void fn_113_243BC(A* a) {
    a->f3();
}
