#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_46D24(u32 a, u8* b, u32 c, u32 d, u32 e, u32 f);

class soObjBase {
public:
    virtual void vf0();
    virtual u32 vf1(u32 p);
};

extern "C" void fn_27_48FB0(u8* self, u32 p2, u32 p3) {
    soObjBase* obj = *(soObjBase**)(self + 0x48);
    u32 r = obj->vf1(p3);
    s32 res = fn_27_46D24(r, self + 0x28, *(u32*)(self + 0x20), p2, p3, *(u32*)(self + 0x24));
    *(s32*)(self + 0x24) += res;
}
