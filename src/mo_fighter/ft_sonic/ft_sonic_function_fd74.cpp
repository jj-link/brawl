#pragma force_active on
struct FnBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
    virtual void v4();
    virtual void v5();
};

extern "C" bool fn_123_FD74(FnBase* self) {
    return !self->v3();
}
