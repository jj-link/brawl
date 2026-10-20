#pragma force_active on
class soVirtualBase {
public:
    virtual ~soVirtualBase();
    virtual void vfunc0();
    virtual void vfunc1();
};

extern "C" void fn_27_84B50(soVirtualBase* self) {
    self->vfunc0();
}
