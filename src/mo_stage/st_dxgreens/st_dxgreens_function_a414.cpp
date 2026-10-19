#pragma force_active on
struct dxGreensBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_79_A414(dxGreensBase* p) {
    return !p->v3();
}
