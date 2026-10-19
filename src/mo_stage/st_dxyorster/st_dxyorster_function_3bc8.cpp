#pragma force_active on
struct fn76Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_76_3BC8(fn76Base* self) {
    return !self->v3();
}
