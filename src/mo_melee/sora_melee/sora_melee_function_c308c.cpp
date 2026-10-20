#pragma force_active on
class soVirtBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
};

extern "C" void fn_27_C308C(soVirtBase* self) {
    self->vf7();
}
