#pragma force_active on
struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_61_C9E4(Obj* p) {
    return !p->f3();
}
