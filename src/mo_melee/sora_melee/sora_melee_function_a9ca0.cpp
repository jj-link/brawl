#include <types.h>
#pragma force_active on

class soWorkBase {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(s32 value);
    virtual void vf6(s32 value);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

extern "C" void fn_27_A9CA0(soWorkBase* self) {
    self->vf5(-2);
    self->vf6(-2);
    self->vf11();
}
