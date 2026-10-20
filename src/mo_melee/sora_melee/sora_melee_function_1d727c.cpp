#include <types.h>
#pragma force_active on

class fnInterface27 {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32 arg);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
};

extern "C" void fn_27_1D727C(fnInterface27* self, u32 arg) {
    if (self->vf16() == 1) {
        self->vf8();
    }
    self->vf12(arg);
}
