#include <types.h>
#pragma force_active on

class Object27 {
public:
    char* base;
    u32 pad[2];

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
    virtual void vf14(s32, s32, s32);
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(s32, s32);
};

extern "C" void* fn_27_1D53E4(void*, u32, u32);

extern "C" void fn_27_1D7048(Object27* self, s32 arg1) {
    if (arg1 != (s32)fn_27_1D53E4(self->base + 0x9E8, 9, 0)) {
        self->vf14(arg1, 9, 0);
        if (arg1 == 0x3D) {
            self->vf17(0x12, 0);
            return;
        }
        if (arg1 == 0x6A) {
            self->vf17(0x13, 0);
        }
    }
}
