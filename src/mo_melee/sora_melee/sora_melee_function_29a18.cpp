#include <types.h>
#pragma force_active on

struct soVirtObj {
    virtual void* vf0();
    virtual void* vf1(u32 v);
    virtual void* vf2();
    virtual void* vf3();
};

struct soFlagBits {
    u32 hi : 16;
    u32 f : 4;
    u32 lo : 12;
};

extern "C" void fn_27_29A18(u8* self, u32 a, u32 b) {
    soVirtObj* obj = *(soVirtObj**)(self + 0x28);
    soFlagBits* p = (soFlagBits*)((u8*)obj->vf1(b) + 0x38);
    p->f = a;
}
