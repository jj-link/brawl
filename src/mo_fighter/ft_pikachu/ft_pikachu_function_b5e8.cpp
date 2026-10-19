#pragma force_active on
struct FnObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" int fn_98_B5E8(FnObj* self) {
    return !self->v3();
}
