#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2BC3B0(void*);

class soWorkBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

extern "C" void* fn_27_2BBDD4(soWorkBase* self) {
    s32 idx = fn_27_2BC3B0(self);
    if (self->vf4() != 1) {
        if (idx >= 0) {
            self->vf13();
        }
    }
    return (char*)self + idx * 0x14 + 0xc;
}
