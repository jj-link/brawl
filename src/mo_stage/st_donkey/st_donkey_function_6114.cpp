#pragma force_active on
struct fn_50_6114_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_50_6114(fn_50_6114_Base* self) {
    return self->v3() == 0;
}
