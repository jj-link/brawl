#pragma force_active on
struct IFace {
    virtual void f0();
    virtual void f1();
};

struct Pad {
    int a;
    int b;
    int c;
    int d;
};

struct Derived : public Pad, public IFace {
};

extern "C" void fn_27_1E4D70(Derived& p) {
    ((IFace&)p).f1();
}
