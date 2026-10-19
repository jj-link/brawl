#pragma force_active on
struct soObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_106A14(soObj* obj) {
    return !obj->vf3();
}
