#pragma force_active on
class soVirtualBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" bool fn_27_7B2EC(soVirtualBase* self) {
    return !self->vfunc3();
}
