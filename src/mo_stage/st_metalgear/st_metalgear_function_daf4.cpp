#pragma force_active on
struct fn_71_DAF4_Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_71_DAF4(fn_71_DAF4_Base* obj) {
    return !obj->vf3();
}
