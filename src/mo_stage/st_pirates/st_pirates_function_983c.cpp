#pragma force_active on
struct StVirtBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_52_983C(StVirtBase* self) {
    return !self->v3();
}
