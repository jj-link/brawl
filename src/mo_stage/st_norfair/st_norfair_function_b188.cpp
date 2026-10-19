#pragma force_active on
struct StBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_54_B188(StBase* p) {
    return !p->v3();
}
