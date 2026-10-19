#pragma force_active on
struct DacObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_71_DAC0(DacObj* self) {
    return self->v3() == 0;
}
