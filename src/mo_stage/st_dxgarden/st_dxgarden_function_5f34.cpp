#pragma force_active on
struct DxGardenBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_77_5F34(DxGardenBase* obj) {
    return !obj->vf3();
}
