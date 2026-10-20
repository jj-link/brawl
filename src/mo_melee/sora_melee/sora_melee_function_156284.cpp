#include <types.h>
#pragma force_active on

#define VF(n) virtual s32 f##n();

struct VA {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8)
    VF(9) VF(10) VF(11) VF(12) VF(13) VF(14) VF(15)
    virtual s32 f16();
};

struct VB {
    VF(0) VF(1) VF(2) VF(3)
    virtual s32 f4(u32 x);
};

extern "C" s32 fn_27_156284(void* unused, u8* obj) {
    u8* p = *(u8**)(obj + 0xd8);
    VA* a = *(VA**)(p + 0x70);
    if (a->f16() == 0xC1) {
        goto zero;
    }
    {
        VB* b = *(VB**)(*(u8**)(obj + 0xd8) + 0x64);
        if (b->f4(0x1000000F) > 0) {
            goto zero;
        }
    }
    return 1;
zero:
    return 0;
}
