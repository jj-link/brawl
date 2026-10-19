#pragma force_active on
class soIfaceBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
};

extern "C" bool fn_27_86964(soIfaceBase* p) {
    return !p->vfunc3();
}
