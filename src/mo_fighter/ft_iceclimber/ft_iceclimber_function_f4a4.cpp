#pragma force_active on
struct IceClimberObject {
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual bool vfunc_0C();
};

extern "C" bool fn_105_F4A4(IceClimberObject* object) {
    return !object->vfunc_0C();
}
