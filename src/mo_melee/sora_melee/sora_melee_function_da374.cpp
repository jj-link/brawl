#include <types.h>
#pragma force_active on

class SoInner {
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
    virtual s32 vf18(u32* a, s32 b, s16* c, s32 d);
};

class SoOuter {
public:
    u8 pad[8];
    SoInner* m_inner;
};

extern "C" s16 fn_27_DA374(SoOuter* self, u32 val, s8 flag) {
    s16 c = 0;
    s32 r = self->m_inner->vf18((u32*)&val, -1, &c, flag);
    return (s16)r;
}
