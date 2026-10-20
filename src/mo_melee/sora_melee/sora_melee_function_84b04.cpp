#pragma force_active on
class soVirtualBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
};

extern "C" {
void fn_27_84B04(soVirtualBase* self) {
    self->vfunc1();
}
}
