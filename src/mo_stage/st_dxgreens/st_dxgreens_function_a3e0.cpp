#pragma force_active on
struct stDxGreensObject {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
};

extern "C" bool fn_79_A3E0(stDxGreensObject* obj) {
    return !obj->vfunc3();
}
