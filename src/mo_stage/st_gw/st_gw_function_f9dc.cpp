#pragma force_active on
struct StObjBase {
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual bool vf3() = 0;
};

extern "C" bool fn_63_F9DC(StObjBase* self) {
    return self->vf3() == 0;
}
