#pragma force_active on
class soVirtualBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3() const;
};

extern "C" {
bool fn_27_C9384(soVirtualBase* obj) {
    return !obj->vfunc3();
}
}
