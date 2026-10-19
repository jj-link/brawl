#pragma force_active on
struct fnObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_71_DA8C(fnObj* obj) {
    return obj->vf3() == 0;
}
