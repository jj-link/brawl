#pragma force_active on
struct stMansionBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_47_978C(stMansionBase* obj) {
    return !obj->vf3();
}
