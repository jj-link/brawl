#pragma force_active on
class fn_27_8F9F0_Base {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual bool vfunc4();
};

extern "C" bool fn_27_8F9F0(fn_27_8F9F0_Base* self) {
    return !self->vfunc4();
}
