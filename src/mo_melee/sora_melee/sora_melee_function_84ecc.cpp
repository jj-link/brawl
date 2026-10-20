#pragma force_active on
class soVirtualBase {
public:
    virtual ~soVirtualBase();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual bool vfunc6();
};

extern "C" {
bool fn_27_84ECC(soVirtualBase* p) {
    return !p->vfunc6();
}
}
