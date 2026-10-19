#pragma force_active on
struct fn110Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_110_AA04(fn110Base* p) {
    return p->v3() == 0;
}
