#pragma force_active on
struct stIceBase {
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual int vf3() = 0;
};

extern "C" bool fn_62_5E28(stIceBase* obj) {
    return obj->vf3() == 0;
}
