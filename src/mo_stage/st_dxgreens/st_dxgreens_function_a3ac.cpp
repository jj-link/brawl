#pragma force_active on
struct StDxGreensBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_79_A3AC(StDxGreensBase* self) {
    return !self->vf3();
}
