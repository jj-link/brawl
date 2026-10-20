#pragma force_active on
struct fn27Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct fn27Outer {
    int pad[4];
    fn27Base sub;
};

extern "C" {
void fn_27_1CD0C8(fn27Outer* p) {
    fn27Base* b = &p->sub;
    b->f1();
}
}
