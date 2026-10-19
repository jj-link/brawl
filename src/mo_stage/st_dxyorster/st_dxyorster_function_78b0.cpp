#pragma force_active on
struct fn_76_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_76_78B0(fn_76_Base* self) {
    return !self->v3();
}
