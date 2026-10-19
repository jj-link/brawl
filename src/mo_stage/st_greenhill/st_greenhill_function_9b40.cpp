#pragma force_active on
struct fn_72_9B40_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_72_9B40(fn_72_9B40_Base* self) {
    return self->v3() == 0;
}
