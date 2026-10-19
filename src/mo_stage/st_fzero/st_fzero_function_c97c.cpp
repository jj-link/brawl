#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_61_C97C(Base* p) {
    return p->f3() == 0;
}
