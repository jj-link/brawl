#pragma force_active on
struct ftFoxVirtBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_97_C93C(ftFoxVirtBase* obj) {
    return obj->vf3() == 0;
}
