#pragma force_active on
struct fn_76_78E4_Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_76_78E4(fn_76_78E4_Base* self) {
    return !self->vf3();
}
