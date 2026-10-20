#include <types.h>
#pragma force_active on

class soIfaceFn {
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
    virtual s32 vf18(u32* a, s32 b, u16* c, s8 d);
};

class soHolderFn {
public:
    u32 m_pad[2];
    soIfaceFn* m_obj;
};

extern "C" s16 fn_27_DA7D4(soHolderFn* self, u32 value, s8 flag) {
    u16 z = 0;
    return (s16)self->m_obj->vf18(&value, -1, &z, flag);
}
