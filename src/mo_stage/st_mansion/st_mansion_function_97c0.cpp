#pragma force_active on
struct FnBase47 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v5();
};

extern "C" bool fn_47_97C0(FnBase47* obj) {
    return obj->v5() == 0;
}
