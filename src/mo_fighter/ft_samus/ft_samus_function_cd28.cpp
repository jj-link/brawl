#pragma force_active on
struct fn94Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_94_CD28(fn94Base* p) {
    return !p->v3();
}
