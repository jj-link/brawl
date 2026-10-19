#pragma force_active on
struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int f();
};

extern "C" int fn_56_AF44(Obj* p) {
    return !p->f();
}
