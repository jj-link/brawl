#pragma force_active on
struct fn_40_1E2A0_Base {
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual bool vfunc5();
};

extern "C" {
bool fn_40_1E2A0(fn_40_1E2A0_Base* obj) {
    return !obj->vfunc5();
}
}
