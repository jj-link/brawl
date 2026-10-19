#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
    virtual void v4();
    virtual void v5();
};

extern "C" {
bool fn_51_6220(Obj* p) {
    return !p->v3();
}
}
