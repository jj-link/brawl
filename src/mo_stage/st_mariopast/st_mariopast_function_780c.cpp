#pragma force_active on
struct FnBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_48_780C(FnBase* p) {
    return p->v3() == 0;
}
