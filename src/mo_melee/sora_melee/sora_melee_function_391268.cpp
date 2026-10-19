#pragma force_active on
class soVirtBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" bool fn_27_391268(soVirtBase* p) {
    return !p->vfunc3();
}
