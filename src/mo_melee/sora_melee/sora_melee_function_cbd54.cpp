#pragma force_active on
struct fn27Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_27_CBD54(fn27Obj* p) {
    return !p->v3();
}
