#include <types.h>
#pragma force_active on

class fn27Target {
public:
    virtual void vf0();
    virtual void vf1();
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
    virtual void vf20(u32 a, u32 b, u16* out, s32 c);
};

extern "C" {
void fn_27_846B0(fn27Target* self, u32 a, u32 b) {
    u16 x = 0;
    self->vf20(a, b, &x, -1);
}
}
