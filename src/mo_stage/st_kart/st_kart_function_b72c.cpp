#pragma force_active on
struct fn_49_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_49_B72C(fn_49_Base* self) {
    return !self->v3();
}
