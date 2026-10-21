#pragma force_active on
struct Obj {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
};
extern "C" void fn_104_128F0(Obj* o) { o->f14(); }
