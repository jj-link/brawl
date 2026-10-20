#include <types.h>
#pragma force_active on

class fn_27_Base {
public:
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17(u32 a, u32 b) = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual u32 vf20() = 0;
};

extern "C" {
void fn_27_93F8C(fn_27_Base* self, u32 a, u32 b) {
    if (self->vf20() == 1) {
        self->vf17(a, b);
    }
}
}
