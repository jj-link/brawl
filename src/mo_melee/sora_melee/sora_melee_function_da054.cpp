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
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual s16 target(s32* a, s32 b, s16* c, s8 d);
};

class soOuterObj {
public:
    u8 pad[8];
    soInnerObj* inner;
};

extern "C" s32 fn_27_DA054(soOuterObj* self, s32 val, s8 flag) {
    s16 out = 0;
    s16 r = self->inner->target(&val, -1, &out, flag);
    return r;
}
