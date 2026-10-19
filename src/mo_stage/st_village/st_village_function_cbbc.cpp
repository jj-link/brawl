#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_70_CBBC(Obj* obj) {
    return obj->v3() == 0;
}
