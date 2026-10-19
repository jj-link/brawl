#pragma force_active on
struct stIceVirtBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_62_A3AC(stIceVirtBase* self) {
    return !self->v3();
}
