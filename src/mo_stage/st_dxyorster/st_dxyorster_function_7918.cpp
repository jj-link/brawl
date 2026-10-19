#pragma force_active on
struct fn_76_7918_Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
    virtual void vf4();
    virtual void vf5();
};

extern "C" bool fn_76_7918(fn_76_7918_Base* self) {
    return !self->vf3();
}
