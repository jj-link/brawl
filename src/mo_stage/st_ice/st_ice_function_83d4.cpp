#pragma force_active on
struct stIceBase {
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5();
};

extern "C" bool fn_62_83D4(stIceBase* obj) {
    return !obj->vf5();
}
