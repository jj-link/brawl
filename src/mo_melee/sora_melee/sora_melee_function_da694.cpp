#include <types.h>
#pragma force_active on

struct soGeneralInnerVtblHolder {
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
    virtual s32 vf18(u32* a, s32 b, u16* c, s8 d);
};

struct soGeneralOuter {
    u8 pad[8];
    soGeneralInnerVtblHolder* inner;
};

extern "C" s16 fn_27_DA694(soGeneralOuter* o, u32 a, s8 b) {
    u16 c = 0;
    return (s16)o->inner->vf18(&a, -1, &c, b);
}
