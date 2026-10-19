#pragma force_active on
struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
    virtual void f4();
    virtual void f5();
};

extern "C" bool fn_79_A47C(Obj* obj) {
    return !obj->f3();
}
