#include <types.h>
#pragma force_active on

class fnBase {
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
    virtual s32 vf20(s32 a, s32 b, u16* c, s32 d);
};

extern "C" s32 fn_27_84B60(fnBase* p, s32 a, s32 b) {
    u16 local = 0;
    return p->vf20(a, b, &local, -1);
}
