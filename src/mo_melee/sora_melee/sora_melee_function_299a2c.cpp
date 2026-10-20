#include <types.h>
#pragma force_active on

class soVirtTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4(u32 arg);
};

extern "C" {
u32 fn_27_299A2C(void* unused, void* p) {
    void* a = *(void**)((u8*)p + 0x60);
    void* b = *(void**)((u8*)a + 0xd8);
    soVirtTarget* c = *(soVirtTarget**)((u8*)b + 0x64);
    return c->vf4(0x10000000);
}
}
