#pragma force_active on
struct fnBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_49_B6F8(fnBase* p) {
    return !p->v3();
}
