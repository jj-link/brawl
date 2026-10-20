#include <types.h>
#pragma force_active on

class soGeneralObj {
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
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual u32 vf22();
    virtual void vf23();
};

extern "C" {
s32 fn_27_8D3E4(soGeneralObj* self) {
    if (self->vf22() == 1) {
        self->vf23();
    } else {
        self->vf21();
    }
    return 1;
}
}
