#pragma force_active on
extern "C" int fn_27_2AD89C(void* self);

class soWorkBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual unsigned int vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
};

extern "C" void* fn_27_2AF068(soWorkBase* self) {
    int idx = fn_27_2AD89C(self);
    if (self->vfunc4() != 1 && idx >= 0) {
        self->vfunc13();
    }
    return (char*)self + idx * 12 + 0x10;
}
