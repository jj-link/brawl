#pragma force_active on
struct fn_120_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_120_AF7C(fn_120_Base* self) {
    return self->v3() == 0;
}
