#pragma force_active on
class soVirtualBase {
public:
    virtual ~soVirtualBase();
    virtual void vfunc0();
    virtual void vfunc1();
    virtual bool vfunc2();
};

extern "C" bool fn_27_552B8(soVirtualBase* p) {
    return !p->vfunc2();
}
