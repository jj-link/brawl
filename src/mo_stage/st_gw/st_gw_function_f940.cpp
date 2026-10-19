#pragma force_active on
struct Fn63Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_63_F940(Fn63Obj* obj) {
    return obj->v3() == 0;
}
