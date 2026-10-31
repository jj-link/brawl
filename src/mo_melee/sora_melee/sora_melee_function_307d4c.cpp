#include <types.h>
#pragma force_active on

class SoVObj {
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
    virtual s32 vf9(u32 a, u32 b);
};

extern "C" s32 fn_27_307D4C(s32 ret, u8* p, s32 id) {
    if (id == 0x118) {
        return ret;
    }
    if (id == 0x15b) {
        return ret;
    }
    SoVObj* b = *(SoVObj**)(*(u8**)(p + 0xd8) + 0x3c);
    return b->vf9(0, 0);
}
