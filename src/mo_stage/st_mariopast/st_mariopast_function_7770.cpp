#pragma force_active on
struct StBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_48_7770(StBase* p) {
    return !p->v3();
}
