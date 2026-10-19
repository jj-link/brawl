#pragma force_active on
struct stNorfairVirtBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_54_B154(stNorfairVirtBase* self) {
    return !self->vf3();
}
