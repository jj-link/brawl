#pragma force_active on
struct soVirtualBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_49_6970(soVirtualBase* self) {
    return !self->vf3();
}
