#pragma force_active on
struct soObjBase {
    virtual ~soObjBase();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf5();
};

extern "C" bool fn_52_9870(soObjBase* self) {
    return !self->vf5();
}
