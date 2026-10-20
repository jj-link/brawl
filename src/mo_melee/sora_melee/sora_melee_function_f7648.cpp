#pragma force_active on
struct Vt {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Pad {
    int a, b, c, d;
};

struct Outer : public Pad, public Vt {
};

extern "C" void fn_27_F7648(Outer& p) {
    ((Vt&)p).f1();
}
