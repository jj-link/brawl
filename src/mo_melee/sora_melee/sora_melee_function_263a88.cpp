#include <types.h>
#pragma force_active on

class soInnerObj {
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
    virtual void vf12(u32 a, u32 b);
};

extern "C" void fn_27_263A88(u8* self, u32 type, u32 value) {
    if (type == 1) {
        u8* a = *(u8**)(self + 0x180);
        soInnerObj* b = *(soInnerObj**)(a + 0x90);
        return b->vf12(value, 1);
    }
    u8* a = *(u8**)(self + 0x180);
    soInnerObj* b = *(soInnerObj**)(a + 0x90);
    return b->vf12(value, 0);
}
