#pragma force_active on
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Other {
    int a;
    int b;
    int c;
    int d;
};

struct Outer : public Other, public Sub {
};

extern "C" void fn_27_AFC14(Outer* p) {
    Sub& s = *p;
    s.v1();
}
