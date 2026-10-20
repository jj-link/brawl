#pragma force_active on
class soVirtualBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

extern "C" void fn_27_10EB9C(soVirtualBase* self) {
    self->vfunc1();
}
