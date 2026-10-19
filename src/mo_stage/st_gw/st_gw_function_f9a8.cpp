#pragma force_active on
struct stBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_63_F9A8(stBase* obj) {
    return !obj->vf3();
}
