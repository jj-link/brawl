#pragma force_active on
struct stVirtBase {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual bool v3() = 0;
};

extern "C" bool fn_78_79DC(stVirtBase* p) {
    return !p->v3();
}
