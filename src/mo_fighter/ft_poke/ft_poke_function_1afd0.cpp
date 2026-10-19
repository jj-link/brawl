#pragma force_active on
struct A {
    virtual void f0();
    virtual void f1();
};

extern "C" void fn_116_1AFD0(A* a) {
    a->f1();
}
