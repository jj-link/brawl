#pragma force_active on
struct Pad {
    int a[4];
};

struct Sub {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
};

struct Outer : public Pad, public Sub {
};

extern "C" {
void fn_27_1BE6E4(Outer& o);
}

extern "C" void fn_27_1BE6E4(Outer& o) {
    static_cast<Sub&>(o).f13();
}
