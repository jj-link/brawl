#pragma force_active on
struct Iface {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

struct Base0 {
    virtual void g0();
    int pad[3];
};

struct Outer : public Base0, public Iface {
    virtual void g0();
};

extern "C" void fn_27_1ADAAC(Outer& p) {
    static_cast<Iface&>(p).vf8();
}
