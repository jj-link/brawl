#pragma force_active on
struct grBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_40_29898(grBase* p) {
    return !p->f3();
}
