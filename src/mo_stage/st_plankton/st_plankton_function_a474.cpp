#pragma force_active on
struct fn_74_A474_Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_74_A474(fn_74_A474_Base* obj) {
    return !obj->vf3();
}
