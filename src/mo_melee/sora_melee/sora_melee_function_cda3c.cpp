#pragma force_active on
class soObjBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
};

extern "C" bool fn_27_CDA3C(soObjBase* obj) {
    return !obj->vfunc3();
}
