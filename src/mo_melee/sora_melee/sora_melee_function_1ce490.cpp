#pragma force_active on
struct soVBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad[3];
};

struct soSecond {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
};

struct soDerived : soVBase, soSecond {
};

extern "C" {
void fn_27_1CE490(soDerived& self) {
    static_cast<soSecond&>(self).g1();
}
}
