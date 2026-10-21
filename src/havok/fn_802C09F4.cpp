#pragma force_active on
struct V {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
};

extern "C" void fn_802C09F4(int a, int b, int c, int d, V* v) {
    v->f1();
}
