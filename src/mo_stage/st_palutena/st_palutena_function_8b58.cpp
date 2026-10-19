#pragma force_active on
struct fnBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_67_8B58(fnBase* self) {
    return self->v3() == 0;
}
