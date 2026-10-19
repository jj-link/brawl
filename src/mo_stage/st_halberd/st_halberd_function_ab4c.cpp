#pragma force_active on
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_57_AB4C(Base* self) {
    return !self->v3();
}
