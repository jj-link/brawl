#pragma force_active on
struct V {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
};

extern "C" void fn_801C10D0(V* v) {
    v->f2();
}