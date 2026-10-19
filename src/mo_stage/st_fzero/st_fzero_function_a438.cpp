#pragma force_active on
struct stFzeroObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_61_A438(stFzeroObj* obj) {
    return !obj->vf3();
}
